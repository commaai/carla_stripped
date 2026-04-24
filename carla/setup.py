"""Shim setup.py: downloads CARLA's prebuilt wheel from GitHub Releases at install time.

The published wheel ships `carla.cpython-312-x86_64-linux-gnu.so` as a top-level extension
module. We extract that .so into this shim's package directory as `_carla.<ext>.so` and expose
its public API through `carla/__init__.py` (`from ._carla import *`).

Network fetch happens only on first install — uv caches the git source by commit sha and the
resulting built wheel, so subsequent `uv run --frozen` invocations stay offline.
"""
import os
import platform
import time
import zipfile
from io import BytesIO
from urllib.error import URLError
from urllib.request import urlopen

import tomllib

from setuptools import setup
from setuptools.command.build_py import build_py

_HERE = os.path.dirname(os.path.abspath(__file__))
with open(os.path.join(_HERE, "pyproject.toml"), "rb") as _f:
  _cfg = tomllib.load(_f)

REPO_URL = _cfg["tool"]["shim"]["repo_url"]
TAG = _cfg["tool"]["shim"]["tag"]
WHEEL_TAG = _cfg["tool"]["shim"]["wheel_tag"]
VERSION = _cfg["project"]["version"]
MODULE = _cfg["project"]["name"]

PLATFORM_MAP = {
  ("Linux", "x86_64"): "linux_x86_64",
}


class InstallPrebuilt(build_py):
  def run(self):
    module_dir = os.path.join(_HERE, MODULE)
    # Skip if already extracted (e.g. re-running build_py on an already-populated checkout)
    if any(fn.endswith(".so") for fn in os.listdir(module_dir)):
      super().run()
      return

    key = (platform.system(), platform.machine())
    plat = PLATFORM_MAP.get(key)
    if plat is None:
      raise RuntimeError(f"unsupported platform for prebuilt carla wheel: {key}")

    whl_name = f"{MODULE}-{VERSION}-{WHEEL_TAG}-{plat}.whl"
    url = f"{REPO_URL}/releases/download/{TAG}/{whl_name}"

    print(f"Downloading {url} ...")
    for attempt in range(3):
      try:
        raw = urlopen(url, timeout=120).read()
        break
      except (URLError, OSError) as e:
        if attempt == 2:
          raise
        wait = 2 ** attempt
        print(f"Download failed ({e}), retrying in {wait}s ...")
        time.sleep(wait)

    print("Extracting native .so ...")
    with zipfile.ZipFile(BytesIO(raw)) as zf:
      for info in zf.infolist():
        # Preserve the .so's filename — PyInit_carla is baked in at compile time, so the file
        # must be loaded as a module named `carla`. Drop it into our shim's carla/ package dir
        # unchanged; it becomes the submodule `carla.carla` (whose PyInit is PyInit_carla).
        name = info.filename
        if name.startswith(f"{MODULE}.") and name.endswith(".so"):
          dest = os.path.join(module_dir, name)
          with open(dest, "wb") as f:
            f.write(zf.read(info))
          if info.external_attr >> 16 & 0o111:
            os.chmod(dest, 0o755)

    super().run()


setup(cmdclass={"build_py": InstallPrebuilt})

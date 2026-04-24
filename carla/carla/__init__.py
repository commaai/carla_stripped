"""Shim package: re-export the native CARLA extension's public surface.

The published wheel ships `carla.cpython-*.so` as a top-level single-file extension. The shim
at build time extracts it as `_carla.cpython-*.so` inside this package; this `__init__.py`
delegates to it so `import carla; carla.Client(...)` works as if users had installed the
original wheel.
"""
from ._carla import *  # noqa: F401, F403

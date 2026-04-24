"""Shim package for the prebuilt CARLA extension.

The native module lives at `carla/carla.cpython-*.so` (a submodule whose PyInit_carla is
called when loaded as `carla.carla`). Re-export its public surface so users can do
`import carla; carla.Client(...)` as if they'd installed the original wheel.
"""
from .carla import *  # noqa: F401, F403

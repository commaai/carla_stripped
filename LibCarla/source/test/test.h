<<<<<<< HEAD
// Copyright (c) 2025 Computer Vision Center (CVC) at the Universitat Autonoma
=======
// Copyright (c) 2024 Computer Vision Center (CVC) at the Universitat Autonoma
>>>>>>> f676339c2 (added template for defaultgame.ini)
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#ifndef NDEBUG
#  define LIBCARLA_LOG_LEVEL LIBCARLA_LOG_LEVEL_INFO
#endif // NDEBUG

#include "test/Buffer.h"

#include <carla/Logging.h>
#include <carla/profiler/Profiler.h>

#include <gtest/gtest.h>

#include <chrono>
#include <cstdint>
#include <iostream>

constexpr uint16_t TESTING_PORT = 0u;

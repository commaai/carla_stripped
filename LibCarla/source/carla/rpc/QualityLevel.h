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

#include "carla/MsgPack.h"

#include <cstdint>

namespace carla {
namespace rpc {

  enum class QualityLevel : uint8_t {
    Low,
    // Medium,
    // High,
    Epic,

    SIZE,
    INVALID
  };

} // namespace rpc
} // namespace carla

MSGPACK_ADD_ENUM(carla::rpc::QualityLevel);

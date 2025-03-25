<<<<<<< HEAD
// Copyright (c) 2025 Computer Vision Center (CVC) at the Universitat Autonoma
=======
// Copyright (c) 2024 Computer Vision Center (CVC) at the Universitat Autonoma
>>>>>>> f676339c2 (added template for defaultgame.ini)
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>

#pragma once

#include "carla/MsgPack.h"
#include "carla/MsgPackAdaptors.h"

namespace carla {
namespace rpc {

  enum class VehicleWheelLocation : uint8_t {

    FL_Wheel = 0,
    FR_Wheel = 1,
    BL_Wheel = 2, 
    BR_Wheel = 3,
    //Use for bikes and bicycles
    Front_Wheel = 0,
    Back_Wheel = 1,
  };
  
}
}

<<<<<<< HEAD
MSGPACK_ADD_ENUM(carla::rpc::VehicleWheelLocation);
=======
MSGPACK_ADD_ENUM(carla::rpc::VehicleWheelLocation);
>>>>>>> f676339c2 (added template for defaultgame.ini)

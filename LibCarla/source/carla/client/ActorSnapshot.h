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

#include "carla/geom/Transform.h"
#include "carla/geom/Vector3D.h"
#include "carla/rpc/ActorId.h"
#include "carla/rpc/ActorState.h"
#include "carla/sensor/data/ActorDynamicState.h"

namespace carla {
namespace client {

  struct ActorSnapshot {
    ActorId id = 0u;
    rpc::ActorState actor_state;
    geom::Transform transform;
    geom::Vector3D velocity;
    geom::Vector3D angular_velocity;
    geom::Vector3D acceleration;
    sensor::data::ActorDynamicState::TypeDependentState state;
  };

} // namespace client
} // namespace carla

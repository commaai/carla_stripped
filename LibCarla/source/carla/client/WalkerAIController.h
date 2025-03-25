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

#include "carla/client/Actor.h"
#include "carla/geom/Vector3D.h"

#include <optional>

namespace carla {
namespace client {

  class WalkerAIController : public Actor {
  public:

    explicit WalkerAIController(ActorInitializer init);

    void Start();

    void Stop();

    std::optional<geom::Location> GetRandomLocation();

    void GoToLocation(const carla::geom::Location &destination);

    void SetMaxSpeed(const float max_speed);
  };

} // namespace client
} // namespace carla

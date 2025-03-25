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
#include "carla/geom/Transform.h"

#include <string>
#include <vector>

namespace carla {
namespace rpc {

  class MapInfo {
  public:

    std::string name;

    std::vector<geom::Transform> recommended_spawn_points;

    MSGPACK_DEFINE_ARRAY(name, recommended_spawn_points);
  };

} // namespace rpc
} // namespace carla

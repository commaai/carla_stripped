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

#include "carla/road/element/LaneMarking.h"

#include <vector>

namespace carla {
namespace geom { struct Location; }
namespace road {

  class Map;

namespace element {

  class LaneCrossingCalculator {
  public:

    static std::vector<LaneMarking> Calculate(
        const Map &map,
        const geom::Location &origin,
        const geom::Location &destination);
  };

} // namespace element
} // namespace road
} // namespace carla

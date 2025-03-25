<<<<<<< HEAD
// Copyright (c) 2025 Computer Vision Center (CVC) at the Universitat Autonoma
=======
// Copyright (c) 2024 Computer Vision Center (CVC) at the Universitat Autonoma
>>>>>>> f676339c2 (added template for defaultgame.ini)
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include "carla/client/TrafficSign.h"
#include "carla/client/detail/Simulator.h"
#include "carla/client/ActorList.h"

namespace carla {
namespace client {

  carla::road::SignId TrafficSign::GetSignId() const {
    return std::string(GetEpisode().Lock()->GetActorSnapshot(*this).state.traffic_light_data.sign_id);
  }

} // namespace client
} // namespace carla

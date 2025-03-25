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

#include "TrafficLightState.generated.h"


UENUM(BlueprintType)
enum class ETrafficLightState : uint8 {
  Red       UMETA(DisplayName = "Red"),
  Yellow    UMETA(DisplayName = "Yellow"),
  Green     UMETA(DisplayName = "Green"),
  Off       UMETA(DisplayName = "Off")
};

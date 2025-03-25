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

#include "VehicleAckermannControl.generated.h"

USTRUCT(BlueprintType)
struct CARLA_API FVehicleAckermannControl
{
  GENERATED_BODY()

  UPROPERTY(Category = "Vehicle Ackermann Control", EditAnywhere, BlueprintReadWrite)
  float Steer = 0.0f;

  UPROPERTY(Category = "Vehicle Ackermann Control", EditAnywhere, BlueprintReadWrite)
  float SteerSpeed = 0.0f;

  UPROPERTY(Category = "Vehicle Ackermann Control", EditAnywhere, BlueprintReadWrite)
  float Speed = 0.0f;

  UPROPERTY(Category = "Vehicle Ackermann Control", EditAnywhere, BlueprintReadWrite)
  float Acceleration = 0.0f;

  UPROPERTY(Category = "Vehicle Ackermann Control", EditAnywhere, BlueprintReadWrite)
  float Jerk = 0.0f;
};


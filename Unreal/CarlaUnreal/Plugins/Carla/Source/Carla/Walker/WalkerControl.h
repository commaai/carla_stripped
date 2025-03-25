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

#include "WalkerControl.generated.h"

USTRUCT(BlueprintType)
struct CARLA_API FWalkerControl
{
  GENERATED_BODY()

  UPROPERTY(Category = "Walker Control", EditAnywhere, BlueprintReadWrite)
  FVector Direction = {1.0f, 0.0f, 0.0f};

  UPROPERTY(Category = "Walker Control", EditAnywhere, BlueprintReadWrite)
  float Speed = 0.0f;

  UPROPERTY(Category = "Walker Control", EditAnywhere, BlueprintReadWrite)
  bool Jump = false;
};

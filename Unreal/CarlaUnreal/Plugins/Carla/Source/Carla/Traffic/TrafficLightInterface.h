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

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TrafficLightState.h"
#include "TrafficLightInterface.generated.h"

UINTERFACE(BlueprintType)
class CARLA_API UTrafficLightInterface : public UInterface
{
  GENERATED_BODY()
};

class ITrafficLightInterface
{
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Traffic Light Interface")
  void LightChanged(ETrafficLightState NewLightState);
};

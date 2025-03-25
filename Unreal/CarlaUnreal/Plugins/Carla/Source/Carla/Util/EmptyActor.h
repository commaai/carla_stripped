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

#include "GameFramework/Pawn.h"
#include "EmptyActor.generated.h"

UCLASS()
class CARLA_API AEmptyActor : public APawn
{
  GENERATED_BODY()

public:
  AEmptyActor(const FObjectInitializer &ObjectInitializer);

private:
  UPROPERTY(Category="Empty Actor", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
  USceneComponent* RootSceneComponent;
};

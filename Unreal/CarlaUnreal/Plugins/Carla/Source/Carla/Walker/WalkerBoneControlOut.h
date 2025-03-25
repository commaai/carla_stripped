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

#include "WalkerBoneControlOut.generated.h"

USTRUCT(BlueprintType)
struct CARLA_API FWalkerBoneControlOutData
{
  GENERATED_BODY()
  FTransform World;
  FTransform Component;
  FTransform Relative;
};

USTRUCT(BlueprintType)
struct CARLA_API FWalkerBoneControlOut
{
  GENERATED_BODY()

  UPROPERTY(Category = "Walker Bone Control", EditAnywhere, BlueprintReadWrite)
  TMap<FString, FWalkerBoneControlOutData> BoneTransforms;

};

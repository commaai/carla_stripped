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

#include <util/ue-header-guard-begin.h>
#include "CoreMinimal.h"
#include <util/ue-header-guard-end.h>

#include "EditorCamera.generated.h"

UCLASS(BlueprintType)
class CARLATOOLS_API AEditorCameraUtils :
    public AActor
{
    GENERATED_BODY()
public:

    UFUNCTION(BlueprintCallable, CallInEditor)
    void Get();

    UFUNCTION(BlueprintCallable, CallInEditor)
    void Set();



    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FTransform CameraTransform;

};

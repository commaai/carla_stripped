
// Copyright (c) 2025 Computer Vision Center (CVC) at the Universitat Autonoma de Barcelona (UAB).


#include "UncenteredPivotPointMesh.h"

AUncenteredPivotPointMesh::AUncenteredPivotPointMesh(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
{
  PrimaryActorTick.bCanEverTick = false;

  RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
  SMComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
  SMComp->SetupAttachment(RootComponent);
}

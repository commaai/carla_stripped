<<<<<<< HEAD
// Copyright (c) 2025 Computer Vision Center (CVC) at the Universitat Autonoma
=======
// Copyright (c) 2024 Computer Vision Center (CVC) at the Universitat Autonoma
>>>>>>> f676339c2 (added template for defaultgame.ini)
// de Barcelona (UAB).
// Copyright (c) 2019 Intel Corporation
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include "CarlaWheeledVehicleNW.h"
#include "WheeledVehicleMovementComponentNW.h"

ACarlaWheeledVehicleNW::ACarlaWheeledVehicleNW(const FObjectInitializer& ObjectInitializer) :
  Super(ObjectInitializer.SetDefaultSubobjectClass<UChaosWheeledVehicleMovementComponent>(
	  AWheeledVehiclePawn::VehicleMovementComponentName))
{
  bIsNWVehicle = true;
}

ACarlaWheeledVehicleNW::~ACarlaWheeledVehicleNW() {}

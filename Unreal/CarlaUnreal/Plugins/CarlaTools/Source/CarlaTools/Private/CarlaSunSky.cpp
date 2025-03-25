<<<<<<< HEAD
// Copyright (c) 2025 Computer Vision Center (CVC) at the Universitat Autonoma de Barcelona (UAB). This work is licensed under the terms of the MIT license. For a copy, see <https://opensource.org/licenses/MIT>.
=======
// Copyright (c) 2024 Computer Vision Center (CVC) at the Universitat Autonoma de Barcelona (UAB). This work is licensed under the terms of the MIT license. For a copy, see <https://opensource.org/licenses/MIT>.
>>>>>>> f676339c2 (added template for defaultgame.ini)


#include "CarlaSunSky.h"

#include <util/ue-header-guard-begin.h>
#include "Components/SkyLightComponent.h"
#include <util/ue-header-guard-end.h>

void ACarlaSunSky::SetRealTimeCapture(USkyLightComponent* SkyLightComp, bool NewRTC)
{
  SkyLightComp->bRealTimeCapture = NewRTC;
  
}


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

#include <sstream>
#include <vector>
#include <type_traits>

#pragma pack(push, 1)
struct CarlaRecorderLightScene
{

  int LightId;
  float Intensity;
  FLinearColor Color;
  bool bOn;
  uint8 Type;

  void Read(std::istream &InFile);

  void Write(std::ostream &OutFile);
};
#pragma pack(pop)

struct CarlaRecorderLightScenes
{
public:

  void Add(const CarlaRecorderLightScene &InObj);

  void Clear(void);

  void Write(std::ostream &OutFile);

  void Read(std::istream &InFile);

  const std::vector<CarlaRecorderLightScene>& GetLights();

private:

  std::vector<CarlaRecorderLightScene> Lights;
};

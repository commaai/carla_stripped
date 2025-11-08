// Copyright (c) 2025 Computer Vision Center (CVC) at the Universitat Autonoma de Barcelona (UAB).

#pragma once

#include <memory>
#include <vector>

#include "CarlaPublisher.h"

namespace carla {
namespace ros2 {

  struct CarlaSpeedometerSensorImpl;

  class CarlaSpeedometerSensor : public CarlaPublisher {
    public:
      CarlaSpeedometerSensor(const char* ros_name = "", const char* parent = "");
      ~CarlaSpeedometerSensor();
      CarlaSpeedometerSensor(const CarlaSpeedometerSensor&);
      CarlaSpeedometerSensor& operator=(const CarlaSpeedometerSensor&);
      CarlaSpeedometerSensor(CarlaSpeedometerSensor&&);
      CarlaSpeedometerSensor& operator=(CarlaSpeedometerSensor&&);

      bool Init();
      bool Publish();
      void SetData(float data);
      const char* type() const override { return "speedometer"; }

    private:
      std::shared_ptr<CarlaSpeedometerSensorImpl> _impl;
  };
}
}

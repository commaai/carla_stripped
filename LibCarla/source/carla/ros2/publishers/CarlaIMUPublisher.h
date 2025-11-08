// Copyright (c) 2025 Computer Vision Center (CVC) at the Universitat Autonoma de Barcelona (UAB).

#pragma once

#include <memory>

#include "CarlaPublisher.h"

namespace carla {
namespace ros2 {

  struct CarlaIMUPublisherImpl;

  class CarlaIMUPublisher : public CarlaPublisher {
    public:
      CarlaIMUPublisher(const char* ros_name = "", const char* parent = "");
      ~CarlaIMUPublisher();
      CarlaIMUPublisher(const CarlaIMUPublisher&);
      CarlaIMUPublisher& operator=(const CarlaIMUPublisher&);
      CarlaIMUPublisher(CarlaIMUPublisher&&);
      CarlaIMUPublisher& operator=(CarlaIMUPublisher&&);

      bool Init();
      bool Publish();
      void SetData(int32_t seconds, uint32_t nanoseconds, float* accelerometer, float* gyroscope, float compass);
      const char* type() const override { return "inertial measurement unit"; }

    private:
      std::shared_ptr<CarlaIMUPublisherImpl> _impl;
  };
}
}

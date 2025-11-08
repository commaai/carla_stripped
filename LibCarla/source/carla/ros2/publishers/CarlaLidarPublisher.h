// Copyright (c) 2025 Computer Vision Center (CVC) at the Universitat Autonoma de Barcelona (UAB).

#pragma once

#include <memory>
#include <vector>

#include "CarlaPublisher.h"

namespace carla {
namespace ros2 {

  struct CarlaLidarPublisherImpl;

  class CarlaLidarPublisher : public CarlaPublisher {
    public:
      CarlaLidarPublisher(const char* ros_name = "", const char* parent = "");
      ~CarlaLidarPublisher();
      CarlaLidarPublisher(const CarlaLidarPublisher&);
      CarlaLidarPublisher& operator=(const CarlaLidarPublisher&);
      CarlaLidarPublisher(CarlaLidarPublisher&&);
      CarlaLidarPublisher& operator=(CarlaLidarPublisher&&);

      bool Init();
      bool Publish();
      void SetData(int32_t seconds, uint32_t nanoseconds, size_t height, size_t width, float* data);
      const char* type() const override { return "lidar"; }

    private:
      void SetData(int32_t seconds, uint32_t nanoseconds, size_t height, size_t width, std::vector<uint8_t>&& data);

    private:
      std::shared_ptr<CarlaLidarPublisherImpl> _impl;
  };
}
}

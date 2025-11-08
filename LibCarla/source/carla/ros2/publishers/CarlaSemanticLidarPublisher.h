// Copyright (c) 2025 Computer Vision Center (CVC) at the Universitat Autonoma de Barcelona (UAB).

#pragma once

#include <memory>
#include <vector>

#include "CarlaPublisher.h"

namespace carla {
namespace ros2 {

  struct CarlaSemanticLidarPublisherImpl;

  class CarlaSemanticLidarPublisher : public CarlaPublisher {
    public:
      CarlaSemanticLidarPublisher(const char* ros_name = "", const char* parent = "");
      ~CarlaSemanticLidarPublisher();
      CarlaSemanticLidarPublisher(const CarlaSemanticLidarPublisher&);
      CarlaSemanticLidarPublisher& operator=(const CarlaSemanticLidarPublisher&);
      CarlaSemanticLidarPublisher(CarlaSemanticLidarPublisher&&);
      CarlaSemanticLidarPublisher& operator=(CarlaSemanticLidarPublisher&&);

      bool Init();
      bool Publish();
      void SetData(int32_t seconds, uint32_t nanoseconds, size_t elements, size_t height, size_t width, float* data);
      const char* type() const override { return "semantic lidar"; }

    private:
      void SetData(int32_t seconds, uint32_t nanoseconds, size_t height, size_t width, std::vector<uint8_t>&& data);

    private:
      std::shared_ptr<CarlaSemanticLidarPublisherImpl> _impl;
  };
}
}

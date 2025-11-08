// Copyright (c) 2025 Computer Vision Center (CVC) at the Universitat Autonoma de Barcelona (UAB).

#pragma once

#include <memory>
#include <vector>

#include "CarlaPublisher.h"

namespace carla {
namespace ros2 {

  struct CarlaCollisionPublisherImpl;

  class CarlaCollisionPublisher : public CarlaPublisher {
    public:
      CarlaCollisionPublisher(const char* ros_name = "", const char* parent = "");
      ~CarlaCollisionPublisher();
      CarlaCollisionPublisher(const CarlaCollisionPublisher&);
      CarlaCollisionPublisher& operator=(const CarlaCollisionPublisher&);
      CarlaCollisionPublisher(CarlaCollisionPublisher&&);
      CarlaCollisionPublisher& operator=(CarlaCollisionPublisher&&);

      bool Init();
      bool Publish();
      void SetData(int32_t seconds, uint32_t nanoseconds, uint32_t actor_id, float x, float y, float z);
      const char* type() const override { return "collision"; }

    private:
      void SetData(int32_t seconds, uint32_t nanoseconds, uint32_t actor_id, std::vector<float>&& data);

    private:
      std::shared_ptr<CarlaCollisionPublisherImpl> _impl;
  };
}
}

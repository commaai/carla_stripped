// Copyright (c) 2025 Computer Vision Center (CVC) at the Universitat Autonoma de Barcelona (UAB).

#pragma once

#include <memory>
#include "CarlaPublisher.h"

namespace carla {
namespace ros2 {

  struct BasicPublisherImpl;

  class BasicPublisher : public CarlaPublisher {
    public:
      BasicPublisher(const char* ros_name = "", const char* parent = "");
      ~BasicPublisher();
      BasicPublisher(const BasicPublisher&);
      BasicPublisher& operator=(const BasicPublisher&);
      BasicPublisher(BasicPublisher&&);
      BasicPublisher& operator=(BasicPublisher&&);

      bool Init();
      bool Publish();
      void SetData(const char* msg);
      const char* type() const override { return "basic_publisher"; }

    private:
      std::shared_ptr<BasicPublisherImpl> _impl;
  };
}
}

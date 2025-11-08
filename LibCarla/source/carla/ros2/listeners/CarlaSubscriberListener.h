// Copyright (c) 2025 Computer Vision Center (CVC) at the Universitat Autonoma de Barcelona (UAB).

#pragma once

#include <memory>

namespace carla {
namespace ros2 {

  class CarlaSubscriberListenerImpl;
  class CarlaEgoVehicleControlSubscriber;

  class CarlaSubscriberListener {
    public:
      CarlaSubscriberListener(CarlaEgoVehicleControlSubscriber* owner);
      ~CarlaSubscriberListener();
      CarlaSubscriberListener(const CarlaSubscriberListener&) = delete;
      CarlaSubscriberListener& operator=(const CarlaSubscriberListener&) = delete;
      CarlaSubscriberListener(CarlaSubscriberListener&&) = delete;
      CarlaSubscriberListener& operator=(CarlaSubscriberListener&&) = delete;

      void SetOwner(CarlaEgoVehicleControlSubscriber* owner);

      std::unique_ptr<CarlaSubscriberListenerImpl> _impl;
  };
}
}

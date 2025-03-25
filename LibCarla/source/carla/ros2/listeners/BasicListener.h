<<<<<<< HEAD
// Copyright (c) 2025 Computer Vision Center (CVC) at the Universitat Autonoma de Barcelona (UAB).
=======
// Copyright (c) 2024 Computer Vision Center (CVC) at the Universitat Autonoma de Barcelona (UAB).
>>>>>>> f676339c2 (added template for defaultgame.ini)
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include <memory>

namespace carla {
namespace ros2 {

  class BasicListenerImpl;
  class BasicSubscriber;

  class BasicListener {
    public:
      BasicListener(BasicSubscriber* owner);
      ~BasicListener();
      BasicListener(const BasicListener&) = delete;
      BasicListener& operator=(const BasicListener&) = delete;
      BasicListener(BasicListener&&) = delete;
      BasicListener& operator=(BasicListener&&) = delete;

      void SetOwner(BasicSubscriber* owner);

      std::unique_ptr<BasicListenerImpl> _impl;
  };
}
}

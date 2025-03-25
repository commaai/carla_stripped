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

#include "carla/FileSystem.h"

<<<<<<< HEAD
#include <filesystem>
#include <string_view>
#include <string>
=======
#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>
>>>>>>> f676339c2 (added template for defaultgame.ini)

namespace carla {
namespace client {

  class FileTransfer {

  public:

    FileTransfer() = delete;

<<<<<<< HEAD
    static bool SetFilesBaseFolder(std::string_view path);

    static std::string GetFilesBaseFolder();

    static bool FileExists(std::string_view file);

    static bool WriteFile(std::string_view path, std::vector<uint8_t> content);

    static std::vector<uint8_t> ReadFile(std::string_view path);
=======
    static bool SetFilesBaseFolder(const std::string &path);

    static const std::string& GetFilesBaseFolder();

    static bool FileExists(std::string file);

    static bool WriteFile(std::string path, std::vector<uint8_t> content);

    static std::vector<uint8_t> ReadFile(std::string path);

  private:

    static std::string _filesBaseFolder;
>>>>>>> f676339c2 (added template for defaultgame.ini)

  };

} // namespace client
} // namespace carla

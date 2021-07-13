#pragma once

#include <fmt/color.h>

#include <map>
#include <string>

#include "abstract_video_capture.hpp"
#include "types/device/camera_types.hpp"
#include "types/module/roi_types.hpp"

namespace wv::device {

using namespace wv::types;

class Camera : VideoCapture {
 public:
  Camera(std::string _camera_config_path);

  ~Camera() = default;

  Camera_Data getCameraData(const RoI_Data& _roi_data);

 protected:
  std::map<std::string, std::string> identifier{
    {"green", fmt::format(fg(fmt::color::green) | fmt::emphasis::bold, "camera")},
    {"red", fmt::format(fg(fmt::color::red) | fmt::emphasis::bold, "camera")},
  };

 private:
  Camera_Config camera_config_;
  Camera_Data   camera_data_;
};

}  // namespace wv::device

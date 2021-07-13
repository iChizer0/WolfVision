#include "camera.hpp"

namespace wv::device {

Camera::Camera(std::string _camera_config_path) {
  fmt::print("[{}] Locading config from file: {}\n", identifier["green"], _camera_config_path);
}

Camera_Data Camera::getCameraData(const RoI_Data& _roi_data) {
  RoI_Data roi_data = _roi_data;
  roi_data          = RoI_Data();

  return camera_data_;
}

}  // namespace wv::device

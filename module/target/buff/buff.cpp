#include "buff.hpp"

namespace wv::module {

Buff::Buff(std::string _buff_config_path) {
  fmt::print("[{}] Locading config from file: {}\n", identifier["green"], _buff_config_path);
}

Target_Data Buff::getTargetData(const Serial_Data& _serial_data, const Camera_Data& _camera_data) {
  Serial_Data serial_data = _serial_data;
  serial_data             = Serial_Data();

  Camera_Data camera_data = _camera_data;
  camera_data             = Camera_Data();

  return Target_Data();
}

}  // namespace wv::module

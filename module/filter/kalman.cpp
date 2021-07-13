#include "kalman.hpp"

namespace wv::module {

Kalman::Kalman(std::string _kalman_config_path) {
  fmt::print("[{}] Locading config from file: {}\n", identifier["green"], _kalman_config_path);
}

Filter_Data Kalman::getFilterData(const Serial_Data& _serial_data, const RingBuffer<Locate_Data>& _locate_data_rb) {
  Serial_Data serial_data                = _serial_data;
  serial_data                            = Serial_Data();
  RingBuffer<Locate_Data> locate_data_rb = _locate_data_rb;
  locate_data_rb                         = _locate_data_rb;

  return Filter_Data();
}

}  // namespace wv::module

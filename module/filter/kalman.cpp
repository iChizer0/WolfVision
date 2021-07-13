#include "kalman.hpp"

namespace wv::module {

Kalman::Kalman(std::string _kalman_config_path) {
  fmt::print("[{}] Locading config from file: {}\n", identifier["green"], _kalman_config_path);
}

Kalman_Data Kalman::getKalmanData(const Serial_Data& _serial_data, const RingBuffer<PNP_Data>& _pnp_data_ring_buffer) {
  Serial_Data serial_data                   = _serial_data;
  serial_data                               = Serial_Data();
  RingBuffer<PNP_Data> pnp_data_ring_buffer = _pnp_data_ring_buffer;
  pnp_data_ring_buffer                      = _pnp_data_ring_buffer;

  return Kalman_Data();
}

}  // namespace wv::module
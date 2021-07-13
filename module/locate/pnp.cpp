#include "pnp.hpp"

namespace wv::module {

PNP::PNP(std::string _pnp_config_path) {
  fmt::print("[{}] Locading config from file: {}\n", identifier["green"], _pnp_config_path);
}

PNP_Data PNP::getPNPData(const Serial_Data& _serial_data, const Target_Data& _target_data) {
  Serial_Data serial_data = _serial_data;
  serial_data             = Serial_Data();
  Target_Data target_data = _target_data;
  target_data             = Target_Data();

  return PNP_Data();
}

}  // namespace wv::module

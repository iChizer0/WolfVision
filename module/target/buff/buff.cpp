#include "buff.hpp"

#include "module/target/abstract/armor.hpp"
#include "module/target/abstract/color_literal.hpp"
#include "module/target/abstract/pnp.hpp"
#include "module/target/abstract/pre_processing.hpp"

namespace wv::module::buff {

Buff::Buff(std::string _buff_config_path) {
  fmt::print("[{}] Locading config from file: {}\n", identifier["green"], _buff_config_path);
}

Target_Data Buff::getTargetData(const Serial_Data&             _serial_data [[maybe_unused]],
                                const RingBuffer<Camera_Data>& _camera_data_buffer [[maybe_unused]],
                                const RingBuffer<Target_Data>& _target_data_buffer [[maybe_unused]]) {
  return Target_Data();
}

}  // namespace wv::module::buff

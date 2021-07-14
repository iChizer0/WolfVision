#include "compensate.hpp"

#include "abstract/gravity.hpp"
#include "abstract/velocity.hpp"

namespace wv::module {

Compensate::Compensate(std::string _compensate_config_path) {
  fmt::print("[{}] Locading config from file: {}\n", identifier["green"], _compensate_config_path);
}

Target_Data Compensate::getTargetData(const Serial_Data&             _serial_data [[maybe_unused]],
                                      const RingBuffer<Target_Data>& _target_data_buffer) {
  RingBuffer<Target_Data>& _target_data_buffer_ref{const_cast<RingBuffer<Target_Data>&>(_target_data_buffer)};
  Target_Data              target_data;

  target_data = gravity::getNewTargetData(_target_data_buffer_ref.current());
  target_data = velocity::getNewTargetData(target_data);

  return target_data;
}

}  // namespace wv::module

#include "predict.hpp"

#include "abstract/kalman_filter.hpp"

namespace wv::module {

Predict::Predict(std::string _predict_config_path) {
  fmt::print("[{}] Locading config from file: {}\n", identifier["green"], _predict_config_path);
}

Target_Data Predict::getTargetData(const Serial_Data&             _serial_data [[maybe_unused]],
                                   const RingBuffer<Target_Data>& _target_data_buffer) {
  RingBuffer<Target_Data>& _target_data_buffer_ref{const_cast<RingBuffer<Target_Data>&>(_target_data_buffer)};
  Target_Data              target_data{kalman_filter::getNewTargetData(_target_data_buffer_ref.current())};

  return target_data;
}

}  // namespace wv::module

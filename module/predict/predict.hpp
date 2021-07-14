#pragma once

#include <fmt/color.h>

#include <map>
#include <string>

#include "types/basic/ring_buffer_types.hpp"
#include "types/device/serial_types.hpp"
#include "types/module/predict_types.hpp"
#include "types/module/target_types.hpp"

namespace wv::module {

using namespace wv::types;

class Predict {
 public:
  Predict(std::string _predict_config_path);

  ~Predict() = default;

  Target_Data getTargetData(const Serial_Data& _serial_data, const RingBuffer<Target_Data>& _target_data_buffer);

 protected:
  std::map<std::string, std::string> identifier{
    {"green", fmt::format(fg(fmt::color::green) | fmt::emphasis::bold, "predict")},
    {"red", fmt::format(fg(fmt::color::red) | fmt::emphasis::bold, "predict")},
  };

 private:
  Predict_Config Predict_config_;
};

}  // namespace wv::module

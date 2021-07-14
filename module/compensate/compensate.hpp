#pragma once

#include <fmt/color.h>

#include <map>
#include <string>

#include "types/basic/ring_buffer_types.hpp"
#include "types/device/serial_types.hpp"
#include "types/module/compensate_types.hpp"
#include "types/module/target_types.hpp"

namespace wv::module {

using namespace wv::types;

class Compensate {
 public:
  Compensate(std::string _compensate_config_path);

  ~Compensate() = default;

  Target_Data getTargetData(const Serial_Data& _serial_data, const RingBuffer<Target_Data>& _target_data_buffer);

 protected:
  std::map<std::string, std::string> identifier{
    {"green", fmt::format(fg(fmt::color::green) | fmt::emphasis::bold, "compensate")},
    {"red", fmt::format(fg(fmt::color::red) | fmt::emphasis::bold, "compensate")},
  };

 private:
  Compensate_Config compensate_config_;
};

}  // namespace wv::module

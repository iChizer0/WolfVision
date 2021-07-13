#pragma once

#include <fmt/color.h>

#include <map>
#include <string>

#include "module/target/abstract/armor.hpp"
#include "module/target/abstract/color_literal.hpp"
#include "module/target/abstract/pre_processing.hpp"
#include "types/device/camera_types.hpp"
#include "types/device/serial_types.hpp"
#include "types/module/target_types.hpp"

namespace wv::module {

using namespace wv::types;

class Buff {
 public:
  Buff(std::string _buff_config_path);

  ~Buff() = default;

   Target_Data getTargetData(const Serial_Data& _serial_data, const Camera_Data& _camera_data);

 protected:
  std::map<std::string, std::string> identifier{
    {"green", fmt::format(fg(fmt::color::green) | fmt::emphasis::bold, "buff")},
    {"red", fmt::format(fg(fmt::color::red) | fmt::emphasis::bold, "buff")},
  };

 private:
  Buff_Config buff_config_;
};

}  // namespace wv::module

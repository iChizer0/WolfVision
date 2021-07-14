#pragma once

#include <fmt/color.h>

#include <map>
#include <string>

#include "types/basic/ring_buffer_types.hpp"
#include "types/device/camera_types.hpp"
#include "types/device/serial_types.hpp"
#include "types/module/target_types.hpp"

namespace wv::module::buff {

using namespace wv::types;

class Buff {
 public:
  Buff(std::string _buff_config_path);

  ~Buff() = default;

  Target_Data getTargetData(const Serial_Data&             _serial_data,
                            const RingBuffer<Camera_Data>& _camera_data_buffer,
                            const RingBuffer<Target_Data>& _target_data_buffer);

 protected:
  std::map<std::string, std::string> identifier{
    {"green", fmt::format(fg(fmt::color::green) | fmt::emphasis::bold, "buff")},
    {"red", fmt::format(fg(fmt::color::red) | fmt::emphasis::bold, "buff")},
  };

 private:
  Buff_Config buff_config_;
  Armor_Data  armor_data_;
  PNP_Data    pnp_data_;
};

}  // namespace wv::module::buff

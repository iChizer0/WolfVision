#pragma once

#include "types/device/serial_types.hpp"
#include "types/module/target_types.hpp"

namespace wv::utils {

using namespace wv::types;

Serial_Data Target2Serial(const Target_Data& _target_data) {
  Target_Data target_data = _target_data;
  target_data             = Target_Data();

  return Serial_Data();
}

}  // namespace wv::utils

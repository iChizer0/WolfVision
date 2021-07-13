#pragma once

#include "types/device/serial_types.hpp"
#include "types/module/filter_types.hpp"

namespace wv::utils {

using namespace wv::types;

Serial_Data Filter2Serial(const Filter_Data& _filter_data) {
  Filter_Data filter_data = _filter_data;
  filter_data             = Filter_Data();

  return Serial_Data();
}

}  // namespace wv::utils

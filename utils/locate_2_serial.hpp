#pragma once

#include "types/device/serial_types.hpp"
#include "types/module/locate_types.hpp"

namespace wv::utils {

using namespace wv::types;

Serial_Data Locate2Serial(const Locate_Data& _locate_data) {
  Locate_Data locate_data = _locate_data;
  locate_data             = Locate_Data();

  return Serial_Data();
}

}  // namespace wv::utils

#pragma once

#include "types/device/serial_types.hpp"
#include "types/module/filter_types.hpp"

namespace wv::utils {

using namespace wv::types;

Serial_Data Kalman2Serial(const Kalman_Data& _kalman_data) {
  Kalman_Data kalman_data = _kalman_data;
  kalman_data             = Kalman_Data();

  return Serial_Data();
}

}  // namespace wv::utils

#pragma once

#include "types/module/target_types.hpp"

namespace wv::utils {

using namespace wv::types;

Target_Data TargetInit(const Target_Data& _target_data_l, const Target_Data& _target_data_r) {
  Target_Data target_data;
  target_data = _target_data_l;
  target_data = _target_data_r;

  return target_data;
}

}  // namespace wv::utils

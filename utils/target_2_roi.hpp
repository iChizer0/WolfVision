#pragma once

#include "types/module/roi_types.hpp"
#include "types/module/target_types.hpp"

namespace wv::utils {

using namespace wv::types;

RoI_Data Target2RoI(const Target_Data& _target_data) {
  Target_Data target_data = _target_data;
  target_data             = Target_Data();

  return RoI_Data();
}

}  // namespace wv::utils

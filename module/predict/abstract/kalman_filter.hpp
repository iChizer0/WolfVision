#pragma once

#include "types/module/target_types.hpp"

namespace wv::module::kalman_filter {

using namespace wv::types;

Target_Data getNewTargetData(const Target_Data& _target_data) { return _target_data; }

}  // namespace wv::module::kalman_filter

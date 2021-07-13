#pragma once

namespace wv::types {

struct Kalman_Config {
  Kalman_Config() = default;
};

struct Filter_Config : Kalman_Config {
  Filter_Config() = default;
};

struct Kalman_Data {
  Kalman_Data() = default;
};

struct Filter_Data : Kalman_Data {
  Filter_Data() = default;
};

}  // namespace wv::types

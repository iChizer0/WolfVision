#pragma once

namespace wv::types {

struct PNP_Config {
  PNP_Config() = default;
};

struct Locate_Config : PNP_Config {
  Locate_Config() = default;
};

struct PNP_Data {
  PNP_Data() = default;
};

struct Locate_Data : PNP_Data {
  Locate_Data() = default;
};

}  // namespace wv::types

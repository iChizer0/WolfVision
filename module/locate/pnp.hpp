#pragma once

#include <fmt/color.h>

#include <map>
#include <string>

#include "types/device/serial_types.hpp"
#include "types/module/locate_types.hpp"
#include "types/module/target_types.hpp"

namespace wv::module {

using namespace wv::types;

class PNP {
 public:
  PNP(std::string _pnp_config_path);

  ~PNP() = default;

  PNP_Data getPNPData(const Serial_Data& _serial_data, const Target_Data& _target_data);

 protected:
  std::map<std::string, std::string> identifier{
    {"green", fmt::format(fg(fmt::color::green) | fmt::emphasis::bold, "pnp")},
    {"red", fmt::format(fg(fmt::color::red) | fmt::emphasis::bold, "pnp")},
  };

 private:
  PNP_Config pnp_config_;
};

}  // namespace wv::module

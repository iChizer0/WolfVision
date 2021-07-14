#pragma once

#include <fmt/color.h>

#include <map>
#include <string>

#include "types/module/roi_types.hpp"

namespace wv::module {

using namespace wv::types;

class RoI {
 public:
  RoI(std::string _roi_config_path);

  ~RoI() = default;

  RoI_Data getRoIData();

 protected:
  std::map<std::string, std::string> identifier{
    {"green", fmt::format(fg(fmt::color::green) | fmt::emphasis::bold, "roi")},
    {"red", fmt::format(fg(fmt::color::red) | fmt::emphasis::bold, "roi")},
  };

 private:
  RoI_Config roi_config_;
};

}  // namespace wv::module

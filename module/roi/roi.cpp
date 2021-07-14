#include "roi.hpp"

namespace wv::module {

RoI::RoI(std::string _roi_config_path) {
  fmt::print("[{}] Locading config from file: {}\n", identifier["green"], _roi_config_path);
}

 RoI_Data RoI::getRoIData() { return RoI_Data(); }

}  // namespace wv::module

#pragma once

#include <fmt/color.h>

#include <map>
#include <string>

#include "types/device/serial_types.hpp"
#include "types/module/filter_types.hpp"
#include "types/module/locate_types.hpp"
#include "types/types.hpp"

namespace wv::module {

using namespace wv::types;

class Kalman {
 public:
  Kalman(std::string _kalman_config_path);

  ~Kalman() = default;

  Kalman_Data getKalmanData(const Serial_Data& _serial_data, const RingBuffer<PNP_Data>& _pnp_data_ring_buffer);

 protected:
  std::map<std::string, std::string> identifier{
    {"green", fmt::format(fg(fmt::color::green) | fmt::emphasis::bold, "kalman")},
    {"red", fmt::format(fg(fmt::color::red) | fmt::emphasis::bold, "kalman")},
  };

 private:
  Kalman_Config kalman_config_;
};

}  // namespace wv::module

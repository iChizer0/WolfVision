#pragma once

#include <fmt/color.h>

#include <map>
#include <string>

#include "abstract_serial.hpp"
#include "types/device/serial_types.hpp"

namespace wv::device {

using namespace wv::types;

class SerialPort : Serial {
 public:
  SerialPort(std::string _serial_config_path);

  ~SerialPort() = default;

  Serial_Data getSerialData();

  bool sendSerialData(const Serial_Data& _serial_data);

 protected:
  std::map<std::string, std::string> identifier{
    {"green", fmt::format(fg(fmt::color::green) | fmt::emphasis::bold, "serial_port")},
    {"red", fmt::format(fg(fmt::color::red) | fmt::emphasis::bold, "serial_port")},
  };

 private:
  Serial_Config serial_config_;
  Serial_Data   serial_data_;
};

}  // namespace wv::device

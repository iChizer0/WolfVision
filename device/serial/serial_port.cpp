#include "serial_port.hpp"

namespace wv::device {

SerialPort::SerialPort(std::string _serial_config_path) {
  fmt::print("[{}] Locading config from file: {}\n", identifier["green"], _serial_config_path);
}

Serial_Data SerialPort::getSerialData() { return serial_data_; }

bool SerialPort::sendSerialData(const Serial_Data& _serial_data) {
  Serial_Data serial_data_to_send = _serial_data;
  serial_data_to_send             = Serial_Data();

  send(std::string());

  return true;
}

}  // namespace wv::device

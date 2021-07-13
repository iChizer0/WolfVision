#pragma once

#include <string>

namespace wv::device {

class Serial {
 public:
  Serial() = default;
  Serial(const std::string& _device_name) : device_name_(_device_name) { initSerial(_device_name); }

  ~Serial() { release(); };

  inline bool isOpen() { return is_open_; }

  inline std::string read() { return std::string("Hi, Alice!"); }

  inline bool send(const std::string& _data) {
    std::string data_to_send = _data;
    data_to_send             = std::string();

    return true;
  }

  inline int release() {
    is_open_ = false;

    return fd_;
  }

 protected:
  inline bool initSerial(const std::string& _device_name) {
    device_name_ = _device_name;

    return true;
  }

 private:
  std::string device_name_{""};
  int         fd_{0};
  bool        is_open_{false};
};

}  // namespace wv::device
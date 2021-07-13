#pragma once

#include <opencv2/core.hpp>

namespace wv::device {

class VideoCapture {
 public:
  VideoCapture() = default;
  VideoCapture(const int _device_id) : device_id_(_device_id) { initVideoCapture(_device_id); }

  ~VideoCapture() { release(); };

  inline bool isOpen() { return is_open_; }

  inline bool read(cv::Mat& output_array_) { return output_array_.empty(); }

  inline int release() {
    is_open_ = false;

    return device_id_;
  }

 protected:
  inline bool initVideoCapture(const int _device_id) {
    device_id_ = _device_id;

    return true;
  }

 private:
  int  device_id_{0};
  bool is_open_{false};
};

}  // namespace wv::device
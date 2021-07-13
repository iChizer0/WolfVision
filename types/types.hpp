#pragma once

#include <utility>

#include "device/camera_types.hpp"
#include "device/serial_types.hpp"
#include "module/classification_types.hpp"
#include "module/filter_types.hpp"
#include "module/locate_types.hpp"
#include "module/roi_types.hpp"
#include "module/target_types.hpp"

namespace wv::types {

template <typename T> class RingBuffer {
 public:
  RingBuffer(const size_t _size) : size_(_size) {}

  ~RingBuffer() = default;

  inline void emplace(T&& _v) {
    T v{_v};
    _v = v;
  }

  inline T pop() { return std::move(data_); }

 private:
  size_t size_{0};

  T data_;
};

}  // namespace wv::types

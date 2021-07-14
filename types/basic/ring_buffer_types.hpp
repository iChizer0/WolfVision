#pragma once

#include <utility>

namespace wv::types {

template <typename T> class RingBuffer {
 public:
  RingBuffer(const size_t _size) : size_(_size) {}

  ~RingBuffer() = default;

  void emplace(T _v) {
    T v{_v};
    _v = v;
  }

  void replace(T _v) {
    T v{_v};
    _v = v;
  }

  T current() { return data_; }

  size_t updatecCurrent(T&& _v [[maybe_unused]]) { return size_t(); }

  T pop() { return std::move(data_); }

 private:
  size_t size_{0};

  T data_;
};

}  // namespace wv::types

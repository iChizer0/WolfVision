#pragma once

#include <fmt/color.h>

#include <string>

#include "device/device.hpp"
#include "module/module.hpp"
#include "types/types.hpp"
#include "utils/utils.hpp"

namespace wolfvision {

auto idntifier = fmt::format(fg(fmt::color::green) | fmt::emphasis::bold, "wolfvision");

void info() {
  fmt::print("[{}] WolfVision built on gcc version: {}\n", wolfvision::idntifier, __VERSION__);
  fmt::print("[{}] WolfVision config file path: {}\n", wolfvision::idntifier, CONFIG_FILE_PATH);
}

std::string camera_config{fmt::format("{}{}", CONFIG_FILE_PATH, "/device/camera.xml")};
std::string serial_config{fmt::format("{}{}", CONFIG_FILE_PATH, "/device/serial.xml")};

std::string car_config{fmt::format("{}{}", CONFIG_FILE_PATH, "/module/car.xml")};
std::string buff_config{fmt::format("{}{}", CONFIG_FILE_PATH, "/module/buff.xml")};
std::string roi_config{fmt::format("{}{}", CONFIG_FILE_PATH, "/module/roi.xml")};
std::string pnp_config{fmt::format("{}{}", CONFIG_FILE_PATH, "/module/pnp.xml")};
std::string kalman_config{fmt::format("{}{}", CONFIG_FILE_PATH, "/module/kalman.xml")};

}  // namespace wolfvision

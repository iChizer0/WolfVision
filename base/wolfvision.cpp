#include "wolfvision.hpp"

int main() {
  wolfvision::info();

  wv::device::Camera     camera(wolfvision::camera_config);
  wv::device::SerialPort serial_port(wolfvision::serial_config);

  wv::module::Car    car(wolfvision::car_config);
  wv::module::Buff   buff(wolfvision::buff_config);
  wv::module::RoI    roi(wolfvision::roi_config);
  wv::module::PNP    pnp(wolfvision::pnp_config);
  wv::module::Kalman kalman(wolfvision::kalman_config);

  wv::types::RoI_Data                        roi_data;
  wv::types::RingBuffer<wv::types::Locate_Data> locate_data_buffer(5);

  while (1) {
    wv::types::Serial_Data serial_data{serial_port.getSerialData()};

    wv::types::Camera_Data camera_data{camera.getCameraData(roi_data)};

    wv::types::Target_Data target_data{wv::utils::TargetInit(buff.getTargetData(serial_data, camera_data),
                                                             car.getTargetData(serial_data, camera_data))};

    roi_data = wv::utils::Target2RoI(target_data);

    locate_data_buffer.emplace(pnp.getLocateData(serial_data, target_data));

    wv::types::Filter_Data filter_data{kalman.getFilterData(serial_data, locate_data_buffer)};

    serial_port.sendSerialData(wv::utils::Filter2Serial(filter_data));
  };

  return 0;
}

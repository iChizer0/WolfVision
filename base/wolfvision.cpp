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
  wv::types::RingBuffer<wv::types::PNP_Data> pnp_data_ring_buffer(5);

  while (1) {
    wv::types::Serial_Data serial_data{serial_port.getSerialData()};

    wv::types::Camera_Data camera_data{camera.getCameraData(roi_data)};

    wv::types::Target_Data target_data{wv::utils::TargetDataInit(buff.getTargetData(serial_data, camera_data),
                                                                 car.getTargetData(serial_data, camera_data))};

    roi_data = wv::utils::Target2RoI(target_data);

    pnp_data_ring_buffer.emplace(pnp.getPNPData(serial_data, target_data));

    wv::types::Kalman_Data kalman_data{kalman.getKalmanData(serial_data, pnp_data_ring_buffer)};

    serial_port.sendSerialData(wv::utils::Kalman2Serial(kalman_data));
  };

  return 0;
}

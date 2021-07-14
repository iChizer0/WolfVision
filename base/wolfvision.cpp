#include "wolfvision.hpp"

int main() {
  wolfvision::info();

  wv::device::Camera     camera(wolfvision::camera_config);
  wv::device::SerialPort serial_port(wolfvision::serial_config);

  wv::module::Car        car(wolfvision::car_config);
  wv::module::Buff       buff(wolfvision::buff_config);
  wv::module::RoI        roi(wolfvision::roi_config);
  wv::module::Predict    predict(wolfvision::predict_config);
  wv::module::Compensate compensate(wolfvision::compensate_config);

  wv::types::RoI_Data                           roi_data;
  wv::types::RingBuffer<wv::types::Camera_Data> camera_data_buffer(10);
  wv::types::RingBuffer<wv::types::Target_Data> target_data_buffer(10);

  while (1) {
    wv::types::Serial_Data serial_data{serial_port.getSerialData()};

    camera_data_buffer.emplace(camera.getCameraData(roi_data));

    wv::types::Target_Data target_data{
      wv::utils::TargetInit(buff.getTargetData(serial_data, camera_data_buffer, target_data_buffer),
                            car.getTargetData(serial_data, camera_data_buffer, target_data_buffer))};

    target_data_buffer.emplace(target_data);

    wv::types::Target_Data target_data_fixed;

    target_data_fixed = predict.getTargetData(serial_data, target_data_buffer);
    target_data_fixed = compensate.getTargetData(serial_data, target_data_buffer);
    roi_data          = wv::utils::Target2RoI(target_data_fixed);

    serial_port.sendSerialData(wv::utils::Target2Serial(target_data_fixed));
  }

  return 0;
}

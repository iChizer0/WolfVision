# Create project
cmake_minimum_required(VERSION 3.16.0)
project(WolfVision VERSION 2021.7.9 LANGUAGES CXX)

# Check system platform
if(NOT CMAKE_SYSTEM_NAME STREQUAL Linux)
    message(FATAL_ERROR "Not supported platform: ${CMAKE_SYSTEM_NAME}")
endif()

# Specialize CMake build flags for different build types
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-deprecated")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Use standard c++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add DEBUG marco to define if debug configured
add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>")

# Don't build test by default
set(BUILD_TEST False)

# Prefer posix threads
find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG True)
set(CMAKE_THREAD_LIBS_INIT "-lpthread")

# Find and add opencv as required
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
link_libraries(${OpenCV_LIBS})

# Add fmtlib directory
add_subdirectory(3rdparty/fmt)
# Add fmtlib include to EXTRA_INCLUDES
list(APPEND EXTRA_INCLUDES 3rdparty/fmt/include)

# Add mindvision-sdk directory and include path for target
add_library(MVSDK SHARED IMPORTED)
get_filename_component(MVSDK_PATH 3rdparty/mindvision/linux REALPATH)
# Check system architecture for mindvision-sdk library
execute_process(COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE ARCHITECTURE)
if(${ARCHITECTURE} STREQUAL x86_64)
    set(MIMDVISION_SDK_LIBRARY ${MVSDK_PATH}/lib/x64/libMVSDK.so)
elseif(${ARCHITECTURE} STREQUAL aarch64)
    set(MIMDVISION_SDK_LIBRARY ${MVSDK_PATH}/lib/arm64/libMVSDK.so)
else()
    message(FATAL_ERROR "Not supported architecture for MVSDK: ${ARCHITECTURE}")
endif()
set_property(TARGET MVSDK PROPERTY IMPORTED_LOCATION ${MIMDVISION_SDK_LIBRARY})
# Add mindvision include path
list(APPEND EXTRA_INCLUDES 3rdparty/mindvision/linux/include)
# Add mindvision lib to build target
list(APPEND EXTRA_LIBS MVSDK)

# Add project source includes
list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR})
list(APPEND EXTRA_INCLUDES base)
list(APPEND EXTRA_INCLUDES devices)
list(APPEND EXTRA_INCLUDES devices/camera)
list(APPEND EXTRA_INCLUDES devices/can_bus)
list(APPEND EXTRA_INCLUDES devices/serial)
list(APPEND EXTRA_INCLUDES module)
list(APPEND EXTRA_INCLUDES module/classification)
list(APPEND EXTRA_INCLUDES module/compensate)
list(APPEND EXTRA_INCLUDES module/predict)
list(APPEND EXTRA_INCLUDES module/roi)
list(APPEND EXTRA_INCLUDES module/target)
list(APPEND EXTRA_INCLUDES module/target/armor)
list(APPEND EXTRA_INCLUDES module/target/buff)
list(APPEND EXTRA_INCLUDES types)
list(APPEND EXTRA_INCLUDES utils)

# Add project source libs
add_library(wv-camera SHARED device/camera/camera.cpp)
list(APPEND WV_EXTRA_LIBS wv-camera)
add_library(wv-can-bus SHARED device/can_bus/can_bus.cpp)
list(APPEND WV_EXTRA_LIBS wv-can-bus)
add_library(wv-serial-port SHARED device/serial/serial_port.cpp)
list(APPEND WV_EXTRA_LIBS wv-serial-port)

add_library(wv-classification SHARED module/classification/classification.cpp)
list(APPEND WV_EXTRA_LIBS wv-classification)
add_library(wv-compensate SHARED module/compensate/compensate.cpp)
list(APPEND WV_EXTRA_LIBS wv-compensate)
add_library(wv-predict SHARED module/predict/predict.cpp)
list(APPEND WV_EXTRA_LIBS wv-predict)
add_library(wv-roi SHARED module/roi/roi.cpp)
list(APPEND WV_EXTRA_LIBS wv-roi)
add_library(wv-target-car SHARED module/target/car/car.cpp)
list(APPEND WV_EXTRA_LIBS wv-target-car)
add_library(wv-target-buff SHARED module/target/buff/buff.cpp)
list(APPEND WV_EXTRA_LIBS wv-target-buff)

# Add EXTRA_INCLUDES to project includes
include_directories(${EXTRA_INCLUDES})

# Add base/wolfvision to executable
add_executable(WolfVision base/wolfvision.cpp)

# Add shared library link to WolfVision
target_link_libraries(WolfVision
    PUBLIC
    Threads::Threads
    fmt::fmt
    ${OpenCV_LIBS}
    ${EXTRA_LIBS}

    PRIVATE
    ${WV_EXTRA_LIBS}
)

# Set WolfVision compile cxx_std features
target_compile_features(WolfVision PUBLIC cxx_std_${CMAKE_CXX_STANDARD})

# Set WolfVision linking time optimization to true
set_target_properties(WolfVision PROPERTIES INTERPROCEDURAL_OPTIMIZATION True)

# Set built binary to ~/bin
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")

# Set built library to ~/lib
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

# Set configs folder absolute path
set(CONFIG_FILE_PATH ${PROJECT_SOURCE_DIR}/configs)
target_compile_definitions(WolfVision PRIVATE "CONFIG_FILE_PATH=\"${CONFIG_FILE_PATH}\"")

# Add test_camera directory
if(BUILD_TEST)
    add_subdirectory(test/test_camera)
endif()

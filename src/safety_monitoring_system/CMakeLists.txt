cmake_minimum_required(VERSION 3.8)
project(safety_monitoring_system)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(chemistry_msgs REQUIRED)

# TODO: Day별 구현 예정
add_executable(safety_monitoring_system_node src/safety_monitoring_system_node.cpp)
ament_target_dependencies(safety_monitoring_system_node rclcpp std_msgs chemistry_msgs)

install(TARGETS safety_monitoring_system_node DESTINATION lib/${PROJECT_NAME})

ament_package()

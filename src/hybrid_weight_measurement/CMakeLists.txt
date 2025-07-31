cmake_minimum_required(VERSION 3.8)
project(hybrid_weight_measurement)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(chemistry_msgs REQUIRED)

# Day 2 구현 예정: 센서 융합 노드
add_executable(weight_fusion_node src/weight_fusion_node.cpp)
ament_target_dependencies(weight_fusion_node rclcpp std_msgs chemistry_msgs)

install(TARGETS weight_fusion_node DESTINATION lib/${PROJECT_NAME})

ament_package()

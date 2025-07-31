cmake_minimum_required(VERSION 3.8)
project(chemistry_experiment_manager)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(chemistry_msgs REQUIRED)

# TODO: Day별 구현 예정
add_executable(chemistry_experiment_manager_node src/chemistry_experiment_manager_node.cpp)
ament_target_dependencies(chemistry_experiment_manager_node rclcpp std_msgs chemistry_msgs)

install(TARGETS chemistry_experiment_manager_node DESTINATION lib/${PROJECT_NAME})

ament_package()

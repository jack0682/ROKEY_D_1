cmake_minimum_required(VERSION 3.8)
project(sugar_water_experiment)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
# find_package(doosan_m0609_msgs REQUIRED)

# Include directories
include_directories(include)

# Sugar Water Experimenter Node
add_executable(sugar_water_experimenter_node 
  src/sugar_water_experimenter_node.cpp
  src/pose_controller.cpp
  src/weight_monitor.cpp
  src/safety_monitor.cpp
)

ament_target_dependencies(sugar_water_experimenter_node
  rclcpp
  std_msgs
  geometry_msgs
  sensor_msgs
)

# Simple Sequential Controller
add_executable(simple_sequence_controller
  src/simple_sequence_controller.cpp
)

ament_target_dependencies(simple_sequence_controller
  rclcpp
  std_msgs
  geometry_msgs
  sensor_msgs
)

# Install targets
install(TARGETS
  sugar_water_experimenter_node
  simple_sequence_controller
  DESTINATION lib/${PROJECT_N}
)

# Install launch files
install(DIRECTORY launch
  DESTINATION share/${PROJECT_N}/
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

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

# DRFL 관련 의존성 추가
find_package(PkgConfig REQUIRED)
pkg_check_modules(POCO REQUIRED libpoco-dev)

# Include directories
include_directories(include)
include_directories(../dsr_common2/include)

# DRFL 라이브러리 경로 설정
set(DRFL_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../dsr_common2/lib/humble/x86_64/libDRFL.a")

# Doosan Robot Interface Library
add_library(doosan_robot_interface
  src/doosan_robot_interface.cpp
)

ament_target_dependencies(doosan_robot_interface
  rclcpp
  std_msgs
  geometry_msgs
  sensor_msgs
)

# DRFL 라이브러리 링크
target_link_libraries(doosan_robot_interface
  ${DRFL_LIB_PATH}
  PocoFoundation
  PocoNet
  pthread
)

# Sugar Water Experimenter Refactored Node (NEW - 공식 예제 방식)
add_executable(sugar_water_experiment_refactored
  src/sugar_water_experiment_refactored.cpp
)

ament_target_dependencies(sugar_water_experiment_refactored
  rclcpp
  std_msgs
  geometry_msgs
  sensor_msgs
)

target_link_libraries(sugar_water_experiment_refactored
  doosan_robot_interface
  ${DRFL_LIB_PATH}
  PocoFoundation
  PocoNet
  pthread
)

# Sugar Water Experimenter Node (LEGACY - 기존 토픽 기반)
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

# Simple Sequential Controller (LEGACY - 시뮬레이션용)
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
  doosan_robot_interface
  DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS
  sugar_water_experiment_refactored
  sugar_water_experimenter_node
  simple_sequence_controller
  DESTINATION lib/${PROJECT_NAME}
)

# Install headers
install(DIRECTORY include/
  DESTINATION include/
)

# Install launch files
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_export_include_directories(include)
ament_export_libraries(doosan_robot_interface)
ament_package()

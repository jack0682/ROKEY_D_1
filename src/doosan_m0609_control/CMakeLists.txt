cmake_minimum_required(VERSION 3.10)
project(doosan_m0609_control)

# ROS2 종속성
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# -----------------------------
# API-DRFL 헤더 및 라이브러리 경로 (경로 변경 반영됨)
# -----------------------------
include_directories(
  include
  ${CMAKE_SOURCE_DIR}/../API-DRFL/include
)

link_directories(
  ${CMAKE_SOURCE_DIR}/../API-DRFL/library/Linux/64bits/amd64/22.04
)

# -----------------------------
# 노드 소스 빌드
# -----------------------------
add_executable(m0609_control_node
  src/main_node.cpp
  # 나중에 src/dart_interface.cpp 추가 가능
)

target_link_libraries(m0609_control_node
  drfl
  PocoFoundation
  PocoNet
  pthread
  rt
)

ament_target_dependencies(m0609_control_node
  rclcpp
  std_msgs
)

# -----------------------------
# 설치
# -----------------------------
install(TARGETS
  m0609_control_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()

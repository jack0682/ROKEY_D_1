cmake_minimum_required(VERSION 3.5)
project(common_msgs)

find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/BoundingBox.msg"
  "msg/BoundingBoxes.msg"
  "msg/CrackEstimate.msg"
  DEPENDENCIES std_msgs
)

ament_package()

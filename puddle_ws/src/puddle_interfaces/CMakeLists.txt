cmake_minimum_required(VERSION 3.5)
project(puddle_interfaces)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(builtin_interfaces REQUIRED)

# 메시지 선언을 조금 더 명확하게 지정
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Puddle.msg"
  "msg/PuddleArray.msg"
  DEPENDENCIES builtin_interfaces
)

ament_export_dependencies(rosidl_default_runtime)

# 가장 마지막에 위치해야 함!
ament_package()

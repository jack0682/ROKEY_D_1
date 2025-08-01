cmake_minimum_required(VERSION 3.10.2)
project(doosan_m0609_description)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)

# Install 디렉토리들 먼저 설치
install(DIRECTORY meshes urdf xacro config ros2_control mujoco_models DESTINATION share/${PROJECT_NAME})
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})
install(DIRECTORY rviz DESTINATION share/${PROJECT_NAME})

# Environment hooks 설정
ament_environment_hooks("doosan_m0609_description_path.dsv.in")

# Package 완료
ament_package()

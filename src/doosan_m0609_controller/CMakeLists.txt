cmake_minimum_required(VERSION 3.8)
project(doosan_m0609_controller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 🎯 dsr_common2 경로 설정 (절대경로로 확실하게)
SET(COMMON_INC_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/../dsr_common2/include
)
SET(COMMON_LIB_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/../dsr_common2/lib
)

# 행텄 디버깅 정보
message(STATUS "🔍 COMMON_INC_FILES: ${COMMON_INC_FILES}")
message(STATUS "🔍 COMMON_LIB_FILES: ${COMMON_LIB_FILES}")
message(STATUS "🔍 CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Message and Service generation
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/JointState.msg"
  "msg/RobotStatus.msg" 
  "srv/MoveJ.srv"
  "srv/ConnectRobot.srv"
  DEPENDENCIES std_msgs sensor_msgs geometry_msgs
)

# Include directories - 공식 구조와 동일
include_directories(
  include
  ${Boost_INCLUDE_DIRS}
  ${COMMON_INC_FILES}
)

# 🔥 공식 예제와 동일한 라이브러리 링크 방식
LINK_LIBRARIES(DRFL PocoFoundation PocoNet)

if($ENV{ROS_DISTRO} STREQUAL "humble")                          
  LINK_DIRECTORIES("${COMMON_LIB_FILES}/$ENV{ROS_DISTRO}/x86_64")
else()
  message(WARNING "Unknown ROS distro: $ENV{ROS_DISTRO}")
endif()

# Create main executable
add_executable(doosan_controller_node
  src/doosan_controller_node.cpp
  src/doosan_robot_controller.cpp
)

# Target dependencies
ament_target_dependencies(doosan_controller_node 
  rclcpp
  std_msgs
  sensor_msgs
  geometry_msgs
)

# Include directories for target
target_include_directories(doosan_controller_node PRIVATE
  include
  ${COMMON_INC_FILES}
)

# Interface dependencies
rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(doosan_controller_node "${cpp_typesupport_target}")

# Install targets
install(TARGETS
  doosan_controller_node
  DESTINATION lib/${PROJECT_NAME}
)

# Install directories
install(DIRECTORY include/
  DESTINATION include
)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/launch)
  install(DIRECTORY launch/
    DESTINATION share/${PROJECT_NAME}/launch
  )
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config)
  install(DIRECTORY config/
    DESTINATION share/${PROJECT_NAME}/config
  )
endif()

# Testing
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

# Export information
ament_export_include_directories(include)
ament_export_dependencies(rosidl_default_runtime)
ament_package()

message(STATUS "========================================")
message(STATUS "📋 Doosan M0609 Controller Configuration:")
message(STATUS "   • Using Official DRFL Library")
message(STATUS "   • COMMON_INC: ${COMMON_INC_FILES}")
message(STATUS "   • COMMON_LIB: ${COMMON_LIB_FILES}")
message(STATUS "   • ROS_DISTRO: $ENV{ROS_DISTRO}")
message(STATUS "========================================")

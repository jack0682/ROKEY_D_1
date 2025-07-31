cmake_minimum_required(VERSION 3.8)
project(doosan_m0609_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Find Poco libraries (DRFL dependency)
find_package(PkgConfig REQUIRED)
pkg_check_modules(POCO REQUIRED IMPORTED_TARGET 
  PkgConfig::libpocofoundation 
  PkgConfig::libpoconet
)

# DRFL 라이브러리 설정
set(DRFL_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../../API-DRFL)
set(DRFL_INCLUDE_DIR ${DRFL_ROOT}/include)
set(DRFL_LIBRARY_DIR ${DRFL_ROOT}/library/Linux/64bits/amd64/22.04)

# Include directories
include_directories(
  include
  ${DRFL_INCLUDE_DIR}
)

# Generate custom interfaces from srv files
file(GLOB_RECURSE SRV_FILES "srv/*.srv")
rosidl_generate_interfaces(${PROJECT_NAME}
  ${SRV_FILES}
  DEPENDENCIES 
    std_msgs 
    sensor_msgs 
    geometry_msgs
    builtin_interfaces
)

# Create the main robot control node
add_executable(doosan_robot_node
  src/main_node.cpp
  src/dart_interface.cpp
)

# Link libraries
target_link_libraries(doosan_robot_node
  # ROS2 dependencies
  ${rclcpp_LIBRARIES}
  ${std_msgs_LIBRARIES}
  ${sensor_msgs_LIBRARIES}
  ${geometry_msgs_LIBRARIES}
  
  # DRFL dependencies
  ${DRFL_LIBRARY_DIR}/libDRFL.a
  ${DRFL_LIBRARY_DIR}/libPocoFoundation.so.80
  ${DRFL_LIBRARY_DIR}/libPocoNet.so.80
  
  # System libraries
  pthread
  dl
)

# Specify dependencies
ament_target_dependencies(doosan_robot_node
  rclcpp
  std_msgs
  sensor_msgs
  geometry_msgs
  builtin_interfaces
)

# Link against the generated interfaces
rosidl_target_interfaces(doosan_robot_node
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

# Install targets
install(TARGETS
  doosan_robot_node
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

# Install config files if any
install(DIRECTORY
  config
  DESTINATION share/${PROJECT_NAME}
  OPTIONAL
)

# Testing
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
  
  find_package(ament_cmake_gtest REQUIRED)
  
  # Unit tests
  ament_add_gtest(${PROJECT_NAME}_test
    test/test_dart_interface.cpp
    src/dart_interface.cpp
  )
  
  if(TARGET ${PROJECT_NAME}_test)
    target_include_directories(${PROJECT_NAME}_test PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}/include
      ${DRFL_INCLUDE_DIR}
    )
    target_link_libraries(${PROJECT_NAME}_test
      ${DRFL_LIBRARY_DIR}/libDRFL.a
      ${DRFL_LIBRARY_DIR}/libPocoFoundation.so.80
      ${DRFL_LIBRARY_DIR}/libPocoNet.so.80
      pthread
      dl
    )
    ament_target_dependencies(${PROJECT_NAME}_test
      rclcpp
      std_msgs
      sensor_msgs
      geometry_msgs
    )
  endif()
endif()

# Export information
ament_export_dependencies(rosidl_default_runtime)
ament_export_include_directories(include)

ament_package()
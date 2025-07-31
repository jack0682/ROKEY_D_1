cmake_minimum_required(VERSION 3.8)
project(arduino_loadcell_interface)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(serial REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Generate custom messages
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/LoadcellData.msg"
  DEPENDENCIES std_msgs sensor_msgs
)

# Create loadcell node
add_executable(loadcell_node src/loadcell_node.cpp)
ament_target_dependencies(loadcell_node rclcpp std_msgs sensor_msgs serial)

# Link generated interfaces
rosidl_target_interfaces(loadcell_node ${PROJECT_NAME} "rosidl_typesupport_cpp")

# Install targets
install(TARGETS loadcell_node DESTINATION lib/${PROJECT_NAME})

# Install launch files
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME} OPTIONAL)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_export_dependencies(rosidl_default_runtime)
ament_package()

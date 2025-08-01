cmake_minimum_required(VERSION 3.8)
project(doosan_m0609_controller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

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

# Include directories
include_directories(
  include
  ${CMAKE_CURRENT_SOURCE_DIR}/include/DRFL
)

# Find Poco libraries using find_library (no pkg-config needed)
message(STATUS "Searching for Poco libraries using find_library...")

# Try to find Poco using CMake's find_package first
find_package(Poco QUIET COMPONENTS Foundation Net)

if(Poco_FOUND)
    message(STATUS "Found Poco using find_package")
    set(POCO_LIBRARIES Poco::Foundation Poco::Net)
    set(POCO_FOUND TRUE)
else()
    message(STATUS "find_package(Poco) failed, trying direct library search...")
    
    # Direct library search (Ubuntu standard approach)
    find_library(POCO_FOUNDATION_LIB 
        NAMES PocoFoundation
        PATHS 
            /usr/lib/x86_64-linux-gnu
            /usr/lib
            /usr/local/lib
        DOC "Poco Foundation library")
    
    find_library(POCO_NET_LIB 
        NAMES PocoNet
        PATHS 
            /usr/lib/x86_64-linux-gnu
            /usr/lib
            /usr/local/lib
        DOC "Poco Net library")
    
    # Check if both libraries were found
    if(POCO_FOUNDATION_LIB AND POCO_NET_LIB)
        set(POCO_LIBRARIES ${POCO_FOUNDATION_LIB} ${POCO_NET_LIB})
        message(STATUS "Found Poco Foundation: ${POCO_FOUNDATION_LIB}")
        message(STATUS "Found Poco Net: ${POCO_NET_LIB}")
        set(POCO_FOUND TRUE)
    else()
        message(STATUS "Poco libraries not found")
        set(POCO_FOUND FALSE)
        set(POCO_LIBRARIES "")
    endif()
endif()

# Find Poco headers
find_path(POCO_INCLUDE_DIR 
    NAMES Poco/Foundation.h
    PATHS 
        /usr/include
        /usr/local/include
    DOC "Poco include directory")

if(POCO_INCLUDE_DIR)
    message(STATUS "Found Poco headers: ${POCO_INCLUDE_DIR}")
    include_directories(${POCO_INCLUDE_DIR})
endif()

# Set compile definitions based on Poco availability
if(POCO_FOUND AND POCO_INCLUDE_DIR)
    message(STATUS "Building with full Poco support")
    set(HAVE_POCO 1)
else()
    message(STATUS "Building in dummy mode (no Poco)")
    set(HAVE_POCO 0)
endif()

# Create doosan_controller_node executable
add_executable(doosan_controller_node
  src/doosan_controller_node.cpp
  src/doosan_robot_controller.cpp
  src/drfl_dummy.cpp
)

# Target dependencies
ament_target_dependencies(doosan_controller_node 
  rclcpp
  std_msgs
  sensor_msgs
  geometry_msgs
)

# Link libraries
target_link_libraries(doosan_controller_node ${POCO_LIBRARIES} pthread)

# Add compile definitions
target_compile_definitions(doosan_controller_node PRIVATE 
  HAVE_POCO=${HAVE_POCO}
)

# Add include directories
target_include_directories(doosan_controller_node PRIVATE
  include
  ${CMAKE_CURRENT_SOURCE_DIR}/include/DRFL
)

# Interface dependencies (this must come after the executable is defined)
rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(doosan_controller_node "${cpp_typesupport_target}")

# Install targets
install(TARGETS
  doosan_controller_node
  DESTINATION lib/${PROJECT_NAME}
)

# Install headers
install(DIRECTORY include/
  DESTINATION include
)

# Install launch files if they exist
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/launch)
  install(DIRECTORY launch/
    DESTINATION share/${PROJECT_NAME}/launch
  )
endif()

# Install config files if they exist  
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config)
  install(DIRECTORY config/
    DESTINATION share/${PROJECT_NAME}/config
  )
endif()

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_export_include_directories(include)
ament_export_dependencies(rosidl_default_runtime)
ament_package()
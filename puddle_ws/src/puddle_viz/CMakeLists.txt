cmake_minimum_required(VERSION 3.5)
project(puddle_viz)

find_package(ament_cmake REQUIRED)
find_package(ament_python REQUIRED)

ament_python_install_package(${PROJECT_NAME})

install(DIRECTORY
  launch
  config
  DESTINATION share/${PROJECT_NAME}
)

install(FILES
  resource/${PROJECT_NAME}
  DESTINATION share/${PROJECT_NAME}/resource
)

ament_package()

cmake_minimum_required(VERSION 3.5)
project(puddle_tracking)

find_package(ament_cmake REQUIRED)
find_package(ament_python REQUIRED)

ament_python_install_package(${PROJECT_NAME})

install(PROGRAMS
  # 여기에 직접 실행 가능한 Python 스크립트 등록 가능 (현재 없음)
  DESTINATION lib/${PROJECT_NAME}
)

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

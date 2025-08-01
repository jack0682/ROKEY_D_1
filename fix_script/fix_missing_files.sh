#!/bin/bash
# 누락된 핵심 파일들 생성 스크립트

cd /home/jaeho/project_ws

echo "🔧 누락된 핵심 파일들 생성 중..."

# =================================================================
# 1. 각 패키지별 package.xml 생성
# =================================================================

# arduino_loadcell_interface
cat > src/arduino_loadcell_interface/package.xml << 'EOF'
<?xml version="1.0"?>
<package format="3">
  <n>arduino_loadcell_interface</n>
  <version>1.0.0</version>
  <description>Arduino HX711 로드셀 인터페이스 패키지 - Day 1 목표</description>
  <maintainer email="jaeho@example.com">Jaehong Oh</maintainer>
  <license>Apache License 2.0</license>

  <buildtool_depend>ament_cmake</buildtool_depend>
  
  <build_depend>rclcpp</build_depend>
  <build_depend>std_msgs</build_depend>
  <build_depend>sensor_msgs</build_depend>
  <build_depend>serial</build_depend>
  <build_depend>rosidl_default_generators</build_depend>
  
  <exec_depend>rclcpp</exec_depend>
  <exec_depend>std_msgs</exec_depend>
  <exec_depend>sensor_msgs</exec_depend>
  <exec_depend>serial</exec_depend>
  <exec_depend>rosidl_default_runtime</exec_depend>

  <member_of_group>rosidl_interface_packages</member_of_group>
  <export><build_type>ament_cmake</build_type></export>
</package>
EOF

# chemistry_msgs
cat > src/chemistry_msgs/package.xml << 'EOF'
<?xml version="1.0"?>
<package format="3">
  <n>chemistry_msgs</n>
  <version>1.0.0</version>
  <description>화학 실험 시스템 전용 메시지, 서비스, 액션 정의</description>
  <maintainer email="jaeho@example.com">Jaehong Oh</maintainer>
  <license>Apache License 2.0</license>

  <buildtool_depend>ament_cmake</buildtool_depend>
  
  <build_depend>std_msgs</build_depend>
  <build_depend>geometry_msgs</build_depend>
  <build_depend>sensor_msgs</build_depend>
  <build_depend>builtin_interfaces</build_depend>
  <build_depend>rosidl_default_generators</build_depend>
  
  <exec_depend>std_msgs</exec_depend>
  <exec_depend>geometry_msgs</exec_depend>
  <exec_depend>sensor_msgs</exec_depend>
  <exec_depend>builtin_interfaces</exec_depend>
  <exec_depend>rosidl_default_runtime</exec_depend>

  <member_of_group>rosidl_interface_packages</member_of_group>
  <export><build_type>ament_cmake</build_type></export>
</package>
EOF

# development 디렉토리 및 빌드 스크립트 생성
mkdir -p development/scripts

cat > development/scripts/build_day1.sh << 'EOF'
#!/bin/bash
# Day 1 패키지들만 빌드

cd /home/jaeho/project_ws
source /opt/ros/humble/setup.bash

echo "🔨 Day 1 패키지 빌드: arduino_loadcell_interface + doosan_m0609_control"

colcon build --packages-select \
    chemistry_msgs \
    doosan_m0609_control \
    arduino_loadcell_interface

echo "✅ Day 1 빌드 완료!"
EOF

chmod +x development/scripts/build_day1.sh

echo "✅ 핵심 파일들 생성 완료"
#!/bin/bash
# 모든 패키지에 기본 파일들 생성 (Git 추적용)

cd /home/jaeho/project_ws

echo "📁 모든 패키지에 기본 파일들 생성 중..."

# =================================================================
# 1. arduino_loadcell_interface 기본 파일들
# =================================================================
echo "🔧 arduino_loadcell_interface 기본 파일 생성..."

# package.xml
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

# CMakeLists.txt
cat > src/arduino_loadcell_interface/CMakeLists.txt << 'EOF'
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
EOF

# 기본 소스 파일
cat > src/arduino_loadcell_interface/src/loadcell_node.cpp << 'EOF'
// Arduino HX711 로드셀 인터페이스 노드
// Day 1 목표: 0.01g 분해능, 80Hz 샘플링

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32.hpp>
#include <sensor_msgs/msg/temperature.hpp>

class LoadcellNode : public rclcpp::Node
{
public:
    LoadcellNode() : Node("loadcell_node")
    {
        // Day 1 구현 예정:
        // - Arduino Serial 통신
        // - HX711 데이터 파싱
        // - 무게 데이터 퍼블리시
        
        RCLCPP_INFO(this->get_logger(), "Arduino Loadcell Interface Node Started - Day 1 Implementation");
        RCLCPP_INFO(this->get_logger(), "Target: 0.01g resolution, 80Hz sampling rate");
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LoadcellNode>());
    rclcpp::shutdown();
    return 0;
}
EOF

# 기본 메시지 정의
cat > src/arduino_loadcell_interface/msg/LoadcellData.msg << 'EOF'
# Arduino HX711 로드셀 데이터
std_msgs/Header header

# Raw loadcell reading
float32 raw_value

# Calibrated weight in grams
float32 weight_grams

# Measurement confidence (0.0 to 1.0)
float32 confidence

# Sampling rate in Hz
float32 sample_rate
EOF

# 헤더 파일
cat > src/arduino_loadcell_interface/include/arduino_loadcell_interface/loadcell_interface.hpp << 'EOF'
#pragma once

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32.hpp>

namespace arduino_loadcell_interface
{
    class LoadcellInterface
    {
    public:
        LoadcellInterface();
        ~LoadcellInterface();
        
        // Day 1 구현 예정 메서드들
        bool initialize_serial_connection();
        float read_weight();
        bool calibrate(float known_weight);
        
    private:
        // Day 1 구현 예정 멤버 변수들
        std::string serial_port_;
        int baud_rate_;
        float calibration_factor_;
    };
}
EOF

# =================================================================
# 2. chemistry_msgs 기본 파일들
# =================================================================
echo "📝 chemistry_msgs 기본 파일 생성..."

# package.xml
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

# CMakeLists.txt
cat > src/chemistry_msgs/CMakeLists.txt << 'EOF'
cmake_minimum_required(VERSION 3.8)
project(chemistry_msgs)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Generate interfaces
rosidl_generate_interfaces(${PROJECT_NAME}
  # Messages
  "msg/WeightMeasurement.msg"
  "msg/ConcentrationData.msg"
  "msg/ExperimentStatus.msg"
  "msg/SafetyStatus.msg"
  
  # Services
  "srv/CalculateConcentration.srv"
  "srv/MeasureWeight.srv"
  "srv/PourLiquid.srv"
  
  # Actions
  "action/RunExperiment.action"
  "action/PrecisionPour.action"
  
  DEPENDENCIES 
    std_msgs 
    geometry_msgs 
    sensor_msgs
    builtin_interfaces
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_export_dependencies(rosidl_default_runtime)
ament_package()
EOF

# 기본 메시지들
cat > src/chemistry_msgs/msg/WeightMeasurement.msg << 'EOF'
# 하이브리드 무게 측정 데이터
std_msgs/Header header

# 로드셀 측정값 (grams)
float32 loadcell_weight

# M0609 토크센서 측정값 (grams)
float32 torque_weight

# 융합 측정값 (grams)
float32 fused_weight

# 측정 불확실성 (grams)
float32 uncertainty

# 측정 신뢰도 (0.0 to 1.0)
float32 confidence
EOF

cat > src/chemistry_msgs/msg/ConcentrationData.msg << 'EOF'
# 농도 계산 결과
std_msgs/Header header

# 목표 농도 (w/w%)
float32 target_concentration

# 실제 농도 (w/w%)
float32 actual_concentration

# 소금 무게 (grams)
float32 salt_weight

# 물 무게 (grams)
float32 water_weight

# 농도 오차 (%)
float32 concentration_error

# 계산 상태
uint8 CALCULATION_SUCCESS = 0
uint8 CALCULATION_ERROR = 1
uint8 calculation_status
EOF

cat > src/chemistry_msgs/srv/CalculateConcentration.srv << 'EOF'
# 농도 계산 서비스
# Request
float32 target_concentration_percent  # 목표 농도 (w/w%)
float32 total_solution_weight        # 총 용액량 (grams)

---
# Response
bool success
string message

# 계산 결과
float32 required_salt_weight    # 필요한 소금량 (grams)
float32 required_water_weight   # 필요한 물량 (grams)
float32 expected_accuracy       # 예상 정확도 (%)
EOF

# =================================================================
# 3. 나머지 패키지들 기본 파일 생성
# =================================================================

# hybrid_weight_measurement
cat > src/hybrid_weight_measurement/package.xml << 'EOF'
<?xml version="1.0"?>
<package format="3">
  <n>hybrid_weight_measurement</n>
  <version>1.0.0</version>
  <description>M0609 토크센서 + 로드셀 융합 무게 측정 시스템 - Day 2 목표</description>
  <maintainer email="jaeho@example.com">Jaehong Oh</maintainer>
  <license>Apache License 2.0</license>

  <buildtool_depend>ament_cmake</buildtool_depend>
  
  <build_depend>rclcpp</build_depend>
  <build_depend>std_msgs</build_depend>
  <build_depend>sensor_msgs</build_depend>
  <build_depend>geometry_msgs</build_depend>
  <build_depend>doosan_m0609_control</build_depend>
  <build_depend>arduino_loadcell_interface</build_depend>
  <build_depend>chemistry_msgs</build_depend>
  
  <exec_depend>rclcpp</exec_depend>
  <exec_depend>std_msgs</exec_depend>
  <exec_depend>sensor_msgs</exec_depend>
  <exec_depend>geometry_msgs</exec_depend>
  <exec_depend>doosan_m0609_control</exec_depend>
  <exec_depend>arduino_loadcell_interface</exec_depend>
  <exec_depend>chemistry_msgs</exec_depend>

  <export><build_type>ament_cmake</build_type></export>
</package>
EOF

cat > src/hybrid_weight_measurement/CMakeLists.txt << 'EOF'
cmake_minimum_required(VERSION 3.8)
project(hybrid_weight_measurement)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(chemistry_msgs REQUIRED)

# Day 2 구현 예정: 센서 융합 노드
add_executable(weight_fusion_node src/weight_fusion_node.cpp)
ament_target_dependencies(weight_fusion_node rclcpp std_msgs chemistry_msgs)

install(TARGETS weight_fusion_node DESTINATION lib/${PROJECT_NAME})

ament_package()
EOF

cat > src/hybrid_weight_measurement/src/weight_fusion_node.cpp << 'EOF'
// Day 2: 하이브리드 센서 융합 시스템
#include <rclcpp/rclcpp.hpp>

class WeightFusionNode : public rclcpp::Node
{
public:
    WeightFusionNode() : Node("weight_fusion_node")
    {
        RCLCPP_INFO(this->get_logger(), "Weight Fusion Node - Day 2 Implementation");
        RCLCPP_INFO(this->get_logger(), "Target: 0.005g effective resolution through sensor fusion");
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<WeightFusionNode>());
    rclcpp::shutdown();
    return 0;
}
EOF

# 나머지 패키지들도 기본 구조 생성
for pkg in salt_concentration_calculator precision_liquid_pouring chemistry_experiment_manager safety_monitoring_system experiment_data_logger; do
    echo "📦 $pkg 기본 파일 생성..."
    
    cat > src/$pkg/CMakeLists.txt << EOF
cmake_minimum_required(VERSION 3.8)
project($pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(chemistry_msgs REQUIRED)

# TODO: Day별 구현 예정
add_executable(${pkg}_node src/${pkg}_node.cpp)
ament_target_dependencies(${pkg}_node rclcpp std_msgs chemistry_msgs)

install(TARGETS ${pkg}_node DESTINATION lib/\${PROJECT_NAME})

ament_package()
EOF

    cat > src/$pkg/src/${pkg}_node.cpp << EOF
// $pkg - 구현 예정
#include <rclcpp/rclcpp.hpp>

class ${pkg^}Node : public rclcpp::Node
{
public:
    ${pkg^}Node() : Node("${pkg}_node")
    {
        RCLCPP_INFO(this->get_logger(), "${pkg^} Node - Implementation pending");
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<${pkg^}Node>());
    rclcpp::shutdown();
    return 0;
}
EOF

    # package.xml 파일도 생성
    cat > src/$pkg/package.xml << EOF
<?xml version="1.0"?>
<package format="3">
  <n>$pkg</n>
  <version>1.0.0</version>
  <description>$pkg package for precision chemistry system</description>
  <maintainer email="jaeho@example.com">Jaehong Oh</maintainer>
  <license>Apache License 2.0</license>

  <buildtool_depend>ament_cmake</buildtool_depend>
  
  <build_depend>rclcpp</build_depend>
  <build_depend>std_msgs</build_depend>
  <build_depend>chemistry_msgs</build_depend>
  
  <exec_depend>rclcpp</exec_depend>
  <exec_depend>std_msgs</exec_depend>
  <exec_depend>chemistry_msgs</exec_depend>

  <export><build_type>ament_cmake</build_type></export>
</package>
EOF
done

# =================================================================
# 4. development 스크립트들
# =================================================================
mkdir -p development/scripts

cat > development/scripts/build_day1.sh << 'EOF'
#!/bin/bash
# Day 1 패키지들만 빌드

cd /home/jaeho/project_ws
source /opt/ros/humble/setup.bash

echo "🔨 Day 1 패키지 빌드: chemistry_msgs + arduino_loadcell_interface"

colcon build --packages-select \
    chemistry_msgs \
    arduino_loadcell_interface

echo "✅ Day 1 빌드 완료!"
source install/setup.bash
EOF

cat > development/scripts/build_all_chemistry.sh << 'EOF'
#!/bin/bash
# 화학 시스템 전체 빌드

cd /home/jaeho/project_ws
source /opt/ros/humble/setup.bash

echo "🧪 화학 실험 시스템 전체 빌드..."

colcon build

echo "🎉 전체 시스템 빌드 완료!"
source install/setup.bash
EOF

chmod +x development/scripts/*.sh

echo ""
echo "🎉 모든 패키지 기본 파일 생성 완료!"
echo ""
echo "📦 생성된 패키지들:"
echo "├── arduino_loadcell_interface    # Day 1: 완전한 기본 구조"
echo "├── chemistry_msgs                # 메시지 정의: 완전한 기본 구조"
echo "├── hybrid_weight_measurement     # Day 2: 기본 구조"
echo "├── salt_concentration_calculator # Day 3: 기본 구조"
echo "├── precision_liquid_pouring      # Day 4: 기본 구조"
echo "├── chemistry_experiment_manager  # Day 5: 기본 구조"
echo "├── safety_monitoring_system      # Day 6: 기본 구조"
echo "└── experiment_data_logger        # Day 7: 기본 구조"
echo ""
echo "🚀 이제 Git에서 모든 패키지가 인식됩니다!"
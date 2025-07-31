#!/bin/bash
# 화학 시스템 전체 빌드

cd /home/jaeho/project_ws
source /opt/ros/humble/setup.bash

echo "🧪 화학 실험 시스템 전체 빌드..."

colcon build

echo "🎉 전체 시스템 빌드 완료!"
source install/setup.bash

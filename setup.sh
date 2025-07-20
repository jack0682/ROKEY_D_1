#!/bin/bash

# MQTT + InfluxDB 대시보드 초기 설정 스크립트
# Author: 피피

echo "🛠️ 초기 환경 설정 시작..."

# 백엔드 의존성 설치
echo "📦 백엔드 의존성 설치..."
cd "$(dirname "$0")/backend" || exit 1

# 가상환경 생성
if [ ! -d "venv" ]; then
  echo "🐍 Python 가상환경 생성..."
  python3 -m venv venv
fi

# 가상환경 활성화 및 패키지 설치
source venv/bin/activate
pip install --upgrade pip > /dev/null
pip install -r requirements.txt
deactivate

# 프론트엔드 의존성 설치
echo "🌐 프론트엔드 의존성 설치..."
cd ../frontend || exit 1
if [ ! -d "node_modules" ]; then
  npm install
fi

echo "✅ 설정 완료! 다음 명령어로 실행하세요:"
echo "👉 ./run-backend.sh  # 백엔드 실행"
echo "👉 ./run-frontend.sh # 프론트엔드 실행"

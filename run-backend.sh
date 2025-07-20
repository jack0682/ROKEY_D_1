#!/bin/bash

# 백엔드 실행 스크립트
# Author: 피피

echo "📦 MQTT-Influx 백엔드 실행 시작"

# 경로 이동
cd "$(dirname "$0")/backend" || exit 1

# 가상환경 생성 (최초 1회만)
if [ ! -d "venv" ]; then
  echo "🐍 가상환경 생성 중..."
  python3 -m venv venv
fi

# 가상환경 활성화
source venv/bin/activate

# 의존성 설치
echo "📚 requirements.txt 설치 중..."
pip install --upgrade pip > /dev/null
pip install -r requirements.txt

# 브리지 실행
echo "🚀 mqtt-to-influx.py 실행 중..."
python mqtt-to-influx.py

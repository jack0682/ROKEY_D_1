#!/bin/bash

# 🔧 Fix Execute Permissions Script
# Author: Jack
# Date: 2024

echo "🔑 Setting execute permissions for shell scripts..."

# 작업 디렉토리로 이동
cd /home/jaeho/project_ws

# 모든 shell 스크립트에 실행 권한 부여
chmod +x *.sh

echo "✅ Execute permissions set for all .sh files"
echo ""
echo "📋 Available scripts:"
ls -la *.sh

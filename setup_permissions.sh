#!/bin/bash
# setup_permissions.sh - 실행 권한 설정 스크립트

echo "🔐 실행 권한 설정 중..."

# 스크립트 파일들에 실행 권한 부여
chmod +x /home/jack/project_ws/integrate_doosan_wrapper.sh
chmod +x /home/jack/project_ws/post_integration_setup.sh

echo "✅ 권한 설정 완료!"
echo ""
echo "🚀 이제 다음 명령으로 통합을 시작하세요:"
echo "  cd /home/jack/project_ws"
echo "  ./integrate_doosan_wrapper.sh"
echo ""
echo "📖 자세한 가이드는 다음 파일을 참조하세요:"
echo "  cat INTEGRATION_COMPLETE_GUIDE.md"

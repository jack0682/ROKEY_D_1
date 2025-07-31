# chemistry_experiment_manager/config.py

from pathlib import Path
from datetime import datetime

# 기본 실험 설정
EXPERIMENT_NAME = "salt_solution_precision_test"
TIMESTAMP = datetime.now().strftime("%Y%m%d_%H%M%S")

# 반복 횟수
NUM_TRIALS = 5

# 실험 대상 농도 (%), ml 기준
TARGET_CONCENTRATIONS = [0.5, 1.0, 1.5, 2.0]  # 퍼센트 단위

# 각 타겟 농도별 총 용액량 (ml)
TARGET_TOTAL_VOLUME_ML = 100.0

# 정밀도 요구 사항
CONCENTRATION_TOLERANCE = 0.05  # ±0.05% 허용 오차

# 하위 pouring 시스템 path (import 시 사용)
POURING_MODULE_PATH = str(Path(__file__).parent.parent / "precision_liquid_pouring")

# 결과 저장 위치
RESULT_DIR = Path.home() / "experiment_results" / EXPERIMENT_NAME / TIMESTAMP
RESULT_DIR.mkdir(parents=True, exist_ok=True)

# 로깅 설정
LOG_TO_CONSOLE = True
LOG_TO_FILE = True

# 실험 간 대기 시간 (초)
INTER_TRIAL_DELAY_SEC = 3.0

# 사용할 로드셀 평균 횟수
HX711_AVERAGE_READS = 10

# 고정된 소금 무게 (g)
FIXED_SALT_WEIGHT_GRAMS = 2.0  # 실험마다 같다고 가정

# 사용할 실험 프로토콜
DEFAULT_PROTOCOL = "fixed_concentration_protocol"

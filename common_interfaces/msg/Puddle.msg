# Puddle.msg - 단일 puddle 객체의 정보를 표현

int32 id                             # 고유 ID
float64 x                           # 중심점 x (map 기준)
float64 y                           # 중심점 y
float64 z                           # 깊이 또는 추후 3D 확장용
float64 area                        # 추정 면적
float64[] hu_moments                # shape 불변성 특징 (7차원 Hu Moment)
float64 euler_char                 # 위상 특성: Euler characteristic
string shape_hash                   # shape signature 해시값 (선택)
int32 risk_level                    # 위험도 (0: 안전, 1: 위험, 2: 긴급 등)
builtin_interfaces/Time timestamp  # 인식 시점

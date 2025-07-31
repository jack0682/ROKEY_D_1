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

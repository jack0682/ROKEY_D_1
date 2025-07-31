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

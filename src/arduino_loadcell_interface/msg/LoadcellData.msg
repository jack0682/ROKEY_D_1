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

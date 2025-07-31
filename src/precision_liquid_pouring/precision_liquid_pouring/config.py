# config.py
# Centralized configuration for the precision_liquid_pouring package

# Load cell (HX711 or equivalent) configuration
SCALE_SERIAL_PORT = "/dev/ttyUSB0"  # Change this to match your Arduino/USB setup
REFERENCE_UNIT = -7050               # Calibrated scale factor (determined experimentally)
OFFSET = 0                           # Tare offset, may be adjusted on startup

# Experiment parameters
FIXED_SALT_GRAMS = 15.0              # Mass of salt used for each experiment [grams]
TARGET_CONCENTRATION_PERCENT = 3.0   # Target saltwater concentration (w/w %) to reach
TOLERANCE_PERCENT = 0.05             # Acceptable margin of error (%)

# Logging / Debugging
VERBOSE = True                       # Enable or disable debug prints

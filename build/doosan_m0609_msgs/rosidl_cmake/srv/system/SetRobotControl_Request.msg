#____________________________________________________________________________________________
# set_robot_control
# 0 : CONTROL_INIT_CONFIG
# executes the function to convert from STATE_NOT_READY to STATE_INITIALIZING, and only the T/P applicatiexecutes this function.
# 1 : CONTROL_ENABLE_OPERATION
# executes the function to convert from STATE_INITIALIZING to STATE_STANDBY, and only the T/P applicatiexecutes this function.
# 2 : CONTROL_RESET_SAFET_STOP
# executes the function to convert from STATE_SAFE_STOP to STATE_STANDBY. Program restart can be set in the case of automatic mode.
# 3 : CONTROL_RESET_SAFET_OFF
# executes the function to convert from STATE_SAFE_OFF to STATE_STANDBY.
# 4 : CONTROL_RECOVERY_SAFE_STOP
# executes the S/W-based function to convert from STATE_SAFE_STOP2 to STATE_RECOVERY.
# 5 : CONTROL_RECOVERY_SAFE_OFF
# executes the S/W-based function to convert from STATE_SAFE_OFF2 to STATE_RECOVERY.
# 6 : CONTROL_RECOVERY_BACKDRIVE
# executes the H/W-based function to convert from STATE_SAFE_OFF2 to STATE_RECOVERY. cannot be converted into STATE_STANDBY, and robot controller power should be rebooted.
# 7 : CONTROL_RESET_RECOVERY
# executes the function to convert from STATE_RECOVERY to STATE_STANDBY.
#____________________________________________________________________________________________

int8 robot_control 

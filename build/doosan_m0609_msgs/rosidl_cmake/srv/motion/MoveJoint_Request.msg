#____________________________________________________________________________________________
# move_joint  
# The robot moves to the target joint position (pos) from the current joint position.
#____________________________________________________________________________________________

float64[6] pos               # target joint angle list [degree] 
float64    vel               # set velocity: [deg/sec]
float64    acc               # set acceleration: [deg/sec2]
float64    time #= 0.0       # Time [sec] 
float64    radius #=0.0      # Radius under blending mode [mm] 
int8       mode #= 0         # MOVE_MODE_ABSOLUTE=0, MOVE_MODE_RELATIVE=1 
int8       blend_type #= 0    # BLENDING_SPEED_TYPE_DUPLICATE=0, BLENDING_SPEED_TYPE_OVERRIDE=1
int8       sync_type #=0      # SYNC = 0, ASYNC = 1

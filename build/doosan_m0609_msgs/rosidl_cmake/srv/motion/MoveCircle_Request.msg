#____________________________________________________________________________________________
# move_circle  
#____________________________________________________________________________________________

std_msgs/Float64MultiArray[] pos  # target[2][6]  
float64[2]      vel               # set velocity: [mm/sec], [deg/sec]
float64[2]      acc               # set acceleration: [mm/sec2], [deg/sec2]
float64         time #= 0.0       # Time [sec] 
float64         radius #=0.0      # Radius under blending mode [mm] 
int8            ref               # DR_BASE(0), DR_TOOL(1), DR_WORLD(2)
                                  # <DR_WORLD is only available in M2.40 or later> 
int8            mode #= 0         # MOVE_MODE_ABSOLUTE=0, MOVE_MODE_RELATIVE=1 
float64         angle1 #= 0.0     # angle1 [degree]
float64         angle2 #= 0.0     # angle2 [degree]
int8            blend_type #= 0    # BLENDING_SPEED_TYPE_DUPLICATE=0, BLENDING_SPEED_TYPE_OVERRIDE=1
int8            sync_type #=0      # SYNC = 0, ASYNC = 1

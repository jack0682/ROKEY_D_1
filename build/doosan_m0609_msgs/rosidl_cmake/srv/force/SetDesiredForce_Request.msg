#____________________________________________________________________________________________
# set_desired_force  
#____________________________________________________________________________________________

float64[6] fd                # Three translational target forces + Three rotational target moments
int8[6]    dir               # Force control in the corresponding direction if 1, Compliance control in the corresponding direction if 0
int8       ref               # Reference coordinate of the coordinate to get
float64    time # 0          # Transition time of target force to take effect (0 ~ 1.0 sec)
int8       mod               # DR_FC_MOD_ABS(0): force control with absolute value, 
                             # DR_FC_MOD_REL(1): force control with relative value to initial state (the instance when this function is called) 

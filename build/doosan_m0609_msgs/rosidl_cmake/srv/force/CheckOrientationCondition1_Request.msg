#____________________________________________________________________________________________
# check_orientation_condition(axis, min, max, ref, mod)  
#____________________________________________________________________________________________

int8       axis              # DR_AXIS_A(10), DR_AXIS_B(11), DR_AXIS_C(12) 
float64[6] min               # task pos(posx)  
float64[6] max               # task pos(posx)  
int8       ref  #= 0         # DR_BASE(0), DR_TOOL(1), DR_WORLD(2), user_coordinate(101~200)
                             # <DR_WORLD is only available in M2.40 or later> 
int8       mode #= 0         # DR_MV_MOD_ABS(0)

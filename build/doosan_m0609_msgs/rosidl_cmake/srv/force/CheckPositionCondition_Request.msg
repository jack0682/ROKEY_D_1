#____________________________________________________________________________________________
# check_position_condition  
#____________________________________________________________________________________________

int8       axis              # DR_AXIS_X(0), DR_AXIS_Y(1), DR_AXIS_Z(2) 
float64    min               # min    
float64    max               # max  
int8       ref     #= 0      # DR_BASE(0), DR_TOOL(1), DR_WORLD(2), user_coordinate(101~200)
                             # <DR_WORLD is only available in M2.40 or later> 
int8       mode #= 0         # DR_MV_MOD_ABS(0), DR_MV_MOD_REL(1) 
float64[6] pos               # task pos(posx)  

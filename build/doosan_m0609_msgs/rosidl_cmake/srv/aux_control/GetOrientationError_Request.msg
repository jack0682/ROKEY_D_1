#____________________________________________________________________________________________
# get_orientation_error  
#____________________________________________________________________________________________
# This service returns the orientation error value between the arbitrary poses xd and xc of the axis.

float64[6] xd                # task pos(posx)  
float64[6] xc                # task pos(posx)  
int8       axis              # DR_AXIS_X(0), DR_AXIS_Y(1), DR_AXIS_Z(2) 

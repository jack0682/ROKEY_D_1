#____________________________________________________________________________________________
# align_axis(x1, x2, x3, pos, axis, ref)
#____________________________________________________________________________________________

float64[6] x1                # task pos(posx)  
float64[6] x2                # task pos(posx)  
float64[6] x3                # task pos(posx)
float64[3] source_vect       # source vector[3]  
int8       axis              # DR_AXIS_X(0), DR_AXIS_Y(1), DR_AXIS_Z(2) 
int8       ref               # DR_BASE(0), DR_WORLD(2), user coord(101~200)
                             # <ref is only available in M2.40 or later> 

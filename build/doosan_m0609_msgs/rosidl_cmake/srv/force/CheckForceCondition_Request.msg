#____________________________________________________________________________________________
# check_force_condition 
#This service checks the status of the given force. It disregards the force direction and only compares the sizes. 
#This condition can be repeated with the while or if statement. Measuring the force, axis is based on the ref coordinate and measuring the moment,
#axis is based on the tool coordinate.
#____________________________________________________________________________________________

int8       axis              # DR_AXIS_X(0), DR_AXIS_Y(1), DR_AXIS_Z(2), DR_AXIS_A(10), DR_AXIS_B(11), DR_AXIS_C(12) 
float64    min               # min >=0.0   
float64    max               # max >=0.0 
int8       ref     #= 0      # DR_BASE(0), DR_TOOL(1), DR_WORLD(2), user coord(101~200)
                             # <DR_WORLD is only available in M2.40 or later> 

#____________________________________________________________________________________________
# set_stiffnessx  
#____________________________________________________________________________________________

float64[6] stx               # default[500, 500, 500, 100, 100, 100], Three translational stiffnesses + Three rotational stiffnesses
int8       ref               # the preset reference coordinate system.
float64    time              # Stiffness varying time(0 ~ 1.0) [sec], Linear transition during the specified time   

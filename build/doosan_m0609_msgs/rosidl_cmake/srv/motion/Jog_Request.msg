#____________________________________________________________________________________________
# single jog
# single jog speed = (250mm/s) x speed [%] 
#____________________________________________________________________________________________

int8 jog_axis          # 0 ~ 5 : JOINT 1 ~ 6 
                       # 6 ~ 11: TASK 1 ~ 6 (X,Y,Z,rx,ry,rz)
int8 move_reference    # 0 : MOVE_REFERENCE_BASE, 1 : MOVE_REFERENCE_TOOL
float64 speed          # jog speed [%] : + forward , 0=stop, - backward  

#____________________________________________________________________________________________
# move_home
# Homing is performed by moving to the joint motion to the mechanical or user defined home position.
# According to the input parameter [target], it moves to the mechanical home defined in the system or the home set by the user.
#____________________________________________________________________________________________

int8       target           # DR_HOME_TARGET_MECHANIC(0) : Mechanical home, joint angle (0,0,0,0,0,0)
                            # DR_HOME_TARGET_USER(1)     : user home

#____________________________________________________________________________________________
# move_periodic  
#____________________________________________________________________________________________

float64[6] amp              # Amplitude (motion between -amp and +amp) [mm] or [deg]   
float64[6] periodic         # Period (time for 1 cycle) [sec]
float64    acc              # Acc-, dec- time [sec] 
int8       repeat           # Repetition count 
int8       ref  #= 1        # DR_BASE(0), DR_TOOL(1), DR_WORLD(2)
                            # <DR_WORLD is only available in M2.40 or later 

int8       sync_type #=0     # SYNC = 0, ASYNC = 1

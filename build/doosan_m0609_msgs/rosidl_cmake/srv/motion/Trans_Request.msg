#____________________________________________________________________________________________
# trans  
#____________________________________________________________________________________________

float64[6] pos               # task pos(posx)  
float64[6] delta             # delta (posx)  
int8       ref     #= 0      # DR_BASE(0), DR_TOOL(1), DR_WORLD(2)
                             # <DR_WORLD is only available in M2.40 or later> 
int8       ref_out #= 0      # DR_BASE(0), DR_WORLD(2)
                             # <ref_out is only available in M2.40 or later>

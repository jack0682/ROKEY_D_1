#____________________________________________________________________________________________
# config_create_modbus  
# This service registers the Modbus signal. 
#____________________________________________________________________________________________

string      name       # modbus signal symbol 
string      ip         # external device ip
int32       port       # external device port     
int8        reg_type   # <MODBUS_REGISTER_TYPE>(0: discrete input, 1: coil, 2: input register, 3: holding register)
int8        index      # modbus signal index(0 ~ 9999)
int8        value      # modbus singla value(unsigned value ; 0 ~ 65535)
int32       slave_id   # Slave ID of the ModbusTCP(0: Broadcase address or 1-247 or 255: Default value for ModbusTCP) 
                       # <slave_id is only available in M2.40 or later versions>  

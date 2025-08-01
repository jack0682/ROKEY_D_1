# Joint state message for M0609 (6-DOF)
std_msgs/Header header
float64[6] position     # Joint positions in radians
float64[6] velocity     # Joint velocities in rad/s  
float64[6] effort       # Joint efforts/torques in Nm

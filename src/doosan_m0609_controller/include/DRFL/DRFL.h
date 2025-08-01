// DRFL.h - Doosan Robot Framework Library
// This is a simplified header for demonstration
// Replace with actual DRFL.h from Doosan SDK

#ifndef DRFL_H
#define DRFL_H

#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

class DRFL {
public:
    DRFL();
    ~DRFL();
    
    // Connection functions
    bool openConnection(const std::string& ip);
    bool closeConnection();
    bool setRobotControl(bool enable);
    
    // Status functions
    bool isConnected() const;
    bool hasControlAuthority() const;
    std::string getRobotState() const;
    
    // Motion functions
    std::vector<double> getJointPosition();
    bool moveJ(const std::vector<double>& joints, 
               double vel_ratio = 0.3, 
               double acc_ratio = 0.3, 
               double time_out = 0.0);
    
    // Safety functions
    bool emergencyStop();
    
    // Utility functions
    void printStatus() const;
    
private:
    bool m_connected;
    bool m_has_control;
    std::string m_robot_ip;
};

#endif // DRFL_H

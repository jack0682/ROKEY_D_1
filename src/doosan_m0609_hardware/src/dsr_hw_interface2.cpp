// /*
//  *  Inferfaces for doosan robot controllor 
//   * Author: Minsoo Song(minsoo.song@doosan.com)
//  *
//  * Copyright (c) 2024 Doosan Robotics
//  * Use of this source code is governed by the BSD, see LICENSE
// */
#include <boost/thread/thread.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/bind.hpp>
#include <sstream>
#include <string>
#include <vector>
#include <thread>
#include <yaml-cpp/yaml.h>
#include <fstream>
#include <iostream>
#include <chrono>
#include <unistd.h>     
#include <math.h>

#include "dsr_hardware2/dsr_hw_interface2.h"
#include "dsr_hardware2/util.hpp"
#include "ament_index_cpp/get_package_share_directory.hpp"
#include "../../dsr_common2/include/DRFLEx.h"

using namespace std;
using namespace chrono;
using namespace DRAFramework;

CDRFLEx Drfl;

bool g_bIsEmulatorMode = FALSE;
std::string g_model;
int m_nVersionDRCF;

void* get_drfl(){
	RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"[DRFL address] %p", &Drfl);
	return &Drfl;
}

namespace doosan_m0609_hardware{

CallbackReturn DRHWInterface::on_init(const hardware_interface::HardwareInfo & info)
{
	if (hardware_interface::SystemInterface::on_init(info) != CallbackReturn::SUCCESS)
	{
		return CallbackReturn::ERROR;
	}

	for(auto parameter : info.hardware_parameters) {
		if("host" == parameter.first) {
			RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"), "host : %s", parameter.second.c_str());
			drcf_ip = parameter.second;
		} else if("rt_host" == parameter.first) {
			RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"), "rt_host : %s", parameter.second.c_str());
			drcf_rt_ip = parameter.second;
		} else if("port" == parameter.first) {
			RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"), "port : %s", parameter.second.c_str());
			drcf_port = std::stoi(parameter.second);
		} else if("mode" == parameter.first) {
			RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"), "mode : %s", parameter.second.c_str());
			mode = parameter.second;
		} else if("model" == parameter.first) {
			RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"), "model : %s", parameter.second.c_str());
			model = parameter.second;
			g_model = model;
		} else {
			RCLCPP_WARN(rclcpp::get_logger("dsr_hw_interface2"), "Unexpected Parameter....\
			 	key : %s, value : %s",parameter.first.c_str(), parameter.second.c_str());
		}
	}
	if(info.hardware_parameters.size() != 5) {
		RCLCPP_WARN(rclcpp::get_logger("dsr_hw_interface2"), "Unexpected Parameter Size ...");
		return CallbackReturn::ERROR;
	}

	// robot has 6 joints and 2 interfaces
	joint_position_.assign(6, 0);
	joint_velocities_.assign(6, 0);
	joint_position_command_.assign(6, 0);
	joint_velocities_command_.assign(6, 0);

	if(6 != info_.joints.size()) {
		RCLCPP_ERROR(rclcpp::get_logger("dsr_hw_interface2"), 
				"[on_init] Hardware joint size : %zu, expected : 6", info.joints.size());
		return CallbackReturn::ERROR;
	}
	RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"), 
					"[on_init] Hardware name : %s, type : %s, class type : %s",
					info_.name.c_str(), info_.type.c_str(), info_.hardware_class_type.c_str());

	for (const auto & joint : info_.joints)
	{
		RCLCPP_DEBUG(rclcpp::get_logger("dsr_hw_interface2"), 
			"[on_init] joint name : %s, type : %s,",
			joint.name.c_str(), joint.type.c_str());
		for (const auto & interface : joint.state_interfaces)
		{
			RCLCPP_DEBUG(rclcpp::get_logger("dsr_hw_interface2"), 
					"[on_init] joint state interface name : %s ", 
					interface.name.c_str());
			if(interface.name == "effort") {
				RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"), 
					"[on_init] Not Implemented effort interface.. ignored");
				continue;
			}
			joint_interfaces[interface.name].push_back(joint.name);
		}
		for (const auto & interface : joint.command_interfaces)
		{
			RCLCPP_DEBUG(rclcpp::get_logger("dsr_hw_interface2"), 
					"[on_init] joint command_interfaces name : %s ", 
					interface.name.c_str());
				if(interface.name == "effort") {
					RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"), 
							"[on_init] Not Implemented effort interface.. ignored");
					continue;
				}
			joint_comm_interfaces[interface.name].push_back(joint.name);
		}
	}


//-----------------------------------------------------------------------------------------------------
	RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"_______________________________________________\n");
	RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"    INITAILIZE");
	RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"_______________________________________________\n");

	// Try to connect to DRCF for 10 (20 * 0.5) sec. 
	bool is_connected = false;
	for (size_t retry = 0; retry < 20; ++retry) {
			is_connected = Drfl.open_connection(drcf_ip, drcf_port);
			if(!is_connected) {
					RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"Connecting failure.. retry...");
					std::this_thread::sleep_for(std::chrono::milliseconds(500));
					continue;
			}
			RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"Connected to DRCF");
			break;
	}
	if(!is_connected)
	{
			RCLCPP_ERROR(rclcpp::get_logger("dsr_hw_interface2"),"    DSRInterface::init() DRCF connecting ERROR!!!");
			return CallbackReturn::ERROR;
	}
	// Check whether DRCF loaded successfully for 10 sec..
	// Even thought, the server connected,
	// The drcf could still be in the booting process. 
	// Need to make sure it loaded successfully.
	// By making sure AUTHORITY and STANDBY_STATE.
	static bool get_control_access = false;
	static bool is_standby = false;
	Drfl.set_on_monitoring_access_control([](const MONITORING_ACCESS_CONTROL access) {
		RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"AUTHORITY : %s", to_str(access).c_str());
		if(MONITORING_ACCESS_CONTROL_GRANT == access) {
			RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"INITIAL AUTHORITY GRANTED !!!");
			get_control_access = true;
			is_standby = false; // previous standby state before getting authority is definitely useless.
		}
		if(MONITORING_ACCESS_CONTROL_LOSS == access) {
			get_control_access = false;
			is_standby = false; // previous standby state after losing authority is definitely useless.
		}
	});
	Drfl.set_on_monitoring_state([](const ROBOT_STATE state) {
		RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"ROBOT_STATE : %s", to_str(state).c_str());
		if(STATE_STANDBY == state) {
			RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"INITIAL STATE_STANDBY !!!");
			is_standby = true;
		}else {
			is_standby = false;
		}
	});
	for (size_t retry = 0; retry < 10; ++retry, std::this_thread::sleep_for(std::chrono::milliseconds(1000))) {
		if(!get_control_access) {
			Drfl.ManageAccessControl(MANAGE_ACCESS_CONTROL_FORCE_REQUEST);
			RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"INITIAL MANAGE_ACCESS_CONTROL_FORCE_REQUEST called");
			continue;
		}
		if(!is_standby) {
			Drfl.set_robot_control(CONTROL_SERVO_ON);
			RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"INITIAL CONTROL_SERVO_ON called");
			continue;
		}
		if(get_control_access && is_standby)   break;
	}
	if(!(get_control_access && is_standby)) {
		RCLCPP_ERROR(rclcpp::get_logger("dsr_hw_interface2"),"INITIAL STATE CALL FAILURE !!");
		return CallbackReturn::ERROR;
	}

	RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"_______________________________________________\n"); 
	RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"    OPEN CONNECTION");
	RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"_______________________________________________\n"); 

	//--- connect Emulator ? ------------------------------    
	if(mode == "virtual") {
		g_bIsEmulatorMode = true;
		RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"    Emulator Mode");
	} else {
		g_bIsEmulatorMode = false;
		RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"    Real Robot Mode");
	}

	//--- Get version -------------------------------------            
	SYSTEM_VERSION tSysVerion;
	memset(&tSysVerion, 0, sizeof(tSysVerion));
	assert(Drfl.get_system_version(&tSysVerion));

	//--- Get DRCF version & convert to integer  ----------            
	m_nVersionDRCF = 0; 
	int k=0;
	for(int i=strlen(tSysVerion._szController); i>0; i--)
			if(tSysVerion._szController[i]>='0' && tSysVerion._szController[i]<='9')
					m_nVersionDRCF += (tSysVerion._szController[i]-'0')*pow(10.0,k++);
	if(m_nVersionDRCF < 100000) m_nVersionDRCF += 100000; 
                 
	RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"    DRCF version = %s",tSysVerion._szController);
	RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"    DRFL version = %s",Drfl.get_library_version());
	RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"    m_nVersionDRCF = %d", m_nVersionDRCF);  //ex> M2.40 = 120400, M2.50 = 120500  
	RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"_______________________________________________\n");

	Drfl.setup_monitoring_version(1); //Enabling extended monitoring functions 

	if(Drfl.GetRobotState() != STATE_STANDBY)	{
		RCLCPP_ERROR(rclcpp::get_logger("dsr_hw_interface2"), "Expected State : Stanby, \
			but Actual State : %s ", to_str(Drfl.GetRobotState()).c_str()); 
		return CallbackReturn::ERROR;
	}

	//--- Set Robot mode : MANUAL or AUTO
	if(!Drfl.SetRobotMode(ROBOT_MODE_AUTONOMOUS)) {
		RCLCPP_ERROR(rclcpp::get_logger("dsr_hw_interface2"), "ROBOT_MODE_AUTONOMOUS Setting Failure !!"); 
		return CallbackReturn::ERROR;
	}

	//--- Set Robot mode : virual or real 
	ROBOT_SYSTEM eTargetSystem = ROBOT_SYSTEM_VIRTUAL;
	if(mode == "real") eTargetSystem = ROBOT_SYSTEM_REAL;
	if(!Drfl.SetRobotSystem(eTargetSystem)) {
		RCLCPP_ERROR(rclcpp::get_logger("dsr_hw_interface2"), "SetRobotSystem {%s} Setting Failure !!",
				mode.c_str()); 
		return CallbackReturn::ERROR;
	}

	// Basically, Controller automatically servo-off after elapse time (5 min)
	// Deactivate it.
	Drfl.set_auto_servo_off(0, 5.0);

	// Virtual controller doesn't support real time connection.
	if(mode != "virtual") {
		// Use RT-specific IP if available and DRCF version >= 3.0
		std::string rt_connection_ip = drcf_ip;
		if(m_nVersionDRCF >= 3000000 && !drcf_rt_ip.empty()) {
			rt_connection_ip = drcf_rt_ip;
			RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"), "Using RT IP: %s", rt_connection_ip.c_str());
		}
		
		// Connect RT control with retry mechanism
		bool rt_connected = false;
		for(int retry = 0; retry < 3; retry++) {
			if (Drfl.connect_rt_control(rt_connection_ip)) {
				rt_connected = true;
				break;
			}
			RCLCPP_WARN(rclcpp::get_logger("dsr_hw_interface2"), "RT control connection attempt %d failed, retrying...", retry+1);
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
		
		if (!rt_connected) {
			RCLCPP_ERROR(rclcpp::get_logger("dsr_hw_interface2"), "Unable to connect RT control stream after 3 attempts");
			return CallbackReturn::FAILURE;
		}
		RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"), "Successfully connected RT control stream");
		
		// Set RT control parameters
		const std::string version   = "v1.0";
		const float       period    = 0.001;  // 1ms for real-time
		const int         losscount = 4;      // Allow 4 missed packets
		if (!Drfl.set_rt_control_output(version, period, losscount)) {
			RCLCPP_ERROR(rclcpp::get_logger("dsr_hw_interface2"), "Failed to set RT control output parameters");
			Drfl.disconnect_rt_control();
			return CallbackReturn::FAILURE;
		}

		// Start RT control
		if (!Drfl.start_rt_control()) {
			RCLCPP_ERROR(rclcpp::get_logger("dsr_hw_interface2"), "Unable to start RT control");
			Drfl.disconnect_rt_control();
			return CallbackReturn::FAILURE;
		}

		RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"), "RT control started successfully");
		
		// Set conservative velocity and acceleration limits for safety
		RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"), "Setting conservative velocity and acceleration limits for real robot");
		float vel_limit[6] = {50.0f, 50.0f, 50.0f, 50.0f, 50.0f, 50.0f};  // Reduced from 70
		float acc_limit[6] = {50.0f, 50.0f, 50.0f, 50.0f, 50.0f, 50.0f};  // Conservative limits
		
		if (!Drfl.set_velj_rt(vel_limit)) {
			RCLCPP_ERROR(rclcpp::get_logger("dsr_hw_interface2"), "Failed to set velocity limits");
			return CallbackReturn::ERROR;
		}
		if (!Drfl.set_accj_rt(acc_limit)) {
			RCLCPP_ERROR(rclcpp::get_logger("dsr_hw_interface2"), "Failed to set acceleration limits");
			return CallbackReturn::ERROR;
		}
		
		RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"), "RT control setup completed successfully");
	}

	Drfl.set_safety_mode(SAFETY_MODE_AUTONOMOUS,SAFETY_MODE_EVENT_MOVE);
	return CallbackReturn::SUCCESS;
}

std::vector<hardware_interface::StateInterface> DRHWInterface::export_state_interfaces()
{
  std::vector<hardware_interface::StateInterface> state_interfaces;

	for(size_t i=0; i<joint_interfaces["position"].size(); i++) {
		state_interfaces.emplace_back(joint_interfaces["position"][i], "position", &joint_position_[i]);
	}
	// TODO(songms, leeminju) support velocity control.
    for(size_t i=0; i<joint_interfaces["velocity"].size(); i++) {
		state_interfaces.emplace_back(joint_interfaces["velocity"][i], "velocity", &joint_velocities_[i]);
	}
	// TODO(songms, leeminju) support effort control.
	for(size_t i=0; i<joint_interfaces["effort"].size(); i++) {
		state_interfaces.emplace_back(joint_interfaces["effort"][i], "effort", &joint_effort_[i]);
	}
  return state_interfaces;
}

std::vector<hardware_interface::CommandInterface> DRHWInterface::export_command_interfaces()
{
  std::vector<hardware_interface::CommandInterface> command_interfaces;
    pre_joint_position_command_ = joint_position_command_;
	for(size_t i=0; i<joint_comm_interfaces["position"].size(); i++) {
		command_interfaces.emplace_back(joint_comm_interfaces["position"][i], "position", &joint_position_command_[i]);
	}
	for(size_t i=0; i<joint_comm_interfaces["velocity"].size(); i++) {
		command_interfaces.emplace_back(joint_comm_interfaces["velocity"][i], "velocity", &joint_velocities_command_[i]);
	}
	// TODO(songms, leeminju) support effort control.
	for(size_t i=0; i<joint_comm_interfaces["effort"].size(); i++) {
		command_interfaces.emplace_back(joint_comm_interfaces["effort"][i], "effort", &joint_effort_command_[i]);
	}
  return command_interfaces;
}


return_type DRHWInterface::read(const rclcpp::Time & /*time*/, const rclcpp::Duration & /*period*/)
{
	if(mode == "real") {
		// Check if RT control is still active
		if(Drfl.GetRobotState() != STATE_STANDBY) {
			RCLCPP_WARN_THROTTLE(rclcpp::get_logger("dsr_hw_interface2"), 
				*rclcpp::Clock{RCL_ROS_TIME}.get_clock(), 5000,
				"Robot not in STANDBY state: %s", to_str(Drfl.GetRobotState()).c_str());
			// Still try to read data but warn user
		}
		
		const LPRT_OUTPUT_DATA_LIST data = Drfl.read_data_rt();
		if(data == nullptr) {
			RCLCPP_ERROR_THROTTLE(rclcpp::get_logger("dsr_hw_interface2"),
				*rclcpp::Clock{RCL_ROS_TIME}.get_clock(), 1000,
				"Failed to read RT data from robot");
			// Keep last known positions instead of returning error
			return return_type::OK;
		}
		
		// Validate joint data before using
		bool data_valid = true;
		for(int i=0; i<6; i++) {
			// Check for reasonable joint position values (-360 to 360 degrees)
			if(abs(data->actual_joint_position[i]) > 360.0) {
				RCLCPP_WARN_THROTTLE(rclcpp::get_logger("dsr_hw_interface2"),
					*rclcpp::Clock{RCL_ROS_TIME}.get_clock(), 5000,
					"Invalid joint %d position: %.2f degrees", i+1, data->actual_joint_position[i]);
				data_valid = false;
				break;
			}
		}
		
		if(data_valid) {
			for(int i=0;i<6;i++) {
				joint_position_[i] = static_cast<float>(data->actual_joint_position[i] * (M_PI / 180.0f));
				joint_velocities_[i] = static_cast<float>(data->actual_joint_velocity[i] * (M_PI / 180.0f));
			}
		} else {
			// Keep last known good values
			RCLCPP_WARN(rclcpp::get_logger("dsr_hw_interface2"), "Using last known joint positions due to invalid data");
		}
	}else if(mode == "virtual") {
		LPROBOT_POSE pose = Drfl.GetCurrentPose();
		if(nullptr == pose) {
			RCLCPP_WARN(rclcpp::get_logger("dsr_hw_interface2"),
									"[read] GetCurrentPose retrieves nullptr");
			return return_type::ERROR; //? what effection of this to control node 
		}
		for(int i=0;i<6;i++){
			joint_position_[i] = deg2rad(pose->_fPosition[i]);
		}
	}else {
		RCLCPP_ERROR(rclcpp::get_logger("dsr_hw_interface2"), 
				"'mode' is neither 'real' nor 'virtual.'" );
	}
	// RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"), "[READ] joint_position_  : {%.3f, %.3f, %.3f, %.3f, %.3f, %.3f}"
	//     ,joint_position_[0]
	//     ,joint_position_[1]
	//     ,joint_position_[2]
	//     ,joint_position_[3]
	//     ,joint_position_[4]
	//     ,joint_position_[5]);
  return return_type::OK;
}

bool positionCommandRunning(const std::vector<double>& lhs, const std::vector<double>& rhs) {
	double var = 0;
	for(size_t i=0; i<lhs.size(); i++) {
		var += abs(lhs[i] - rhs[i]);
	}
	return var >= 0.0001;
}

vector<vector<float>> joint_position_commands;
return_type DRHWInterface::write(const rclcpp::Time &, const rclcpp::Duration &dt)
{
	// RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"), "[WRITE] dt  : %.3f", float(dt.seconds()) );
	// RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"), "[WRITE] joint_position_command_  : {%.3f, %.3f, %.3f, %.3f, %.3f, %.3f}"
	//         ,joint_position_command_[0]
	//         ,joint_position_command_[1]
	//         ,joint_position_command_[2]
	//         ,joint_position_command_[3]
	//         ,joint_position_command_[4]
	//         ,joint_position_command_[5]);
	// RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"), "[WRITE] joint_velocities_command_  : {%.3f, %.3f, %.3f, %.3f, %.3f, %.3f}"
	//         ,joint_velocities_command_[0]
	//         ,joint_velocities_command_[1]
	//         ,joint_velocities_command_[2]
	//         ,joint_velocities_command_[3]
	//         ,joint_velocities_command_[4]
	//         ,joint_velocities_command_[5]);
	static bool idle = false;
	// TODO: this seems to be a workaround. refer to hardware design of 'prepare_command_mode_switch'
	if(positionCommandRunning(pre_joint_position_command_, joint_position_command_)) {
		if(true == idle) {
			// This is workaround to overcome issues :
			// move_joint (drfl) API internally sent safety_off right after moving. 
			// which occurs problems like :
			// "move_joint service command -> trajectory command => error ! "
			Drfl.set_safety_mode(SAFETY_MODE_AUTONOMOUS,SAFETY_MODE_EVENT_MOVE);
			idle = false;
		}

		float pos[6];
		float targetVel[6];
		for(int i=0;i<6;i++) {
			pos[i] = static_cast<float>(joint_position_command_[i] * (180.0f / M_PI));
			targetVel[i] = static_cast<float>(joint_velocities_command_[i] * (180.0f / M_PI));
		}
		if(mode == "real") {
			// Safety checks before sending RT command
			bool safe_to_move = true;
			
			// Check if any joint position command is drastically different
			for(int i = 0; i < 6; i++) {
				float pos_diff = abs(pos[i] - static_cast<float>(joint_position_[i] * (180.0f / M_PI)));
				if(pos_diff > 30.0f) {  // More than 30 degrees difference
					RCLCPP_WARN(rclcpp::get_logger("dsr_hw_interface2"), 
						"Large joint %d position change detected: %.2f degrees. Limiting to 30 deg.", i+1, pos_diff);
					// Limit the change to maximum 30 degrees
					float current_deg = static_cast<float>(joint_position_[i] * (180.0f / M_PI));
					if(pos[i] > current_deg) {
						pos[i] = current_deg + 30.0f;
					} else {
						pos[i] = current_deg - 30.0f;
					}
				}
			}
			
			// Limit target velocities for safety
			for(int i = 0; i < 6; i++) {
				if(abs(targetVel[i]) > 45.0f) {  // Limit to 45 deg/s
					targetVel[i] = (targetVel[i] > 0) ? 45.0f : -45.0f;
				}
			}
			
			// Use conservative timing with margin for non-RT systems
			float time_margin = 2.0f; // Increased margin for safety
			float execution_time = float(dt.seconds() * time_margin);
			
			// Ensure minimum execution time for safety
			if(execution_time < 0.02f) { // Minimum 20ms
				execution_time = 0.02f;
			}
			
			float acc[6] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}; // Use controller's internal profile
			
			// Send RT servo command
			if(!Drfl.servoj_rt(pos, targetVel, acc, execution_time)) {
				RCLCPP_ERROR(rclcpp::get_logger("dsr_hw_interface2"), "Failed to send RT servo command");
				// Don't return error immediately, just log and continue
			}
		}
		else { // "virtual"
			float target_vel_acc[6] = {70.0f, 70.0f, 70.0f, 70.0f, 70.0f, 70.0f};
			Drfl.amovej(pos, target_vel_acc, target_vel_acc); // Workaround. needed updated.
		}
		pre_joint_position_command_ = joint_position_command_;
		return return_type::OK;
	}
	idle = true;
	pre_joint_position_command_ = joint_position_command_;
	return return_type::OK;
}

DRHWInterface::~DRHWInterface()
{
	Drfl.close_connection();
	Drfl.disconnect_rt_control();

	RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"_______________________________________________\n"); 
	RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"    CONNECTION IS CLOSED");
	RCLCPP_INFO(rclcpp::get_logger("dsr_hw_interface2"),"_______________________________________________\n"); 
}

}

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(
  doosan_m0609_hardware::DRHWInterface, hardware_interface::SystemInterface)

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/msg/detail/robot_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotState_b_actual_encorder_reset_signal
{
public:
  explicit Init_RobotState_b_actual_encorder_reset_signal(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::msg::RobotState b_actual_encorder_reset_signal(::doosan_m0609_msgs::msg::RobotState::_b_actual_encorder_reset_signal_type arg)
  {
    msg_.b_actual_encorder_reset_signal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_i_actual_encorder_raw_data
{
public:
  explicit Init_RobotState_i_actual_encorder_raw_data(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_b_actual_encorder_reset_signal i_actual_encorder_raw_data(::doosan_m0609_msgs::msg::RobotState::_i_actual_encorder_raw_data_type arg)
  {
    msg_.i_actual_encorder_raw_data = std::move(arg);
    return Init_RobotState_b_actual_encorder_reset_signal(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_b_actual_encorder_strove_signal
{
public:
  explicit Init_RobotState_b_actual_encorder_strove_signal(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_i_actual_encorder_raw_data b_actual_encorder_strove_signal(::doosan_m0609_msgs::msg::RobotState::_b_actual_encorder_strove_signal_type arg)
  {
    msg_.b_actual_encorder_strove_signal = std::move(arg);
    return Init_RobotState_i_actual_encorder_raw_data(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_i_target_analog_output_type
{
public:
  explicit Init_RobotState_i_target_analog_output_type(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_b_actual_encorder_strove_signal i_target_analog_output_type(::doosan_m0609_msgs::msg::RobotState::_i_target_analog_output_type_type arg)
  {
    msg_.i_target_analog_output_type = std::move(arg);
    return Init_RobotState_b_actual_encorder_strove_signal(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_f_target_analog_output
{
public:
  explicit Init_RobotState_f_target_analog_output(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_i_target_analog_output_type f_target_analog_output(::doosan_m0609_msgs::msg::RobotState::_f_target_analog_output_type arg)
  {
    msg_.f_target_analog_output = std::move(arg);
    return Init_RobotState_i_target_analog_output_type(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_i_actual_analog_input_type
{
public:
  explicit Init_RobotState_i_actual_analog_input_type(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_f_target_analog_output i_actual_analog_input_type(::doosan_m0609_msgs::msg::RobotState::_i_actual_analog_input_type_type arg)
  {
    msg_.i_actual_analog_input_type = std::move(arg);
    return Init_RobotState_f_target_analog_output(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_b_actual_safety_input
{
public:
  explicit Init_RobotState_b_actual_safety_input(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_i_actual_analog_input_type b_actual_safety_input(::doosan_m0609_msgs::msg::RobotState::_b_actual_safety_input_type arg)
  {
    msg_.b_actual_safety_input = std::move(arg);
    return Init_RobotState_i_actual_analog_input_type(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_b_actual_switch_input
{
public:
  explicit Init_RobotState_b_actual_switch_input(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_b_actual_safety_input b_actual_switch_input(::doosan_m0609_msgs::msg::RobotState::_b_actual_switch_input_type arg)
  {
    msg_.b_actual_switch_input = std::move(arg);
    return Init_RobotState_b_actual_safety_input(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_f_actual_analog_input
{
public:
  explicit Init_RobotState_f_actual_analog_input(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_b_actual_switch_input f_actual_analog_input(::doosan_m0609_msgs::msg::RobotState::_f_actual_analog_input_type arg)
  {
    msg_.f_actual_analog_input = std::move(arg);
    return Init_RobotState_b_actual_switch_input(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_f_rotation_matrix_user
{
public:
  explicit Init_RobotState_f_rotation_matrix_user(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_f_actual_analog_input f_rotation_matrix_user(::doosan_m0609_msgs::msg::RobotState::_f_rotation_matrix_user_type arg)
  {
    msg_.f_rotation_matrix_user = std::move(arg);
    return Init_RobotState_f_actual_analog_input(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_f_target_vel_user
{
public:
  explicit Init_RobotState_f_target_vel_user(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_f_rotation_matrix_user f_target_vel_user(::doosan_m0609_msgs::msg::RobotState::_f_target_vel_user_type arg)
  {
    msg_.f_target_vel_user = std::move(arg);
    return Init_RobotState_f_rotation_matrix_user(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_f_target_pos_user
{
public:
  explicit Init_RobotState_f_target_pos_user(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_f_target_vel_user f_target_pos_user(::doosan_m0609_msgs::msg::RobotState::_f_target_pos_user_type arg)
  {
    msg_.f_target_pos_user = std::move(arg);
    return Init_RobotState_f_target_vel_user(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_f_user_ext_task_torque
{
public:
  explicit Init_RobotState_f_user_ext_task_torque(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_f_target_pos_user f_user_ext_task_torque(::doosan_m0609_msgs::msg::RobotState::_f_user_ext_task_torque_type arg)
  {
    msg_.f_user_ext_task_torque = std::move(arg);
    return Init_RobotState_f_target_pos_user(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_f_current_vel_user
{
public:
  explicit Init_RobotState_f_current_vel_user(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_f_user_ext_task_torque f_current_vel_user(::doosan_m0609_msgs::msg::RobotState::_f_current_vel_user_type arg)
  {
    msg_.f_current_vel_user = std::move(arg);
    return Init_RobotState_f_user_ext_task_torque(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_f_current_pos_user
{
public:
  explicit Init_RobotState_f_current_pos_user(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_f_current_vel_user f_current_pos_user(::doosan_m0609_msgs::msg::RobotState::_f_current_pos_user_type arg)
  {
    msg_.f_current_pos_user = std::move(arg);
    return Init_RobotState_f_current_vel_user(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_i_coord_ref
{
public:
  explicit Init_RobotState_i_coord_ref(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_f_current_pos_user i_coord_ref(::doosan_m0609_msgs::msg::RobotState::_i_coord_ref_type arg)
  {
    msg_.i_coord_ref = std::move(arg);
    return Init_RobotState_f_current_pos_user(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_i_actual_user_coord_num
{
public:
  explicit Init_RobotState_i_actual_user_coord_num(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_i_coord_ref i_actual_user_coord_num(::doosan_m0609_msgs::msg::RobotState::_i_actual_user_coord_num_type arg)
  {
    msg_.i_actual_user_coord_num = std::move(arg);
    return Init_RobotState_i_coord_ref(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_f_rotation_matrix_world
{
public:
  explicit Init_RobotState_f_rotation_matrix_world(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_i_actual_user_coord_num f_rotation_matrix_world(::doosan_m0609_msgs::msg::RobotState::_f_rotation_matrix_world_type arg)
  {
    msg_.f_rotation_matrix_world = std::move(arg);
    return Init_RobotState_i_actual_user_coord_num(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_f_target_vel_world
{
public:
  explicit Init_RobotState_f_target_vel_world(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_f_rotation_matrix_world f_target_vel_world(::doosan_m0609_msgs::msg::RobotState::_f_target_vel_world_type arg)
  {
    msg_.f_target_vel_world = std::move(arg);
    return Init_RobotState_f_rotation_matrix_world(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_f_target_pos_world
{
public:
  explicit Init_RobotState_f_target_pos_world(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_f_target_vel_world f_target_pos_world(::doosan_m0609_msgs::msg::RobotState::_f_target_pos_world_type arg)
  {
    msg_.f_target_pos_world = std::move(arg);
    return Init_RobotState_f_target_vel_world(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_f_world_ext_target_torque
{
public:
  explicit Init_RobotState_f_world_ext_target_torque(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_f_target_pos_world f_world_ext_target_torque(::doosan_m0609_msgs::msg::RobotState::_f_world_ext_target_torque_type arg)
  {
    msg_.f_world_ext_target_torque = std::move(arg);
    return Init_RobotState_f_target_pos_world(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_f_current_vel_world
{
public:
  explicit Init_RobotState_f_current_vel_world(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_f_world_ext_target_torque f_current_vel_world(::doosan_m0609_msgs::msg::RobotState::_f_current_vel_world_type arg)
  {
    msg_.f_current_vel_world = std::move(arg);
    return Init_RobotState_f_world_ext_target_torque(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_f_current_pos_world
{
public:
  explicit Init_RobotState_f_current_pos_world(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_f_current_vel_world f_current_pos_world(::doosan_m0609_msgs::msg::RobotState::_f_current_pos_world_type arg)
  {
    msg_.f_current_pos_world = std::move(arg);
    return Init_RobotState_f_current_vel_world(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_f_actual_w2b
{
public:
  explicit Init_RobotState_f_actual_w2b(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_f_current_pos_world f_actual_w2b(::doosan_m0609_msgs::msg::RobotState::_f_actual_w2b_type arg)
  {
    msg_.f_actual_w2b = std::move(arg);
    return Init_RobotState_f_current_pos_world(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_disconnected
{
public:
  explicit Init_RobotState_disconnected(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_f_actual_w2b disconnected(::doosan_m0609_msgs::msg::RobotState::_disconnected_type arg)
  {
    msg_.disconnected = std::move(arg);
    return Init_RobotState_f_actual_w2b(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_drl_stopped
{
public:
  explicit Init_RobotState_drl_stopped(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_disconnected drl_stopped(::doosan_m0609_msgs::msg::RobotState::_drl_stopped_type arg)
  {
    msg_.drl_stopped = std::move(arg);
    return Init_RobotState_disconnected(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_mastering_need
{
public:
  explicit Init_RobotState_mastering_need(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_drl_stopped mastering_need(::doosan_m0609_msgs::msg::RobotState::_mastering_need_type arg)
  {
    msg_.mastering_need = std::move(arg);
    return Init_RobotState_drl_stopped(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_tp_initialized
{
public:
  explicit Init_RobotState_tp_initialized(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_mastering_need tp_initialized(::doosan_m0609_msgs::msg::RobotState::_tp_initialized_type arg)
  {
    msg_.tp_initialized = std::move(arg);
    return Init_RobotState_mastering_need(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_homming_completed
{
public:
  explicit Init_RobotState_homming_completed(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_tp_initialized homming_completed(::doosan_m0609_msgs::msg::RobotState::_homming_completed_type arg)
  {
    msg_.homming_completed = std::move(arg);
    return Init_RobotState_tp_initialized(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_access_control
{
public:
  explicit Init_RobotState_access_control(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_homming_completed access_control(::doosan_m0609_msgs::msg::RobotState::_access_control_type arg)
  {
    msg_.access_control = std::move(arg);
    return Init_RobotState_homming_completed(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_modbus_state
{
public:
  explicit Init_RobotState_modbus_state(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_access_control modbus_state(::doosan_m0609_msgs::msg::RobotState::_modbus_state_type arg)
  {
    msg_.modbus_state = std::move(arg);
    return Init_RobotState_access_control(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_flange_digital_output
{
public:
  explicit Init_RobotState_flange_digital_output(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_modbus_state flange_digital_output(::doosan_m0609_msgs::msg::RobotState::_flange_digital_output_type arg)
  {
    msg_.flange_digital_output = std::move(arg);
    return Init_RobotState_modbus_state(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_flange_digital_input
{
public:
  explicit Init_RobotState_flange_digital_input(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_flange_digital_output flange_digital_input(::doosan_m0609_msgs::msg::RobotState::_flange_digital_input_type arg)
  {
    msg_.flange_digital_input = std::move(arg);
    return Init_RobotState_flange_digital_output(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_ctrlbox_digital_output
{
public:
  explicit Init_RobotState_ctrlbox_digital_output(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_flange_digital_input ctrlbox_digital_output(::doosan_m0609_msgs::msg::RobotState::_ctrlbox_digital_output_type arg)
  {
    msg_.ctrlbox_digital_output = std::move(arg);
    return Init_RobotState_flange_digital_input(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_ctrlbox_digital_input
{
public:
  explicit Init_RobotState_ctrlbox_digital_input(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_ctrlbox_digital_output ctrlbox_digital_input(::doosan_m0609_msgs::msg::RobotState::_ctrlbox_digital_input_type arg)
  {
    msg_.ctrlbox_digital_input = std::move(arg);
    return Init_RobotState_ctrlbox_digital_output(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_rotation_matrix
{
public:
  explicit Init_RobotState_rotation_matrix(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_ctrlbox_digital_input rotation_matrix(::doosan_m0609_msgs::msg::RobotState::_rotation_matrix_type arg)
  {
    msg_.rotation_matrix = std::move(arg);
    return Init_RobotState_ctrlbox_digital_input(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_actual_bt
{
public:
  explicit Init_RobotState_actual_bt(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_rotation_matrix actual_bt(::doosan_m0609_msgs::msg::RobotState::_actual_bt_type arg)
  {
    msg_.actual_bt = std::move(arg);
    return Init_RobotState_rotation_matrix(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_sync_time
{
public:
  explicit Init_RobotState_sync_time(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_actual_bt sync_time(::doosan_m0609_msgs::msg::RobotState::_sync_time_type arg)
  {
    msg_.sync_time = std::move(arg);
    return Init_RobotState_actual_bt(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_solution_space
{
public:
  explicit Init_RobotState_solution_space(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_sync_time solution_space(::doosan_m0609_msgs::msg::RobotState::_solution_space_type arg)
  {
    msg_.solution_space = std::move(arg);
    return Init_RobotState_sync_time(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_actual_mt
{
public:
  explicit Init_RobotState_actual_mt(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_solution_space actual_mt(::doosan_m0609_msgs::msg::RobotState::_actual_mt_type arg)
  {
    msg_.actual_mt = std::move(arg);
    return Init_RobotState_solution_space(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_actual_mc
{
public:
  explicit Init_RobotState_actual_mc(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_actual_mt actual_mc(::doosan_m0609_msgs::msg::RobotState::_actual_mc_type arg)
  {
    msg_.actual_mc = std::move(arg);
    return Init_RobotState_actual_mt(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_actual_bk
{
public:
  explicit Init_RobotState_actual_bk(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_actual_mc actual_bk(::doosan_m0609_msgs::msg::RobotState::_actual_bk_type arg)
  {
    msg_.actual_bk = std::move(arg);
    return Init_RobotState_actual_mc(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_actual_ett
{
public:
  explicit Init_RobotState_actual_ett(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_actual_bk actual_ett(::doosan_m0609_msgs::msg::RobotState::_actual_ett_type arg)
  {
    msg_.actual_ett = std::move(arg);
    return Init_RobotState_actual_bk(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_actual_ejt
{
public:
  explicit Init_RobotState_actual_ejt(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_actual_ett actual_ejt(::doosan_m0609_msgs::msg::RobotState::_actual_ejt_type arg)
  {
    msg_.actual_ejt = std::move(arg);
    return Init_RobotState_actual_ett(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_actual_jts
{
public:
  explicit Init_RobotState_actual_jts(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_actual_ejt actual_jts(::doosan_m0609_msgs::msg::RobotState::_actual_jts_type arg)
  {
    msg_.actual_jts = std::move(arg);
    return Init_RobotState_actual_ejt(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_dynamic_tor
{
public:
  explicit Init_RobotState_dynamic_tor(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_actual_jts dynamic_tor(::doosan_m0609_msgs::msg::RobotState::_dynamic_tor_type arg)
  {
    msg_.dynamic_tor = std::move(arg);
    return Init_RobotState_actual_jts(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_target_posx
{
public:
  explicit Init_RobotState_target_posx(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_dynamic_tor target_posx(::doosan_m0609_msgs::msg::RobotState::_target_posx_type arg)
  {
    msg_.target_posx = std::move(arg);
    return Init_RobotState_dynamic_tor(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_target_velx
{
public:
  explicit Init_RobotState_target_velx(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_target_posx target_velx(::doosan_m0609_msgs::msg::RobotState::_target_velx_type arg)
  {
    msg_.target_velx = std::move(arg);
    return Init_RobotState_target_posx(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_task_err
{
public:
  explicit Init_RobotState_task_err(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_target_velx task_err(::doosan_m0609_msgs::msg::RobotState::_task_err_type arg)
  {
    msg_.task_err = std::move(arg);
    return Init_RobotState_target_velx(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_current_velx
{
public:
  explicit Init_RobotState_current_velx(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_task_err current_velx(::doosan_m0609_msgs::msg::RobotState::_current_velx_type arg)
  {
    msg_.current_velx = std::move(arg);
    return Init_RobotState_task_err(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_current_tool_posx
{
public:
  explicit Init_RobotState_current_tool_posx(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_current_velx current_tool_posx(::doosan_m0609_msgs::msg::RobotState::_current_tool_posx_type arg)
  {
    msg_.current_tool_posx = std::move(arg);
    return Init_RobotState_current_velx(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_current_posx
{
public:
  explicit Init_RobotState_current_posx(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_current_tool_posx current_posx(::doosan_m0609_msgs::msg::RobotState::_current_posx_type arg)
  {
    msg_.current_posx = std::move(arg);
    return Init_RobotState_current_tool_posx(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_target_velj
{
public:
  explicit Init_RobotState_target_velj(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_current_posx target_velj(::doosan_m0609_msgs::msg::RobotState::_target_velj_type arg)
  {
    msg_.target_velj = std::move(arg);
    return Init_RobotState_current_posx(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_target_posj
{
public:
  explicit Init_RobotState_target_posj(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_target_velj target_posj(::doosan_m0609_msgs::msg::RobotState::_target_posj_type arg)
  {
    msg_.target_posj = std::move(arg);
    return Init_RobotState_target_velj(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_joint_err
{
public:
  explicit Init_RobotState_joint_err(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_target_posj joint_err(::doosan_m0609_msgs::msg::RobotState::_joint_err_type arg)
  {
    msg_.joint_err = std::move(arg);
    return Init_RobotState_target_posj(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_joint_abs
{
public:
  explicit Init_RobotState_joint_abs(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_joint_err joint_abs(::doosan_m0609_msgs::msg::RobotState::_joint_abs_type arg)
  {
    msg_.joint_abs = std::move(arg);
    return Init_RobotState_joint_err(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_current_velj
{
public:
  explicit Init_RobotState_current_velj(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_joint_abs current_velj(::doosan_m0609_msgs::msg::RobotState::_current_velj_type arg)
  {
    msg_.current_velj = std::move(arg);
    return Init_RobotState_joint_abs(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_current_posj
{
public:
  explicit Init_RobotState_current_posj(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_current_velj current_posj(::doosan_m0609_msgs::msg::RobotState::_current_posj_type arg)
  {
    msg_.current_posj = std::move(arg);
    return Init_RobotState_current_velj(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_actual_space
{
public:
  explicit Init_RobotState_actual_space(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_current_posj actual_space(::doosan_m0609_msgs::msg::RobotState::_actual_space_type arg)
  {
    msg_.actual_space = std::move(arg);
    return Init_RobotState_current_posj(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_actual_mode
{
public:
  explicit Init_RobotState_actual_mode(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_actual_space actual_mode(::doosan_m0609_msgs::msg::RobotState::_actual_mode_type arg)
  {
    msg_.actual_mode = std::move(arg);
    return Init_RobotState_actual_space(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_robot_state_str
{
public:
  explicit Init_RobotState_robot_state_str(::doosan_m0609_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_actual_mode robot_state_str(::doosan_m0609_msgs::msg::RobotState::_robot_state_str_type arg)
  {
    msg_.robot_state_str = std::move(arg);
    return Init_RobotState_actual_mode(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

class Init_RobotState_robot_state
{
public:
  Init_RobotState_robot_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotState_robot_state_str robot_state(::doosan_m0609_msgs::msg::RobotState::_robot_state_type arg)
  {
    msg_.robot_state = std::move(arg);
    return Init_RobotState_robot_state_str(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::msg::RobotState>()
{
  return doosan_m0609_msgs::msg::builder::Init_RobotState_robot_state();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_

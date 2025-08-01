// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_controller:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_CONTROLLER__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_
#define DOOSAN_M0609_CONTROLLER__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_controller/msg/detail/robot_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_controller
{

namespace msg
{

namespace builder
{

class Init_RobotStatus_error_message
{
public:
  explicit Init_RobotStatus_error_message(::doosan_m0609_controller::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_controller::msg::RobotStatus error_message(::doosan_m0609_controller::msg::RobotStatus::_error_message_type arg)
  {
    msg_.error_message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_controller::msg::RobotStatus msg_;
};

class Init_RobotStatus_robot_state
{
public:
  explicit Init_RobotStatus_robot_state(::doosan_m0609_controller::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_error_message robot_state(::doosan_m0609_controller::msg::RobotStatus::_robot_state_type arg)
  {
    msg_.robot_state = std::move(arg);
    return Init_RobotStatus_error_message(msg_);
  }

private:
  ::doosan_m0609_controller::msg::RobotStatus msg_;
};

class Init_RobotStatus_has_control_authority
{
public:
  explicit Init_RobotStatus_has_control_authority(::doosan_m0609_controller::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_robot_state has_control_authority(::doosan_m0609_controller::msg::RobotStatus::_has_control_authority_type arg)
  {
    msg_.has_control_authority = std::move(arg);
    return Init_RobotStatus_robot_state(msg_);
  }

private:
  ::doosan_m0609_controller::msg::RobotStatus msg_;
};

class Init_RobotStatus_is_enabled
{
public:
  explicit Init_RobotStatus_is_enabled(::doosan_m0609_controller::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_has_control_authority is_enabled(::doosan_m0609_controller::msg::RobotStatus::_is_enabled_type arg)
  {
    msg_.is_enabled = std::move(arg);
    return Init_RobotStatus_has_control_authority(msg_);
  }

private:
  ::doosan_m0609_controller::msg::RobotStatus msg_;
};

class Init_RobotStatus_is_connected
{
public:
  explicit Init_RobotStatus_is_connected(::doosan_m0609_controller::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_is_enabled is_connected(::doosan_m0609_controller::msg::RobotStatus::_is_connected_type arg)
  {
    msg_.is_connected = std::move(arg);
    return Init_RobotStatus_is_enabled(msg_);
  }

private:
  ::doosan_m0609_controller::msg::RobotStatus msg_;
};

class Init_RobotStatus_header
{
public:
  Init_RobotStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotStatus_is_connected header(::doosan_m0609_controller::msg::RobotStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RobotStatus_is_connected(msg_);
  }

private:
  ::doosan_m0609_controller::msg::RobotStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_controller::msg::RobotStatus>()
{
  return doosan_m0609_controller::msg::builder::Init_RobotStatus_header();
}

}  // namespace doosan_m0609_controller

#endif  // DOOSAN_M0609_CONTROLLER__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_

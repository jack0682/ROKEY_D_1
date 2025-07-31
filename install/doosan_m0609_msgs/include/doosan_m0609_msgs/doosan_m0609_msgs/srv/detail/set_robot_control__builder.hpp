// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/SetRobotControl.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_ROBOT_CONTROL__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_ROBOT_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/set_robot_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetRobotControl_Request_robot_control
{
public:
  Init_SetRobotControl_Request_robot_control()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::SetRobotControl_Request robot_control(::doosan_m0609_msgs::srv::SetRobotControl_Request::_robot_control_type arg)
  {
    msg_.robot_control = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetRobotControl_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetRobotControl_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetRobotControl_Request_robot_control();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetRobotControl_Response_success
{
public:
  Init_SetRobotControl_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::SetRobotControl_Response success(::doosan_m0609_msgs::srv::SetRobotControl_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetRobotControl_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetRobotControl_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetRobotControl_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_ROBOT_CONTROL__BUILDER_HPP_

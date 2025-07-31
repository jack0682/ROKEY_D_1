// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/SetRobotMode.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_ROBOT_MODE__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_ROBOT_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/set_robot_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetRobotMode_Request_robot_mode
{
public:
  Init_SetRobotMode_Request_robot_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::SetRobotMode_Request robot_mode(::doosan_m0609_msgs::srv::SetRobotMode_Request::_robot_mode_type arg)
  {
    msg_.robot_mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetRobotMode_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetRobotMode_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetRobotMode_Request_robot_mode();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetRobotMode_Response_success
{
public:
  Init_SetRobotMode_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::SetRobotMode_Response success(::doosan_m0609_msgs::srv::SetRobotMode_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetRobotMode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetRobotMode_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetRobotMode_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_ROBOT_MODE__BUILDER_HPP_

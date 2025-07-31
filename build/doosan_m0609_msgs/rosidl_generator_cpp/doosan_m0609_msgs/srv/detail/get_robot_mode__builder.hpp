// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/GetRobotMode.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_ROBOT_MODE__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_ROBOT_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/get_robot_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetRobotMode_Request>()
{
  return ::doosan_m0609_msgs::srv::GetRobotMode_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetRobotMode_Response_success
{
public:
  explicit Init_GetRobotMode_Response_success(::doosan_m0609_msgs::srv::GetRobotMode_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::GetRobotMode_Response success(::doosan_m0609_msgs::srv::GetRobotMode_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetRobotMode_Response msg_;
};

class Init_GetRobotMode_Response_robot_mode
{
public:
  Init_GetRobotMode_Response_robot_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetRobotMode_Response_success robot_mode(::doosan_m0609_msgs::srv::GetRobotMode_Response::_robot_mode_type arg)
  {
    msg_.robot_mode = std::move(arg);
    return Init_GetRobotMode_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetRobotMode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetRobotMode_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetRobotMode_Response_robot_mode();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_ROBOT_MODE__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/DrlStart.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__DRL_START__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__DRL_START__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/drl_start__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_DrlStart_Request_code
{
public:
  explicit Init_DrlStart_Request_code(::doosan_m0609_msgs::srv::DrlStart_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::DrlStart_Request code(::doosan_m0609_msgs::srv::DrlStart_Request::_code_type arg)
  {
    msg_.code = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::DrlStart_Request msg_;
};

class Init_DrlStart_Request_robot_system
{
public:
  Init_DrlStart_Request_robot_system()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DrlStart_Request_code robot_system(::doosan_m0609_msgs::srv::DrlStart_Request::_robot_system_type arg)
  {
    msg_.robot_system = std::move(arg);
    return Init_DrlStart_Request_code(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::DrlStart_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::DrlStart_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_DrlStart_Request_robot_system();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_DrlStart_Response_success
{
public:
  Init_DrlStart_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::DrlStart_Response success(::doosan_m0609_msgs::srv::DrlStart_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::DrlStart_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::DrlStart_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_DrlStart_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__DRL_START__BUILDER_HPP_

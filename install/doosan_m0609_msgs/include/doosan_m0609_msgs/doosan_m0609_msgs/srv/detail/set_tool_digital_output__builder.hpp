// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/SetToolDigitalOutput.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_TOOL_DIGITAL_OUTPUT__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_TOOL_DIGITAL_OUTPUT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/set_tool_digital_output__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetToolDigitalOutput_Request_value
{
public:
  explicit Init_SetToolDigitalOutput_Request_value(::doosan_m0609_msgs::srv::SetToolDigitalOutput_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::SetToolDigitalOutput_Request value(::doosan_m0609_msgs::srv::SetToolDigitalOutput_Request::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetToolDigitalOutput_Request msg_;
};

class Init_SetToolDigitalOutput_Request_index
{
public:
  Init_SetToolDigitalOutput_Request_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetToolDigitalOutput_Request_value index(::doosan_m0609_msgs::srv::SetToolDigitalOutput_Request::_index_type arg)
  {
    msg_.index = std::move(arg);
    return Init_SetToolDigitalOutput_Request_value(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetToolDigitalOutput_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetToolDigitalOutput_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetToolDigitalOutput_Request_index();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetToolDigitalOutput_Response_success
{
public:
  Init_SetToolDigitalOutput_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::SetToolDigitalOutput_Response success(::doosan_m0609_msgs::srv::SetToolDigitalOutput_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetToolDigitalOutput_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetToolDigitalOutput_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetToolDigitalOutput_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_TOOL_DIGITAL_OUTPUT__BUILDER_HPP_

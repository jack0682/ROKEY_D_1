// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/SetCtrlBoxAnalogOutput.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_CTRL_BOX_ANALOG_OUTPUT__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_CTRL_BOX_ANALOG_OUTPUT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/set_ctrl_box_analog_output__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetCtrlBoxAnalogOutput_Request_value
{
public:
  explicit Init_SetCtrlBoxAnalogOutput_Request_value(::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutput_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutput_Request value(::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutput_Request::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutput_Request msg_;
};

class Init_SetCtrlBoxAnalogOutput_Request_channel
{
public:
  Init_SetCtrlBoxAnalogOutput_Request_channel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetCtrlBoxAnalogOutput_Request_value channel(::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutput_Request::_channel_type arg)
  {
    msg_.channel = std::move(arg);
    return Init_SetCtrlBoxAnalogOutput_Request_value(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutput_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutput_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetCtrlBoxAnalogOutput_Request_channel();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetCtrlBoxAnalogOutput_Response_success
{
public:
  Init_SetCtrlBoxAnalogOutput_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutput_Response success(::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutput_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutput_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutput_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetCtrlBoxAnalogOutput_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_CTRL_BOX_ANALOG_OUTPUT__BUILDER_HPP_

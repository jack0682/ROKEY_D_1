// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/GetCtrlBoxAnalogInput.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CTRL_BOX_ANALOG_INPUT__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CTRL_BOX_ANALOG_INPUT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/get_ctrl_box_analog_input__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetCtrlBoxAnalogInput_Request_channel
{
public:
  Init_GetCtrlBoxAnalogInput_Request_channel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::GetCtrlBoxAnalogInput_Request channel(::doosan_m0609_msgs::srv::GetCtrlBoxAnalogInput_Request::_channel_type arg)
  {
    msg_.channel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetCtrlBoxAnalogInput_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetCtrlBoxAnalogInput_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetCtrlBoxAnalogInput_Request_channel();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetCtrlBoxAnalogInput_Response_success
{
public:
  explicit Init_GetCtrlBoxAnalogInput_Response_success(::doosan_m0609_msgs::srv::GetCtrlBoxAnalogInput_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::GetCtrlBoxAnalogInput_Response success(::doosan_m0609_msgs::srv::GetCtrlBoxAnalogInput_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetCtrlBoxAnalogInput_Response msg_;
};

class Init_GetCtrlBoxAnalogInput_Response_value
{
public:
  Init_GetCtrlBoxAnalogInput_Response_value()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetCtrlBoxAnalogInput_Response_success value(::doosan_m0609_msgs::srv::GetCtrlBoxAnalogInput_Response::_value_type arg)
  {
    msg_.value = std::move(arg);
    return Init_GetCtrlBoxAnalogInput_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetCtrlBoxAnalogInput_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetCtrlBoxAnalogInput_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetCtrlBoxAnalogInput_Response_value();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CTRL_BOX_ANALOG_INPUT__BUILDER_HPP_

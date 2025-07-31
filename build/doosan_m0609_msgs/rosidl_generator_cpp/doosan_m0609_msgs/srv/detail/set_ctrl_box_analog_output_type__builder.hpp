// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/SetCtrlBoxAnalogOutputType.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_CTRL_BOX_ANALOG_OUTPUT_TYPE__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_CTRL_BOX_ANALOG_OUTPUT_TYPE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/set_ctrl_box_analog_output_type__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetCtrlBoxAnalogOutputType_Request_mode
{
public:
  explicit Init_SetCtrlBoxAnalogOutputType_Request_mode(::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Request mode(::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Request msg_;
};

class Init_SetCtrlBoxAnalogOutputType_Request_channel
{
public:
  Init_SetCtrlBoxAnalogOutputType_Request_channel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetCtrlBoxAnalogOutputType_Request_mode channel(::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Request::_channel_type arg)
  {
    msg_.channel = std::move(arg);
    return Init_SetCtrlBoxAnalogOutputType_Request_mode(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetCtrlBoxAnalogOutputType_Request_channel();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetCtrlBoxAnalogOutputType_Response_success
{
public:
  Init_SetCtrlBoxAnalogOutputType_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Response success(::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetCtrlBoxAnalogOutputType_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_CTRL_BOX_ANALOG_OUTPUT_TYPE__BUILDER_HPP_

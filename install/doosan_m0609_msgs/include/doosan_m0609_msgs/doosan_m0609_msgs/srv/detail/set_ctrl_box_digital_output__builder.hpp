// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/SetCtrlBoxDigitalOutput.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_CTRL_BOX_DIGITAL_OUTPUT__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_CTRL_BOX_DIGITAL_OUTPUT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/set_ctrl_box_digital_output__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetCtrlBoxDigitalOutput_Request_value
{
public:
  explicit Init_SetCtrlBoxDigitalOutput_Request_value(::doosan_m0609_msgs::srv::SetCtrlBoxDigitalOutput_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::SetCtrlBoxDigitalOutput_Request value(::doosan_m0609_msgs::srv::SetCtrlBoxDigitalOutput_Request::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetCtrlBoxDigitalOutput_Request msg_;
};

class Init_SetCtrlBoxDigitalOutput_Request_index
{
public:
  Init_SetCtrlBoxDigitalOutput_Request_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetCtrlBoxDigitalOutput_Request_value index(::doosan_m0609_msgs::srv::SetCtrlBoxDigitalOutput_Request::_index_type arg)
  {
    msg_.index = std::move(arg);
    return Init_SetCtrlBoxDigitalOutput_Request_value(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetCtrlBoxDigitalOutput_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetCtrlBoxDigitalOutput_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetCtrlBoxDigitalOutput_Request_index();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetCtrlBoxDigitalOutput_Response_success
{
public:
  Init_SetCtrlBoxDigitalOutput_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::SetCtrlBoxDigitalOutput_Response success(::doosan_m0609_msgs::srv::SetCtrlBoxDigitalOutput_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetCtrlBoxDigitalOutput_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetCtrlBoxDigitalOutput_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetCtrlBoxDigitalOutput_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_CTRL_BOX_DIGITAL_OUTPUT__BUILDER_HPP_

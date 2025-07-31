// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/GetCtrlBoxDigitalInput.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CTRL_BOX_DIGITAL_INPUT__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CTRL_BOX_DIGITAL_INPUT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/get_ctrl_box_digital_input__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetCtrlBoxDigitalInput_Request_index
{
public:
  Init_GetCtrlBoxDigitalInput_Request_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::GetCtrlBoxDigitalInput_Request index(::doosan_m0609_msgs::srv::GetCtrlBoxDigitalInput_Request::_index_type arg)
  {
    msg_.index = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetCtrlBoxDigitalInput_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetCtrlBoxDigitalInput_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetCtrlBoxDigitalInput_Request_index();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetCtrlBoxDigitalInput_Response_success
{
public:
  explicit Init_GetCtrlBoxDigitalInput_Response_success(::doosan_m0609_msgs::srv::GetCtrlBoxDigitalInput_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::GetCtrlBoxDigitalInput_Response success(::doosan_m0609_msgs::srv::GetCtrlBoxDigitalInput_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetCtrlBoxDigitalInput_Response msg_;
};

class Init_GetCtrlBoxDigitalInput_Response_value
{
public:
  Init_GetCtrlBoxDigitalInput_Response_value()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetCtrlBoxDigitalInput_Response_success value(::doosan_m0609_msgs::srv::GetCtrlBoxDigitalInput_Response::_value_type arg)
  {
    msg_.value = std::move(arg);
    return Init_GetCtrlBoxDigitalInput_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetCtrlBoxDigitalInput_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetCtrlBoxDigitalInput_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetCtrlBoxDigitalInput_Response_value();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CTRL_BOX_DIGITAL_INPUT__BUILDER_HPP_

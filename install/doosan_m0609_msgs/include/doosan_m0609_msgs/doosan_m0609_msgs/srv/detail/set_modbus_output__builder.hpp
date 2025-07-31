// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/SetModbusOutput.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_MODBUS_OUTPUT__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_MODBUS_OUTPUT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/set_modbus_output__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetModbusOutput_Request_value
{
public:
  explicit Init_SetModbusOutput_Request_value(::doosan_m0609_msgs::srv::SetModbusOutput_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::SetModbusOutput_Request value(::doosan_m0609_msgs::srv::SetModbusOutput_Request::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetModbusOutput_Request msg_;
};

class Init_SetModbusOutput_Request_name
{
public:
  Init_SetModbusOutput_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetModbusOutput_Request_value name(::doosan_m0609_msgs::srv::SetModbusOutput_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_SetModbusOutput_Request_value(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetModbusOutput_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetModbusOutput_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetModbusOutput_Request_name();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetModbusOutput_Response_success
{
public:
  Init_SetModbusOutput_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::SetModbusOutput_Response success(::doosan_m0609_msgs::srv::SetModbusOutput_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetModbusOutput_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetModbusOutput_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetModbusOutput_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_MODBUS_OUTPUT__BUILDER_HPP_

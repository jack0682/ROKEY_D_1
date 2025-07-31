// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:msg/ModbusState.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__MODBUS_STATE__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__MODBUS_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/msg/detail/modbus_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace msg
{

namespace builder
{

class Init_ModbusState_modbus_value
{
public:
  explicit Init_ModbusState_modbus_value(::doosan_m0609_msgs::msg::ModbusState & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::msg::ModbusState modbus_value(::doosan_m0609_msgs::msg::ModbusState::_modbus_value_type arg)
  {
    msg_.modbus_value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::ModbusState msg_;
};

class Init_ModbusState_modbus_symbol
{
public:
  Init_ModbusState_modbus_symbol()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ModbusState_modbus_value modbus_symbol(::doosan_m0609_msgs::msg::ModbusState::_modbus_symbol_type arg)
  {
    msg_.modbus_symbol = std::move(arg);
    return Init_ModbusState_modbus_value(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::ModbusState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::msg::ModbusState>()
{
  return doosan_m0609_msgs::msg::builder::Init_ModbusState_modbus_symbol();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__MODBUS_STATE__BUILDER_HPP_

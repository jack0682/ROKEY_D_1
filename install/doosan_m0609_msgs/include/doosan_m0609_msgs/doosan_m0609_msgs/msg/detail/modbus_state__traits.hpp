// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from doosan_m0609_msgs:msg/ModbusState.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__MODBUS_STATE__TRAITS_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__MODBUS_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "doosan_m0609_msgs/msg/detail/modbus_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace doosan_m0609_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ModbusState & msg,
  std::ostream & out)
{
  out << "{";
  // member: modbus_symbol
  {
    out << "modbus_symbol: ";
    rosidl_generator_traits::value_to_yaml(msg.modbus_symbol, out);
    out << ", ";
  }

  // member: modbus_value
  {
    out << "modbus_value: ";
    rosidl_generator_traits::value_to_yaml(msg.modbus_value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ModbusState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: modbus_symbol
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "modbus_symbol: ";
    rosidl_generator_traits::value_to_yaml(msg.modbus_symbol, out);
    out << "\n";
  }

  // member: modbus_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "modbus_value: ";
    rosidl_generator_traits::value_to_yaml(msg.modbus_value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ModbusState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace doosan_m0609_msgs

namespace rosidl_generator_traits
{

[[deprecated("use doosan_m0609_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const doosan_m0609_msgs::msg::ModbusState & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::msg::ModbusState & msg)
{
  return doosan_m0609_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::msg::ModbusState>()
{
  return "doosan_m0609_msgs::msg::ModbusState";
}

template<>
inline const char * name<doosan_m0609_msgs::msg::ModbusState>()
{
  return "doosan_m0609_msgs/msg/ModbusState";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::msg::ModbusState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::msg::ModbusState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<doosan_m0609_msgs::msg::ModbusState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__MODBUS_STATE__TRAITS_HPP_

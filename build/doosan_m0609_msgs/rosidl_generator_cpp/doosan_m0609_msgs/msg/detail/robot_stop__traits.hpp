// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from doosan_m0609_msgs:msg/RobotStop.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_STOP__TRAITS_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_STOP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "doosan_m0609_msgs/msg/detail/robot_stop__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace doosan_m0609_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotStop & msg,
  std::ostream & out)
{
  out << "{";
  // member: stop_mode
  {
    out << "stop_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.stop_mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotStop & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: stop_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stop_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.stop_mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotStop & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::msg::RobotStop & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::msg::RobotStop & msg)
{
  return doosan_m0609_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::msg::RobotStop>()
{
  return "doosan_m0609_msgs::msg::RobotStop";
}

template<>
inline const char * name<doosan_m0609_msgs::msg::RobotStop>()
{
  return "doosan_m0609_msgs/msg/RobotStop";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::msg::RobotStop>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::msg::RobotStop>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::msg::RobotStop>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_STOP__TRAITS_HPP_

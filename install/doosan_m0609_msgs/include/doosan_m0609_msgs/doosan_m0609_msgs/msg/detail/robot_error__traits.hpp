// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from doosan_m0609_msgs:msg/RobotError.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_ERROR__TRAITS_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_ERROR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "doosan_m0609_msgs/msg/detail/robot_error__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace doosan_m0609_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotError & msg,
  std::ostream & out)
{
  out << "{";
  // member: level
  {
    out << "level: ";
    rosidl_generator_traits::value_to_yaml(msg.level, out);
    out << ", ";
  }

  // member: group
  {
    out << "group: ";
    rosidl_generator_traits::value_to_yaml(msg.group, out);
    out << ", ";
  }

  // member: code
  {
    out << "code: ";
    rosidl_generator_traits::value_to_yaml(msg.code, out);
    out << ", ";
  }

  // member: msg1
  {
    out << "msg1: ";
    rosidl_generator_traits::value_to_yaml(msg.msg1, out);
    out << ", ";
  }

  // member: msg2
  {
    out << "msg2: ";
    rosidl_generator_traits::value_to_yaml(msg.msg2, out);
    out << ", ";
  }

  // member: msg3
  {
    out << "msg3: ";
    rosidl_generator_traits::value_to_yaml(msg.msg3, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotError & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "level: ";
    rosidl_generator_traits::value_to_yaml(msg.level, out);
    out << "\n";
  }

  // member: group
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "group: ";
    rosidl_generator_traits::value_to_yaml(msg.group, out);
    out << "\n";
  }

  // member: code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "code: ";
    rosidl_generator_traits::value_to_yaml(msg.code, out);
    out << "\n";
  }

  // member: msg1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "msg1: ";
    rosidl_generator_traits::value_to_yaml(msg.msg1, out);
    out << "\n";
  }

  // member: msg2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "msg2: ";
    rosidl_generator_traits::value_to_yaml(msg.msg2, out);
    out << "\n";
  }

  // member: msg3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "msg3: ";
    rosidl_generator_traits::value_to_yaml(msg.msg3, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotError & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::msg::RobotError & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::msg::RobotError & msg)
{
  return doosan_m0609_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::msg::RobotError>()
{
  return "doosan_m0609_msgs::msg::RobotError";
}

template<>
inline const char * name<doosan_m0609_msgs::msg::RobotError>()
{
  return "doosan_m0609_msgs/msg/RobotError";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::msg::RobotError>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::msg::RobotError>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<doosan_m0609_msgs::msg::RobotError>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_ERROR__TRAITS_HPP_

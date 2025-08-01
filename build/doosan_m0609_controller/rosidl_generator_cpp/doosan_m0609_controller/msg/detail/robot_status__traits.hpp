// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from doosan_m0609_controller:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_CONTROLLER__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_
#define DOOSAN_M0609_CONTROLLER__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "doosan_m0609_controller/msg/detail/robot_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace doosan_m0609_controller
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: is_connected
  {
    out << "is_connected: ";
    rosidl_generator_traits::value_to_yaml(msg.is_connected, out);
    out << ", ";
  }

  // member: is_enabled
  {
    out << "is_enabled: ";
    rosidl_generator_traits::value_to_yaml(msg.is_enabled, out);
    out << ", ";
  }

  // member: has_control_authority
  {
    out << "has_control_authority: ";
    rosidl_generator_traits::value_to_yaml(msg.has_control_authority, out);
    out << ", ";
  }

  // member: robot_state
  {
    out << "robot_state: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_state, out);
    out << ", ";
  }

  // member: error_message
  {
    out << "error_message: ";
    rosidl_generator_traits::value_to_yaml(msg.error_message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: is_connected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_connected: ";
    rosidl_generator_traits::value_to_yaml(msg.is_connected, out);
    out << "\n";
  }

  // member: is_enabled
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_enabled: ";
    rosidl_generator_traits::value_to_yaml(msg.is_enabled, out);
    out << "\n";
  }

  // member: has_control_authority
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "has_control_authority: ";
    rosidl_generator_traits::value_to_yaml(msg.has_control_authority, out);
    out << "\n";
  }

  // member: robot_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_state: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_state, out);
    out << "\n";
  }

  // member: error_message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_message: ";
    rosidl_generator_traits::value_to_yaml(msg.error_message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotStatus & msg, bool use_flow_style = false)
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

}  // namespace doosan_m0609_controller

namespace rosidl_generator_traits
{

[[deprecated("use doosan_m0609_controller::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const doosan_m0609_controller::msg::RobotStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_controller::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_controller::msg::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_controller::msg::RobotStatus & msg)
{
  return doosan_m0609_controller::msg::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_controller::msg::RobotStatus>()
{
  return "doosan_m0609_controller::msg::RobotStatus";
}

template<>
inline const char * name<doosan_m0609_controller::msg::RobotStatus>()
{
  return "doosan_m0609_controller/msg/RobotStatus";
}

template<>
struct has_fixed_size<doosan_m0609_controller::msg::RobotStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<doosan_m0609_controller::msg::RobotStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<doosan_m0609_controller::msg::RobotStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DOOSAN_M0609_CONTROLLER__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_

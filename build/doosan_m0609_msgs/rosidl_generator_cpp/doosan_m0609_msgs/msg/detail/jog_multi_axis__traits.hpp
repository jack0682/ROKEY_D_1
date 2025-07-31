// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from doosan_m0609_msgs:msg/JogMultiAxis.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__JOG_MULTI_AXIS__TRAITS_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__JOG_MULTI_AXIS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "doosan_m0609_msgs/msg/detail/jog_multi_axis__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace doosan_m0609_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const JogMultiAxis & msg,
  std::ostream & out)
{
  out << "{";
  // member: jog_axis
  {
    if (msg.jog_axis.size() == 0) {
      out << "jog_axis: []";
    } else {
      out << "jog_axis: [";
      size_t pending_items = msg.jog_axis.size();
      for (auto item : msg.jog_axis) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: move_reference
  {
    out << "move_reference: ";
    rosidl_generator_traits::value_to_yaml(msg.move_reference, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const JogMultiAxis & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: jog_axis
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.jog_axis.size() == 0) {
      out << "jog_axis: []\n";
    } else {
      out << "jog_axis:\n";
      for (auto item : msg.jog_axis) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: move_reference
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "move_reference: ";
    rosidl_generator_traits::value_to_yaml(msg.move_reference, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const JogMultiAxis & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::msg::JogMultiAxis & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::msg::JogMultiAxis & msg)
{
  return doosan_m0609_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::msg::JogMultiAxis>()
{
  return "doosan_m0609_msgs::msg::JogMultiAxis";
}

template<>
inline const char * name<doosan_m0609_msgs::msg::JogMultiAxis>()
{
  return "doosan_m0609_msgs/msg/JogMultiAxis";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::msg::JogMultiAxis>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::msg::JogMultiAxis>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::msg::JogMultiAxis>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__JOG_MULTI_AXIS__TRAITS_HPP_

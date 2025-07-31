// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from doosan_m0609_msgs:msg/TorqueRtStream.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__TORQUE_RT_STREAM__TRAITS_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__TORQUE_RT_STREAM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "doosan_m0609_msgs/msg/detail/torque_rt_stream__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace doosan_m0609_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TorqueRtStream & msg,
  std::ostream & out)
{
  out << "{";
  // member: tor
  {
    if (msg.tor.size() == 0) {
      out << "tor: []";
    } else {
      out << "tor: [";
      size_t pending_items = msg.tor.size();
      for (auto item : msg.tor) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: time
  {
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TorqueRtStream & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: tor
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tor.size() == 0) {
      out << "tor: []\n";
    } else {
      out << "tor:\n";
      for (auto item : msg.tor) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TorqueRtStream & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::msg::TorqueRtStream & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::msg::TorqueRtStream & msg)
{
  return doosan_m0609_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::msg::TorqueRtStream>()
{
  return "doosan_m0609_msgs::msg::TorqueRtStream";
}

template<>
inline const char * name<doosan_m0609_msgs::msg::TorqueRtStream>()
{
  return "doosan_m0609_msgs/msg/TorqueRtStream";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::msg::TorqueRtStream>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::msg::TorqueRtStream>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::msg::TorqueRtStream>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__TORQUE_RT_STREAM__TRAITS_HPP_

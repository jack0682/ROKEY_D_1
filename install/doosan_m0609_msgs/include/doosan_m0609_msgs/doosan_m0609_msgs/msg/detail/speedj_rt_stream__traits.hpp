// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from doosan_m0609_msgs:msg/SpeedjRtStream.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__SPEEDJ_RT_STREAM__TRAITS_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__SPEEDJ_RT_STREAM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "doosan_m0609_msgs/msg/detail/speedj_rt_stream__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace doosan_m0609_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SpeedjRtStream & msg,
  std::ostream & out)
{
  out << "{";
  // member: vel
  {
    if (msg.vel.size() == 0) {
      out << "vel: []";
    } else {
      out << "vel: [";
      size_t pending_items = msg.vel.size();
      for (auto item : msg.vel) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: acc
  {
    if (msg.acc.size() == 0) {
      out << "acc: []";
    } else {
      out << "acc: [";
      size_t pending_items = msg.acc.size();
      for (auto item : msg.acc) {
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
  const SpeedjRtStream & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.vel.size() == 0) {
      out << "vel: []\n";
    } else {
      out << "vel:\n";
      for (auto item : msg.vel) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.acc.size() == 0) {
      out << "acc: []\n";
    } else {
      out << "acc:\n";
      for (auto item : msg.acc) {
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

inline std::string to_yaml(const SpeedjRtStream & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::msg::SpeedjRtStream & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::msg::SpeedjRtStream & msg)
{
  return doosan_m0609_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::msg::SpeedjRtStream>()
{
  return "doosan_m0609_msgs::msg::SpeedjRtStream";
}

template<>
inline const char * name<doosan_m0609_msgs::msg::SpeedjRtStream>()
{
  return "doosan_m0609_msgs/msg/SpeedjRtStream";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::msg::SpeedjRtStream>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::msg::SpeedjRtStream>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::msg::SpeedjRtStream>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__SPEEDJ_RT_STREAM__TRAITS_HPP_

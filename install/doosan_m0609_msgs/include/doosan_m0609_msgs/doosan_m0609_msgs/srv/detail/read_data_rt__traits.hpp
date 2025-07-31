// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from doosan_m0609_msgs:srv/ReadDataRt.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__READ_DATA_RT__TRAITS_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__READ_DATA_RT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "doosan_m0609_msgs/srv/detail/read_data_rt__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace doosan_m0609_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ReadDataRt_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ReadDataRt_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ReadDataRt_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace doosan_m0609_msgs

namespace rosidl_generator_traits
{

[[deprecated("use doosan_m0609_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const doosan_m0609_msgs::srv::ReadDataRt_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::srv::ReadDataRt_Request & msg)
{
  return doosan_m0609_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::srv::ReadDataRt_Request>()
{
  return "doosan_m0609_msgs::srv::ReadDataRt_Request";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::ReadDataRt_Request>()
{
  return "doosan_m0609_msgs/srv/ReadDataRt_Request";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::ReadDataRt_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::ReadDataRt_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::srv::ReadDataRt_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'data'
#include "doosan_m0609_msgs/msg/detail/robot_state_rt__traits.hpp"

namespace doosan_m0609_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ReadDataRt_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: data
  {
    out << "data: ";
    to_flow_style_yaml(msg.data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ReadDataRt_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data:\n";
    to_block_style_yaml(msg.data, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ReadDataRt_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace doosan_m0609_msgs

namespace rosidl_generator_traits
{

[[deprecated("use doosan_m0609_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const doosan_m0609_msgs::srv::ReadDataRt_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::srv::ReadDataRt_Response & msg)
{
  return doosan_m0609_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::srv::ReadDataRt_Response>()
{
  return "doosan_m0609_msgs::srv::ReadDataRt_Response";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::ReadDataRt_Response>()
{
  return "doosan_m0609_msgs/srv/ReadDataRt_Response";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::ReadDataRt_Response>
  : std::integral_constant<bool, has_fixed_size<doosan_m0609_msgs::msg::RobotStateRt>::value> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::ReadDataRt_Response>
  : std::integral_constant<bool, has_bounded_size<doosan_m0609_msgs::msg::RobotStateRt>::value> {};

template<>
struct is_message<doosan_m0609_msgs::srv::ReadDataRt_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<doosan_m0609_msgs::srv::ReadDataRt>()
{
  return "doosan_m0609_msgs::srv::ReadDataRt";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::ReadDataRt>()
{
  return "doosan_m0609_msgs/srv/ReadDataRt";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::ReadDataRt>
  : std::integral_constant<
    bool,
    has_fixed_size<doosan_m0609_msgs::srv::ReadDataRt_Request>::value &&
    has_fixed_size<doosan_m0609_msgs::srv::ReadDataRt_Response>::value
  >
{
};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::ReadDataRt>
  : std::integral_constant<
    bool,
    has_bounded_size<doosan_m0609_msgs::srv::ReadDataRt_Request>::value &&
    has_bounded_size<doosan_m0609_msgs::srv::ReadDataRt_Response>::value
  >
{
};

template<>
struct is_service<doosan_m0609_msgs::srv::ReadDataRt>
  : std::true_type
{
};

template<>
struct is_service_request<doosan_m0609_msgs::srv::ReadDataRt_Request>
  : std::true_type
{
};

template<>
struct is_service_response<doosan_m0609_msgs::srv::ReadDataRt_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__READ_DATA_RT__TRAITS_HPP_

// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from doosan_m0609_msgs:srv/SetAccxRt.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_ACCX_RT__TRAITS_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_ACCX_RT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "doosan_m0609_msgs/srv/detail/set_accx_rt__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace doosan_m0609_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetAccxRt_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: trans
  {
    out << "trans: ";
    rosidl_generator_traits::value_to_yaml(msg.trans, out);
    out << ", ";
  }

  // member: rotation
  {
    out << "rotation: ";
    rosidl_generator_traits::value_to_yaml(msg.rotation, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetAccxRt_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: trans
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trans: ";
    rosidl_generator_traits::value_to_yaml(msg.trans, out);
    out << "\n";
  }

  // member: rotation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rotation: ";
    rosidl_generator_traits::value_to_yaml(msg.rotation, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetAccxRt_Request & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::srv::SetAccxRt_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::srv::SetAccxRt_Request & msg)
{
  return doosan_m0609_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::srv::SetAccxRt_Request>()
{
  return "doosan_m0609_msgs::srv::SetAccxRt_Request";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::SetAccxRt_Request>()
{
  return "doosan_m0609_msgs/srv/SetAccxRt_Request";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::SetAccxRt_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::SetAccxRt_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::srv::SetAccxRt_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace doosan_m0609_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetAccxRt_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetAccxRt_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetAccxRt_Response & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::srv::SetAccxRt_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::srv::SetAccxRt_Response & msg)
{
  return doosan_m0609_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::srv::SetAccxRt_Response>()
{
  return "doosan_m0609_msgs::srv::SetAccxRt_Response";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::SetAccxRt_Response>()
{
  return "doosan_m0609_msgs/srv/SetAccxRt_Response";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::SetAccxRt_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::SetAccxRt_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::srv::SetAccxRt_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<doosan_m0609_msgs::srv::SetAccxRt>()
{
  return "doosan_m0609_msgs::srv::SetAccxRt";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::SetAccxRt>()
{
  return "doosan_m0609_msgs/srv/SetAccxRt";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::SetAccxRt>
  : std::integral_constant<
    bool,
    has_fixed_size<doosan_m0609_msgs::srv::SetAccxRt_Request>::value &&
    has_fixed_size<doosan_m0609_msgs::srv::SetAccxRt_Response>::value
  >
{
};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::SetAccxRt>
  : std::integral_constant<
    bool,
    has_bounded_size<doosan_m0609_msgs::srv::SetAccxRt_Request>::value &&
    has_bounded_size<doosan_m0609_msgs::srv::SetAccxRt_Response>::value
  >
{
};

template<>
struct is_service<doosan_m0609_msgs::srv::SetAccxRt>
  : std::true_type
{
};

template<>
struct is_service_request<doosan_m0609_msgs::srv::SetAccxRt_Request>
  : std::true_type
{
};

template<>
struct is_service_response<doosan_m0609_msgs::srv::SetAccxRt_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_ACCX_RT__TRAITS_HPP_

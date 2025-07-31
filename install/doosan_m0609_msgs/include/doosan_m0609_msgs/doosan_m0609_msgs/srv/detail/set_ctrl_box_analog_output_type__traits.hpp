// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from doosan_m0609_msgs:srv/SetCtrlBoxAnalogOutputType.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_CTRL_BOX_ANALOG_OUTPUT_TYPE__TRAITS_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_CTRL_BOX_ANALOG_OUTPUT_TYPE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "doosan_m0609_msgs/srv/detail/set_ctrl_box_analog_output_type__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace doosan_m0609_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetCtrlBoxAnalogOutputType_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: channel
  {
    out << "channel: ";
    rosidl_generator_traits::value_to_yaml(msg.channel, out);
    out << ", ";
  }

  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetCtrlBoxAnalogOutputType_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: channel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "channel: ";
    rosidl_generator_traits::value_to_yaml(msg.channel, out);
    out << "\n";
  }

  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetCtrlBoxAnalogOutputType_Request & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Request & msg)
{
  return doosan_m0609_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Request>()
{
  return "doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Request";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Request>()
{
  return "doosan_m0609_msgs/srv/SetCtrlBoxAnalogOutputType_Request";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace doosan_m0609_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetCtrlBoxAnalogOutputType_Response & msg,
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
  const SetCtrlBoxAnalogOutputType_Response & msg,
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

inline std::string to_yaml(const SetCtrlBoxAnalogOutputType_Response & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Response & msg)
{
  return doosan_m0609_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Response>()
{
  return "doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Response";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Response>()
{
  return "doosan_m0609_msgs/srv/SetCtrlBoxAnalogOutputType_Response";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType>()
{
  return "doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType>()
{
  return "doosan_m0609_msgs/srv/SetCtrlBoxAnalogOutputType";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType>
  : std::integral_constant<
    bool,
    has_fixed_size<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Request>::value &&
    has_fixed_size<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Response>::value
  >
{
};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType>
  : std::integral_constant<
    bool,
    has_bounded_size<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Request>::value &&
    has_bounded_size<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Response>::value
  >
{
};

template<>
struct is_service<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType>
  : std::true_type
{
};

template<>
struct is_service_request<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Request>
  : std::true_type
{
};

template<>
struct is_service_response<doosan_m0609_msgs::srv::SetCtrlBoxAnalogOutputType_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_CTRL_BOX_ANALOG_OUTPUT_TYPE__TRAITS_HPP_

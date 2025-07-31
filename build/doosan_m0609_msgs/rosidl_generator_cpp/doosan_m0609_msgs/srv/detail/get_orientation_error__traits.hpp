// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from doosan_m0609_msgs:srv/GetOrientationError.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_ORIENTATION_ERROR__TRAITS_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_ORIENTATION_ERROR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "doosan_m0609_msgs/srv/detail/get_orientation_error__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace doosan_m0609_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetOrientationError_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: xd
  {
    if (msg.xd.size() == 0) {
      out << "xd: []";
    } else {
      out << "xd: [";
      size_t pending_items = msg.xd.size();
      for (auto item : msg.xd) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: xc
  {
    if (msg.xc.size() == 0) {
      out << "xc: []";
    } else {
      out << "xc: [";
      size_t pending_items = msg.xc.size();
      for (auto item : msg.xc) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: axis
  {
    out << "axis: ";
    rosidl_generator_traits::value_to_yaml(msg.axis, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetOrientationError_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: xd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.xd.size() == 0) {
      out << "xd: []\n";
    } else {
      out << "xd:\n";
      for (auto item : msg.xd) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: xc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.xc.size() == 0) {
      out << "xc: []\n";
    } else {
      out << "xc:\n";
      for (auto item : msg.xc) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: axis
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "axis: ";
    rosidl_generator_traits::value_to_yaml(msg.axis, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetOrientationError_Request & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::srv::GetOrientationError_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::srv::GetOrientationError_Request & msg)
{
  return doosan_m0609_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::srv::GetOrientationError_Request>()
{
  return "doosan_m0609_msgs::srv::GetOrientationError_Request";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::GetOrientationError_Request>()
{
  return "doosan_m0609_msgs/srv/GetOrientationError_Request";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::GetOrientationError_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::GetOrientationError_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::srv::GetOrientationError_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace doosan_m0609_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetOrientationError_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: ori_error
  {
    out << "ori_error: ";
    rosidl_generator_traits::value_to_yaml(msg.ori_error, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetOrientationError_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ori_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ori_error: ";
    rosidl_generator_traits::value_to_yaml(msg.ori_error, out);
    out << "\n";
  }

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

inline std::string to_yaml(const GetOrientationError_Response & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::srv::GetOrientationError_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::srv::GetOrientationError_Response & msg)
{
  return doosan_m0609_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::srv::GetOrientationError_Response>()
{
  return "doosan_m0609_msgs::srv::GetOrientationError_Response";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::GetOrientationError_Response>()
{
  return "doosan_m0609_msgs/srv/GetOrientationError_Response";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::GetOrientationError_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::GetOrientationError_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::srv::GetOrientationError_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<doosan_m0609_msgs::srv::GetOrientationError>()
{
  return "doosan_m0609_msgs::srv::GetOrientationError";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::GetOrientationError>()
{
  return "doosan_m0609_msgs/srv/GetOrientationError";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::GetOrientationError>
  : std::integral_constant<
    bool,
    has_fixed_size<doosan_m0609_msgs::srv::GetOrientationError_Request>::value &&
    has_fixed_size<doosan_m0609_msgs::srv::GetOrientationError_Response>::value
  >
{
};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::GetOrientationError>
  : std::integral_constant<
    bool,
    has_bounded_size<doosan_m0609_msgs::srv::GetOrientationError_Request>::value &&
    has_bounded_size<doosan_m0609_msgs::srv::GetOrientationError_Response>::value
  >
{
};

template<>
struct is_service<doosan_m0609_msgs::srv::GetOrientationError>
  : std::true_type
{
};

template<>
struct is_service_request<doosan_m0609_msgs::srv::GetOrientationError_Request>
  : std::true_type
{
};

template<>
struct is_service_response<doosan_m0609_msgs::srv::GetOrientationError_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_ORIENTATION_ERROR__TRAITS_HPP_

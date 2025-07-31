// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from doosan_m0609_msgs:srv/GetDesiredVelj.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_DESIRED_VELJ__TRAITS_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_DESIRED_VELJ__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "doosan_m0609_msgs/srv/detail/get_desired_velj__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace doosan_m0609_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetDesiredVelj_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetDesiredVelj_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetDesiredVelj_Request & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::srv::GetDesiredVelj_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::srv::GetDesiredVelj_Request & msg)
{
  return doosan_m0609_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::srv::GetDesiredVelj_Request>()
{
  return "doosan_m0609_msgs::srv::GetDesiredVelj_Request";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::GetDesiredVelj_Request>()
{
  return "doosan_m0609_msgs/srv/GetDesiredVelj_Request";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::GetDesiredVelj_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::GetDesiredVelj_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::srv::GetDesiredVelj_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace doosan_m0609_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetDesiredVelj_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: joint_vel
  {
    if (msg.joint_vel.size() == 0) {
      out << "joint_vel: []";
    } else {
      out << "joint_vel: [";
      size_t pending_items = msg.joint_vel.size();
      for (auto item : msg.joint_vel) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
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
  const GetDesiredVelj_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: joint_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_vel.size() == 0) {
      out << "joint_vel: []\n";
    } else {
      out << "joint_vel:\n";
      for (auto item : msg.joint_vel) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
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

inline std::string to_yaml(const GetDesiredVelj_Response & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::srv::GetDesiredVelj_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::srv::GetDesiredVelj_Response & msg)
{
  return doosan_m0609_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::srv::GetDesiredVelj_Response>()
{
  return "doosan_m0609_msgs::srv::GetDesiredVelj_Response";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::GetDesiredVelj_Response>()
{
  return "doosan_m0609_msgs/srv/GetDesiredVelj_Response";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::GetDesiredVelj_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::GetDesiredVelj_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::srv::GetDesiredVelj_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<doosan_m0609_msgs::srv::GetDesiredVelj>()
{
  return "doosan_m0609_msgs::srv::GetDesiredVelj";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::GetDesiredVelj>()
{
  return "doosan_m0609_msgs/srv/GetDesiredVelj";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::GetDesiredVelj>
  : std::integral_constant<
    bool,
    has_fixed_size<doosan_m0609_msgs::srv::GetDesiredVelj_Request>::value &&
    has_fixed_size<doosan_m0609_msgs::srv::GetDesiredVelj_Response>::value
  >
{
};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::GetDesiredVelj>
  : std::integral_constant<
    bool,
    has_bounded_size<doosan_m0609_msgs::srv::GetDesiredVelj_Request>::value &&
    has_bounded_size<doosan_m0609_msgs::srv::GetDesiredVelj_Response>::value
  >
{
};

template<>
struct is_service<doosan_m0609_msgs::srv::GetDesiredVelj>
  : std::true_type
{
};

template<>
struct is_service_request<doosan_m0609_msgs::srv::GetDesiredVelj_Request>
  : std::true_type
{
};

template<>
struct is_service_response<doosan_m0609_msgs::srv::GetDesiredVelj_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_DESIRED_VELJ__TRAITS_HPP_

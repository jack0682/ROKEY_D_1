// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from doosan_m0609_msgs:srv/GetSolutionSpace.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_SOLUTION_SPACE__TRAITS_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_SOLUTION_SPACE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "doosan_m0609_msgs/srv/detail/get_solution_space__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace doosan_m0609_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetSolutionSpace_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: pos
  {
    if (msg.pos.size() == 0) {
      out << "pos: []";
    } else {
      out << "pos: [";
      size_t pending_items = msg.pos.size();
      for (auto item : msg.pos) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetSolutionSpace_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.pos.size() == 0) {
      out << "pos: []\n";
    } else {
      out << "pos:\n";
      for (auto item : msg.pos) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetSolutionSpace_Request & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::srv::GetSolutionSpace_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::srv::GetSolutionSpace_Request & msg)
{
  return doosan_m0609_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::srv::GetSolutionSpace_Request>()
{
  return "doosan_m0609_msgs::srv::GetSolutionSpace_Request";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::GetSolutionSpace_Request>()
{
  return "doosan_m0609_msgs/srv/GetSolutionSpace_Request";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::GetSolutionSpace_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::GetSolutionSpace_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::srv::GetSolutionSpace_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace doosan_m0609_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetSolutionSpace_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: sol_space
  {
    out << "sol_space: ";
    rosidl_generator_traits::value_to_yaml(msg.sol_space, out);
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
  const GetSolutionSpace_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sol_space
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sol_space: ";
    rosidl_generator_traits::value_to_yaml(msg.sol_space, out);
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

inline std::string to_yaml(const GetSolutionSpace_Response & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::srv::GetSolutionSpace_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::srv::GetSolutionSpace_Response & msg)
{
  return doosan_m0609_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::srv::GetSolutionSpace_Response>()
{
  return "doosan_m0609_msgs::srv::GetSolutionSpace_Response";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::GetSolutionSpace_Response>()
{
  return "doosan_m0609_msgs/srv/GetSolutionSpace_Response";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::GetSolutionSpace_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::GetSolutionSpace_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::srv::GetSolutionSpace_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<doosan_m0609_msgs::srv::GetSolutionSpace>()
{
  return "doosan_m0609_msgs::srv::GetSolutionSpace";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::GetSolutionSpace>()
{
  return "doosan_m0609_msgs/srv/GetSolutionSpace";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::GetSolutionSpace>
  : std::integral_constant<
    bool,
    has_fixed_size<doosan_m0609_msgs::srv::GetSolutionSpace_Request>::value &&
    has_fixed_size<doosan_m0609_msgs::srv::GetSolutionSpace_Response>::value
  >
{
};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::GetSolutionSpace>
  : std::integral_constant<
    bool,
    has_bounded_size<doosan_m0609_msgs::srv::GetSolutionSpace_Request>::value &&
    has_bounded_size<doosan_m0609_msgs::srv::GetSolutionSpace_Response>::value
  >
{
};

template<>
struct is_service<doosan_m0609_msgs::srv::GetSolutionSpace>
  : std::true_type
{
};

template<>
struct is_service_request<doosan_m0609_msgs::srv::GetSolutionSpace_Request>
  : std::true_type
{
};

template<>
struct is_service_response<doosan_m0609_msgs::srv::GetSolutionSpace_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_SOLUTION_SPACE__TRAITS_HPP_

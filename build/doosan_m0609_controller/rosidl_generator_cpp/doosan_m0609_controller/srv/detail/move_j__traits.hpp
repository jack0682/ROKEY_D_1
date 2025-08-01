// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from doosan_m0609_controller:srv/MoveJ.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_CONTROLLER__SRV__DETAIL__MOVE_J__TRAITS_HPP_
#define DOOSAN_M0609_CONTROLLER__SRV__DETAIL__MOVE_J__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "doosan_m0609_controller/srv/detail/move_j__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace doosan_m0609_controller
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoveJ_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_joints
  {
    if (msg.target_joints.size() == 0) {
      out << "target_joints: []";
    } else {
      out << "target_joints: [";
      size_t pending_items = msg.target_joints.size();
      for (auto item : msg.target_joints) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: velocity_ratio
  {
    out << "velocity_ratio: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity_ratio, out);
    out << ", ";
  }

  // member: acceleration_ratio
  {
    out << "acceleration_ratio: ";
    rosidl_generator_traits::value_to_yaml(msg.acceleration_ratio, out);
    out << ", ";
  }

  // member: time_out
  {
    out << "time_out: ";
    rosidl_generator_traits::value_to_yaml(msg.time_out, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveJ_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target_joints
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.target_joints.size() == 0) {
      out << "target_joints: []\n";
    } else {
      out << "target_joints:\n";
      for (auto item : msg.target_joints) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: velocity_ratio
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity_ratio: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity_ratio, out);
    out << "\n";
  }

  // member: acceleration_ratio
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acceleration_ratio: ";
    rosidl_generator_traits::value_to_yaml(msg.acceleration_ratio, out);
    out << "\n";
  }

  // member: time_out
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_out: ";
    rosidl_generator_traits::value_to_yaml(msg.time_out, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveJ_Request & msg, bool use_flow_style = false)
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

}  // namespace doosan_m0609_controller

namespace rosidl_generator_traits
{

[[deprecated("use doosan_m0609_controller::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const doosan_m0609_controller::srv::MoveJ_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_controller::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_controller::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_controller::srv::MoveJ_Request & msg)
{
  return doosan_m0609_controller::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_controller::srv::MoveJ_Request>()
{
  return "doosan_m0609_controller::srv::MoveJ_Request";
}

template<>
inline const char * name<doosan_m0609_controller::srv::MoveJ_Request>()
{
  return "doosan_m0609_controller/srv/MoveJ_Request";
}

template<>
struct has_fixed_size<doosan_m0609_controller::srv::MoveJ_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_controller::srv::MoveJ_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_controller::srv::MoveJ_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace doosan_m0609_controller
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoveJ_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveJ_Response & msg,
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

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveJ_Response & msg, bool use_flow_style = false)
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

}  // namespace doosan_m0609_controller

namespace rosidl_generator_traits
{

[[deprecated("use doosan_m0609_controller::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const doosan_m0609_controller::srv::MoveJ_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_controller::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_controller::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_controller::srv::MoveJ_Response & msg)
{
  return doosan_m0609_controller::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_controller::srv::MoveJ_Response>()
{
  return "doosan_m0609_controller::srv::MoveJ_Response";
}

template<>
inline const char * name<doosan_m0609_controller::srv::MoveJ_Response>()
{
  return "doosan_m0609_controller/srv/MoveJ_Response";
}

template<>
struct has_fixed_size<doosan_m0609_controller::srv::MoveJ_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<doosan_m0609_controller::srv::MoveJ_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<doosan_m0609_controller::srv::MoveJ_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<doosan_m0609_controller::srv::MoveJ>()
{
  return "doosan_m0609_controller::srv::MoveJ";
}

template<>
inline const char * name<doosan_m0609_controller::srv::MoveJ>()
{
  return "doosan_m0609_controller/srv/MoveJ";
}

template<>
struct has_fixed_size<doosan_m0609_controller::srv::MoveJ>
  : std::integral_constant<
    bool,
    has_fixed_size<doosan_m0609_controller::srv::MoveJ_Request>::value &&
    has_fixed_size<doosan_m0609_controller::srv::MoveJ_Response>::value
  >
{
};

template<>
struct has_bounded_size<doosan_m0609_controller::srv::MoveJ>
  : std::integral_constant<
    bool,
    has_bounded_size<doosan_m0609_controller::srv::MoveJ_Request>::value &&
    has_bounded_size<doosan_m0609_controller::srv::MoveJ_Response>::value
  >
{
};

template<>
struct is_service<doosan_m0609_controller::srv::MoveJ>
  : std::true_type
{
};

template<>
struct is_service_request<doosan_m0609_controller::srv::MoveJ_Request>
  : std::true_type
{
};

template<>
struct is_service_response<doosan_m0609_controller::srv::MoveJ_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DOOSAN_M0609_CONTROLLER__SRV__DETAIL__MOVE_J__TRAITS_HPP_

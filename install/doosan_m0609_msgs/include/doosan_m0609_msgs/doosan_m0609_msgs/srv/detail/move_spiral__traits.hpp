// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from doosan_m0609_msgs:srv/MoveSpiral.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_SPIRAL__TRAITS_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_SPIRAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "doosan_m0609_msgs/srv/detail/move_spiral__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace doosan_m0609_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoveSpiral_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: revolution
  {
    out << "revolution: ";
    rosidl_generator_traits::value_to_yaml(msg.revolution, out);
    out << ", ";
  }

  // member: max_radius
  {
    out << "max_radius: ";
    rosidl_generator_traits::value_to_yaml(msg.max_radius, out);
    out << ", ";
  }

  // member: max_length
  {
    out << "max_length: ";
    rosidl_generator_traits::value_to_yaml(msg.max_length, out);
    out << ", ";
  }

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
    out << ", ";
  }

  // member: task_axis
  {
    out << "task_axis: ";
    rosidl_generator_traits::value_to_yaml(msg.task_axis, out);
    out << ", ";
  }

  // member: ref
  {
    out << "ref: ";
    rosidl_generator_traits::value_to_yaml(msg.ref, out);
    out << ", ";
  }

  // member: sync_type
  {
    out << "sync_type: ";
    rosidl_generator_traits::value_to_yaml(msg.sync_type, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveSpiral_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: revolution
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "revolution: ";
    rosidl_generator_traits::value_to_yaml(msg.revolution, out);
    out << "\n";
  }

  // member: max_radius
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_radius: ";
    rosidl_generator_traits::value_to_yaml(msg.max_radius, out);
    out << "\n";
  }

  // member: max_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_length: ";
    rosidl_generator_traits::value_to_yaml(msg.max_length, out);
    out << "\n";
  }

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

  // member: task_axis
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_axis: ";
    rosidl_generator_traits::value_to_yaml(msg.task_axis, out);
    out << "\n";
  }

  // member: ref
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ref: ";
    rosidl_generator_traits::value_to_yaml(msg.ref, out);
    out << "\n";
  }

  // member: sync_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sync_type: ";
    rosidl_generator_traits::value_to_yaml(msg.sync_type, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveSpiral_Request & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::srv::MoveSpiral_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::srv::MoveSpiral_Request & msg)
{
  return doosan_m0609_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::srv::MoveSpiral_Request>()
{
  return "doosan_m0609_msgs::srv::MoveSpiral_Request";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::MoveSpiral_Request>()
{
  return "doosan_m0609_msgs/srv/MoveSpiral_Request";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::MoveSpiral_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::MoveSpiral_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::srv::MoveSpiral_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace doosan_m0609_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoveSpiral_Response & msg,
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
  const MoveSpiral_Response & msg,
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

inline std::string to_yaml(const MoveSpiral_Response & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::srv::MoveSpiral_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::srv::MoveSpiral_Response & msg)
{
  return doosan_m0609_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::srv::MoveSpiral_Response>()
{
  return "doosan_m0609_msgs::srv::MoveSpiral_Response";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::MoveSpiral_Response>()
{
  return "doosan_m0609_msgs/srv/MoveSpiral_Response";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::MoveSpiral_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::MoveSpiral_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::srv::MoveSpiral_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<doosan_m0609_msgs::srv::MoveSpiral>()
{
  return "doosan_m0609_msgs::srv::MoveSpiral";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::MoveSpiral>()
{
  return "doosan_m0609_msgs/srv/MoveSpiral";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::MoveSpiral>
  : std::integral_constant<
    bool,
    has_fixed_size<doosan_m0609_msgs::srv::MoveSpiral_Request>::value &&
    has_fixed_size<doosan_m0609_msgs::srv::MoveSpiral_Response>::value
  >
{
};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::MoveSpiral>
  : std::integral_constant<
    bool,
    has_bounded_size<doosan_m0609_msgs::srv::MoveSpiral_Request>::value &&
    has_bounded_size<doosan_m0609_msgs::srv::MoveSpiral_Response>::value
  >
{
};

template<>
struct is_service<doosan_m0609_msgs::srv::MoveSpiral>
  : std::true_type
{
};

template<>
struct is_service_request<doosan_m0609_msgs::srv::MoveSpiral_Request>
  : std::true_type
{
};

template<>
struct is_service_response<doosan_m0609_msgs::srv::MoveSpiral_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_SPIRAL__TRAITS_HPP_

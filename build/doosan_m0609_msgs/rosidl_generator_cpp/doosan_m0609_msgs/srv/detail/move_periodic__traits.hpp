// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from doosan_m0609_msgs:srv/MovePeriodic.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_PERIODIC__TRAITS_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_PERIODIC__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "doosan_m0609_msgs/srv/detail/move_periodic__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace doosan_m0609_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const MovePeriodic_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: amp
  {
    if (msg.amp.size() == 0) {
      out << "amp: []";
    } else {
      out << "amp: [";
      size_t pending_items = msg.amp.size();
      for (auto item : msg.amp) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: periodic
  {
    if (msg.periodic.size() == 0) {
      out << "periodic: []";
    } else {
      out << "periodic: [";
      size_t pending_items = msg.periodic.size();
      for (auto item : msg.periodic) {
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
    out << "acc: ";
    rosidl_generator_traits::value_to_yaml(msg.acc, out);
    out << ", ";
  }

  // member: repeat
  {
    out << "repeat: ";
    rosidl_generator_traits::value_to_yaml(msg.repeat, out);
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
  const MovePeriodic_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: amp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.amp.size() == 0) {
      out << "amp: []\n";
    } else {
      out << "amp:\n";
      for (auto item : msg.amp) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: periodic
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.periodic.size() == 0) {
      out << "periodic: []\n";
    } else {
      out << "periodic:\n";
      for (auto item : msg.periodic) {
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
    out << "acc: ";
    rosidl_generator_traits::value_to_yaml(msg.acc, out);
    out << "\n";
  }

  // member: repeat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "repeat: ";
    rosidl_generator_traits::value_to_yaml(msg.repeat, out);
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

inline std::string to_yaml(const MovePeriodic_Request & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::srv::MovePeriodic_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::srv::MovePeriodic_Request & msg)
{
  return doosan_m0609_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::srv::MovePeriodic_Request>()
{
  return "doosan_m0609_msgs::srv::MovePeriodic_Request";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::MovePeriodic_Request>()
{
  return "doosan_m0609_msgs/srv/MovePeriodic_Request";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::MovePeriodic_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::MovePeriodic_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::srv::MovePeriodic_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace doosan_m0609_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const MovePeriodic_Response & msg,
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
  const MovePeriodic_Response & msg,
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

inline std::string to_yaml(const MovePeriodic_Response & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::srv::MovePeriodic_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::srv::MovePeriodic_Response & msg)
{
  return doosan_m0609_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::srv::MovePeriodic_Response>()
{
  return "doosan_m0609_msgs::srv::MovePeriodic_Response";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::MovePeriodic_Response>()
{
  return "doosan_m0609_msgs/srv/MovePeriodic_Response";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::MovePeriodic_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::MovePeriodic_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::srv::MovePeriodic_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<doosan_m0609_msgs::srv::MovePeriodic>()
{
  return "doosan_m0609_msgs::srv::MovePeriodic";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::MovePeriodic>()
{
  return "doosan_m0609_msgs/srv/MovePeriodic";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::MovePeriodic>
  : std::integral_constant<
    bool,
    has_fixed_size<doosan_m0609_msgs::srv::MovePeriodic_Request>::value &&
    has_fixed_size<doosan_m0609_msgs::srv::MovePeriodic_Response>::value
  >
{
};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::MovePeriodic>
  : std::integral_constant<
    bool,
    has_bounded_size<doosan_m0609_msgs::srv::MovePeriodic_Request>::value &&
    has_bounded_size<doosan_m0609_msgs::srv::MovePeriodic_Response>::value
  >
{
};

template<>
struct is_service<doosan_m0609_msgs::srv::MovePeriodic>
  : std::true_type
{
};

template<>
struct is_service_request<doosan_m0609_msgs::srv::MovePeriodic_Request>
  : std::true_type
{
};

template<>
struct is_service_response<doosan_m0609_msgs::srv::MovePeriodic_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_PERIODIC__TRAITS_HPP_

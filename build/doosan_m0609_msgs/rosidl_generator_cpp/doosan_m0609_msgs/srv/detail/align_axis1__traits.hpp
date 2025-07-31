// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from doosan_m0609_msgs:srv/AlignAxis1.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__ALIGN_AXIS1__TRAITS_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__ALIGN_AXIS1__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "doosan_m0609_msgs/srv/detail/align_axis1__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace doosan_m0609_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const AlignAxis1_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: x1
  {
    if (msg.x1.size() == 0) {
      out << "x1: []";
    } else {
      out << "x1: [";
      size_t pending_items = msg.x1.size();
      for (auto item : msg.x1) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: x2
  {
    if (msg.x2.size() == 0) {
      out << "x2: []";
    } else {
      out << "x2: [";
      size_t pending_items = msg.x2.size();
      for (auto item : msg.x2) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: x3
  {
    if (msg.x3.size() == 0) {
      out << "x3: []";
    } else {
      out << "x3: [";
      size_t pending_items = msg.x3.size();
      for (auto item : msg.x3) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: source_vect
  {
    if (msg.source_vect.size() == 0) {
      out << "source_vect: []";
    } else {
      out << "source_vect: [";
      size_t pending_items = msg.source_vect.size();
      for (auto item : msg.source_vect) {
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
    out << ", ";
  }

  // member: ref
  {
    out << "ref: ";
    rosidl_generator_traits::value_to_yaml(msg.ref, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AlignAxis1_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.x1.size() == 0) {
      out << "x1: []\n";
    } else {
      out << "x1:\n";
      for (auto item : msg.x1) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: x2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.x2.size() == 0) {
      out << "x2: []\n";
    } else {
      out << "x2:\n";
      for (auto item : msg.x2) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: x3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.x3.size() == 0) {
      out << "x3: []\n";
    } else {
      out << "x3:\n";
      for (auto item : msg.x3) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: source_vect
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.source_vect.size() == 0) {
      out << "source_vect: []\n";
    } else {
      out << "source_vect:\n";
      for (auto item : msg.source_vect) {
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

  // member: ref
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ref: ";
    rosidl_generator_traits::value_to_yaml(msg.ref, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AlignAxis1_Request & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::srv::AlignAxis1_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::srv::AlignAxis1_Request & msg)
{
  return doosan_m0609_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::srv::AlignAxis1_Request>()
{
  return "doosan_m0609_msgs::srv::AlignAxis1_Request";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::AlignAxis1_Request>()
{
  return "doosan_m0609_msgs/srv/AlignAxis1_Request";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::AlignAxis1_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::AlignAxis1_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::srv::AlignAxis1_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace doosan_m0609_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const AlignAxis1_Response & msg,
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
  const AlignAxis1_Response & msg,
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

inline std::string to_yaml(const AlignAxis1_Response & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::srv::AlignAxis1_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::srv::AlignAxis1_Response & msg)
{
  return doosan_m0609_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::srv::AlignAxis1_Response>()
{
  return "doosan_m0609_msgs::srv::AlignAxis1_Response";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::AlignAxis1_Response>()
{
  return "doosan_m0609_msgs/srv/AlignAxis1_Response";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::AlignAxis1_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::AlignAxis1_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::srv::AlignAxis1_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<doosan_m0609_msgs::srv::AlignAxis1>()
{
  return "doosan_m0609_msgs::srv::AlignAxis1";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::AlignAxis1>()
{
  return "doosan_m0609_msgs/srv/AlignAxis1";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::AlignAxis1>
  : std::integral_constant<
    bool,
    has_fixed_size<doosan_m0609_msgs::srv::AlignAxis1_Request>::value &&
    has_fixed_size<doosan_m0609_msgs::srv::AlignAxis1_Response>::value
  >
{
};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::AlignAxis1>
  : std::integral_constant<
    bool,
    has_bounded_size<doosan_m0609_msgs::srv::AlignAxis1_Request>::value &&
    has_bounded_size<doosan_m0609_msgs::srv::AlignAxis1_Response>::value
  >
{
};

template<>
struct is_service<doosan_m0609_msgs::srv::AlignAxis1>
  : std::true_type
{
};

template<>
struct is_service_request<doosan_m0609_msgs::srv::AlignAxis1_Request>
  : std::true_type
{
};

template<>
struct is_service_response<doosan_m0609_msgs::srv::AlignAxis1_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__ALIGN_AXIS1__TRAITS_HPP_

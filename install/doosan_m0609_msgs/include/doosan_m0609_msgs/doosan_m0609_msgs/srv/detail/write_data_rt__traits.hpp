// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from doosan_m0609_msgs:srv/WriteDataRt.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__WRITE_DATA_RT__TRAITS_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__WRITE_DATA_RT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "doosan_m0609_msgs/srv/detail/write_data_rt__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace doosan_m0609_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const WriteDataRt_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: external_force_torque
  {
    if (msg.external_force_torque.size() == 0) {
      out << "external_force_torque: []";
    } else {
      out << "external_force_torque: [";
      size_t pending_items = msg.external_force_torque.size();
      for (auto item : msg.external_force_torque) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: external_digital_input
  {
    out << "external_digital_input: ";
    rosidl_generator_traits::value_to_yaml(msg.external_digital_input, out);
    out << ", ";
  }

  // member: external_digital_output
  {
    out << "external_digital_output: ";
    rosidl_generator_traits::value_to_yaml(msg.external_digital_output, out);
    out << ", ";
  }

  // member: external_analog_input
  {
    if (msg.external_analog_input.size() == 0) {
      out << "external_analog_input: []";
    } else {
      out << "external_analog_input: [";
      size_t pending_items = msg.external_analog_input.size();
      for (auto item : msg.external_analog_input) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: external_analog_output
  {
    if (msg.external_analog_output.size() == 0) {
      out << "external_analog_output: []";
    } else {
      out << "external_analog_output: [";
      size_t pending_items = msg.external_analog_output.size();
      for (auto item : msg.external_analog_output) {
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
  const WriteDataRt_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: external_force_torque
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.external_force_torque.size() == 0) {
      out << "external_force_torque: []\n";
    } else {
      out << "external_force_torque:\n";
      for (auto item : msg.external_force_torque) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: external_digital_input
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "external_digital_input: ";
    rosidl_generator_traits::value_to_yaml(msg.external_digital_input, out);
    out << "\n";
  }

  // member: external_digital_output
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "external_digital_output: ";
    rosidl_generator_traits::value_to_yaml(msg.external_digital_output, out);
    out << "\n";
  }

  // member: external_analog_input
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.external_analog_input.size() == 0) {
      out << "external_analog_input: []\n";
    } else {
      out << "external_analog_input:\n";
      for (auto item : msg.external_analog_input) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: external_analog_output
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.external_analog_output.size() == 0) {
      out << "external_analog_output: []\n";
    } else {
      out << "external_analog_output:\n";
      for (auto item : msg.external_analog_output) {
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

inline std::string to_yaml(const WriteDataRt_Request & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::srv::WriteDataRt_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::srv::WriteDataRt_Request & msg)
{
  return doosan_m0609_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::srv::WriteDataRt_Request>()
{
  return "doosan_m0609_msgs::srv::WriteDataRt_Request";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::WriteDataRt_Request>()
{
  return "doosan_m0609_msgs/srv/WriteDataRt_Request";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::WriteDataRt_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::WriteDataRt_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::srv::WriteDataRt_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace doosan_m0609_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const WriteDataRt_Response & msg,
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
  const WriteDataRt_Response & msg,
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

inline std::string to_yaml(const WriteDataRt_Response & msg, bool use_flow_style = false)
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
  const doosan_m0609_msgs::srv::WriteDataRt_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  doosan_m0609_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use doosan_m0609_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const doosan_m0609_msgs::srv::WriteDataRt_Response & msg)
{
  return doosan_m0609_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<doosan_m0609_msgs::srv::WriteDataRt_Response>()
{
  return "doosan_m0609_msgs::srv::WriteDataRt_Response";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::WriteDataRt_Response>()
{
  return "doosan_m0609_msgs/srv/WriteDataRt_Response";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::WriteDataRt_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::WriteDataRt_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<doosan_m0609_msgs::srv::WriteDataRt_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<doosan_m0609_msgs::srv::WriteDataRt>()
{
  return "doosan_m0609_msgs::srv::WriteDataRt";
}

template<>
inline const char * name<doosan_m0609_msgs::srv::WriteDataRt>()
{
  return "doosan_m0609_msgs/srv/WriteDataRt";
}

template<>
struct has_fixed_size<doosan_m0609_msgs::srv::WriteDataRt>
  : std::integral_constant<
    bool,
    has_fixed_size<doosan_m0609_msgs::srv::WriteDataRt_Request>::value &&
    has_fixed_size<doosan_m0609_msgs::srv::WriteDataRt_Response>::value
  >
{
};

template<>
struct has_bounded_size<doosan_m0609_msgs::srv::WriteDataRt>
  : std::integral_constant<
    bool,
    has_bounded_size<doosan_m0609_msgs::srv::WriteDataRt_Request>::value &&
    has_bounded_size<doosan_m0609_msgs::srv::WriteDataRt_Response>::value
  >
{
};

template<>
struct is_service<doosan_m0609_msgs::srv::WriteDataRt>
  : std::true_type
{
};

template<>
struct is_service_request<doosan_m0609_msgs::srv::WriteDataRt_Request>
  : std::true_type
{
};

template<>
struct is_service_response<doosan_m0609_msgs::srv::WriteDataRt_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__WRITE_DATA_RT__TRAITS_HPP_

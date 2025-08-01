// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from doosan_m0609_controller:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_CONTROLLER__MSG__DETAIL__ROBOT_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define DOOSAN_M0609_CONTROLLER__MSG__DETAIL__ROBOT_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "doosan_m0609_controller/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "doosan_m0609_controller/msg/detail/robot_status__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace doosan_m0609_controller
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_doosan_m0609_controller
cdr_serialize(
  const doosan_m0609_controller::msg::RobotStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_doosan_m0609_controller
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  doosan_m0609_controller::msg::RobotStatus & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_doosan_m0609_controller
get_serialized_size(
  const doosan_m0609_controller::msg::RobotStatus & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_doosan_m0609_controller
max_serialized_size_RobotStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace doosan_m0609_controller

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_doosan_m0609_controller
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, doosan_m0609_controller, msg, RobotStatus)();

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_CONTROLLER__MSG__DETAIL__ROBOT_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from doosan_m0609_msgs:msg/RobotStop.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "doosan_m0609_msgs/msg/detail/robot_stop__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace doosan_m0609_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void RobotStop_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) doosan_m0609_msgs::msg::RobotStop(_init);
}

void RobotStop_fini_function(void * message_memory)
{
  auto typed_message = static_cast<doosan_m0609_msgs::msg::RobotStop *>(message_memory);
  typed_message->~RobotStop();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RobotStop_message_member_array[1] = {
  {
    "stop_mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs::msg::RobotStop, stop_mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RobotStop_message_members = {
  "doosan_m0609_msgs::msg",  // message namespace
  "RobotStop",  // message name
  1,  // number of fields
  sizeof(doosan_m0609_msgs::msg::RobotStop),
  RobotStop_message_member_array,  // message members
  RobotStop_init_function,  // function to initialize message memory (memory has to be allocated)
  RobotStop_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RobotStop_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RobotStop_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace doosan_m0609_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<doosan_m0609_msgs::msg::RobotStop>()
{
  return &::doosan_m0609_msgs::msg::rosidl_typesupport_introspection_cpp::RobotStop_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, doosan_m0609_msgs, msg, RobotStop)() {
  return &::doosan_m0609_msgs::msg::rosidl_typesupport_introspection_cpp::RobotStop_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from doosan_m0609_msgs:msg/TorqueRtStream.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "doosan_m0609_msgs/msg/detail/torque_rt_stream__struct.hpp"
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

void TorqueRtStream_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) doosan_m0609_msgs::msg::TorqueRtStream(_init);
}

void TorqueRtStream_fini_function(void * message_memory)
{
  auto typed_message = static_cast<doosan_m0609_msgs::msg::TorqueRtStream *>(message_memory);
  typed_message->~TorqueRtStream();
}

size_t size_function__TorqueRtStream__tor(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__TorqueRtStream__tor(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__TorqueRtStream__tor(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__TorqueRtStream__tor(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__TorqueRtStream__tor(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__TorqueRtStream__tor(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__TorqueRtStream__tor(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TorqueRtStream_message_member_array[2] = {
  {
    "tor",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs::msg::TorqueRtStream, tor),  // bytes offset in struct
    nullptr,  // default value
    size_function__TorqueRtStream__tor,  // size() function pointer
    get_const_function__TorqueRtStream__tor,  // get_const(index) function pointer
    get_function__TorqueRtStream__tor,  // get(index) function pointer
    fetch_function__TorqueRtStream__tor,  // fetch(index, &value) function pointer
    assign_function__TorqueRtStream__tor,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs::msg::TorqueRtStream, time),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TorqueRtStream_message_members = {
  "doosan_m0609_msgs::msg",  // message namespace
  "TorqueRtStream",  // message name
  2,  // number of fields
  sizeof(doosan_m0609_msgs::msg::TorqueRtStream),
  TorqueRtStream_message_member_array,  // message members
  TorqueRtStream_init_function,  // function to initialize message memory (memory has to be allocated)
  TorqueRtStream_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TorqueRtStream_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TorqueRtStream_message_members,
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
get_message_type_support_handle<doosan_m0609_msgs::msg::TorqueRtStream>()
{
  return &::doosan_m0609_msgs::msg::rosidl_typesupport_introspection_cpp::TorqueRtStream_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, doosan_m0609_msgs, msg, TorqueRtStream)() {
  return &::doosan_m0609_msgs::msg::rosidl_typesupport_introspection_cpp::TorqueRtStream_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

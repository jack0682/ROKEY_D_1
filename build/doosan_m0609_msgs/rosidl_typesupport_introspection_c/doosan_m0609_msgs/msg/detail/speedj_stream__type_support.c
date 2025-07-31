// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from doosan_m0609_msgs:msg/SpeedjStream.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "doosan_m0609_msgs/msg/detail/speedj_stream__rosidl_typesupport_introspection_c.h"
#include "doosan_m0609_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "doosan_m0609_msgs/msg/detail/speedj_stream__functions.h"
#include "doosan_m0609_msgs/msg/detail/speedj_stream__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__SpeedjStream_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  doosan_m0609_msgs__msg__SpeedjStream__init(message_memory);
}

void doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__SpeedjStream_fini_function(void * message_memory)
{
  doosan_m0609_msgs__msg__SpeedjStream__fini(message_memory);
}

size_t doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__size_function__SpeedjStream__vel(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__get_const_function__SpeedjStream__vel(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__get_function__SpeedjStream__vel(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__fetch_function__SpeedjStream__vel(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__get_const_function__SpeedjStream__vel(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__assign_function__SpeedjStream__vel(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__get_function__SpeedjStream__vel(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__size_function__SpeedjStream__acc(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__get_const_function__SpeedjStream__acc(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__get_function__SpeedjStream__acc(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__fetch_function__SpeedjStream__acc(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__get_const_function__SpeedjStream__acc(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__assign_function__SpeedjStream__acc(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__get_function__SpeedjStream__acc(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__SpeedjStream_message_member_array[3] = {
  {
    "vel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__msg__SpeedjStream, vel),  // bytes offset in struct
    NULL,  // default value
    doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__size_function__SpeedjStream__vel,  // size() function pointer
    doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__get_const_function__SpeedjStream__vel,  // get_const(index) function pointer
    doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__get_function__SpeedjStream__vel,  // get(index) function pointer
    doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__fetch_function__SpeedjStream__vel,  // fetch(index, &value) function pointer
    doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__assign_function__SpeedjStream__vel,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acc",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__msg__SpeedjStream, acc),  // bytes offset in struct
    NULL,  // default value
    doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__size_function__SpeedjStream__acc,  // size() function pointer
    doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__get_const_function__SpeedjStream__acc,  // get_const(index) function pointer
    doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__get_function__SpeedjStream__acc,  // get(index) function pointer
    doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__fetch_function__SpeedjStream__acc,  // fetch(index, &value) function pointer
    doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__assign_function__SpeedjStream__acc,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__msg__SpeedjStream, time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__SpeedjStream_message_members = {
  "doosan_m0609_msgs__msg",  // message namespace
  "SpeedjStream",  // message name
  3,  // number of fields
  sizeof(doosan_m0609_msgs__msg__SpeedjStream),
  doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__SpeedjStream_message_member_array,  // message members
  doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__SpeedjStream_init_function,  // function to initialize message memory (memory has to be allocated)
  doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__SpeedjStream_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__SpeedjStream_message_type_support_handle = {
  0,
  &doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__SpeedjStream_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_doosan_m0609_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_msgs, msg, SpeedjStream)() {
  if (!doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__SpeedjStream_message_type_support_handle.typesupport_identifier) {
    doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__SpeedjStream_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &doosan_m0609_msgs__msg__SpeedjStream__rosidl_typesupport_introspection_c__SpeedjStream_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

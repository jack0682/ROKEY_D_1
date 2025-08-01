// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from doosan_m0609_controller:msg/JointState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "doosan_m0609_controller/msg/detail/joint_state__rosidl_typesupport_introspection_c.h"
#include "doosan_m0609_controller/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "doosan_m0609_controller/msg/detail/joint_state__functions.h"
#include "doosan_m0609_controller/msg/detail/joint_state__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__JointState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  doosan_m0609_controller__msg__JointState__init(message_memory);
}

void doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__JointState_fini_function(void * message_memory)
{
  doosan_m0609_controller__msg__JointState__fini(message_memory);
}

size_t doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__size_function__JointState__position(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__get_const_function__JointState__position(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__get_function__JointState__position(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__fetch_function__JointState__position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__get_const_function__JointState__position(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__assign_function__JointState__position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__get_function__JointState__position(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__size_function__JointState__velocity(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__get_const_function__JointState__velocity(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__get_function__JointState__velocity(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__fetch_function__JointState__velocity(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__get_const_function__JointState__velocity(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__assign_function__JointState__velocity(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__get_function__JointState__velocity(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__size_function__JointState__effort(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__get_const_function__JointState__effort(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__get_function__JointState__effort(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__fetch_function__JointState__effort(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__get_const_function__JointState__effort(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__assign_function__JointState__effort(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__get_function__JointState__effort(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__JointState_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_controller__msg__JointState, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_controller__msg__JointState, position),  // bytes offset in struct
    NULL,  // default value
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__size_function__JointState__position,  // size() function pointer
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__get_const_function__JointState__position,  // get_const(index) function pointer
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__get_function__JointState__position,  // get(index) function pointer
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__fetch_function__JointState__position,  // fetch(index, &value) function pointer
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__assign_function__JointState__position,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_controller__msg__JointState, velocity),  // bytes offset in struct
    NULL,  // default value
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__size_function__JointState__velocity,  // size() function pointer
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__get_const_function__JointState__velocity,  // get_const(index) function pointer
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__get_function__JointState__velocity,  // get(index) function pointer
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__fetch_function__JointState__velocity,  // fetch(index, &value) function pointer
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__assign_function__JointState__velocity,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "effort",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_controller__msg__JointState, effort),  // bytes offset in struct
    NULL,  // default value
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__size_function__JointState__effort,  // size() function pointer
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__get_const_function__JointState__effort,  // get_const(index) function pointer
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__get_function__JointState__effort,  // get(index) function pointer
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__fetch_function__JointState__effort,  // fetch(index, &value) function pointer
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__assign_function__JointState__effort,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__JointState_message_members = {
  "doosan_m0609_controller__msg",  // message namespace
  "JointState",  // message name
  4,  // number of fields
  sizeof(doosan_m0609_controller__msg__JointState),
  doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__JointState_message_member_array,  // message members
  doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__JointState_init_function,  // function to initialize message memory (memory has to be allocated)
  doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__JointState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__JointState_message_type_support_handle = {
  0,
  &doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__JointState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_doosan_m0609_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_controller, msg, JointState)() {
  doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__JointState_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__JointState_message_type_support_handle.typesupport_identifier) {
    doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__JointState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &doosan_m0609_controller__msg__JointState__rosidl_typesupport_introspection_c__JointState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

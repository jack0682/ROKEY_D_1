// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from doosan_m0609_msgs:msg/RobotError.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "doosan_m0609_msgs/msg/detail/robot_error__rosidl_typesupport_introspection_c.h"
#include "doosan_m0609_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "doosan_m0609_msgs/msg/detail/robot_error__functions.h"
#include "doosan_m0609_msgs/msg/detail/robot_error__struct.h"


// Include directives for member types
// Member `msg1`
// Member `msg2`
// Member `msg3`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void doosan_m0609_msgs__msg__RobotError__rosidl_typesupport_introspection_c__RobotError_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  doosan_m0609_msgs__msg__RobotError__init(message_memory);
}

void doosan_m0609_msgs__msg__RobotError__rosidl_typesupport_introspection_c__RobotError_fini_function(void * message_memory)
{
  doosan_m0609_msgs__msg__RobotError__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember doosan_m0609_msgs__msg__RobotError__rosidl_typesupport_introspection_c__RobotError_message_member_array[6] = {
  {
    "level",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__msg__RobotError, level),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "group",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__msg__RobotError, group),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "code",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__msg__RobotError, code),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "msg1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__msg__RobotError, msg1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "msg2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__msg__RobotError, msg2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "msg3",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__msg__RobotError, msg3),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers doosan_m0609_msgs__msg__RobotError__rosidl_typesupport_introspection_c__RobotError_message_members = {
  "doosan_m0609_msgs__msg",  // message namespace
  "RobotError",  // message name
  6,  // number of fields
  sizeof(doosan_m0609_msgs__msg__RobotError),
  doosan_m0609_msgs__msg__RobotError__rosidl_typesupport_introspection_c__RobotError_message_member_array,  // message members
  doosan_m0609_msgs__msg__RobotError__rosidl_typesupport_introspection_c__RobotError_init_function,  // function to initialize message memory (memory has to be allocated)
  doosan_m0609_msgs__msg__RobotError__rosidl_typesupport_introspection_c__RobotError_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t doosan_m0609_msgs__msg__RobotError__rosidl_typesupport_introspection_c__RobotError_message_type_support_handle = {
  0,
  &doosan_m0609_msgs__msg__RobotError__rosidl_typesupport_introspection_c__RobotError_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_doosan_m0609_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_msgs, msg, RobotError)() {
  if (!doosan_m0609_msgs__msg__RobotError__rosidl_typesupport_introspection_c__RobotError_message_type_support_handle.typesupport_identifier) {
    doosan_m0609_msgs__msg__RobotError__rosidl_typesupport_introspection_c__RobotError_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &doosan_m0609_msgs__msg__RobotError__rosidl_typesupport_introspection_c__RobotError_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

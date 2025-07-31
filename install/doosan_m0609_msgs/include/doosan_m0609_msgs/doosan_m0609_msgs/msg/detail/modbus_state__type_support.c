// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from doosan_m0609_msgs:msg/ModbusState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "doosan_m0609_msgs/msg/detail/modbus_state__rosidl_typesupport_introspection_c.h"
#include "doosan_m0609_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "doosan_m0609_msgs/msg/detail/modbus_state__functions.h"
#include "doosan_m0609_msgs/msg/detail/modbus_state__struct.h"


// Include directives for member types
// Member `modbus_symbol`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void doosan_m0609_msgs__msg__ModbusState__rosidl_typesupport_introspection_c__ModbusState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  doosan_m0609_msgs__msg__ModbusState__init(message_memory);
}

void doosan_m0609_msgs__msg__ModbusState__rosidl_typesupport_introspection_c__ModbusState_fini_function(void * message_memory)
{
  doosan_m0609_msgs__msg__ModbusState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember doosan_m0609_msgs__msg__ModbusState__rosidl_typesupport_introspection_c__ModbusState_message_member_array[2] = {
  {
    "modbus_symbol",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__msg__ModbusState, modbus_symbol),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "modbus_value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__msg__ModbusState, modbus_value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers doosan_m0609_msgs__msg__ModbusState__rosidl_typesupport_introspection_c__ModbusState_message_members = {
  "doosan_m0609_msgs__msg",  // message namespace
  "ModbusState",  // message name
  2,  // number of fields
  sizeof(doosan_m0609_msgs__msg__ModbusState),
  doosan_m0609_msgs__msg__ModbusState__rosidl_typesupport_introspection_c__ModbusState_message_member_array,  // message members
  doosan_m0609_msgs__msg__ModbusState__rosidl_typesupport_introspection_c__ModbusState_init_function,  // function to initialize message memory (memory has to be allocated)
  doosan_m0609_msgs__msg__ModbusState__rosidl_typesupport_introspection_c__ModbusState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t doosan_m0609_msgs__msg__ModbusState__rosidl_typesupport_introspection_c__ModbusState_message_type_support_handle = {
  0,
  &doosan_m0609_msgs__msg__ModbusState__rosidl_typesupport_introspection_c__ModbusState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_doosan_m0609_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_msgs, msg, ModbusState)() {
  if (!doosan_m0609_msgs__msg__ModbusState__rosidl_typesupport_introspection_c__ModbusState_message_type_support_handle.typesupport_identifier) {
    doosan_m0609_msgs__msg__ModbusState__rosidl_typesupport_introspection_c__ModbusState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &doosan_m0609_msgs__msg__ModbusState__rosidl_typesupport_introspection_c__ModbusState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/ConfigCreateModbus.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_CREATE_MODBUS__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_CREATE_MODBUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
// Member 'ip'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ConfigCreateModbus in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__ConfigCreateModbus_Request
{
  /// modbus signal symbol
  rosidl_runtime_c__String name;
  /// external device ip
  rosidl_runtime_c__String ip;
  /// external device port
  int32_t port;
  /// <MODBUS_REGISTER_TYPE>(0: discrete input, 1: coil, 2: input register, 3: holding register)
  int8_t reg_type;
  /// modbus signal index(0 ~ 9999)
  int8_t index;
  /// modbus singla value(unsigned value ; 0 ~ 65535)
  int8_t value;
  /// Slave ID of the ModbusTCP(0: Broadcase address or 1-247 or 255: Default value for ModbusTCP)
  /// <slave_id is only available in M2.40 or later versions>
  int32_t slave_id;
} doosan_m0609_msgs__srv__ConfigCreateModbus_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__ConfigCreateModbus_Request.
typedef struct doosan_m0609_msgs__srv__ConfigCreateModbus_Request__Sequence
{
  doosan_m0609_msgs__srv__ConfigCreateModbus_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__ConfigCreateModbus_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ConfigCreateModbus in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__ConfigCreateModbus_Response
{
  bool success;
} doosan_m0609_msgs__srv__ConfigCreateModbus_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__ConfigCreateModbus_Response.
typedef struct doosan_m0609_msgs__srv__ConfigCreateModbus_Response__Sequence
{
  doosan_m0609_msgs__srv__ConfigCreateModbus_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__ConfigCreateModbus_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_CREATE_MODBUS__STRUCT_H_

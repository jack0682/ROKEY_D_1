// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/SetToolDigitalOutput.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_TOOL_DIGITAL_OUTPUT__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_TOOL_DIGITAL_OUTPUT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetToolDigitalOutput in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__SetToolDigitalOutput_Request
{
  /// flange digital output port(1 ~ 6)
  int8_t index;
  /// 0 : ON, 1 : OFF
  int8_t value;
} doosan_m0609_msgs__srv__SetToolDigitalOutput_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__SetToolDigitalOutput_Request.
typedef struct doosan_m0609_msgs__srv__SetToolDigitalOutput_Request__Sequence
{
  doosan_m0609_msgs__srv__SetToolDigitalOutput_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__SetToolDigitalOutput_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetToolDigitalOutput in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__SetToolDigitalOutput_Response
{
  bool success;
} doosan_m0609_msgs__srv__SetToolDigitalOutput_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__SetToolDigitalOutput_Response.
typedef struct doosan_m0609_msgs__srv__SetToolDigitalOutput_Response__Sequence
{
  doosan_m0609_msgs__srv__SetToolDigitalOutput_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__SetToolDigitalOutput_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_TOOL_DIGITAL_OUTPUT__STRUCT_H_

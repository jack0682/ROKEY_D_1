// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/SetCtrlBoxAnalogOutputType.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_CTRL_BOX_ANALOG_OUTPUT_TYPE__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_CTRL_BOX_ANALOG_OUTPUT_TYPE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetCtrlBoxAnalogOutputType in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__SetCtrlBoxAnalogOutputType_Request
{
  /// 1 = ch1, 2= ch2
  int8_t channel;
  /// 0 = current, 1 = voltage
  int8_t mode;
} doosan_m0609_msgs__srv__SetCtrlBoxAnalogOutputType_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__SetCtrlBoxAnalogOutputType_Request.
typedef struct doosan_m0609_msgs__srv__SetCtrlBoxAnalogOutputType_Request__Sequence
{
  doosan_m0609_msgs__srv__SetCtrlBoxAnalogOutputType_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__SetCtrlBoxAnalogOutputType_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetCtrlBoxAnalogOutputType in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__SetCtrlBoxAnalogOutputType_Response
{
  bool success;
} doosan_m0609_msgs__srv__SetCtrlBoxAnalogOutputType_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__SetCtrlBoxAnalogOutputType_Response.
typedef struct doosan_m0609_msgs__srv__SetCtrlBoxAnalogOutputType_Response__Sequence
{
  doosan_m0609_msgs__srv__SetCtrlBoxAnalogOutputType_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__SetCtrlBoxAnalogOutputType_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_CTRL_BOX_ANALOG_OUTPUT_TYPE__STRUCT_H_

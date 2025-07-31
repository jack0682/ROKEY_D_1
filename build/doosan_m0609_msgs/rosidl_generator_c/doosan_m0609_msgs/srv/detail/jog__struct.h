// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/Jog.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__JOG__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__JOG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Jog in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__Jog_Request
{
  /// 0 ~ 5 : JOINT 1 ~ 6
  /// 6 ~ 11: TASK 1 ~ 6 (X,Y,Z,rx,ry,rz)
  int8_t jog_axis;
  /// 0 : MOVE_REFERENCE_BASE, 1 : MOVE_REFERENCE_TOOL
  int8_t move_reference;
  /// jog speed : + forward , 0=stop, - backward
  double speed;
} doosan_m0609_msgs__srv__Jog_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__Jog_Request.
typedef struct doosan_m0609_msgs__srv__Jog_Request__Sequence
{
  doosan_m0609_msgs__srv__Jog_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__Jog_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Jog in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__Jog_Response
{
  bool success;
} doosan_m0609_msgs__srv__Jog_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__Jog_Response.
typedef struct doosan_m0609_msgs__srv__Jog_Response__Sequence
{
  doosan_m0609_msgs__srv__Jog_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__Jog_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__JOG__STRUCT_H_

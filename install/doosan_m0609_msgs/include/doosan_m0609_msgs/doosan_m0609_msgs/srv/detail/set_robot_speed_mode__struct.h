// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/SetRobotSpeedMode.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_ROBOT_SPEED_MODE__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_ROBOT_SPEED_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetRobotSpeedMode in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__SetRobotSpeedMode_Request
{
  /// 0 : SPEED_NORMAL_MODE, 1 : SPEED_REDUCED_MODE
  int8_t speed_mode;
} doosan_m0609_msgs__srv__SetRobotSpeedMode_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__SetRobotSpeedMode_Request.
typedef struct doosan_m0609_msgs__srv__SetRobotSpeedMode_Request__Sequence
{
  doosan_m0609_msgs__srv__SetRobotSpeedMode_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__SetRobotSpeedMode_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetRobotSpeedMode in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__SetRobotSpeedMode_Response
{
  bool success;
} doosan_m0609_msgs__srv__SetRobotSpeedMode_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__SetRobotSpeedMode_Response.
typedef struct doosan_m0609_msgs__srv__SetRobotSpeedMode_Response__Sequence
{
  doosan_m0609_msgs__srv__SetRobotSpeedMode_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__SetRobotSpeedMode_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_ROBOT_SPEED_MODE__STRUCT_H_

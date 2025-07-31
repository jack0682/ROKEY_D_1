// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:msg/RobotError.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_ERROR__STRUCT_H_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_ERROR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'msg1'
// Member 'msg2'
// Member 'msg3'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/RobotError in the package doosan_m0609_msgs.
/**
  * ____________________________________________________________________________________________
  *  [ robot error msg ] 
  * ____________________________________________________________________________________________
 */
typedef struct doosan_m0609_msgs__msg__RobotError
{
  /// INFO =1, WARN =2, ERROR =3
  int32_t level;
  /// SYSTEM =1, MOTION =2, TP =3, INVERTER =4, SAFETY_CONTROLLER =5
  int32_t group;
  /// error code
  int32_t code;
  /// error msg 1
  rosidl_runtime_c__String msg1;
  /// error msg 2
  rosidl_runtime_c__String msg2;
  /// error msg 3
  rosidl_runtime_c__String msg3;
} doosan_m0609_msgs__msg__RobotError;

// Struct for a sequence of doosan_m0609_msgs__msg__RobotError.
typedef struct doosan_m0609_msgs__msg__RobotError__Sequence
{
  doosan_m0609_msgs__msg__RobotError * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__msg__RobotError__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_ERROR__STRUCT_H_

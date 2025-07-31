// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:msg/AlterMotionStream.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__ALTER_MOTION_STREAM__STRUCT_H_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__ALTER_MOTION_STREAM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/AlterMotionStream in the package doosan_m0609_msgs.
/**
  * ____________________________________________________________________________________________
  *  alter_motion  
  *
  * ____________________________________________________________________________________________
 */
typedef struct doosan_m0609_msgs__msg__AlterMotionStream
{
  /// position
  double pos[6];
} doosan_m0609_msgs__msg__AlterMotionStream;

// Struct for a sequence of doosan_m0609_msgs__msg__AlterMotionStream.
typedef struct doosan_m0609_msgs__msg__AlterMotionStream__Sequence
{
  doosan_m0609_msgs__msg__AlterMotionStream * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__msg__AlterMotionStream__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__ALTER_MOTION_STREAM__STRUCT_H_

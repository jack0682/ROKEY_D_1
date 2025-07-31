// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:msg/ServojStream.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__SERVOJ_STREAM__STRUCT_H_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__SERVOJ_STREAM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ServojStream in the package doosan_m0609_msgs.
/**
  * ____________________________________________________________________________________________
  *  servoj
  *
  * ____________________________________________________________________________________________
 */
typedef struct doosan_m0609_msgs__msg__ServojStream
{
  /// position
  double pos[6];
  /// velocity
  double vel[6];
  /// acceleration
  double acc[6];
  /// time
  double time;
  /// servoj mode; 0:DR_SERVO_OVERRIDE, 1:DR_SERVO_QUEUE
  int8_t mode;
} doosan_m0609_msgs__msg__ServojStream;

// Struct for a sequence of doosan_m0609_msgs__msg__ServojStream.
typedef struct doosan_m0609_msgs__msg__ServojStream__Sequence
{
  doosan_m0609_msgs__msg__ServojStream * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__msg__ServojStream__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__SERVOJ_STREAM__STRUCT_H_

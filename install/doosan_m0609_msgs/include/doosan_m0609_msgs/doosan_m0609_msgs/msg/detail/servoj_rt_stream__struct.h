// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:msg/ServojRtStream.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__SERVOJ_RT_STREAM__STRUCT_H_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__SERVOJ_RT_STREAM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ServojRtStream in the package doosan_m0609_msgs.
/**
  * ____________________________________________________________________________________________
  *  servoj_rt
  *
  * ____________________________________________________________________________________________
 */
typedef struct doosan_m0609_msgs__msg__ServojRtStream
{
  /// position
  double pos[6];
  /// velocity
  double vel[6];
  /// acceleration
  double acc[6];
  /// time
  double time;
} doosan_m0609_msgs__msg__ServojRtStream;

// Struct for a sequence of doosan_m0609_msgs__msg__ServojRtStream.
typedef struct doosan_m0609_msgs__msg__ServojRtStream__Sequence
{
  doosan_m0609_msgs__msg__ServojRtStream * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__msg__ServojRtStream__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__SERVOJ_RT_STREAM__STRUCT_H_

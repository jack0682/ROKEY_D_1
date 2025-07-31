// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:msg/LogAlarm.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__LOG_ALARM__STRUCT_H_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__LOG_ALARM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'param'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/LogAlarm in the package doosan_m0609_msgs.
/**
  * ____________________________________________________________________________________________
  *  log of alarm
  * ____________________________________________________________________________________________
 */
typedef struct doosan_m0609_msgs__msg__LogAlarm
{
  int32_t level;
  int32_t group;
  int32_t index;
  rosidl_runtime_c__String param[3];
} doosan_m0609_msgs__msg__LogAlarm;

// Struct for a sequence of doosan_m0609_msgs__msg__LogAlarm.
typedef struct doosan_m0609_msgs__msg__LogAlarm__Sequence
{
  doosan_m0609_msgs__msg__LogAlarm * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__msg__LogAlarm__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__LOG_ALARM__STRUCT_H_

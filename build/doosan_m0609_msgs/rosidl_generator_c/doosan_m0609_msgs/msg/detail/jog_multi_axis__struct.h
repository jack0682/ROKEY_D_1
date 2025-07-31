// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:msg/JogMultiAxis.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__JOG_MULTI_AXIS__STRUCT_H_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__JOG_MULTI_AXIS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/JogMultiAxis in the package doosan_m0609_msgs.
/**
  * ____________________________________________________________________________________________
  *  multi jog
  *  multi jog speed = (250mm/s x 1.73) x unit vecter x speed 
  * ____________________________________________________________________________________________
 */
typedef struct doosan_m0609_msgs__msg__JogMultiAxis
{
  /// unit vecter of Task space [Tx, Ty, Tz, Rx, Ry, Rz] : -1.0 ~ +1.0
  double jog_axis[6];
  /// 0 : MOVE_REFERENCE_BASE, 1 : MOVE_REFERENCE_TOOL, 2 : MOVE_REFERENCE_WORLD
  int8_t move_reference;
  /// jog speed
  double speed;
} doosan_m0609_msgs__msg__JogMultiAxis;

// Struct for a sequence of doosan_m0609_msgs__msg__JogMultiAxis.
typedef struct doosan_m0609_msgs__msg__JogMultiAxis__Sequence
{
  doosan_m0609_msgs__msg__JogMultiAxis * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__msg__JogMultiAxis__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__JOG_MULTI_AXIS__STRUCT_H_

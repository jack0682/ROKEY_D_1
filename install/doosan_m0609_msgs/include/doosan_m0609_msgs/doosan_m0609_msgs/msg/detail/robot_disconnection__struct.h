// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:msg/RobotDisconnection.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_DISCONNECTION__STRUCT_H_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_DISCONNECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/RobotDisconnection in the package doosan_m0609_msgs.
/**
  * Event driven when the robot connection losts.
 */
typedef struct doosan_m0609_msgs__msg__RobotDisconnection
{
  uint8_t structure_needs_at_least_one_member;
} doosan_m0609_msgs__msg__RobotDisconnection;

// Struct for a sequence of doosan_m0609_msgs__msg__RobotDisconnection.
typedef struct doosan_m0609_msgs__msg__RobotDisconnection__Sequence
{
  doosan_m0609_msgs__msg__RobotDisconnection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__msg__RobotDisconnection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_DISCONNECTION__STRUCT_H_

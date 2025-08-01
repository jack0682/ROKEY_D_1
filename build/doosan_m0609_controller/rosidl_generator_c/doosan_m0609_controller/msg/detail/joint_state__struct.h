// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_controller:msg/JointState.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_CONTROLLER__MSG__DETAIL__JOINT_STATE__STRUCT_H_
#define DOOSAN_M0609_CONTROLLER__MSG__DETAIL__JOINT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/JointState in the package doosan_m0609_controller.
/**
  * Joint state message for M0609 (6-DOF)
 */
typedef struct doosan_m0609_controller__msg__JointState
{
  std_msgs__msg__Header header;
  /// Joint positions in radians
  double position[6];
  /// Joint velocities in rad/s
  double velocity[6];
  /// Joint efforts/torques in Nm
  double effort[6];
} doosan_m0609_controller__msg__JointState;

// Struct for a sequence of doosan_m0609_controller__msg__JointState.
typedef struct doosan_m0609_controller__msg__JointState__Sequence
{
  doosan_m0609_controller__msg__JointState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_controller__msg__JointState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_CONTROLLER__MSG__DETAIL__JOINT_STATE__STRUCT_H_

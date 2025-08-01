// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_controller:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_CONTROLLER__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
#define DOOSAN_M0609_CONTROLLER__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_

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
// Member 'robot_state'
// Member 'error_message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/RobotStatus in the package doosan_m0609_controller.
/**
  * Robot status message
 */
typedef struct doosan_m0609_controller__msg__RobotStatus
{
  std_msgs__msg__Header header;
  /// Connection status
  bool is_connected;
  /// Robot enabled status
  bool is_enabled;
  /// Control authority status
  bool has_control_authority;
  /// Robot state string
  rosidl_runtime_c__String robot_state;
  /// Any error messages
  rosidl_runtime_c__String error_message;
} doosan_m0609_controller__msg__RobotStatus;

// Struct for a sequence of doosan_m0609_controller__msg__RobotStatus.
typedef struct doosan_m0609_controller__msg__RobotStatus__Sequence
{
  doosan_m0609_controller__msg__RobotStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_controller__msg__RobotStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_CONTROLLER__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_

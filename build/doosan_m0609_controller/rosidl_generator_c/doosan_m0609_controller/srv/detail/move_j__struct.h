// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_controller:srv/MoveJ.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_CONTROLLER__SRV__DETAIL__MOVE_J__STRUCT_H_
#define DOOSAN_M0609_CONTROLLER__SRV__DETAIL__MOVE_J__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/MoveJ in the package doosan_m0609_controller.
typedef struct doosan_m0609_controller__srv__MoveJ_Request
{
  /// Target joint positions in radians
  double target_joints[6];
  /// Velocity ratio (0.0 ~ 1.0)
  double velocity_ratio;
  /// Acceleration ratio (0.0 ~ 1.0)
  double acceleration_ratio;
  /// Timeout in seconds
  double time_out;
} doosan_m0609_controller__srv__MoveJ_Request;

// Struct for a sequence of doosan_m0609_controller__srv__MoveJ_Request.
typedef struct doosan_m0609_controller__srv__MoveJ_Request__Sequence
{
  doosan_m0609_controller__srv__MoveJ_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_controller__srv__MoveJ_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/MoveJ in the package doosan_m0609_controller.
typedef struct doosan_m0609_controller__srv__MoveJ_Response
{
  /// Success flag
  bool success;
  /// Result message
  rosidl_runtime_c__String message;
} doosan_m0609_controller__srv__MoveJ_Response;

// Struct for a sequence of doosan_m0609_controller__srv__MoveJ_Response.
typedef struct doosan_m0609_controller__srv__MoveJ_Response__Sequence
{
  doosan_m0609_controller__srv__MoveJ_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_controller__srv__MoveJ_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_CONTROLLER__SRV__DETAIL__MOVE_J__STRUCT_H_

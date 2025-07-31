// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/MoveJoint.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_JOINT__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_JOINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/MoveJoint in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__MoveJoint_Request
{
  /// target joint angle list
  double pos[6];
  /// set velocity:
  double vel;
  /// set acceleration:
  double acc;
  /// = 0.0       # Time
  double time;
  /// =0.0      # Radius under blending mode
  double radius;
  /// = 0         # MOVE_MODE_ABSOLUTE=0, MOVE_MODE_RELATIVE=1
  int8_t mode;
  /// = 0    # BLENDING_SPEED_TYPE_DUPLICATE=0, BLENDING_SPEED_TYPE_OVERRIDE=1
  int8_t blend_type;
  /// =0      # SYNC = 0, ASYNC = 1
  int8_t sync_type;
} doosan_m0609_msgs__srv__MoveJoint_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__MoveJoint_Request.
typedef struct doosan_m0609_msgs__srv__MoveJoint_Request__Sequence
{
  doosan_m0609_msgs__srv__MoveJoint_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__MoveJoint_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/MoveJoint in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__MoveJoint_Response
{
  bool success;
} doosan_m0609_msgs__srv__MoveJoint_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__MoveJoint_Response.
typedef struct doosan_m0609_msgs__srv__MoveJoint_Response__Sequence
{
  doosan_m0609_msgs__srv__MoveJoint_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__MoveJoint_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_JOINT__STRUCT_H_

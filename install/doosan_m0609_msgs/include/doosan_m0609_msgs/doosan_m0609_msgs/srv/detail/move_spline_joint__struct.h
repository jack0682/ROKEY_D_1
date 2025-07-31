// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/MoveSplineJoint.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_SPLINE_JOINT__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_SPLINE_JOINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pos'
#include "std_msgs/msg/detail/float64_multi_array__struct.h"

/// Struct defined in srv/MoveSplineJoint in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__MoveSplineJoint_Request
{
  /// target [100][6] pos
  std_msgs__msg__Float64MultiArray__Sequence pos;
  /// target cnt
  int8_t pos_cnt;
  /// set joint velocity:
  double vel[6];
  /// set joint acceleration:
  double acc[6];
  /// = 0.0                   # Time
  double time;
  /// = 0                     # MOVE_MODE_ABSOLUTE=0, MOVE_MODE_RELATIVE=1
  int8_t mode;
  /// =0                 # SYNC = 0, ASYNC = 1
  int8_t sync_type;
} doosan_m0609_msgs__srv__MoveSplineJoint_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__MoveSplineJoint_Request.
typedef struct doosan_m0609_msgs__srv__MoveSplineJoint_Request__Sequence
{
  doosan_m0609_msgs__srv__MoveSplineJoint_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__MoveSplineJoint_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/MoveSplineJoint in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__MoveSplineJoint_Response
{
  bool success;
} doosan_m0609_msgs__srv__MoveSplineJoint_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__MoveSplineJoint_Response.
typedef struct doosan_m0609_msgs__srv__MoveSplineJoint_Response__Sequence
{
  doosan_m0609_msgs__srv__MoveSplineJoint_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__MoveSplineJoint_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_SPLINE_JOINT__STRUCT_H_

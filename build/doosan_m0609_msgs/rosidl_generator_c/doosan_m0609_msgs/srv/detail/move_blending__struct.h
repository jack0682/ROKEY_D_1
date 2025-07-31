// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/MoveBlending.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_BLENDING__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_BLENDING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'segment'
#include "std_msgs/msg/detail/float64_multi_array__struct.h"

/// Struct defined in srv/MoveBlending in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__MoveBlending_Request
{
  /// 50 x (pos1[6]:pos2[6]:type[1]:radius[1])
  std_msgs__msg__Float64MultiArray__Sequence segment;
  /// target cnt
  int8_t pos_cnt;
  /// set velocity: [mm/sec], [deg/sec]
  double vel[2];
  /// set acceleration: [mm/sec2], [deg/sec2]
  double acc[2];
  /// = 0.0          # Time
  double time;
  /// DR_BASE(0), DR_TOOL(1), DR_WORLD(2)
  /// <DR_WORLD is only available in M2.40 or later
  int8_t ref;
  /// = 0            # MOVE_MODE_ABSOLUTE=0, MOVE_MODE_RELATIVE=1
  int8_t mode;
  /// =0         # SYNC = 0, ASYNC = 1
  int8_t sync_type;
} doosan_m0609_msgs__srv__MoveBlending_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__MoveBlending_Request.
typedef struct doosan_m0609_msgs__srv__MoveBlending_Request__Sequence
{
  doosan_m0609_msgs__srv__MoveBlending_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__MoveBlending_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/MoveBlending in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__MoveBlending_Response
{
  bool success;
} doosan_m0609_msgs__srv__MoveBlending_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__MoveBlending_Response.
typedef struct doosan_m0609_msgs__srv__MoveBlending_Response__Sequence
{
  doosan_m0609_msgs__srv__MoveBlending_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__MoveBlending_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_BLENDING__STRUCT_H_

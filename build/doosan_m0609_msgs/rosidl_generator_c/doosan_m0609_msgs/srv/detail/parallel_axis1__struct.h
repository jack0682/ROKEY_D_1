// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/ParallelAxis1.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__PARALLEL_AXIS1__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__PARALLEL_AXIS1__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ParallelAxis1 in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__ParallelAxis1_Request
{
  /// task pos(posx)
  double x1[6];
  /// task pos(posx)
  double x2[6];
  /// task pos(posx)
  double x3[6];
  /// DR_AXIS_X(0), DR_AXIS_Y(1), DR_AXIS_Z(2)
  int8_t axis;
  /// = 0   # DR_BASE(0), DR_WORLD(2), user coord(101~200)
  ///  <ref is only available in M2.40 or later>
  int8_t ref;
} doosan_m0609_msgs__srv__ParallelAxis1_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__ParallelAxis1_Request.
typedef struct doosan_m0609_msgs__srv__ParallelAxis1_Request__Sequence
{
  doosan_m0609_msgs__srv__ParallelAxis1_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__ParallelAxis1_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ParallelAxis1 in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__ParallelAxis1_Response
{
  bool success;
} doosan_m0609_msgs__srv__ParallelAxis1_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__ParallelAxis1_Response.
typedef struct doosan_m0609_msgs__srv__ParallelAxis1_Response__Sequence
{
  doosan_m0609_msgs__srv__ParallelAxis1_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__ParallelAxis1_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__PARALLEL_AXIS1__STRUCT_H_

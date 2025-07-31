// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/AlignAxis2.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__ALIGN_AXIS2__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__ALIGN_AXIS2__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/AlignAxis2 in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__AlignAxis2_Request
{
  /// target vector
  double target_vect[3];
  /// source vector
  double source_vect[3];
  /// DR_AXIS_X(0), DR_AXIS_Y(1), DR_AXIS_Z(2)
  int8_t axis;
  /// DR_BASE(0), DR_WORLD(2), user coord(101~200)
  /// <ref is only available in M2.40 or later>
  int8_t ref;
} doosan_m0609_msgs__srv__AlignAxis2_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__AlignAxis2_Request.
typedef struct doosan_m0609_msgs__srv__AlignAxis2_Request__Sequence
{
  doosan_m0609_msgs__srv__AlignAxis2_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__AlignAxis2_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/AlignAxis2 in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__AlignAxis2_Response
{
  bool success;
} doosan_m0609_msgs__srv__AlignAxis2_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__AlignAxis2_Response.
typedef struct doosan_m0609_msgs__srv__AlignAxis2_Response__Sequence
{
  doosan_m0609_msgs__srv__AlignAxis2_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__AlignAxis2_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__ALIGN_AXIS2__STRUCT_H_

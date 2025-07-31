// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/CoordTransform.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__COORD_TRANSFORM__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__COORD_TRANSFORM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/CoordTransform in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__CoordTransform_Request
{
  /// task pos(posx)
  double pos_in[6];
  /// DR_BASE(0), DR_TOOL(1), DR_WORLD(2), user coord(101~200)
  /// <ref is only available in M2.40 or later>
  int8_t ref_in;
  /// DR_BASE(0), DR_TOOL(1), DR_WORLD(2), user coord(101~200)
  /// <ref is only available in M2.40 or later>
  int8_t ref_out;
} doosan_m0609_msgs__srv__CoordTransform_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__CoordTransform_Request.
typedef struct doosan_m0609_msgs__srv__CoordTransform_Request__Sequence
{
  doosan_m0609_msgs__srv__CoordTransform_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__CoordTransform_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/CoordTransform in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__CoordTransform_Response
{
  /// task pos(posx)
  double conv_posx[6];
  bool success;
} doosan_m0609_msgs__srv__CoordTransform_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__CoordTransform_Response.
typedef struct doosan_m0609_msgs__srv__CoordTransform_Response__Sequence
{
  doosan_m0609_msgs__srv__CoordTransform_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__CoordTransform_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__COORD_TRANSFORM__STRUCT_H_

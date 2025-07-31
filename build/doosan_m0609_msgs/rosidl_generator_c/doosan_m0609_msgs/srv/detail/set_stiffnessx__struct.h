// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/SetStiffnessx.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_STIFFNESSX__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_STIFFNESSX__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetStiffnessx in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__SetStiffnessx_Request
{
  /// default[500, 500, 500, 100, 100, 100], Three translational stiffnesses + Three rotational stiffnesses
  double stx[6];
  /// the preset reference coordinate system.
  int8_t ref;
  /// Stiffness varying time(0 ~ 1.0), Linear transition during the specified time
  double time;
} doosan_m0609_msgs__srv__SetStiffnessx_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__SetStiffnessx_Request.
typedef struct doosan_m0609_msgs__srv__SetStiffnessx_Request__Sequence
{
  doosan_m0609_msgs__srv__SetStiffnessx_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__SetStiffnessx_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetStiffnessx in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__SetStiffnessx_Response
{
  bool success;
} doosan_m0609_msgs__srv__SetStiffnessx_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__SetStiffnessx_Response.
typedef struct doosan_m0609_msgs__srv__SetStiffnessx_Response__Sequence
{
  doosan_m0609_msgs__srv__SetStiffnessx_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__SetStiffnessx_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_STIFFNESSX__STRUCT_H_

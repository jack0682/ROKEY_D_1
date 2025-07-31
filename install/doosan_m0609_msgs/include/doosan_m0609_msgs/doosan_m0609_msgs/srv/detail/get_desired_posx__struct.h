// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/GetDesiredPosx.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_DESIRED_POSX__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_DESIRED_POSX__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetDesiredPosx in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__GetDesiredPosx_Request
{
  /// = 0   # DR_BASE(0), DR_WORLD(2), user coord(101~200)
  ///  <ref is only available in M2.40 or later>
  int8_t ref;
} doosan_m0609_msgs__srv__GetDesiredPosx_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__GetDesiredPosx_Request.
typedef struct doosan_m0609_msgs__srv__GetDesiredPosx_Request__Sequence
{
  doosan_m0609_msgs__srv__GetDesiredPosx_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__GetDesiredPosx_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/GetDesiredPosx in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__GetDesiredPosx_Response
{
  /// task pos(posx)
  double pos[6];
  bool success;
} doosan_m0609_msgs__srv__GetDesiredPosx_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__GetDesiredPosx_Response.
typedef struct doosan_m0609_msgs__srv__GetDesiredPosx_Response__Sequence
{
  doosan_m0609_msgs__srv__GetDesiredPosx_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__GetDesiredPosx_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_DESIRED_POSX__STRUCT_H_

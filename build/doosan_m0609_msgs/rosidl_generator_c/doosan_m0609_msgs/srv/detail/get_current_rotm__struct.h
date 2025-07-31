// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/GetCurrentRotm.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CURRENT_ROTM__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CURRENT_ROTM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetCurrentRotm in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__GetCurrentRotm_Request
{
  /// DR_BASE(0), DR_WORLD(2)
  int8_t ref;
} doosan_m0609_msgs__srv__GetCurrentRotm_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__GetCurrentRotm_Request.
typedef struct doosan_m0609_msgs__srv__GetCurrentRotm_Request__Sequence
{
  doosan_m0609_msgs__srv__GetCurrentRotm_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__GetCurrentRotm_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'rot_matrix'
#include "std_msgs/msg/detail/float64_multi_array__struct.h"

/// Struct defined in srv/GetCurrentRotm in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__GetCurrentRotm_Response
{
  /// target[3][3] Rotation matrix
  std_msgs__msg__Float64MultiArray__Sequence rot_matrix;
  bool success;
} doosan_m0609_msgs__srv__GetCurrentRotm_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__GetCurrentRotm_Response.
typedef struct doosan_m0609_msgs__srv__GetCurrentRotm_Response__Sequence
{
  doosan_m0609_msgs__srv__GetCurrentRotm_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__GetCurrentRotm_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CURRENT_ROTM__STRUCT_H_

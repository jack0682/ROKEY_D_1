// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/ConfigCreateTcp.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_CREATE_TCP__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_CREATE_TCP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ConfigCreateTcp in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__ConfigCreateTcp_Request
{
  /// tcp name
  rosidl_runtime_c__String name;
  /// coordinates of the TCP
  double pos[6];
} doosan_m0609_msgs__srv__ConfigCreateTcp_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__ConfigCreateTcp_Request.
typedef struct doosan_m0609_msgs__srv__ConfigCreateTcp_Request__Sequence
{
  doosan_m0609_msgs__srv__ConfigCreateTcp_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__ConfigCreateTcp_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ConfigCreateTcp in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__ConfigCreateTcp_Response
{
  bool success;
} doosan_m0609_msgs__srv__ConfigCreateTcp_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__ConfigCreateTcp_Response.
typedef struct doosan_m0609_msgs__srv__ConfigCreateTcp_Response__Sequence
{
  doosan_m0609_msgs__srv__ConfigCreateTcp_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__ConfigCreateTcp_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_CREATE_TCP__STRUCT_H_

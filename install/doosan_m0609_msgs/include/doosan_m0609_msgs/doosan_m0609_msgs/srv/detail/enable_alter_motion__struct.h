// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/EnableAlterMotion.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__ENABLE_ALTER_MOTION__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__ENABLE_ALTER_MOTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/EnableAlterMotion in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__EnableAlterMotion_Request
{
  /// Cycle time number
  int32_t n;
  /// DR_DPOS(0) : accumulation amount, DR_DVEL(1) : increment amount
  int8_t mode;
  /// DR_BASE(0), DR_TOOL(1), DR_WORLD(2), user coord(101~200)
  /// <ref is only available in M2.40 or later>
  int8_t ref;
  /// First value : limitation of position[mm], Second value : limitation of orientation[deg]
  double limit_dpos[2];
  /// First value : limitation of position[mm], Second value : limitation of orientation[deg]
  double limit_dpos_per[2];
} doosan_m0609_msgs__srv__EnableAlterMotion_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__EnableAlterMotion_Request.
typedef struct doosan_m0609_msgs__srv__EnableAlterMotion_Request__Sequence
{
  doosan_m0609_msgs__srv__EnableAlterMotion_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__EnableAlterMotion_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/EnableAlterMotion in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__EnableAlterMotion_Response
{
  bool success;
} doosan_m0609_msgs__srv__EnableAlterMotion_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__EnableAlterMotion_Response.
typedef struct doosan_m0609_msgs__srv__EnableAlterMotion_Response__Sequence
{
  doosan_m0609_msgs__srv__EnableAlterMotion_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__EnableAlterMotion_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__ENABLE_ALTER_MOTION__STRUCT_H_

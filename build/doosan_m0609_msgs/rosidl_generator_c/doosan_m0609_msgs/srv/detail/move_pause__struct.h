// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/MovePause.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_PAUSE__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_PAUSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/MovePause in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__MovePause_Request
{
  uint8_t structure_needs_at_least_one_member;
} doosan_m0609_msgs__srv__MovePause_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__MovePause_Request.
typedef struct doosan_m0609_msgs__srv__MovePause_Request__Sequence
{
  doosan_m0609_msgs__srv__MovePause_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__MovePause_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/MovePause in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__MovePause_Response
{
  bool success;
} doosan_m0609_msgs__srv__MovePause_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__MovePause_Response.
typedef struct doosan_m0609_msgs__srv__MovePause_Response__Sequence
{
  doosan_m0609_msgs__srv__MovePause_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__MovePause_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_PAUSE__STRUCT_H_

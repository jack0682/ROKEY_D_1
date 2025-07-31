// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/GetUserCartCoord.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_USER_CART_COORD__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_USER_CART_COORD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetUserCartCoord in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__GetUserCartCoord_Request
{
  /// ID of user coord
  int8_t id;
} doosan_m0609_msgs__srv__GetUserCartCoord_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__GetUserCartCoord_Request.
typedef struct doosan_m0609_msgs__srv__GetUserCartCoord_Request__Sequence
{
  doosan_m0609_msgs__srv__GetUserCartCoord_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__GetUserCartCoord_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/GetUserCartCoord in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__GetUserCartCoord_Response
{
  /// task pos(posx)
  double conv_posx[6];
  /// Reference coordinate of the coordinate to get
  int8_t ref;
  bool success;
} doosan_m0609_msgs__srv__GetUserCartCoord_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__GetUserCartCoord_Response.
typedef struct doosan_m0609_msgs__srv__GetUserCartCoord_Response__Sequence
{
  doosan_m0609_msgs__srv__GetUserCartCoord_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__GetUserCartCoord_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_USER_CART_COORD__STRUCT_H_

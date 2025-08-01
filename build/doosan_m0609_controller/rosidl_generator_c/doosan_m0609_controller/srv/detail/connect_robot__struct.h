// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_controller:srv/ConnectRobot.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_CONTROLLER__SRV__DETAIL__CONNECT_ROBOT__STRUCT_H_
#define DOOSAN_M0609_CONTROLLER__SRV__DETAIL__CONNECT_ROBOT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'robot_ip'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ConnectRobot in the package doosan_m0609_controller.
typedef struct doosan_m0609_controller__srv__ConnectRobot_Request
{
  /// Robot IP address
  rosidl_runtime_c__String robot_ip;
  /// true: connect, false: disconnect
  bool connect;
} doosan_m0609_controller__srv__ConnectRobot_Request;

// Struct for a sequence of doosan_m0609_controller__srv__ConnectRobot_Request.
typedef struct doosan_m0609_controller__srv__ConnectRobot_Request__Sequence
{
  doosan_m0609_controller__srv__ConnectRobot_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_controller__srv__ConnectRobot_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ConnectRobot in the package doosan_m0609_controller.
typedef struct doosan_m0609_controller__srv__ConnectRobot_Response
{
  /// Success flag
  bool success;
  /// Result message
  rosidl_runtime_c__String message;
} doosan_m0609_controller__srv__ConnectRobot_Response;

// Struct for a sequence of doosan_m0609_controller__srv__ConnectRobot_Response.
typedef struct doosan_m0609_controller__srv__ConnectRobot_Response__Sequence
{
  doosan_m0609_controller__srv__ConnectRobot_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_controller__srv__ConnectRobot_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_CONTROLLER__SRV__DETAIL__CONNECT_ROBOT__STRUCT_H_

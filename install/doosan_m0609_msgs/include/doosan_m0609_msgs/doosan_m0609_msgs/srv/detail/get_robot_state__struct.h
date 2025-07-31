// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/GetRobotState.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_ROBOT_STATE__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_ROBOT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetRobotState in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__GetRobotState_Request
{
  uint8_t structure_needs_at_least_one_member;
} doosan_m0609_msgs__srv__GetRobotState_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__GetRobotState_Request.
typedef struct doosan_m0609_msgs__srv__GetRobotState_Request__Sequence
{
  doosan_m0609_msgs__srv__GetRobotState_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__GetRobotState_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/GetRobotState in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__GetRobotState_Response
{
  /// 0 : STATE_INITIALIZING
  /// 1 : STATE_STANDBY
  /// 2 : STATE_MOVING
  /// 3 : STATE_SAFE_OFF
  /// 4 : STATE_TEACHING
  /// 5 : STATE_SAFE_STOP
  /// 6 : STATE_EMERGENCY_STOP:
  /// 7 : STATE_HOMMING
  /// 8 : STATE_RECOVERY
  /// 9 : eSTATE_SAFE_STOP2
  /// 10: STATE_SAFE_OFF2
  /// 11: STATE_RESERVED1
  /// 12: STATE_RESERVED2
  /// 13: STATE_RESERVED3
  /// 14: STATE_RESERVED4
  /// 15: STATE_NOT_READY
  int8_t robot_state;
  bool success;
} doosan_m0609_msgs__srv__GetRobotState_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__GetRobotState_Response.
typedef struct doosan_m0609_msgs__srv__GetRobotState_Response__Sequence
{
  doosan_m0609_msgs__srv__GetRobotState_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__GetRobotState_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_ROBOT_STATE__STRUCT_H_

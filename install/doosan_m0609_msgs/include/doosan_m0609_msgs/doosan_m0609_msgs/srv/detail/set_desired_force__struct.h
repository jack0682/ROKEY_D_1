// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/SetDesiredForce.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_DESIRED_FORCE__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_DESIRED_FORCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetDesiredForce in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__SetDesiredForce_Request
{
  /// Three translational target forces + Three rotational target moments
  double fd[6];
  /// Force control in the corresponding direction if 1, Compliance control in the corresponding direction if 0
  int8_t dir[6];
  /// Reference coordinate of the coordinate to get
  int8_t ref;
  /// 0          # Transition time of target force to take effect (0 ~ 1.0 sec)
  double time;
  /// DR_FC_MOD_ABS(0): force control with absolute value,
  /// DR_FC_MOD_REL(1): force control with relative value to initial state (the instance when this function is called)
  int8_t mod;
} doosan_m0609_msgs__srv__SetDesiredForce_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__SetDesiredForce_Request.
typedef struct doosan_m0609_msgs__srv__SetDesiredForce_Request__Sequence
{
  doosan_m0609_msgs__srv__SetDesiredForce_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__SetDesiredForce_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetDesiredForce in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__SetDesiredForce_Response
{
  bool success;
} doosan_m0609_msgs__srv__SetDesiredForce_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__SetDesiredForce_Response.
typedef struct doosan_m0609_msgs__srv__SetDesiredForce_Response__Sequence
{
  doosan_m0609_msgs__srv__SetDesiredForce_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__SetDesiredForce_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_DESIRED_FORCE__STRUCT_H_

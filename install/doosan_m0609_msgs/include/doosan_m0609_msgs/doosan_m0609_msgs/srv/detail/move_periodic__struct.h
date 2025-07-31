// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from doosan_m0609_msgs:srv/MovePeriodic.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_PERIODIC__STRUCT_H_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_PERIODIC__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/MovePeriodic in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__MovePeriodic_Request
{
  /// Amplitude (motion between -amp and +amp) [mm] or [deg]
  double amp[6];
  /// Period (time for 1 cycle)
  double periodic[6];
  /// Acc-, dec- time
  double acc;
  /// Repetition count
  int8_t repeat;
  /// = 1        # DR_BASE(0), DR_TOOL(1), DR_WORLD(2)
  ///  <DR_WORLD is only available in M2.40 or later
  int8_t ref;
  /// =0     # SYNC = 0, ASYNC = 1
  int8_t sync_type;
} doosan_m0609_msgs__srv__MovePeriodic_Request;

// Struct for a sequence of doosan_m0609_msgs__srv__MovePeriodic_Request.
typedef struct doosan_m0609_msgs__srv__MovePeriodic_Request__Sequence
{
  doosan_m0609_msgs__srv__MovePeriodic_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__MovePeriodic_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/MovePeriodic in the package doosan_m0609_msgs.
typedef struct doosan_m0609_msgs__srv__MovePeriodic_Response
{
  bool success;
} doosan_m0609_msgs__srv__MovePeriodic_Response;

// Struct for a sequence of doosan_m0609_msgs__srv__MovePeriodic_Response.
typedef struct doosan_m0609_msgs__srv__MovePeriodic_Response__Sequence
{
  doosan_m0609_msgs__srv__MovePeriodic_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} doosan_m0609_msgs__srv__MovePeriodic_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_PERIODIC__STRUCT_H_

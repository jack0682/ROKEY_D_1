// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from doosan_m0609_msgs:srv/MoveBlending.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "doosan_m0609_msgs/srv/detail/move_blending__rosidl_typesupport_introspection_c.h"
#include "doosan_m0609_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "doosan_m0609_msgs/srv/detail/move_blending__functions.h"
#include "doosan_m0609_msgs/srv/detail/move_blending__struct.h"


// Include directives for member types
// Member `segment`
#include "std_msgs/msg/float64_multi_array.h"
// Member `segment`
#include "std_msgs/msg/detail/float64_multi_array__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__MoveBlending_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  doosan_m0609_msgs__srv__MoveBlending_Request__init(message_memory);
}

void doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__MoveBlending_Request_fini_function(void * message_memory)
{
  doosan_m0609_msgs__srv__MoveBlending_Request__fini(message_memory);
}

size_t doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__size_function__MoveBlending_Request__segment(
  const void * untyped_member)
{
  const std_msgs__msg__Float64MultiArray__Sequence * member =
    (const std_msgs__msg__Float64MultiArray__Sequence *)(untyped_member);
  return member->size;
}

const void * doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__get_const_function__MoveBlending_Request__segment(
  const void * untyped_member, size_t index)
{
  const std_msgs__msg__Float64MultiArray__Sequence * member =
    (const std_msgs__msg__Float64MultiArray__Sequence *)(untyped_member);
  return &member->data[index];
}

void * doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__get_function__MoveBlending_Request__segment(
  void * untyped_member, size_t index)
{
  std_msgs__msg__Float64MultiArray__Sequence * member =
    (std_msgs__msg__Float64MultiArray__Sequence *)(untyped_member);
  return &member->data[index];
}

void doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__fetch_function__MoveBlending_Request__segment(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const std_msgs__msg__Float64MultiArray * item =
    ((const std_msgs__msg__Float64MultiArray *)
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__get_const_function__MoveBlending_Request__segment(untyped_member, index));
  std_msgs__msg__Float64MultiArray * value =
    (std_msgs__msg__Float64MultiArray *)(untyped_value);
  *value = *item;
}

void doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__assign_function__MoveBlending_Request__segment(
  void * untyped_member, size_t index, const void * untyped_value)
{
  std_msgs__msg__Float64MultiArray * item =
    ((std_msgs__msg__Float64MultiArray *)
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__get_function__MoveBlending_Request__segment(untyped_member, index));
  const std_msgs__msg__Float64MultiArray * value =
    (const std_msgs__msg__Float64MultiArray *)(untyped_value);
  *item = *value;
}

bool doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__resize_function__MoveBlending_Request__segment(
  void * untyped_member, size_t size)
{
  std_msgs__msg__Float64MultiArray__Sequence * member =
    (std_msgs__msg__Float64MultiArray__Sequence *)(untyped_member);
  std_msgs__msg__Float64MultiArray__Sequence__fini(member);
  return std_msgs__msg__Float64MultiArray__Sequence__init(member, size);
}

size_t doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__size_function__MoveBlending_Request__vel(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__get_const_function__MoveBlending_Request__vel(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__get_function__MoveBlending_Request__vel(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__fetch_function__MoveBlending_Request__vel(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__get_const_function__MoveBlending_Request__vel(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__assign_function__MoveBlending_Request__vel(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__get_function__MoveBlending_Request__vel(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__size_function__MoveBlending_Request__acc(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__get_const_function__MoveBlending_Request__acc(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__get_function__MoveBlending_Request__acc(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__fetch_function__MoveBlending_Request__acc(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__get_const_function__MoveBlending_Request__acc(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__assign_function__MoveBlending_Request__acc(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__get_function__MoveBlending_Request__acc(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__MoveBlending_Request_message_member_array[8] = {
  {
    "segment",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__srv__MoveBlending_Request, segment),  // bytes offset in struct
    NULL,  // default value
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__size_function__MoveBlending_Request__segment,  // size() function pointer
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__get_const_function__MoveBlending_Request__segment,  // get_const(index) function pointer
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__get_function__MoveBlending_Request__segment,  // get(index) function pointer
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__fetch_function__MoveBlending_Request__segment,  // fetch(index, &value) function pointer
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__assign_function__MoveBlending_Request__segment,  // assign(index, value) function pointer
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__resize_function__MoveBlending_Request__segment  // resize(index) function pointer
  },
  {
    "pos_cnt",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__srv__MoveBlending_Request, pos_cnt),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__srv__MoveBlending_Request, vel),  // bytes offset in struct
    NULL,  // default value
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__size_function__MoveBlending_Request__vel,  // size() function pointer
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__get_const_function__MoveBlending_Request__vel,  // get_const(index) function pointer
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__get_function__MoveBlending_Request__vel,  // get(index) function pointer
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__fetch_function__MoveBlending_Request__vel,  // fetch(index, &value) function pointer
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__assign_function__MoveBlending_Request__vel,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acc",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__srv__MoveBlending_Request, acc),  // bytes offset in struct
    NULL,  // default value
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__size_function__MoveBlending_Request__acc,  // size() function pointer
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__get_const_function__MoveBlending_Request__acc,  // get_const(index) function pointer
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__get_function__MoveBlending_Request__acc,  // get(index) function pointer
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__fetch_function__MoveBlending_Request__acc,  // fetch(index, &value) function pointer
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__assign_function__MoveBlending_Request__acc,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__srv__MoveBlending_Request, time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ref",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__srv__MoveBlending_Request, ref),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__srv__MoveBlending_Request, mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sync_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__srv__MoveBlending_Request, sync_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__MoveBlending_Request_message_members = {
  "doosan_m0609_msgs__srv",  // message namespace
  "MoveBlending_Request",  // message name
  8,  // number of fields
  sizeof(doosan_m0609_msgs__srv__MoveBlending_Request),
  doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__MoveBlending_Request_message_member_array,  // message members
  doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__MoveBlending_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__MoveBlending_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__MoveBlending_Request_message_type_support_handle = {
  0,
  &doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__MoveBlending_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_doosan_m0609_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_msgs, srv, MoveBlending_Request)() {
  doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__MoveBlending_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Float64MultiArray)();
  if (!doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__MoveBlending_Request_message_type_support_handle.typesupport_identifier) {
    doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__MoveBlending_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &doosan_m0609_msgs__srv__MoveBlending_Request__rosidl_typesupport_introspection_c__MoveBlending_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "doosan_m0609_msgs/srv/detail/move_blending__rosidl_typesupport_introspection_c.h"
// already included above
// #include "doosan_m0609_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "doosan_m0609_msgs/srv/detail/move_blending__functions.h"
// already included above
// #include "doosan_m0609_msgs/srv/detail/move_blending__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void doosan_m0609_msgs__srv__MoveBlending_Response__rosidl_typesupport_introspection_c__MoveBlending_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  doosan_m0609_msgs__srv__MoveBlending_Response__init(message_memory);
}

void doosan_m0609_msgs__srv__MoveBlending_Response__rosidl_typesupport_introspection_c__MoveBlending_Response_fini_function(void * message_memory)
{
  doosan_m0609_msgs__srv__MoveBlending_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember doosan_m0609_msgs__srv__MoveBlending_Response__rosidl_typesupport_introspection_c__MoveBlending_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__srv__MoveBlending_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers doosan_m0609_msgs__srv__MoveBlending_Response__rosidl_typesupport_introspection_c__MoveBlending_Response_message_members = {
  "doosan_m0609_msgs__srv",  // message namespace
  "MoveBlending_Response",  // message name
  1,  // number of fields
  sizeof(doosan_m0609_msgs__srv__MoveBlending_Response),
  doosan_m0609_msgs__srv__MoveBlending_Response__rosidl_typesupport_introspection_c__MoveBlending_Response_message_member_array,  // message members
  doosan_m0609_msgs__srv__MoveBlending_Response__rosidl_typesupport_introspection_c__MoveBlending_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  doosan_m0609_msgs__srv__MoveBlending_Response__rosidl_typesupport_introspection_c__MoveBlending_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t doosan_m0609_msgs__srv__MoveBlending_Response__rosidl_typesupport_introspection_c__MoveBlending_Response_message_type_support_handle = {
  0,
  &doosan_m0609_msgs__srv__MoveBlending_Response__rosidl_typesupport_introspection_c__MoveBlending_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_doosan_m0609_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_msgs, srv, MoveBlending_Response)() {
  if (!doosan_m0609_msgs__srv__MoveBlending_Response__rosidl_typesupport_introspection_c__MoveBlending_Response_message_type_support_handle.typesupport_identifier) {
    doosan_m0609_msgs__srv__MoveBlending_Response__rosidl_typesupport_introspection_c__MoveBlending_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &doosan_m0609_msgs__srv__MoveBlending_Response__rosidl_typesupport_introspection_c__MoveBlending_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "doosan_m0609_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "doosan_m0609_msgs/srv/detail/move_blending__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers doosan_m0609_msgs__srv__detail__move_blending__rosidl_typesupport_introspection_c__MoveBlending_service_members = {
  "doosan_m0609_msgs__srv",  // service namespace
  "MoveBlending",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // doosan_m0609_msgs__srv__detail__move_blending__rosidl_typesupport_introspection_c__MoveBlending_Request_message_type_support_handle,
  NULL  // response message
  // doosan_m0609_msgs__srv__detail__move_blending__rosidl_typesupport_introspection_c__MoveBlending_Response_message_type_support_handle
};

static rosidl_service_type_support_t doosan_m0609_msgs__srv__detail__move_blending__rosidl_typesupport_introspection_c__MoveBlending_service_type_support_handle = {
  0,
  &doosan_m0609_msgs__srv__detail__move_blending__rosidl_typesupport_introspection_c__MoveBlending_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_msgs, srv, MoveBlending_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_msgs, srv, MoveBlending_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_doosan_m0609_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_msgs, srv, MoveBlending)() {
  if (!doosan_m0609_msgs__srv__detail__move_blending__rosidl_typesupport_introspection_c__MoveBlending_service_type_support_handle.typesupport_identifier) {
    doosan_m0609_msgs__srv__detail__move_blending__rosidl_typesupport_introspection_c__MoveBlending_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)doosan_m0609_msgs__srv__detail__move_blending__rosidl_typesupport_introspection_c__MoveBlending_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_msgs, srv, MoveBlending_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_msgs, srv, MoveBlending_Response)()->data;
  }

  return &doosan_m0609_msgs__srv__detail__move_blending__rosidl_typesupport_introspection_c__MoveBlending_service_type_support_handle;
}

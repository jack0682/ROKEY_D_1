// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from doosan_m0609_controller:srv/MoveJ.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "doosan_m0609_controller/srv/detail/move_j__rosidl_typesupport_introspection_c.h"
#include "doosan_m0609_controller/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "doosan_m0609_controller/srv/detail/move_j__functions.h"
#include "doosan_m0609_controller/srv/detail/move_j__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__MoveJ_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  doosan_m0609_controller__srv__MoveJ_Request__init(message_memory);
}

void doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__MoveJ_Request_fini_function(void * message_memory)
{
  doosan_m0609_controller__srv__MoveJ_Request__fini(message_memory);
}

size_t doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__size_function__MoveJ_Request__target_joints(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__get_const_function__MoveJ_Request__target_joints(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__get_function__MoveJ_Request__target_joints(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__fetch_function__MoveJ_Request__target_joints(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__get_const_function__MoveJ_Request__target_joints(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__assign_function__MoveJ_Request__target_joints(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__get_function__MoveJ_Request__target_joints(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__MoveJ_Request_message_member_array[4] = {
  {
    "target_joints",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_controller__srv__MoveJ_Request, target_joints),  // bytes offset in struct
    NULL,  // default value
    doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__size_function__MoveJ_Request__target_joints,  // size() function pointer
    doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__get_const_function__MoveJ_Request__target_joints,  // get_const(index) function pointer
    doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__get_function__MoveJ_Request__target_joints,  // get(index) function pointer
    doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__fetch_function__MoveJ_Request__target_joints,  // fetch(index, &value) function pointer
    doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__assign_function__MoveJ_Request__target_joints,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity_ratio",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_controller__srv__MoveJ_Request, velocity_ratio),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acceleration_ratio",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_controller__srv__MoveJ_Request, acceleration_ratio),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "time_out",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_controller__srv__MoveJ_Request, time_out),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__MoveJ_Request_message_members = {
  "doosan_m0609_controller__srv",  // message namespace
  "MoveJ_Request",  // message name
  4,  // number of fields
  sizeof(doosan_m0609_controller__srv__MoveJ_Request),
  doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__MoveJ_Request_message_member_array,  // message members
  doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__MoveJ_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__MoveJ_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__MoveJ_Request_message_type_support_handle = {
  0,
  &doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__MoveJ_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_doosan_m0609_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_controller, srv, MoveJ_Request)() {
  if (!doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__MoveJ_Request_message_type_support_handle.typesupport_identifier) {
    doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__MoveJ_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &doosan_m0609_controller__srv__MoveJ_Request__rosidl_typesupport_introspection_c__MoveJ_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "doosan_m0609_controller/srv/detail/move_j__rosidl_typesupport_introspection_c.h"
// already included above
// #include "doosan_m0609_controller/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "doosan_m0609_controller/srv/detail/move_j__functions.h"
// already included above
// #include "doosan_m0609_controller/srv/detail/move_j__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void doosan_m0609_controller__srv__MoveJ_Response__rosidl_typesupport_introspection_c__MoveJ_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  doosan_m0609_controller__srv__MoveJ_Response__init(message_memory);
}

void doosan_m0609_controller__srv__MoveJ_Response__rosidl_typesupport_introspection_c__MoveJ_Response_fini_function(void * message_memory)
{
  doosan_m0609_controller__srv__MoveJ_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember doosan_m0609_controller__srv__MoveJ_Response__rosidl_typesupport_introspection_c__MoveJ_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_controller__srv__MoveJ_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_controller__srv__MoveJ_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers doosan_m0609_controller__srv__MoveJ_Response__rosidl_typesupport_introspection_c__MoveJ_Response_message_members = {
  "doosan_m0609_controller__srv",  // message namespace
  "MoveJ_Response",  // message name
  2,  // number of fields
  sizeof(doosan_m0609_controller__srv__MoveJ_Response),
  doosan_m0609_controller__srv__MoveJ_Response__rosidl_typesupport_introspection_c__MoveJ_Response_message_member_array,  // message members
  doosan_m0609_controller__srv__MoveJ_Response__rosidl_typesupport_introspection_c__MoveJ_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  doosan_m0609_controller__srv__MoveJ_Response__rosidl_typesupport_introspection_c__MoveJ_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t doosan_m0609_controller__srv__MoveJ_Response__rosidl_typesupport_introspection_c__MoveJ_Response_message_type_support_handle = {
  0,
  &doosan_m0609_controller__srv__MoveJ_Response__rosidl_typesupport_introspection_c__MoveJ_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_doosan_m0609_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_controller, srv, MoveJ_Response)() {
  if (!doosan_m0609_controller__srv__MoveJ_Response__rosidl_typesupport_introspection_c__MoveJ_Response_message_type_support_handle.typesupport_identifier) {
    doosan_m0609_controller__srv__MoveJ_Response__rosidl_typesupport_introspection_c__MoveJ_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &doosan_m0609_controller__srv__MoveJ_Response__rosidl_typesupport_introspection_c__MoveJ_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "doosan_m0609_controller/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "doosan_m0609_controller/srv/detail/move_j__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers doosan_m0609_controller__srv__detail__move_j__rosidl_typesupport_introspection_c__MoveJ_service_members = {
  "doosan_m0609_controller__srv",  // service namespace
  "MoveJ",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // doosan_m0609_controller__srv__detail__move_j__rosidl_typesupport_introspection_c__MoveJ_Request_message_type_support_handle,
  NULL  // response message
  // doosan_m0609_controller__srv__detail__move_j__rosidl_typesupport_introspection_c__MoveJ_Response_message_type_support_handle
};

static rosidl_service_type_support_t doosan_m0609_controller__srv__detail__move_j__rosidl_typesupport_introspection_c__MoveJ_service_type_support_handle = {
  0,
  &doosan_m0609_controller__srv__detail__move_j__rosidl_typesupport_introspection_c__MoveJ_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_controller, srv, MoveJ_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_controller, srv, MoveJ_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_doosan_m0609_controller
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_controller, srv, MoveJ)() {
  if (!doosan_m0609_controller__srv__detail__move_j__rosidl_typesupport_introspection_c__MoveJ_service_type_support_handle.typesupport_identifier) {
    doosan_m0609_controller__srv__detail__move_j__rosidl_typesupport_introspection_c__MoveJ_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)doosan_m0609_controller__srv__detail__move_j__rosidl_typesupport_introspection_c__MoveJ_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_controller, srv, MoveJ_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_controller, srv, MoveJ_Response)()->data;
  }

  return &doosan_m0609_controller__srv__detail__move_j__rosidl_typesupport_introspection_c__MoveJ_service_type_support_handle;
}

// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from doosan_m0609_msgs:srv/AlignAxis2.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "doosan_m0609_msgs/srv/detail/align_axis2__rosidl_typesupport_introspection_c.h"
#include "doosan_m0609_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "doosan_m0609_msgs/srv/detail/align_axis2__functions.h"
#include "doosan_m0609_msgs/srv/detail/align_axis2__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__AlignAxis2_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  doosan_m0609_msgs__srv__AlignAxis2_Request__init(message_memory);
}

void doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__AlignAxis2_Request_fini_function(void * message_memory)
{
  doosan_m0609_msgs__srv__AlignAxis2_Request__fini(message_memory);
}

size_t doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__size_function__AlignAxis2_Request__target_vect(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__get_const_function__AlignAxis2_Request__target_vect(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__get_function__AlignAxis2_Request__target_vect(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__fetch_function__AlignAxis2_Request__target_vect(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__get_const_function__AlignAxis2_Request__target_vect(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__assign_function__AlignAxis2_Request__target_vect(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__get_function__AlignAxis2_Request__target_vect(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__size_function__AlignAxis2_Request__source_vect(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__get_const_function__AlignAxis2_Request__source_vect(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__get_function__AlignAxis2_Request__source_vect(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__fetch_function__AlignAxis2_Request__source_vect(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__get_const_function__AlignAxis2_Request__source_vect(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__assign_function__AlignAxis2_Request__source_vect(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__get_function__AlignAxis2_Request__source_vect(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__AlignAxis2_Request_message_member_array[4] = {
  {
    "target_vect",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__srv__AlignAxis2_Request, target_vect),  // bytes offset in struct
    NULL,  // default value
    doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__size_function__AlignAxis2_Request__target_vect,  // size() function pointer
    doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__get_const_function__AlignAxis2_Request__target_vect,  // get_const(index) function pointer
    doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__get_function__AlignAxis2_Request__target_vect,  // get(index) function pointer
    doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__fetch_function__AlignAxis2_Request__target_vect,  // fetch(index, &value) function pointer
    doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__assign_function__AlignAxis2_Request__target_vect,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "source_vect",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__srv__AlignAxis2_Request, source_vect),  // bytes offset in struct
    NULL,  // default value
    doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__size_function__AlignAxis2_Request__source_vect,  // size() function pointer
    doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__get_const_function__AlignAxis2_Request__source_vect,  // get_const(index) function pointer
    doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__get_function__AlignAxis2_Request__source_vect,  // get(index) function pointer
    doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__fetch_function__AlignAxis2_Request__source_vect,  // fetch(index, &value) function pointer
    doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__assign_function__AlignAxis2_Request__source_vect,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "axis",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__srv__AlignAxis2_Request, axis),  // bytes offset in struct
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
    offsetof(doosan_m0609_msgs__srv__AlignAxis2_Request, ref),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__AlignAxis2_Request_message_members = {
  "doosan_m0609_msgs__srv",  // message namespace
  "AlignAxis2_Request",  // message name
  4,  // number of fields
  sizeof(doosan_m0609_msgs__srv__AlignAxis2_Request),
  doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__AlignAxis2_Request_message_member_array,  // message members
  doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__AlignAxis2_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__AlignAxis2_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__AlignAxis2_Request_message_type_support_handle = {
  0,
  &doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__AlignAxis2_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_doosan_m0609_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_msgs, srv, AlignAxis2_Request)() {
  if (!doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__AlignAxis2_Request_message_type_support_handle.typesupport_identifier) {
    doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__AlignAxis2_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &doosan_m0609_msgs__srv__AlignAxis2_Request__rosidl_typesupport_introspection_c__AlignAxis2_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "doosan_m0609_msgs/srv/detail/align_axis2__rosidl_typesupport_introspection_c.h"
// already included above
// #include "doosan_m0609_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "doosan_m0609_msgs/srv/detail/align_axis2__functions.h"
// already included above
// #include "doosan_m0609_msgs/srv/detail/align_axis2__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void doosan_m0609_msgs__srv__AlignAxis2_Response__rosidl_typesupport_introspection_c__AlignAxis2_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  doosan_m0609_msgs__srv__AlignAxis2_Response__init(message_memory);
}

void doosan_m0609_msgs__srv__AlignAxis2_Response__rosidl_typesupport_introspection_c__AlignAxis2_Response_fini_function(void * message_memory)
{
  doosan_m0609_msgs__srv__AlignAxis2_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember doosan_m0609_msgs__srv__AlignAxis2_Response__rosidl_typesupport_introspection_c__AlignAxis2_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(doosan_m0609_msgs__srv__AlignAxis2_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers doosan_m0609_msgs__srv__AlignAxis2_Response__rosidl_typesupport_introspection_c__AlignAxis2_Response_message_members = {
  "doosan_m0609_msgs__srv",  // message namespace
  "AlignAxis2_Response",  // message name
  1,  // number of fields
  sizeof(doosan_m0609_msgs__srv__AlignAxis2_Response),
  doosan_m0609_msgs__srv__AlignAxis2_Response__rosidl_typesupport_introspection_c__AlignAxis2_Response_message_member_array,  // message members
  doosan_m0609_msgs__srv__AlignAxis2_Response__rosidl_typesupport_introspection_c__AlignAxis2_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  doosan_m0609_msgs__srv__AlignAxis2_Response__rosidl_typesupport_introspection_c__AlignAxis2_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t doosan_m0609_msgs__srv__AlignAxis2_Response__rosidl_typesupport_introspection_c__AlignAxis2_Response_message_type_support_handle = {
  0,
  &doosan_m0609_msgs__srv__AlignAxis2_Response__rosidl_typesupport_introspection_c__AlignAxis2_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_doosan_m0609_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_msgs, srv, AlignAxis2_Response)() {
  if (!doosan_m0609_msgs__srv__AlignAxis2_Response__rosidl_typesupport_introspection_c__AlignAxis2_Response_message_type_support_handle.typesupport_identifier) {
    doosan_m0609_msgs__srv__AlignAxis2_Response__rosidl_typesupport_introspection_c__AlignAxis2_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &doosan_m0609_msgs__srv__AlignAxis2_Response__rosidl_typesupport_introspection_c__AlignAxis2_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "doosan_m0609_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "doosan_m0609_msgs/srv/detail/align_axis2__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers doosan_m0609_msgs__srv__detail__align_axis2__rosidl_typesupport_introspection_c__AlignAxis2_service_members = {
  "doosan_m0609_msgs__srv",  // service namespace
  "AlignAxis2",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // doosan_m0609_msgs__srv__detail__align_axis2__rosidl_typesupport_introspection_c__AlignAxis2_Request_message_type_support_handle,
  NULL  // response message
  // doosan_m0609_msgs__srv__detail__align_axis2__rosidl_typesupport_introspection_c__AlignAxis2_Response_message_type_support_handle
};

static rosidl_service_type_support_t doosan_m0609_msgs__srv__detail__align_axis2__rosidl_typesupport_introspection_c__AlignAxis2_service_type_support_handle = {
  0,
  &doosan_m0609_msgs__srv__detail__align_axis2__rosidl_typesupport_introspection_c__AlignAxis2_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_msgs, srv, AlignAxis2_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_msgs, srv, AlignAxis2_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_doosan_m0609_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_msgs, srv, AlignAxis2)() {
  if (!doosan_m0609_msgs__srv__detail__align_axis2__rosidl_typesupport_introspection_c__AlignAxis2_service_type_support_handle.typesupport_identifier) {
    doosan_m0609_msgs__srv__detail__align_axis2__rosidl_typesupport_introspection_c__AlignAxis2_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)doosan_m0609_msgs__srv__detail__align_axis2__rosidl_typesupport_introspection_c__AlignAxis2_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_msgs, srv, AlignAxis2_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, doosan_m0609_msgs, srv, AlignAxis2_Response)()->data;
  }

  return &doosan_m0609_msgs__srv__detail__align_axis2__rosidl_typesupport_introspection_c__AlignAxis2_service_type_support_handle;
}

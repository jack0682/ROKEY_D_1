// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from doosan_m0609_msgs:srv/GetCurrentPosx.idl
// generated code does not contain a copyright notice
#include "doosan_m0609_msgs/srv/detail/get_current_posx__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "doosan_m0609_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "doosan_m0609_msgs/srv/detail/get_current_posx__struct.h"
#include "doosan_m0609_msgs/srv/detail/get_current_posx__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _GetCurrentPosx_Request__ros_msg_type = doosan_m0609_msgs__srv__GetCurrentPosx_Request;

static bool _GetCurrentPosx_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _GetCurrentPosx_Request__ros_msg_type * ros_message = static_cast<const _GetCurrentPosx_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: ref
  {
    cdr << ros_message->ref;
  }

  return true;
}

static bool _GetCurrentPosx_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _GetCurrentPosx_Request__ros_msg_type * ros_message = static_cast<_GetCurrentPosx_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: ref
  {
    cdr >> ros_message->ref;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_doosan_m0609_msgs
size_t get_serialized_size_doosan_m0609_msgs__srv__GetCurrentPosx_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GetCurrentPosx_Request__ros_msg_type * ros_message = static_cast<const _GetCurrentPosx_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name ref
  {
    size_t item_size = sizeof(ros_message->ref);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _GetCurrentPosx_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_doosan_m0609_msgs__srv__GetCurrentPosx_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_doosan_m0609_msgs
size_t max_serialized_size_doosan_m0609_msgs__srv__GetCurrentPosx_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: ref
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = doosan_m0609_msgs__srv__GetCurrentPosx_Request;
    is_plain =
      (
      offsetof(DataType, ref) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _GetCurrentPosx_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_doosan_m0609_msgs__srv__GetCurrentPosx_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_GetCurrentPosx_Request = {
  "doosan_m0609_msgs::srv",
  "GetCurrentPosx_Request",
  _GetCurrentPosx_Request__cdr_serialize,
  _GetCurrentPosx_Request__cdr_deserialize,
  _GetCurrentPosx_Request__get_serialized_size,
  _GetCurrentPosx_Request__max_serialized_size
};

static rosidl_message_type_support_t _GetCurrentPosx_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GetCurrentPosx_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, doosan_m0609_msgs, srv, GetCurrentPosx_Request)() {
  return &_GetCurrentPosx_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "doosan_m0609_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "doosan_m0609_msgs/srv/detail/get_current_posx__struct.h"
// already included above
// #include "doosan_m0609_msgs/srv/detail/get_current_posx__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/float64_multi_array__functions.h"  // task_pos_info

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_doosan_m0609_msgs
size_t get_serialized_size_std_msgs__msg__Float64MultiArray(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_doosan_m0609_msgs
size_t max_serialized_size_std_msgs__msg__Float64MultiArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_doosan_m0609_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Float64MultiArray)();


using _GetCurrentPosx_Response__ros_msg_type = doosan_m0609_msgs__srv__GetCurrentPosx_Response;

static bool _GetCurrentPosx_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _GetCurrentPosx_Response__ros_msg_type * ros_message = static_cast<const _GetCurrentPosx_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: task_pos_info
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Float64MultiArray
      )()->data);
    size_t size = ros_message->task_pos_info.size;
    auto array_ptr = ros_message->task_pos_info.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: success
  {
    cdr << (ros_message->success ? true : false);
  }

  return true;
}

static bool _GetCurrentPosx_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _GetCurrentPosx_Response__ros_msg_type * ros_message = static_cast<_GetCurrentPosx_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: task_pos_info
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Float64MultiArray
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->task_pos_info.data) {
      std_msgs__msg__Float64MultiArray__Sequence__fini(&ros_message->task_pos_info);
    }
    if (!std_msgs__msg__Float64MultiArray__Sequence__init(&ros_message->task_pos_info, size)) {
      fprintf(stderr, "failed to create array for field 'task_pos_info'");
      return false;
    }
    auto array_ptr = ros_message->task_pos_info.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->success = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_doosan_m0609_msgs
size_t get_serialized_size_doosan_m0609_msgs__srv__GetCurrentPosx_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GetCurrentPosx_Response__ros_msg_type * ros_message = static_cast<const _GetCurrentPosx_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name task_pos_info
  {
    size_t array_size = ros_message->task_pos_info.size;
    auto array_ptr = ros_message->task_pos_info.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_std_msgs__msg__Float64MultiArray(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name success
  {
    size_t item_size = sizeof(ros_message->success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _GetCurrentPosx_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_doosan_m0609_msgs__srv__GetCurrentPosx_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_doosan_m0609_msgs
size_t max_serialized_size_doosan_m0609_msgs__srv__GetCurrentPosx_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: task_pos_info
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Float64MultiArray(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: success
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = doosan_m0609_msgs__srv__GetCurrentPosx_Response;
    is_plain =
      (
      offsetof(DataType, success) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _GetCurrentPosx_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_doosan_m0609_msgs__srv__GetCurrentPosx_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_GetCurrentPosx_Response = {
  "doosan_m0609_msgs::srv",
  "GetCurrentPosx_Response",
  _GetCurrentPosx_Response__cdr_serialize,
  _GetCurrentPosx_Response__cdr_deserialize,
  _GetCurrentPosx_Response__get_serialized_size,
  _GetCurrentPosx_Response__max_serialized_size
};

static rosidl_message_type_support_t _GetCurrentPosx_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GetCurrentPosx_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, doosan_m0609_msgs, srv, GetCurrentPosx_Response)() {
  return &_GetCurrentPosx_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "doosan_m0609_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "doosan_m0609_msgs/srv/get_current_posx.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t GetCurrentPosx__callbacks = {
  "doosan_m0609_msgs::srv",
  "GetCurrentPosx",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, doosan_m0609_msgs, srv, GetCurrentPosx_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, doosan_m0609_msgs, srv, GetCurrentPosx_Response)(),
};

static rosidl_service_type_support_t GetCurrentPosx__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &GetCurrentPosx__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, doosan_m0609_msgs, srv, GetCurrentPosx)() {
  return &GetCurrentPosx__handle;
}

#if defined(__cplusplus)
}
#endif

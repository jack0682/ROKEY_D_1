// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from doosan_m0609_msgs:msg/ModbusState.idl
// generated code does not contain a copyright notice
#include "doosan_m0609_msgs/msg/detail/modbus_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "doosan_m0609_msgs/msg/detail/modbus_state__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace doosan_m0609_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_doosan_m0609_msgs
cdr_serialize(
  const doosan_m0609_msgs::msg::ModbusState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: modbus_symbol
  cdr << ros_message.modbus_symbol;
  // Member: modbus_value
  cdr << ros_message.modbus_value;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_doosan_m0609_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  doosan_m0609_msgs::msg::ModbusState & ros_message)
{
  // Member: modbus_symbol
  cdr >> ros_message.modbus_symbol;

  // Member: modbus_value
  cdr >> ros_message.modbus_value;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_doosan_m0609_msgs
get_serialized_size(
  const doosan_m0609_msgs::msg::ModbusState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: modbus_symbol
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.modbus_symbol.size() + 1);
  // Member: modbus_value
  {
    size_t item_size = sizeof(ros_message.modbus_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_doosan_m0609_msgs
max_serialized_size_ModbusState(
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


  // Member: modbus_symbol
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: modbus_value
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = doosan_m0609_msgs::msg::ModbusState;
    is_plain =
      (
      offsetof(DataType, modbus_value) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ModbusState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const doosan_m0609_msgs::msg::ModbusState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ModbusState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<doosan_m0609_msgs::msg::ModbusState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ModbusState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const doosan_m0609_msgs::msg::ModbusState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ModbusState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ModbusState(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ModbusState__callbacks = {
  "doosan_m0609_msgs::msg",
  "ModbusState",
  _ModbusState__cdr_serialize,
  _ModbusState__cdr_deserialize,
  _ModbusState__get_serialized_size,
  _ModbusState__max_serialized_size
};

static rosidl_message_type_support_t _ModbusState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ModbusState__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace doosan_m0609_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_doosan_m0609_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<doosan_m0609_msgs::msg::ModbusState>()
{
  return &doosan_m0609_msgs::msg::typesupport_fastrtps_cpp::_ModbusState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, doosan_m0609_msgs, msg, ModbusState)() {
  return &doosan_m0609_msgs::msg::typesupport_fastrtps_cpp::_ModbusState__handle;
}

#ifdef __cplusplus
}
#endif

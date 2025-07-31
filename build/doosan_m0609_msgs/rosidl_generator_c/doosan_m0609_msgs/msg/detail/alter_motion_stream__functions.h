// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from doosan_m0609_msgs:msg/AlterMotionStream.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__ALTER_MOTION_STREAM__FUNCTIONS_H_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__ALTER_MOTION_STREAM__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "doosan_m0609_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "doosan_m0609_msgs/msg/detail/alter_motion_stream__struct.h"

/// Initialize msg/AlterMotionStream message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * doosan_m0609_msgs__msg__AlterMotionStream
 * )) before or use
 * doosan_m0609_msgs__msg__AlterMotionStream__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
bool
doosan_m0609_msgs__msg__AlterMotionStream__init(doosan_m0609_msgs__msg__AlterMotionStream * msg);

/// Finalize msg/AlterMotionStream message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
void
doosan_m0609_msgs__msg__AlterMotionStream__fini(doosan_m0609_msgs__msg__AlterMotionStream * msg);

/// Create msg/AlterMotionStream message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * doosan_m0609_msgs__msg__AlterMotionStream__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
doosan_m0609_msgs__msg__AlterMotionStream *
doosan_m0609_msgs__msg__AlterMotionStream__create();

/// Destroy msg/AlterMotionStream message.
/**
 * It calls
 * doosan_m0609_msgs__msg__AlterMotionStream__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
void
doosan_m0609_msgs__msg__AlterMotionStream__destroy(doosan_m0609_msgs__msg__AlterMotionStream * msg);

/// Check for msg/AlterMotionStream message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
bool
doosan_m0609_msgs__msg__AlterMotionStream__are_equal(const doosan_m0609_msgs__msg__AlterMotionStream * lhs, const doosan_m0609_msgs__msg__AlterMotionStream * rhs);

/// Copy a msg/AlterMotionStream message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
bool
doosan_m0609_msgs__msg__AlterMotionStream__copy(
  const doosan_m0609_msgs__msg__AlterMotionStream * input,
  doosan_m0609_msgs__msg__AlterMotionStream * output);

/// Initialize array of msg/AlterMotionStream messages.
/**
 * It allocates the memory for the number of elements and calls
 * doosan_m0609_msgs__msg__AlterMotionStream__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
bool
doosan_m0609_msgs__msg__AlterMotionStream__Sequence__init(doosan_m0609_msgs__msg__AlterMotionStream__Sequence * array, size_t size);

/// Finalize array of msg/AlterMotionStream messages.
/**
 * It calls
 * doosan_m0609_msgs__msg__AlterMotionStream__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
void
doosan_m0609_msgs__msg__AlterMotionStream__Sequence__fini(doosan_m0609_msgs__msg__AlterMotionStream__Sequence * array);

/// Create array of msg/AlterMotionStream messages.
/**
 * It allocates the memory for the array and calls
 * doosan_m0609_msgs__msg__AlterMotionStream__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
doosan_m0609_msgs__msg__AlterMotionStream__Sequence *
doosan_m0609_msgs__msg__AlterMotionStream__Sequence__create(size_t size);

/// Destroy array of msg/AlterMotionStream messages.
/**
 * It calls
 * doosan_m0609_msgs__msg__AlterMotionStream__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
void
doosan_m0609_msgs__msg__AlterMotionStream__Sequence__destroy(doosan_m0609_msgs__msg__AlterMotionStream__Sequence * array);

/// Check for msg/AlterMotionStream message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
bool
doosan_m0609_msgs__msg__AlterMotionStream__Sequence__are_equal(const doosan_m0609_msgs__msg__AlterMotionStream__Sequence * lhs, const doosan_m0609_msgs__msg__AlterMotionStream__Sequence * rhs);

/// Copy an array of msg/AlterMotionStream messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
bool
doosan_m0609_msgs__msg__AlterMotionStream__Sequence__copy(
  const doosan_m0609_msgs__msg__AlterMotionStream__Sequence * input,
  doosan_m0609_msgs__msg__AlterMotionStream__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__ALTER_MOTION_STREAM__FUNCTIONS_H_

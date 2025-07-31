// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from doosan_m0609_msgs:msg/SpeedlStream.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__SPEEDL_STREAM__FUNCTIONS_H_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__SPEEDL_STREAM__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "doosan_m0609_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "doosan_m0609_msgs/msg/detail/speedl_stream__struct.h"

/// Initialize msg/SpeedlStream message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * doosan_m0609_msgs__msg__SpeedlStream
 * )) before or use
 * doosan_m0609_msgs__msg__SpeedlStream__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
bool
doosan_m0609_msgs__msg__SpeedlStream__init(doosan_m0609_msgs__msg__SpeedlStream * msg);

/// Finalize msg/SpeedlStream message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
void
doosan_m0609_msgs__msg__SpeedlStream__fini(doosan_m0609_msgs__msg__SpeedlStream * msg);

/// Create msg/SpeedlStream message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * doosan_m0609_msgs__msg__SpeedlStream__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
doosan_m0609_msgs__msg__SpeedlStream *
doosan_m0609_msgs__msg__SpeedlStream__create();

/// Destroy msg/SpeedlStream message.
/**
 * It calls
 * doosan_m0609_msgs__msg__SpeedlStream__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
void
doosan_m0609_msgs__msg__SpeedlStream__destroy(doosan_m0609_msgs__msg__SpeedlStream * msg);

/// Check for msg/SpeedlStream message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
bool
doosan_m0609_msgs__msg__SpeedlStream__are_equal(const doosan_m0609_msgs__msg__SpeedlStream * lhs, const doosan_m0609_msgs__msg__SpeedlStream * rhs);

/// Copy a msg/SpeedlStream message.
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
doosan_m0609_msgs__msg__SpeedlStream__copy(
  const doosan_m0609_msgs__msg__SpeedlStream * input,
  doosan_m0609_msgs__msg__SpeedlStream * output);

/// Initialize array of msg/SpeedlStream messages.
/**
 * It allocates the memory for the number of elements and calls
 * doosan_m0609_msgs__msg__SpeedlStream__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
bool
doosan_m0609_msgs__msg__SpeedlStream__Sequence__init(doosan_m0609_msgs__msg__SpeedlStream__Sequence * array, size_t size);

/// Finalize array of msg/SpeedlStream messages.
/**
 * It calls
 * doosan_m0609_msgs__msg__SpeedlStream__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
void
doosan_m0609_msgs__msg__SpeedlStream__Sequence__fini(doosan_m0609_msgs__msg__SpeedlStream__Sequence * array);

/// Create array of msg/SpeedlStream messages.
/**
 * It allocates the memory for the array and calls
 * doosan_m0609_msgs__msg__SpeedlStream__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
doosan_m0609_msgs__msg__SpeedlStream__Sequence *
doosan_m0609_msgs__msg__SpeedlStream__Sequence__create(size_t size);

/// Destroy array of msg/SpeedlStream messages.
/**
 * It calls
 * doosan_m0609_msgs__msg__SpeedlStream__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
void
doosan_m0609_msgs__msg__SpeedlStream__Sequence__destroy(doosan_m0609_msgs__msg__SpeedlStream__Sequence * array);

/// Check for msg/SpeedlStream message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_msgs
bool
doosan_m0609_msgs__msg__SpeedlStream__Sequence__are_equal(const doosan_m0609_msgs__msg__SpeedlStream__Sequence * lhs, const doosan_m0609_msgs__msg__SpeedlStream__Sequence * rhs);

/// Copy an array of msg/SpeedlStream messages.
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
doosan_m0609_msgs__msg__SpeedlStream__Sequence__copy(
  const doosan_m0609_msgs__msg__SpeedlStream__Sequence * input,
  doosan_m0609_msgs__msg__SpeedlStream__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__SPEEDL_STREAM__FUNCTIONS_H_

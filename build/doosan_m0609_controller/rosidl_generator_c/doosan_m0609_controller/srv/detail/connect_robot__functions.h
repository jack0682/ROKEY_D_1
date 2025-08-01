// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from doosan_m0609_controller:srv/ConnectRobot.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_CONTROLLER__SRV__DETAIL__CONNECT_ROBOT__FUNCTIONS_H_
#define DOOSAN_M0609_CONTROLLER__SRV__DETAIL__CONNECT_ROBOT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "doosan_m0609_controller/msg/rosidl_generator_c__visibility_control.h"

#include "doosan_m0609_controller/srv/detail/connect_robot__struct.h"

/// Initialize srv/ConnectRobot message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * doosan_m0609_controller__srv__ConnectRobot_Request
 * )) before or use
 * doosan_m0609_controller__srv__ConnectRobot_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
bool
doosan_m0609_controller__srv__ConnectRobot_Request__init(doosan_m0609_controller__srv__ConnectRobot_Request * msg);

/// Finalize srv/ConnectRobot message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
void
doosan_m0609_controller__srv__ConnectRobot_Request__fini(doosan_m0609_controller__srv__ConnectRobot_Request * msg);

/// Create srv/ConnectRobot message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * doosan_m0609_controller__srv__ConnectRobot_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
doosan_m0609_controller__srv__ConnectRobot_Request *
doosan_m0609_controller__srv__ConnectRobot_Request__create();

/// Destroy srv/ConnectRobot message.
/**
 * It calls
 * doosan_m0609_controller__srv__ConnectRobot_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
void
doosan_m0609_controller__srv__ConnectRobot_Request__destroy(doosan_m0609_controller__srv__ConnectRobot_Request * msg);

/// Check for srv/ConnectRobot message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
bool
doosan_m0609_controller__srv__ConnectRobot_Request__are_equal(const doosan_m0609_controller__srv__ConnectRobot_Request * lhs, const doosan_m0609_controller__srv__ConnectRobot_Request * rhs);

/// Copy a srv/ConnectRobot message.
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
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
bool
doosan_m0609_controller__srv__ConnectRobot_Request__copy(
  const doosan_m0609_controller__srv__ConnectRobot_Request * input,
  doosan_m0609_controller__srv__ConnectRobot_Request * output);

/// Initialize array of srv/ConnectRobot messages.
/**
 * It allocates the memory for the number of elements and calls
 * doosan_m0609_controller__srv__ConnectRobot_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
bool
doosan_m0609_controller__srv__ConnectRobot_Request__Sequence__init(doosan_m0609_controller__srv__ConnectRobot_Request__Sequence * array, size_t size);

/// Finalize array of srv/ConnectRobot messages.
/**
 * It calls
 * doosan_m0609_controller__srv__ConnectRobot_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
void
doosan_m0609_controller__srv__ConnectRobot_Request__Sequence__fini(doosan_m0609_controller__srv__ConnectRobot_Request__Sequence * array);

/// Create array of srv/ConnectRobot messages.
/**
 * It allocates the memory for the array and calls
 * doosan_m0609_controller__srv__ConnectRobot_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
doosan_m0609_controller__srv__ConnectRobot_Request__Sequence *
doosan_m0609_controller__srv__ConnectRobot_Request__Sequence__create(size_t size);

/// Destroy array of srv/ConnectRobot messages.
/**
 * It calls
 * doosan_m0609_controller__srv__ConnectRobot_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
void
doosan_m0609_controller__srv__ConnectRobot_Request__Sequence__destroy(doosan_m0609_controller__srv__ConnectRobot_Request__Sequence * array);

/// Check for srv/ConnectRobot message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
bool
doosan_m0609_controller__srv__ConnectRobot_Request__Sequence__are_equal(const doosan_m0609_controller__srv__ConnectRobot_Request__Sequence * lhs, const doosan_m0609_controller__srv__ConnectRobot_Request__Sequence * rhs);

/// Copy an array of srv/ConnectRobot messages.
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
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
bool
doosan_m0609_controller__srv__ConnectRobot_Request__Sequence__copy(
  const doosan_m0609_controller__srv__ConnectRobot_Request__Sequence * input,
  doosan_m0609_controller__srv__ConnectRobot_Request__Sequence * output);

/// Initialize srv/ConnectRobot message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * doosan_m0609_controller__srv__ConnectRobot_Response
 * )) before or use
 * doosan_m0609_controller__srv__ConnectRobot_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
bool
doosan_m0609_controller__srv__ConnectRobot_Response__init(doosan_m0609_controller__srv__ConnectRobot_Response * msg);

/// Finalize srv/ConnectRobot message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
void
doosan_m0609_controller__srv__ConnectRobot_Response__fini(doosan_m0609_controller__srv__ConnectRobot_Response * msg);

/// Create srv/ConnectRobot message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * doosan_m0609_controller__srv__ConnectRobot_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
doosan_m0609_controller__srv__ConnectRobot_Response *
doosan_m0609_controller__srv__ConnectRobot_Response__create();

/// Destroy srv/ConnectRobot message.
/**
 * It calls
 * doosan_m0609_controller__srv__ConnectRobot_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
void
doosan_m0609_controller__srv__ConnectRobot_Response__destroy(doosan_m0609_controller__srv__ConnectRobot_Response * msg);

/// Check for srv/ConnectRobot message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
bool
doosan_m0609_controller__srv__ConnectRobot_Response__are_equal(const doosan_m0609_controller__srv__ConnectRobot_Response * lhs, const doosan_m0609_controller__srv__ConnectRobot_Response * rhs);

/// Copy a srv/ConnectRobot message.
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
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
bool
doosan_m0609_controller__srv__ConnectRobot_Response__copy(
  const doosan_m0609_controller__srv__ConnectRobot_Response * input,
  doosan_m0609_controller__srv__ConnectRobot_Response * output);

/// Initialize array of srv/ConnectRobot messages.
/**
 * It allocates the memory for the number of elements and calls
 * doosan_m0609_controller__srv__ConnectRobot_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
bool
doosan_m0609_controller__srv__ConnectRobot_Response__Sequence__init(doosan_m0609_controller__srv__ConnectRobot_Response__Sequence * array, size_t size);

/// Finalize array of srv/ConnectRobot messages.
/**
 * It calls
 * doosan_m0609_controller__srv__ConnectRobot_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
void
doosan_m0609_controller__srv__ConnectRobot_Response__Sequence__fini(doosan_m0609_controller__srv__ConnectRobot_Response__Sequence * array);

/// Create array of srv/ConnectRobot messages.
/**
 * It allocates the memory for the array and calls
 * doosan_m0609_controller__srv__ConnectRobot_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
doosan_m0609_controller__srv__ConnectRobot_Response__Sequence *
doosan_m0609_controller__srv__ConnectRobot_Response__Sequence__create(size_t size);

/// Destroy array of srv/ConnectRobot messages.
/**
 * It calls
 * doosan_m0609_controller__srv__ConnectRobot_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
void
doosan_m0609_controller__srv__ConnectRobot_Response__Sequence__destroy(doosan_m0609_controller__srv__ConnectRobot_Response__Sequence * array);

/// Check for srv/ConnectRobot message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
bool
doosan_m0609_controller__srv__ConnectRobot_Response__Sequence__are_equal(const doosan_m0609_controller__srv__ConnectRobot_Response__Sequence * lhs, const doosan_m0609_controller__srv__ConnectRobot_Response__Sequence * rhs);

/// Copy an array of srv/ConnectRobot messages.
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
ROSIDL_GENERATOR_C_PUBLIC_doosan_m0609_controller
bool
doosan_m0609_controller__srv__ConnectRobot_Response__Sequence__copy(
  const doosan_m0609_controller__srv__ConnectRobot_Response__Sequence * input,
  doosan_m0609_controller__srv__ConnectRobot_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_CONTROLLER__SRV__DETAIL__CONNECT_ROBOT__FUNCTIONS_H_

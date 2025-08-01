// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from doosan_m0609_controller:msg/RobotStatus.idl
// generated code does not contain a copyright notice
#include "doosan_m0609_controller/msg/detail/robot_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `robot_state`
// Member `error_message`
#include "rosidl_runtime_c/string_functions.h"

bool
doosan_m0609_controller__msg__RobotStatus__init(doosan_m0609_controller__msg__RobotStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    doosan_m0609_controller__msg__RobotStatus__fini(msg);
    return false;
  }
  // is_connected
  // is_enabled
  // has_control_authority
  // robot_state
  if (!rosidl_runtime_c__String__init(&msg->robot_state)) {
    doosan_m0609_controller__msg__RobotStatus__fini(msg);
    return false;
  }
  // error_message
  if (!rosidl_runtime_c__String__init(&msg->error_message)) {
    doosan_m0609_controller__msg__RobotStatus__fini(msg);
    return false;
  }
  return true;
}

void
doosan_m0609_controller__msg__RobotStatus__fini(doosan_m0609_controller__msg__RobotStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // is_connected
  // is_enabled
  // has_control_authority
  // robot_state
  rosidl_runtime_c__String__fini(&msg->robot_state);
  // error_message
  rosidl_runtime_c__String__fini(&msg->error_message);
}

bool
doosan_m0609_controller__msg__RobotStatus__are_equal(const doosan_m0609_controller__msg__RobotStatus * lhs, const doosan_m0609_controller__msg__RobotStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // is_connected
  if (lhs->is_connected != rhs->is_connected) {
    return false;
  }
  // is_enabled
  if (lhs->is_enabled != rhs->is_enabled) {
    return false;
  }
  // has_control_authority
  if (lhs->has_control_authority != rhs->has_control_authority) {
    return false;
  }
  // robot_state
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->robot_state), &(rhs->robot_state)))
  {
    return false;
  }
  // error_message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->error_message), &(rhs->error_message)))
  {
    return false;
  }
  return true;
}

bool
doosan_m0609_controller__msg__RobotStatus__copy(
  const doosan_m0609_controller__msg__RobotStatus * input,
  doosan_m0609_controller__msg__RobotStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // is_connected
  output->is_connected = input->is_connected;
  // is_enabled
  output->is_enabled = input->is_enabled;
  // has_control_authority
  output->has_control_authority = input->has_control_authority;
  // robot_state
  if (!rosidl_runtime_c__String__copy(
      &(input->robot_state), &(output->robot_state)))
  {
    return false;
  }
  // error_message
  if (!rosidl_runtime_c__String__copy(
      &(input->error_message), &(output->error_message)))
  {
    return false;
  }
  return true;
}

doosan_m0609_controller__msg__RobotStatus *
doosan_m0609_controller__msg__RobotStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_controller__msg__RobotStatus * msg = (doosan_m0609_controller__msg__RobotStatus *)allocator.allocate(sizeof(doosan_m0609_controller__msg__RobotStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(doosan_m0609_controller__msg__RobotStatus));
  bool success = doosan_m0609_controller__msg__RobotStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
doosan_m0609_controller__msg__RobotStatus__destroy(doosan_m0609_controller__msg__RobotStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    doosan_m0609_controller__msg__RobotStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
doosan_m0609_controller__msg__RobotStatus__Sequence__init(doosan_m0609_controller__msg__RobotStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_controller__msg__RobotStatus * data = NULL;

  if (size) {
    data = (doosan_m0609_controller__msg__RobotStatus *)allocator.zero_allocate(size, sizeof(doosan_m0609_controller__msg__RobotStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = doosan_m0609_controller__msg__RobotStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        doosan_m0609_controller__msg__RobotStatus__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
doosan_m0609_controller__msg__RobotStatus__Sequence__fini(doosan_m0609_controller__msg__RobotStatus__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      doosan_m0609_controller__msg__RobotStatus__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

doosan_m0609_controller__msg__RobotStatus__Sequence *
doosan_m0609_controller__msg__RobotStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_controller__msg__RobotStatus__Sequence * array = (doosan_m0609_controller__msg__RobotStatus__Sequence *)allocator.allocate(sizeof(doosan_m0609_controller__msg__RobotStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = doosan_m0609_controller__msg__RobotStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
doosan_m0609_controller__msg__RobotStatus__Sequence__destroy(doosan_m0609_controller__msg__RobotStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    doosan_m0609_controller__msg__RobotStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
doosan_m0609_controller__msg__RobotStatus__Sequence__are_equal(const doosan_m0609_controller__msg__RobotStatus__Sequence * lhs, const doosan_m0609_controller__msg__RobotStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!doosan_m0609_controller__msg__RobotStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
doosan_m0609_controller__msg__RobotStatus__Sequence__copy(
  const doosan_m0609_controller__msg__RobotStatus__Sequence * input,
  doosan_m0609_controller__msg__RobotStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(doosan_m0609_controller__msg__RobotStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    doosan_m0609_controller__msg__RobotStatus * data =
      (doosan_m0609_controller__msg__RobotStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!doosan_m0609_controller__msg__RobotStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          doosan_m0609_controller__msg__RobotStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!doosan_m0609_controller__msg__RobotStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

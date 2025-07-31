// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from doosan_m0609_msgs:msg/RobotError.idl
// generated code does not contain a copyright notice
#include "doosan_m0609_msgs/msg/detail/robot_error__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `msg1`
// Member `msg2`
// Member `msg3`
#include "rosidl_runtime_c/string_functions.h"

bool
doosan_m0609_msgs__msg__RobotError__init(doosan_m0609_msgs__msg__RobotError * msg)
{
  if (!msg) {
    return false;
  }
  // level
  // group
  // code
  // msg1
  if (!rosidl_runtime_c__String__init(&msg->msg1)) {
    doosan_m0609_msgs__msg__RobotError__fini(msg);
    return false;
  }
  // msg2
  if (!rosidl_runtime_c__String__init(&msg->msg2)) {
    doosan_m0609_msgs__msg__RobotError__fini(msg);
    return false;
  }
  // msg3
  if (!rosidl_runtime_c__String__init(&msg->msg3)) {
    doosan_m0609_msgs__msg__RobotError__fini(msg);
    return false;
  }
  return true;
}

void
doosan_m0609_msgs__msg__RobotError__fini(doosan_m0609_msgs__msg__RobotError * msg)
{
  if (!msg) {
    return;
  }
  // level
  // group
  // code
  // msg1
  rosidl_runtime_c__String__fini(&msg->msg1);
  // msg2
  rosidl_runtime_c__String__fini(&msg->msg2);
  // msg3
  rosidl_runtime_c__String__fini(&msg->msg3);
}

bool
doosan_m0609_msgs__msg__RobotError__are_equal(const doosan_m0609_msgs__msg__RobotError * lhs, const doosan_m0609_msgs__msg__RobotError * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // level
  if (lhs->level != rhs->level) {
    return false;
  }
  // group
  if (lhs->group != rhs->group) {
    return false;
  }
  // code
  if (lhs->code != rhs->code) {
    return false;
  }
  // msg1
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->msg1), &(rhs->msg1)))
  {
    return false;
  }
  // msg2
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->msg2), &(rhs->msg2)))
  {
    return false;
  }
  // msg3
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->msg3), &(rhs->msg3)))
  {
    return false;
  }
  return true;
}

bool
doosan_m0609_msgs__msg__RobotError__copy(
  const doosan_m0609_msgs__msg__RobotError * input,
  doosan_m0609_msgs__msg__RobotError * output)
{
  if (!input || !output) {
    return false;
  }
  // level
  output->level = input->level;
  // group
  output->group = input->group;
  // code
  output->code = input->code;
  // msg1
  if (!rosidl_runtime_c__String__copy(
      &(input->msg1), &(output->msg1)))
  {
    return false;
  }
  // msg2
  if (!rosidl_runtime_c__String__copy(
      &(input->msg2), &(output->msg2)))
  {
    return false;
  }
  // msg3
  if (!rosidl_runtime_c__String__copy(
      &(input->msg3), &(output->msg3)))
  {
    return false;
  }
  return true;
}

doosan_m0609_msgs__msg__RobotError *
doosan_m0609_msgs__msg__RobotError__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__RobotError * msg = (doosan_m0609_msgs__msg__RobotError *)allocator.allocate(sizeof(doosan_m0609_msgs__msg__RobotError), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(doosan_m0609_msgs__msg__RobotError));
  bool success = doosan_m0609_msgs__msg__RobotError__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
doosan_m0609_msgs__msg__RobotError__destroy(doosan_m0609_msgs__msg__RobotError * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    doosan_m0609_msgs__msg__RobotError__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
doosan_m0609_msgs__msg__RobotError__Sequence__init(doosan_m0609_msgs__msg__RobotError__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__RobotError * data = NULL;

  if (size) {
    data = (doosan_m0609_msgs__msg__RobotError *)allocator.zero_allocate(size, sizeof(doosan_m0609_msgs__msg__RobotError), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = doosan_m0609_msgs__msg__RobotError__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        doosan_m0609_msgs__msg__RobotError__fini(&data[i - 1]);
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
doosan_m0609_msgs__msg__RobotError__Sequence__fini(doosan_m0609_msgs__msg__RobotError__Sequence * array)
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
      doosan_m0609_msgs__msg__RobotError__fini(&array->data[i]);
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

doosan_m0609_msgs__msg__RobotError__Sequence *
doosan_m0609_msgs__msg__RobotError__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__RobotError__Sequence * array = (doosan_m0609_msgs__msg__RobotError__Sequence *)allocator.allocate(sizeof(doosan_m0609_msgs__msg__RobotError__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = doosan_m0609_msgs__msg__RobotError__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
doosan_m0609_msgs__msg__RobotError__Sequence__destroy(doosan_m0609_msgs__msg__RobotError__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    doosan_m0609_msgs__msg__RobotError__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
doosan_m0609_msgs__msg__RobotError__Sequence__are_equal(const doosan_m0609_msgs__msg__RobotError__Sequence * lhs, const doosan_m0609_msgs__msg__RobotError__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!doosan_m0609_msgs__msg__RobotError__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
doosan_m0609_msgs__msg__RobotError__Sequence__copy(
  const doosan_m0609_msgs__msg__RobotError__Sequence * input,
  doosan_m0609_msgs__msg__RobotError__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(doosan_m0609_msgs__msg__RobotError);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    doosan_m0609_msgs__msg__RobotError * data =
      (doosan_m0609_msgs__msg__RobotError *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!doosan_m0609_msgs__msg__RobotError__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          doosan_m0609_msgs__msg__RobotError__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!doosan_m0609_msgs__msg__RobotError__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from doosan_m0609_msgs:msg/RobotDisconnection.idl
// generated code does not contain a copyright notice
#include "doosan_m0609_msgs/msg/detail/robot_disconnection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
doosan_m0609_msgs__msg__RobotDisconnection__init(doosan_m0609_msgs__msg__RobotDisconnection * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
doosan_m0609_msgs__msg__RobotDisconnection__fini(doosan_m0609_msgs__msg__RobotDisconnection * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
doosan_m0609_msgs__msg__RobotDisconnection__are_equal(const doosan_m0609_msgs__msg__RobotDisconnection * lhs, const doosan_m0609_msgs__msg__RobotDisconnection * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
doosan_m0609_msgs__msg__RobotDisconnection__copy(
  const doosan_m0609_msgs__msg__RobotDisconnection * input,
  doosan_m0609_msgs__msg__RobotDisconnection * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

doosan_m0609_msgs__msg__RobotDisconnection *
doosan_m0609_msgs__msg__RobotDisconnection__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__RobotDisconnection * msg = (doosan_m0609_msgs__msg__RobotDisconnection *)allocator.allocate(sizeof(doosan_m0609_msgs__msg__RobotDisconnection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(doosan_m0609_msgs__msg__RobotDisconnection));
  bool success = doosan_m0609_msgs__msg__RobotDisconnection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
doosan_m0609_msgs__msg__RobotDisconnection__destroy(doosan_m0609_msgs__msg__RobotDisconnection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    doosan_m0609_msgs__msg__RobotDisconnection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
doosan_m0609_msgs__msg__RobotDisconnection__Sequence__init(doosan_m0609_msgs__msg__RobotDisconnection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__RobotDisconnection * data = NULL;

  if (size) {
    data = (doosan_m0609_msgs__msg__RobotDisconnection *)allocator.zero_allocate(size, sizeof(doosan_m0609_msgs__msg__RobotDisconnection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = doosan_m0609_msgs__msg__RobotDisconnection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        doosan_m0609_msgs__msg__RobotDisconnection__fini(&data[i - 1]);
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
doosan_m0609_msgs__msg__RobotDisconnection__Sequence__fini(doosan_m0609_msgs__msg__RobotDisconnection__Sequence * array)
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
      doosan_m0609_msgs__msg__RobotDisconnection__fini(&array->data[i]);
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

doosan_m0609_msgs__msg__RobotDisconnection__Sequence *
doosan_m0609_msgs__msg__RobotDisconnection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__RobotDisconnection__Sequence * array = (doosan_m0609_msgs__msg__RobotDisconnection__Sequence *)allocator.allocate(sizeof(doosan_m0609_msgs__msg__RobotDisconnection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = doosan_m0609_msgs__msg__RobotDisconnection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
doosan_m0609_msgs__msg__RobotDisconnection__Sequence__destroy(doosan_m0609_msgs__msg__RobotDisconnection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    doosan_m0609_msgs__msg__RobotDisconnection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
doosan_m0609_msgs__msg__RobotDisconnection__Sequence__are_equal(const doosan_m0609_msgs__msg__RobotDisconnection__Sequence * lhs, const doosan_m0609_msgs__msg__RobotDisconnection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!doosan_m0609_msgs__msg__RobotDisconnection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
doosan_m0609_msgs__msg__RobotDisconnection__Sequence__copy(
  const doosan_m0609_msgs__msg__RobotDisconnection__Sequence * input,
  doosan_m0609_msgs__msg__RobotDisconnection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(doosan_m0609_msgs__msg__RobotDisconnection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    doosan_m0609_msgs__msg__RobotDisconnection * data =
      (doosan_m0609_msgs__msg__RobotDisconnection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!doosan_m0609_msgs__msg__RobotDisconnection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          doosan_m0609_msgs__msg__RobotDisconnection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!doosan_m0609_msgs__msg__RobotDisconnection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

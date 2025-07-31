// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from doosan_m0609_msgs:msg/AlterMotionStream.idl
// generated code does not contain a copyright notice
#include "doosan_m0609_msgs/msg/detail/alter_motion_stream__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
doosan_m0609_msgs__msg__AlterMotionStream__init(doosan_m0609_msgs__msg__AlterMotionStream * msg)
{
  if (!msg) {
    return false;
  }
  // pos
  return true;
}

void
doosan_m0609_msgs__msg__AlterMotionStream__fini(doosan_m0609_msgs__msg__AlterMotionStream * msg)
{
  if (!msg) {
    return;
  }
  // pos
}

bool
doosan_m0609_msgs__msg__AlterMotionStream__are_equal(const doosan_m0609_msgs__msg__AlterMotionStream * lhs, const doosan_m0609_msgs__msg__AlterMotionStream * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pos
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->pos[i] != rhs->pos[i]) {
      return false;
    }
  }
  return true;
}

bool
doosan_m0609_msgs__msg__AlterMotionStream__copy(
  const doosan_m0609_msgs__msg__AlterMotionStream * input,
  doosan_m0609_msgs__msg__AlterMotionStream * output)
{
  if (!input || !output) {
    return false;
  }
  // pos
  for (size_t i = 0; i < 6; ++i) {
    output->pos[i] = input->pos[i];
  }
  return true;
}

doosan_m0609_msgs__msg__AlterMotionStream *
doosan_m0609_msgs__msg__AlterMotionStream__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__AlterMotionStream * msg = (doosan_m0609_msgs__msg__AlterMotionStream *)allocator.allocate(sizeof(doosan_m0609_msgs__msg__AlterMotionStream), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(doosan_m0609_msgs__msg__AlterMotionStream));
  bool success = doosan_m0609_msgs__msg__AlterMotionStream__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
doosan_m0609_msgs__msg__AlterMotionStream__destroy(doosan_m0609_msgs__msg__AlterMotionStream * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    doosan_m0609_msgs__msg__AlterMotionStream__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
doosan_m0609_msgs__msg__AlterMotionStream__Sequence__init(doosan_m0609_msgs__msg__AlterMotionStream__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__AlterMotionStream * data = NULL;

  if (size) {
    data = (doosan_m0609_msgs__msg__AlterMotionStream *)allocator.zero_allocate(size, sizeof(doosan_m0609_msgs__msg__AlterMotionStream), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = doosan_m0609_msgs__msg__AlterMotionStream__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        doosan_m0609_msgs__msg__AlterMotionStream__fini(&data[i - 1]);
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
doosan_m0609_msgs__msg__AlterMotionStream__Sequence__fini(doosan_m0609_msgs__msg__AlterMotionStream__Sequence * array)
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
      doosan_m0609_msgs__msg__AlterMotionStream__fini(&array->data[i]);
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

doosan_m0609_msgs__msg__AlterMotionStream__Sequence *
doosan_m0609_msgs__msg__AlterMotionStream__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__AlterMotionStream__Sequence * array = (doosan_m0609_msgs__msg__AlterMotionStream__Sequence *)allocator.allocate(sizeof(doosan_m0609_msgs__msg__AlterMotionStream__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = doosan_m0609_msgs__msg__AlterMotionStream__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
doosan_m0609_msgs__msg__AlterMotionStream__Sequence__destroy(doosan_m0609_msgs__msg__AlterMotionStream__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    doosan_m0609_msgs__msg__AlterMotionStream__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
doosan_m0609_msgs__msg__AlterMotionStream__Sequence__are_equal(const doosan_m0609_msgs__msg__AlterMotionStream__Sequence * lhs, const doosan_m0609_msgs__msg__AlterMotionStream__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!doosan_m0609_msgs__msg__AlterMotionStream__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
doosan_m0609_msgs__msg__AlterMotionStream__Sequence__copy(
  const doosan_m0609_msgs__msg__AlterMotionStream__Sequence * input,
  doosan_m0609_msgs__msg__AlterMotionStream__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(doosan_m0609_msgs__msg__AlterMotionStream);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    doosan_m0609_msgs__msg__AlterMotionStream * data =
      (doosan_m0609_msgs__msg__AlterMotionStream *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!doosan_m0609_msgs__msg__AlterMotionStream__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          doosan_m0609_msgs__msg__AlterMotionStream__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!doosan_m0609_msgs__msg__AlterMotionStream__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

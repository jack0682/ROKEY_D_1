// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from doosan_m0609_msgs:msg/ServojRtStream.idl
// generated code does not contain a copyright notice
#include "doosan_m0609_msgs/msg/detail/servoj_rt_stream__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
doosan_m0609_msgs__msg__ServojRtStream__init(doosan_m0609_msgs__msg__ServojRtStream * msg)
{
  if (!msg) {
    return false;
  }
  // pos
  // vel
  // acc
  // time
  return true;
}

void
doosan_m0609_msgs__msg__ServojRtStream__fini(doosan_m0609_msgs__msg__ServojRtStream * msg)
{
  if (!msg) {
    return;
  }
  // pos
  // vel
  // acc
  // time
}

bool
doosan_m0609_msgs__msg__ServojRtStream__are_equal(const doosan_m0609_msgs__msg__ServojRtStream * lhs, const doosan_m0609_msgs__msg__ServojRtStream * rhs)
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
  // vel
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->vel[i] != rhs->vel[i]) {
      return false;
    }
  }
  // acc
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->acc[i] != rhs->acc[i]) {
      return false;
    }
  }
  // time
  if (lhs->time != rhs->time) {
    return false;
  }
  return true;
}

bool
doosan_m0609_msgs__msg__ServojRtStream__copy(
  const doosan_m0609_msgs__msg__ServojRtStream * input,
  doosan_m0609_msgs__msg__ServojRtStream * output)
{
  if (!input || !output) {
    return false;
  }
  // pos
  for (size_t i = 0; i < 6; ++i) {
    output->pos[i] = input->pos[i];
  }
  // vel
  for (size_t i = 0; i < 6; ++i) {
    output->vel[i] = input->vel[i];
  }
  // acc
  for (size_t i = 0; i < 6; ++i) {
    output->acc[i] = input->acc[i];
  }
  // time
  output->time = input->time;
  return true;
}

doosan_m0609_msgs__msg__ServojRtStream *
doosan_m0609_msgs__msg__ServojRtStream__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__ServojRtStream * msg = (doosan_m0609_msgs__msg__ServojRtStream *)allocator.allocate(sizeof(doosan_m0609_msgs__msg__ServojRtStream), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(doosan_m0609_msgs__msg__ServojRtStream));
  bool success = doosan_m0609_msgs__msg__ServojRtStream__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
doosan_m0609_msgs__msg__ServojRtStream__destroy(doosan_m0609_msgs__msg__ServojRtStream * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    doosan_m0609_msgs__msg__ServojRtStream__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
doosan_m0609_msgs__msg__ServojRtStream__Sequence__init(doosan_m0609_msgs__msg__ServojRtStream__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__ServojRtStream * data = NULL;

  if (size) {
    data = (doosan_m0609_msgs__msg__ServojRtStream *)allocator.zero_allocate(size, sizeof(doosan_m0609_msgs__msg__ServojRtStream), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = doosan_m0609_msgs__msg__ServojRtStream__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        doosan_m0609_msgs__msg__ServojRtStream__fini(&data[i - 1]);
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
doosan_m0609_msgs__msg__ServojRtStream__Sequence__fini(doosan_m0609_msgs__msg__ServojRtStream__Sequence * array)
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
      doosan_m0609_msgs__msg__ServojRtStream__fini(&array->data[i]);
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

doosan_m0609_msgs__msg__ServojRtStream__Sequence *
doosan_m0609_msgs__msg__ServojRtStream__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__ServojRtStream__Sequence * array = (doosan_m0609_msgs__msg__ServojRtStream__Sequence *)allocator.allocate(sizeof(doosan_m0609_msgs__msg__ServojRtStream__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = doosan_m0609_msgs__msg__ServojRtStream__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
doosan_m0609_msgs__msg__ServojRtStream__Sequence__destroy(doosan_m0609_msgs__msg__ServojRtStream__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    doosan_m0609_msgs__msg__ServojRtStream__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
doosan_m0609_msgs__msg__ServojRtStream__Sequence__are_equal(const doosan_m0609_msgs__msg__ServojRtStream__Sequence * lhs, const doosan_m0609_msgs__msg__ServojRtStream__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!doosan_m0609_msgs__msg__ServojRtStream__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
doosan_m0609_msgs__msg__ServojRtStream__Sequence__copy(
  const doosan_m0609_msgs__msg__ServojRtStream__Sequence * input,
  doosan_m0609_msgs__msg__ServojRtStream__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(doosan_m0609_msgs__msg__ServojRtStream);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    doosan_m0609_msgs__msg__ServojRtStream * data =
      (doosan_m0609_msgs__msg__ServojRtStream *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!doosan_m0609_msgs__msg__ServojRtStream__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          doosan_m0609_msgs__msg__ServojRtStream__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!doosan_m0609_msgs__msg__ServojRtStream__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

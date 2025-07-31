// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from doosan_m0609_msgs:msg/JogMultiAxis.idl
// generated code does not contain a copyright notice
#include "doosan_m0609_msgs/msg/detail/jog_multi_axis__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
doosan_m0609_msgs__msg__JogMultiAxis__init(doosan_m0609_msgs__msg__JogMultiAxis * msg)
{
  if (!msg) {
    return false;
  }
  // jog_axis
  // move_reference
  // speed
  return true;
}

void
doosan_m0609_msgs__msg__JogMultiAxis__fini(doosan_m0609_msgs__msg__JogMultiAxis * msg)
{
  if (!msg) {
    return;
  }
  // jog_axis
  // move_reference
  // speed
}

bool
doosan_m0609_msgs__msg__JogMultiAxis__are_equal(const doosan_m0609_msgs__msg__JogMultiAxis * lhs, const doosan_m0609_msgs__msg__JogMultiAxis * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // jog_axis
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->jog_axis[i] != rhs->jog_axis[i]) {
      return false;
    }
  }
  // move_reference
  if (lhs->move_reference != rhs->move_reference) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  return true;
}

bool
doosan_m0609_msgs__msg__JogMultiAxis__copy(
  const doosan_m0609_msgs__msg__JogMultiAxis * input,
  doosan_m0609_msgs__msg__JogMultiAxis * output)
{
  if (!input || !output) {
    return false;
  }
  // jog_axis
  for (size_t i = 0; i < 6; ++i) {
    output->jog_axis[i] = input->jog_axis[i];
  }
  // move_reference
  output->move_reference = input->move_reference;
  // speed
  output->speed = input->speed;
  return true;
}

doosan_m0609_msgs__msg__JogMultiAxis *
doosan_m0609_msgs__msg__JogMultiAxis__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__JogMultiAxis * msg = (doosan_m0609_msgs__msg__JogMultiAxis *)allocator.allocate(sizeof(doosan_m0609_msgs__msg__JogMultiAxis), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(doosan_m0609_msgs__msg__JogMultiAxis));
  bool success = doosan_m0609_msgs__msg__JogMultiAxis__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
doosan_m0609_msgs__msg__JogMultiAxis__destroy(doosan_m0609_msgs__msg__JogMultiAxis * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    doosan_m0609_msgs__msg__JogMultiAxis__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
doosan_m0609_msgs__msg__JogMultiAxis__Sequence__init(doosan_m0609_msgs__msg__JogMultiAxis__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__JogMultiAxis * data = NULL;

  if (size) {
    data = (doosan_m0609_msgs__msg__JogMultiAxis *)allocator.zero_allocate(size, sizeof(doosan_m0609_msgs__msg__JogMultiAxis), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = doosan_m0609_msgs__msg__JogMultiAxis__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        doosan_m0609_msgs__msg__JogMultiAxis__fini(&data[i - 1]);
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
doosan_m0609_msgs__msg__JogMultiAxis__Sequence__fini(doosan_m0609_msgs__msg__JogMultiAxis__Sequence * array)
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
      doosan_m0609_msgs__msg__JogMultiAxis__fini(&array->data[i]);
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

doosan_m0609_msgs__msg__JogMultiAxis__Sequence *
doosan_m0609_msgs__msg__JogMultiAxis__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__JogMultiAxis__Sequence * array = (doosan_m0609_msgs__msg__JogMultiAxis__Sequence *)allocator.allocate(sizeof(doosan_m0609_msgs__msg__JogMultiAxis__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = doosan_m0609_msgs__msg__JogMultiAxis__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
doosan_m0609_msgs__msg__JogMultiAxis__Sequence__destroy(doosan_m0609_msgs__msg__JogMultiAxis__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    doosan_m0609_msgs__msg__JogMultiAxis__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
doosan_m0609_msgs__msg__JogMultiAxis__Sequence__are_equal(const doosan_m0609_msgs__msg__JogMultiAxis__Sequence * lhs, const doosan_m0609_msgs__msg__JogMultiAxis__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!doosan_m0609_msgs__msg__JogMultiAxis__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
doosan_m0609_msgs__msg__JogMultiAxis__Sequence__copy(
  const doosan_m0609_msgs__msg__JogMultiAxis__Sequence * input,
  doosan_m0609_msgs__msg__JogMultiAxis__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(doosan_m0609_msgs__msg__JogMultiAxis);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    doosan_m0609_msgs__msg__JogMultiAxis * data =
      (doosan_m0609_msgs__msg__JogMultiAxis *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!doosan_m0609_msgs__msg__JogMultiAxis__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          doosan_m0609_msgs__msg__JogMultiAxis__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!doosan_m0609_msgs__msg__JogMultiAxis__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

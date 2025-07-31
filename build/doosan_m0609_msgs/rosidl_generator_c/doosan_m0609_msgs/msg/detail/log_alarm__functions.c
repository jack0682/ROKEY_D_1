// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from doosan_m0609_msgs:msg/LogAlarm.idl
// generated code does not contain a copyright notice
#include "doosan_m0609_msgs/msg/detail/log_alarm__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `param`
#include "rosidl_runtime_c/string_functions.h"

bool
doosan_m0609_msgs__msg__LogAlarm__init(doosan_m0609_msgs__msg__LogAlarm * msg)
{
  if (!msg) {
    return false;
  }
  // level
  // group
  // index
  // param
  for (size_t i = 0; i < 3; ++i) {
    if (!rosidl_runtime_c__String__init(&msg->param[i])) {
      doosan_m0609_msgs__msg__LogAlarm__fini(msg);
      return false;
    }
  }
  return true;
}

void
doosan_m0609_msgs__msg__LogAlarm__fini(doosan_m0609_msgs__msg__LogAlarm * msg)
{
  if (!msg) {
    return;
  }
  // level
  // group
  // index
  // param
  for (size_t i = 0; i < 3; ++i) {
    rosidl_runtime_c__String__fini(&msg->param[i]);
  }
}

bool
doosan_m0609_msgs__msg__LogAlarm__are_equal(const doosan_m0609_msgs__msg__LogAlarm * lhs, const doosan_m0609_msgs__msg__LogAlarm * rhs)
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
  // index
  if (lhs->index != rhs->index) {
    return false;
  }
  // param
  for (size_t i = 0; i < 3; ++i) {
    if (!rosidl_runtime_c__String__are_equal(
        &(lhs->param[i]), &(rhs->param[i])))
    {
      return false;
    }
  }
  return true;
}

bool
doosan_m0609_msgs__msg__LogAlarm__copy(
  const doosan_m0609_msgs__msg__LogAlarm * input,
  doosan_m0609_msgs__msg__LogAlarm * output)
{
  if (!input || !output) {
    return false;
  }
  // level
  output->level = input->level;
  // group
  output->group = input->group;
  // index
  output->index = input->index;
  // param
  for (size_t i = 0; i < 3; ++i) {
    if (!rosidl_runtime_c__String__copy(
        &(input->param[i]), &(output->param[i])))
    {
      return false;
    }
  }
  return true;
}

doosan_m0609_msgs__msg__LogAlarm *
doosan_m0609_msgs__msg__LogAlarm__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__LogAlarm * msg = (doosan_m0609_msgs__msg__LogAlarm *)allocator.allocate(sizeof(doosan_m0609_msgs__msg__LogAlarm), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(doosan_m0609_msgs__msg__LogAlarm));
  bool success = doosan_m0609_msgs__msg__LogAlarm__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
doosan_m0609_msgs__msg__LogAlarm__destroy(doosan_m0609_msgs__msg__LogAlarm * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    doosan_m0609_msgs__msg__LogAlarm__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
doosan_m0609_msgs__msg__LogAlarm__Sequence__init(doosan_m0609_msgs__msg__LogAlarm__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__LogAlarm * data = NULL;

  if (size) {
    data = (doosan_m0609_msgs__msg__LogAlarm *)allocator.zero_allocate(size, sizeof(doosan_m0609_msgs__msg__LogAlarm), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = doosan_m0609_msgs__msg__LogAlarm__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        doosan_m0609_msgs__msg__LogAlarm__fini(&data[i - 1]);
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
doosan_m0609_msgs__msg__LogAlarm__Sequence__fini(doosan_m0609_msgs__msg__LogAlarm__Sequence * array)
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
      doosan_m0609_msgs__msg__LogAlarm__fini(&array->data[i]);
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

doosan_m0609_msgs__msg__LogAlarm__Sequence *
doosan_m0609_msgs__msg__LogAlarm__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__LogAlarm__Sequence * array = (doosan_m0609_msgs__msg__LogAlarm__Sequence *)allocator.allocate(sizeof(doosan_m0609_msgs__msg__LogAlarm__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = doosan_m0609_msgs__msg__LogAlarm__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
doosan_m0609_msgs__msg__LogAlarm__Sequence__destroy(doosan_m0609_msgs__msg__LogAlarm__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    doosan_m0609_msgs__msg__LogAlarm__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
doosan_m0609_msgs__msg__LogAlarm__Sequence__are_equal(const doosan_m0609_msgs__msg__LogAlarm__Sequence * lhs, const doosan_m0609_msgs__msg__LogAlarm__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!doosan_m0609_msgs__msg__LogAlarm__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
doosan_m0609_msgs__msg__LogAlarm__Sequence__copy(
  const doosan_m0609_msgs__msg__LogAlarm__Sequence * input,
  doosan_m0609_msgs__msg__LogAlarm__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(doosan_m0609_msgs__msg__LogAlarm);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    doosan_m0609_msgs__msg__LogAlarm * data =
      (doosan_m0609_msgs__msg__LogAlarm *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!doosan_m0609_msgs__msg__LogAlarm__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          doosan_m0609_msgs__msg__LogAlarm__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!doosan_m0609_msgs__msg__LogAlarm__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

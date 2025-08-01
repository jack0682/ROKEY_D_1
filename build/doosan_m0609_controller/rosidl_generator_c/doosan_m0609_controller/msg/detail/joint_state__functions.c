// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from doosan_m0609_controller:msg/JointState.idl
// generated code does not contain a copyright notice
#include "doosan_m0609_controller/msg/detail/joint_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
doosan_m0609_controller__msg__JointState__init(doosan_m0609_controller__msg__JointState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    doosan_m0609_controller__msg__JointState__fini(msg);
    return false;
  }
  // position
  // velocity
  // effort
  return true;
}

void
doosan_m0609_controller__msg__JointState__fini(doosan_m0609_controller__msg__JointState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // position
  // velocity
  // effort
}

bool
doosan_m0609_controller__msg__JointState__are_equal(const doosan_m0609_controller__msg__JointState * lhs, const doosan_m0609_controller__msg__JointState * rhs)
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
  // position
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->position[i] != rhs->position[i]) {
      return false;
    }
  }
  // velocity
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->velocity[i] != rhs->velocity[i]) {
      return false;
    }
  }
  // effort
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->effort[i] != rhs->effort[i]) {
      return false;
    }
  }
  return true;
}

bool
doosan_m0609_controller__msg__JointState__copy(
  const doosan_m0609_controller__msg__JointState * input,
  doosan_m0609_controller__msg__JointState * output)
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
  // position
  for (size_t i = 0; i < 6; ++i) {
    output->position[i] = input->position[i];
  }
  // velocity
  for (size_t i = 0; i < 6; ++i) {
    output->velocity[i] = input->velocity[i];
  }
  // effort
  for (size_t i = 0; i < 6; ++i) {
    output->effort[i] = input->effort[i];
  }
  return true;
}

doosan_m0609_controller__msg__JointState *
doosan_m0609_controller__msg__JointState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_controller__msg__JointState * msg = (doosan_m0609_controller__msg__JointState *)allocator.allocate(sizeof(doosan_m0609_controller__msg__JointState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(doosan_m0609_controller__msg__JointState));
  bool success = doosan_m0609_controller__msg__JointState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
doosan_m0609_controller__msg__JointState__destroy(doosan_m0609_controller__msg__JointState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    doosan_m0609_controller__msg__JointState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
doosan_m0609_controller__msg__JointState__Sequence__init(doosan_m0609_controller__msg__JointState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_controller__msg__JointState * data = NULL;

  if (size) {
    data = (doosan_m0609_controller__msg__JointState *)allocator.zero_allocate(size, sizeof(doosan_m0609_controller__msg__JointState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = doosan_m0609_controller__msg__JointState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        doosan_m0609_controller__msg__JointState__fini(&data[i - 1]);
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
doosan_m0609_controller__msg__JointState__Sequence__fini(doosan_m0609_controller__msg__JointState__Sequence * array)
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
      doosan_m0609_controller__msg__JointState__fini(&array->data[i]);
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

doosan_m0609_controller__msg__JointState__Sequence *
doosan_m0609_controller__msg__JointState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_controller__msg__JointState__Sequence * array = (doosan_m0609_controller__msg__JointState__Sequence *)allocator.allocate(sizeof(doosan_m0609_controller__msg__JointState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = doosan_m0609_controller__msg__JointState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
doosan_m0609_controller__msg__JointState__Sequence__destroy(doosan_m0609_controller__msg__JointState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    doosan_m0609_controller__msg__JointState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
doosan_m0609_controller__msg__JointState__Sequence__are_equal(const doosan_m0609_controller__msg__JointState__Sequence * lhs, const doosan_m0609_controller__msg__JointState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!doosan_m0609_controller__msg__JointState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
doosan_m0609_controller__msg__JointState__Sequence__copy(
  const doosan_m0609_controller__msg__JointState__Sequence * input,
  doosan_m0609_controller__msg__JointState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(doosan_m0609_controller__msg__JointState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    doosan_m0609_controller__msg__JointState * data =
      (doosan_m0609_controller__msg__JointState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!doosan_m0609_controller__msg__JointState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          doosan_m0609_controller__msg__JointState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!doosan_m0609_controller__msg__JointState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

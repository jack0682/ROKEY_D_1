// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from doosan_m0609_msgs:srv/MoveResume.idl
// generated code does not contain a copyright notice
#include "doosan_m0609_msgs/srv/detail/move_resume__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
doosan_m0609_msgs__srv__MoveResume_Request__init(doosan_m0609_msgs__srv__MoveResume_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
doosan_m0609_msgs__srv__MoveResume_Request__fini(doosan_m0609_msgs__srv__MoveResume_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
doosan_m0609_msgs__srv__MoveResume_Request__are_equal(const doosan_m0609_msgs__srv__MoveResume_Request * lhs, const doosan_m0609_msgs__srv__MoveResume_Request * rhs)
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
doosan_m0609_msgs__srv__MoveResume_Request__copy(
  const doosan_m0609_msgs__srv__MoveResume_Request * input,
  doosan_m0609_msgs__srv__MoveResume_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

doosan_m0609_msgs__srv__MoveResume_Request *
doosan_m0609_msgs__srv__MoveResume_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__srv__MoveResume_Request * msg = (doosan_m0609_msgs__srv__MoveResume_Request *)allocator.allocate(sizeof(doosan_m0609_msgs__srv__MoveResume_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(doosan_m0609_msgs__srv__MoveResume_Request));
  bool success = doosan_m0609_msgs__srv__MoveResume_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
doosan_m0609_msgs__srv__MoveResume_Request__destroy(doosan_m0609_msgs__srv__MoveResume_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    doosan_m0609_msgs__srv__MoveResume_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
doosan_m0609_msgs__srv__MoveResume_Request__Sequence__init(doosan_m0609_msgs__srv__MoveResume_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__srv__MoveResume_Request * data = NULL;

  if (size) {
    data = (doosan_m0609_msgs__srv__MoveResume_Request *)allocator.zero_allocate(size, sizeof(doosan_m0609_msgs__srv__MoveResume_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = doosan_m0609_msgs__srv__MoveResume_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        doosan_m0609_msgs__srv__MoveResume_Request__fini(&data[i - 1]);
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
doosan_m0609_msgs__srv__MoveResume_Request__Sequence__fini(doosan_m0609_msgs__srv__MoveResume_Request__Sequence * array)
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
      doosan_m0609_msgs__srv__MoveResume_Request__fini(&array->data[i]);
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

doosan_m0609_msgs__srv__MoveResume_Request__Sequence *
doosan_m0609_msgs__srv__MoveResume_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__srv__MoveResume_Request__Sequence * array = (doosan_m0609_msgs__srv__MoveResume_Request__Sequence *)allocator.allocate(sizeof(doosan_m0609_msgs__srv__MoveResume_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = doosan_m0609_msgs__srv__MoveResume_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
doosan_m0609_msgs__srv__MoveResume_Request__Sequence__destroy(doosan_m0609_msgs__srv__MoveResume_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    doosan_m0609_msgs__srv__MoveResume_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
doosan_m0609_msgs__srv__MoveResume_Request__Sequence__are_equal(const doosan_m0609_msgs__srv__MoveResume_Request__Sequence * lhs, const doosan_m0609_msgs__srv__MoveResume_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!doosan_m0609_msgs__srv__MoveResume_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
doosan_m0609_msgs__srv__MoveResume_Request__Sequence__copy(
  const doosan_m0609_msgs__srv__MoveResume_Request__Sequence * input,
  doosan_m0609_msgs__srv__MoveResume_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(doosan_m0609_msgs__srv__MoveResume_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    doosan_m0609_msgs__srv__MoveResume_Request * data =
      (doosan_m0609_msgs__srv__MoveResume_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!doosan_m0609_msgs__srv__MoveResume_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          doosan_m0609_msgs__srv__MoveResume_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!doosan_m0609_msgs__srv__MoveResume_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
doosan_m0609_msgs__srv__MoveResume_Response__init(doosan_m0609_msgs__srv__MoveResume_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
doosan_m0609_msgs__srv__MoveResume_Response__fini(doosan_m0609_msgs__srv__MoveResume_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
doosan_m0609_msgs__srv__MoveResume_Response__are_equal(const doosan_m0609_msgs__srv__MoveResume_Response * lhs, const doosan_m0609_msgs__srv__MoveResume_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
doosan_m0609_msgs__srv__MoveResume_Response__copy(
  const doosan_m0609_msgs__srv__MoveResume_Response * input,
  doosan_m0609_msgs__srv__MoveResume_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

doosan_m0609_msgs__srv__MoveResume_Response *
doosan_m0609_msgs__srv__MoveResume_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__srv__MoveResume_Response * msg = (doosan_m0609_msgs__srv__MoveResume_Response *)allocator.allocate(sizeof(doosan_m0609_msgs__srv__MoveResume_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(doosan_m0609_msgs__srv__MoveResume_Response));
  bool success = doosan_m0609_msgs__srv__MoveResume_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
doosan_m0609_msgs__srv__MoveResume_Response__destroy(doosan_m0609_msgs__srv__MoveResume_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    doosan_m0609_msgs__srv__MoveResume_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
doosan_m0609_msgs__srv__MoveResume_Response__Sequence__init(doosan_m0609_msgs__srv__MoveResume_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__srv__MoveResume_Response * data = NULL;

  if (size) {
    data = (doosan_m0609_msgs__srv__MoveResume_Response *)allocator.zero_allocate(size, sizeof(doosan_m0609_msgs__srv__MoveResume_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = doosan_m0609_msgs__srv__MoveResume_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        doosan_m0609_msgs__srv__MoveResume_Response__fini(&data[i - 1]);
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
doosan_m0609_msgs__srv__MoveResume_Response__Sequence__fini(doosan_m0609_msgs__srv__MoveResume_Response__Sequence * array)
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
      doosan_m0609_msgs__srv__MoveResume_Response__fini(&array->data[i]);
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

doosan_m0609_msgs__srv__MoveResume_Response__Sequence *
doosan_m0609_msgs__srv__MoveResume_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__srv__MoveResume_Response__Sequence * array = (doosan_m0609_msgs__srv__MoveResume_Response__Sequence *)allocator.allocate(sizeof(doosan_m0609_msgs__srv__MoveResume_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = doosan_m0609_msgs__srv__MoveResume_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
doosan_m0609_msgs__srv__MoveResume_Response__Sequence__destroy(doosan_m0609_msgs__srv__MoveResume_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    doosan_m0609_msgs__srv__MoveResume_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
doosan_m0609_msgs__srv__MoveResume_Response__Sequence__are_equal(const doosan_m0609_msgs__srv__MoveResume_Response__Sequence * lhs, const doosan_m0609_msgs__srv__MoveResume_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!doosan_m0609_msgs__srv__MoveResume_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
doosan_m0609_msgs__srv__MoveResume_Response__Sequence__copy(
  const doosan_m0609_msgs__srv__MoveResume_Response__Sequence * input,
  doosan_m0609_msgs__srv__MoveResume_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(doosan_m0609_msgs__srv__MoveResume_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    doosan_m0609_msgs__srv__MoveResume_Response * data =
      (doosan_m0609_msgs__srv__MoveResume_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!doosan_m0609_msgs__srv__MoveResume_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          doosan_m0609_msgs__srv__MoveResume_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!doosan_m0609_msgs__srv__MoveResume_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

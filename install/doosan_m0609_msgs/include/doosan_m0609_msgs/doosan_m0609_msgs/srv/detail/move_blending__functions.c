// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from doosan_m0609_msgs:srv/MoveBlending.idl
// generated code does not contain a copyright notice
#include "doosan_m0609_msgs/srv/detail/move_blending__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `segment`
#include "std_msgs/msg/detail/float64_multi_array__functions.h"

bool
doosan_m0609_msgs__srv__MoveBlending_Request__init(doosan_m0609_msgs__srv__MoveBlending_Request * msg)
{
  if (!msg) {
    return false;
  }
  // segment
  if (!std_msgs__msg__Float64MultiArray__Sequence__init(&msg->segment, 0)) {
    doosan_m0609_msgs__srv__MoveBlending_Request__fini(msg);
    return false;
  }
  // pos_cnt
  // vel
  // acc
  // time
  // ref
  // mode
  // sync_type
  return true;
}

void
doosan_m0609_msgs__srv__MoveBlending_Request__fini(doosan_m0609_msgs__srv__MoveBlending_Request * msg)
{
  if (!msg) {
    return;
  }
  // segment
  std_msgs__msg__Float64MultiArray__Sequence__fini(&msg->segment);
  // pos_cnt
  // vel
  // acc
  // time
  // ref
  // mode
  // sync_type
}

bool
doosan_m0609_msgs__srv__MoveBlending_Request__are_equal(const doosan_m0609_msgs__srv__MoveBlending_Request * lhs, const doosan_m0609_msgs__srv__MoveBlending_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // segment
  if (!std_msgs__msg__Float64MultiArray__Sequence__are_equal(
      &(lhs->segment), &(rhs->segment)))
  {
    return false;
  }
  // pos_cnt
  if (lhs->pos_cnt != rhs->pos_cnt) {
    return false;
  }
  // vel
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->vel[i] != rhs->vel[i]) {
      return false;
    }
  }
  // acc
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->acc[i] != rhs->acc[i]) {
      return false;
    }
  }
  // time
  if (lhs->time != rhs->time) {
    return false;
  }
  // ref
  if (lhs->ref != rhs->ref) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  // sync_type
  if (lhs->sync_type != rhs->sync_type) {
    return false;
  }
  return true;
}

bool
doosan_m0609_msgs__srv__MoveBlending_Request__copy(
  const doosan_m0609_msgs__srv__MoveBlending_Request * input,
  doosan_m0609_msgs__srv__MoveBlending_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // segment
  if (!std_msgs__msg__Float64MultiArray__Sequence__copy(
      &(input->segment), &(output->segment)))
  {
    return false;
  }
  // pos_cnt
  output->pos_cnt = input->pos_cnt;
  // vel
  for (size_t i = 0; i < 2; ++i) {
    output->vel[i] = input->vel[i];
  }
  // acc
  for (size_t i = 0; i < 2; ++i) {
    output->acc[i] = input->acc[i];
  }
  // time
  output->time = input->time;
  // ref
  output->ref = input->ref;
  // mode
  output->mode = input->mode;
  // sync_type
  output->sync_type = input->sync_type;
  return true;
}

doosan_m0609_msgs__srv__MoveBlending_Request *
doosan_m0609_msgs__srv__MoveBlending_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__srv__MoveBlending_Request * msg = (doosan_m0609_msgs__srv__MoveBlending_Request *)allocator.allocate(sizeof(doosan_m0609_msgs__srv__MoveBlending_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(doosan_m0609_msgs__srv__MoveBlending_Request));
  bool success = doosan_m0609_msgs__srv__MoveBlending_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
doosan_m0609_msgs__srv__MoveBlending_Request__destroy(doosan_m0609_msgs__srv__MoveBlending_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    doosan_m0609_msgs__srv__MoveBlending_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
doosan_m0609_msgs__srv__MoveBlending_Request__Sequence__init(doosan_m0609_msgs__srv__MoveBlending_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__srv__MoveBlending_Request * data = NULL;

  if (size) {
    data = (doosan_m0609_msgs__srv__MoveBlending_Request *)allocator.zero_allocate(size, sizeof(doosan_m0609_msgs__srv__MoveBlending_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = doosan_m0609_msgs__srv__MoveBlending_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        doosan_m0609_msgs__srv__MoveBlending_Request__fini(&data[i - 1]);
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
doosan_m0609_msgs__srv__MoveBlending_Request__Sequence__fini(doosan_m0609_msgs__srv__MoveBlending_Request__Sequence * array)
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
      doosan_m0609_msgs__srv__MoveBlending_Request__fini(&array->data[i]);
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

doosan_m0609_msgs__srv__MoveBlending_Request__Sequence *
doosan_m0609_msgs__srv__MoveBlending_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__srv__MoveBlending_Request__Sequence * array = (doosan_m0609_msgs__srv__MoveBlending_Request__Sequence *)allocator.allocate(sizeof(doosan_m0609_msgs__srv__MoveBlending_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = doosan_m0609_msgs__srv__MoveBlending_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
doosan_m0609_msgs__srv__MoveBlending_Request__Sequence__destroy(doosan_m0609_msgs__srv__MoveBlending_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    doosan_m0609_msgs__srv__MoveBlending_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
doosan_m0609_msgs__srv__MoveBlending_Request__Sequence__are_equal(const doosan_m0609_msgs__srv__MoveBlending_Request__Sequence * lhs, const doosan_m0609_msgs__srv__MoveBlending_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!doosan_m0609_msgs__srv__MoveBlending_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
doosan_m0609_msgs__srv__MoveBlending_Request__Sequence__copy(
  const doosan_m0609_msgs__srv__MoveBlending_Request__Sequence * input,
  doosan_m0609_msgs__srv__MoveBlending_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(doosan_m0609_msgs__srv__MoveBlending_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    doosan_m0609_msgs__srv__MoveBlending_Request * data =
      (doosan_m0609_msgs__srv__MoveBlending_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!doosan_m0609_msgs__srv__MoveBlending_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          doosan_m0609_msgs__srv__MoveBlending_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!doosan_m0609_msgs__srv__MoveBlending_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
doosan_m0609_msgs__srv__MoveBlending_Response__init(doosan_m0609_msgs__srv__MoveBlending_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
doosan_m0609_msgs__srv__MoveBlending_Response__fini(doosan_m0609_msgs__srv__MoveBlending_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
doosan_m0609_msgs__srv__MoveBlending_Response__are_equal(const doosan_m0609_msgs__srv__MoveBlending_Response * lhs, const doosan_m0609_msgs__srv__MoveBlending_Response * rhs)
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
doosan_m0609_msgs__srv__MoveBlending_Response__copy(
  const doosan_m0609_msgs__srv__MoveBlending_Response * input,
  doosan_m0609_msgs__srv__MoveBlending_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

doosan_m0609_msgs__srv__MoveBlending_Response *
doosan_m0609_msgs__srv__MoveBlending_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__srv__MoveBlending_Response * msg = (doosan_m0609_msgs__srv__MoveBlending_Response *)allocator.allocate(sizeof(doosan_m0609_msgs__srv__MoveBlending_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(doosan_m0609_msgs__srv__MoveBlending_Response));
  bool success = doosan_m0609_msgs__srv__MoveBlending_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
doosan_m0609_msgs__srv__MoveBlending_Response__destroy(doosan_m0609_msgs__srv__MoveBlending_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    doosan_m0609_msgs__srv__MoveBlending_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
doosan_m0609_msgs__srv__MoveBlending_Response__Sequence__init(doosan_m0609_msgs__srv__MoveBlending_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__srv__MoveBlending_Response * data = NULL;

  if (size) {
    data = (doosan_m0609_msgs__srv__MoveBlending_Response *)allocator.zero_allocate(size, sizeof(doosan_m0609_msgs__srv__MoveBlending_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = doosan_m0609_msgs__srv__MoveBlending_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        doosan_m0609_msgs__srv__MoveBlending_Response__fini(&data[i - 1]);
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
doosan_m0609_msgs__srv__MoveBlending_Response__Sequence__fini(doosan_m0609_msgs__srv__MoveBlending_Response__Sequence * array)
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
      doosan_m0609_msgs__srv__MoveBlending_Response__fini(&array->data[i]);
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

doosan_m0609_msgs__srv__MoveBlending_Response__Sequence *
doosan_m0609_msgs__srv__MoveBlending_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__srv__MoveBlending_Response__Sequence * array = (doosan_m0609_msgs__srv__MoveBlending_Response__Sequence *)allocator.allocate(sizeof(doosan_m0609_msgs__srv__MoveBlending_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = doosan_m0609_msgs__srv__MoveBlending_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
doosan_m0609_msgs__srv__MoveBlending_Response__Sequence__destroy(doosan_m0609_msgs__srv__MoveBlending_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    doosan_m0609_msgs__srv__MoveBlending_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
doosan_m0609_msgs__srv__MoveBlending_Response__Sequence__are_equal(const doosan_m0609_msgs__srv__MoveBlending_Response__Sequence * lhs, const doosan_m0609_msgs__srv__MoveBlending_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!doosan_m0609_msgs__srv__MoveBlending_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
doosan_m0609_msgs__srv__MoveBlending_Response__Sequence__copy(
  const doosan_m0609_msgs__srv__MoveBlending_Response__Sequence * input,
  doosan_m0609_msgs__srv__MoveBlending_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(doosan_m0609_msgs__srv__MoveBlending_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    doosan_m0609_msgs__srv__MoveBlending_Response * data =
      (doosan_m0609_msgs__srv__MoveBlending_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!doosan_m0609_msgs__srv__MoveBlending_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          doosan_m0609_msgs__srv__MoveBlending_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!doosan_m0609_msgs__srv__MoveBlending_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from doosan_m0609_msgs:msg/ModbusState.idl
// generated code does not contain a copyright notice
#include "doosan_m0609_msgs/msg/detail/modbus_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `modbus_symbol`
#include "rosidl_runtime_c/string_functions.h"

bool
doosan_m0609_msgs__msg__ModbusState__init(doosan_m0609_msgs__msg__ModbusState * msg)
{
  if (!msg) {
    return false;
  }
  // modbus_symbol
  if (!rosidl_runtime_c__String__init(&msg->modbus_symbol)) {
    doosan_m0609_msgs__msg__ModbusState__fini(msg);
    return false;
  }
  // modbus_value
  return true;
}

void
doosan_m0609_msgs__msg__ModbusState__fini(doosan_m0609_msgs__msg__ModbusState * msg)
{
  if (!msg) {
    return;
  }
  // modbus_symbol
  rosidl_runtime_c__String__fini(&msg->modbus_symbol);
  // modbus_value
}

bool
doosan_m0609_msgs__msg__ModbusState__are_equal(const doosan_m0609_msgs__msg__ModbusState * lhs, const doosan_m0609_msgs__msg__ModbusState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // modbus_symbol
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->modbus_symbol), &(rhs->modbus_symbol)))
  {
    return false;
  }
  // modbus_value
  if (lhs->modbus_value != rhs->modbus_value) {
    return false;
  }
  return true;
}

bool
doosan_m0609_msgs__msg__ModbusState__copy(
  const doosan_m0609_msgs__msg__ModbusState * input,
  doosan_m0609_msgs__msg__ModbusState * output)
{
  if (!input || !output) {
    return false;
  }
  // modbus_symbol
  if (!rosidl_runtime_c__String__copy(
      &(input->modbus_symbol), &(output->modbus_symbol)))
  {
    return false;
  }
  // modbus_value
  output->modbus_value = input->modbus_value;
  return true;
}

doosan_m0609_msgs__msg__ModbusState *
doosan_m0609_msgs__msg__ModbusState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__ModbusState * msg = (doosan_m0609_msgs__msg__ModbusState *)allocator.allocate(sizeof(doosan_m0609_msgs__msg__ModbusState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(doosan_m0609_msgs__msg__ModbusState));
  bool success = doosan_m0609_msgs__msg__ModbusState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
doosan_m0609_msgs__msg__ModbusState__destroy(doosan_m0609_msgs__msg__ModbusState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    doosan_m0609_msgs__msg__ModbusState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
doosan_m0609_msgs__msg__ModbusState__Sequence__init(doosan_m0609_msgs__msg__ModbusState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__ModbusState * data = NULL;

  if (size) {
    data = (doosan_m0609_msgs__msg__ModbusState *)allocator.zero_allocate(size, sizeof(doosan_m0609_msgs__msg__ModbusState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = doosan_m0609_msgs__msg__ModbusState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        doosan_m0609_msgs__msg__ModbusState__fini(&data[i - 1]);
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
doosan_m0609_msgs__msg__ModbusState__Sequence__fini(doosan_m0609_msgs__msg__ModbusState__Sequence * array)
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
      doosan_m0609_msgs__msg__ModbusState__fini(&array->data[i]);
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

doosan_m0609_msgs__msg__ModbusState__Sequence *
doosan_m0609_msgs__msg__ModbusState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  doosan_m0609_msgs__msg__ModbusState__Sequence * array = (doosan_m0609_msgs__msg__ModbusState__Sequence *)allocator.allocate(sizeof(doosan_m0609_msgs__msg__ModbusState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = doosan_m0609_msgs__msg__ModbusState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
doosan_m0609_msgs__msg__ModbusState__Sequence__destroy(doosan_m0609_msgs__msg__ModbusState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    doosan_m0609_msgs__msg__ModbusState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
doosan_m0609_msgs__msg__ModbusState__Sequence__are_equal(const doosan_m0609_msgs__msg__ModbusState__Sequence * lhs, const doosan_m0609_msgs__msg__ModbusState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!doosan_m0609_msgs__msg__ModbusState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
doosan_m0609_msgs__msg__ModbusState__Sequence__copy(
  const doosan_m0609_msgs__msg__ModbusState__Sequence * input,
  doosan_m0609_msgs__msg__ModbusState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(doosan_m0609_msgs__msg__ModbusState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    doosan_m0609_msgs__msg__ModbusState * data =
      (doosan_m0609_msgs__msg__ModbusState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!doosan_m0609_msgs__msg__ModbusState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          doosan_m0609_msgs__msg__ModbusState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!doosan_m0609_msgs__msg__ModbusState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

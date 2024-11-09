// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rr_msgs:srv/RobotArmArray.idl
// generated code does not contain a copyright notice
#include "rr_msgs/srv/detail/robot_arm_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `apply`
#include "rosidl_runtime_c/string_functions.h"

bool
rr_msgs__srv__RobotArmArray_Request__init(rr_msgs__srv__RobotArmArray_Request * msg)
{
  if (!msg) {
    return false;
  }
  // apply
  if (!rosidl_runtime_c__String__init(&msg->apply)) {
    rr_msgs__srv__RobotArmArray_Request__fini(msg);
    return false;
  }
  return true;
}

void
rr_msgs__srv__RobotArmArray_Request__fini(rr_msgs__srv__RobotArmArray_Request * msg)
{
  if (!msg) {
    return;
  }
  // apply
  rosidl_runtime_c__String__fini(&msg->apply);
}

bool
rr_msgs__srv__RobotArmArray_Request__are_equal(const rr_msgs__srv__RobotArmArray_Request * lhs, const rr_msgs__srv__RobotArmArray_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // apply
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->apply), &(rhs->apply)))
  {
    return false;
  }
  return true;
}

bool
rr_msgs__srv__RobotArmArray_Request__copy(
  const rr_msgs__srv__RobotArmArray_Request * input,
  rr_msgs__srv__RobotArmArray_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // apply
  if (!rosidl_runtime_c__String__copy(
      &(input->apply), &(output->apply)))
  {
    return false;
  }
  return true;
}

rr_msgs__srv__RobotArmArray_Request *
rr_msgs__srv__RobotArmArray_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rr_msgs__srv__RobotArmArray_Request * msg = (rr_msgs__srv__RobotArmArray_Request *)allocator.allocate(sizeof(rr_msgs__srv__RobotArmArray_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rr_msgs__srv__RobotArmArray_Request));
  bool success = rr_msgs__srv__RobotArmArray_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rr_msgs__srv__RobotArmArray_Request__destroy(rr_msgs__srv__RobotArmArray_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rr_msgs__srv__RobotArmArray_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rr_msgs__srv__RobotArmArray_Request__Sequence__init(rr_msgs__srv__RobotArmArray_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rr_msgs__srv__RobotArmArray_Request * data = NULL;

  if (size) {
    data = (rr_msgs__srv__RobotArmArray_Request *)allocator.zero_allocate(size, sizeof(rr_msgs__srv__RobotArmArray_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rr_msgs__srv__RobotArmArray_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rr_msgs__srv__RobotArmArray_Request__fini(&data[i - 1]);
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
rr_msgs__srv__RobotArmArray_Request__Sequence__fini(rr_msgs__srv__RobotArmArray_Request__Sequence * array)
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
      rr_msgs__srv__RobotArmArray_Request__fini(&array->data[i]);
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

rr_msgs__srv__RobotArmArray_Request__Sequence *
rr_msgs__srv__RobotArmArray_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rr_msgs__srv__RobotArmArray_Request__Sequence * array = (rr_msgs__srv__RobotArmArray_Request__Sequence *)allocator.allocate(sizeof(rr_msgs__srv__RobotArmArray_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rr_msgs__srv__RobotArmArray_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rr_msgs__srv__RobotArmArray_Request__Sequence__destroy(rr_msgs__srv__RobotArmArray_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rr_msgs__srv__RobotArmArray_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rr_msgs__srv__RobotArmArray_Request__Sequence__are_equal(const rr_msgs__srv__RobotArmArray_Request__Sequence * lhs, const rr_msgs__srv__RobotArmArray_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rr_msgs__srv__RobotArmArray_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rr_msgs__srv__RobotArmArray_Request__Sequence__copy(
  const rr_msgs__srv__RobotArmArray_Request__Sequence * input,
  rr_msgs__srv__RobotArmArray_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rr_msgs__srv__RobotArmArray_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rr_msgs__srv__RobotArmArray_Request * data =
      (rr_msgs__srv__RobotArmArray_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rr_msgs__srv__RobotArmArray_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rr_msgs__srv__RobotArmArray_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rr_msgs__srv__RobotArmArray_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `angles`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
rr_msgs__srv__RobotArmArray_Response__init(rr_msgs__srv__RobotArmArray_Response * msg)
{
  if (!msg) {
    return false;
  }
  // angles
  if (!rosidl_runtime_c__double__Sequence__init(&msg->angles, 0)) {
    rr_msgs__srv__RobotArmArray_Response__fini(msg);
    return false;
  }
  return true;
}

void
rr_msgs__srv__RobotArmArray_Response__fini(rr_msgs__srv__RobotArmArray_Response * msg)
{
  if (!msg) {
    return;
  }
  // angles
  rosidl_runtime_c__double__Sequence__fini(&msg->angles);
}

bool
rr_msgs__srv__RobotArmArray_Response__are_equal(const rr_msgs__srv__RobotArmArray_Response * lhs, const rr_msgs__srv__RobotArmArray_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // angles
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->angles), &(rhs->angles)))
  {
    return false;
  }
  return true;
}

bool
rr_msgs__srv__RobotArmArray_Response__copy(
  const rr_msgs__srv__RobotArmArray_Response * input,
  rr_msgs__srv__RobotArmArray_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // angles
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->angles), &(output->angles)))
  {
    return false;
  }
  return true;
}

rr_msgs__srv__RobotArmArray_Response *
rr_msgs__srv__RobotArmArray_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rr_msgs__srv__RobotArmArray_Response * msg = (rr_msgs__srv__RobotArmArray_Response *)allocator.allocate(sizeof(rr_msgs__srv__RobotArmArray_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rr_msgs__srv__RobotArmArray_Response));
  bool success = rr_msgs__srv__RobotArmArray_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rr_msgs__srv__RobotArmArray_Response__destroy(rr_msgs__srv__RobotArmArray_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rr_msgs__srv__RobotArmArray_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rr_msgs__srv__RobotArmArray_Response__Sequence__init(rr_msgs__srv__RobotArmArray_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rr_msgs__srv__RobotArmArray_Response * data = NULL;

  if (size) {
    data = (rr_msgs__srv__RobotArmArray_Response *)allocator.zero_allocate(size, sizeof(rr_msgs__srv__RobotArmArray_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rr_msgs__srv__RobotArmArray_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rr_msgs__srv__RobotArmArray_Response__fini(&data[i - 1]);
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
rr_msgs__srv__RobotArmArray_Response__Sequence__fini(rr_msgs__srv__RobotArmArray_Response__Sequence * array)
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
      rr_msgs__srv__RobotArmArray_Response__fini(&array->data[i]);
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

rr_msgs__srv__RobotArmArray_Response__Sequence *
rr_msgs__srv__RobotArmArray_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rr_msgs__srv__RobotArmArray_Response__Sequence * array = (rr_msgs__srv__RobotArmArray_Response__Sequence *)allocator.allocate(sizeof(rr_msgs__srv__RobotArmArray_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rr_msgs__srv__RobotArmArray_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rr_msgs__srv__RobotArmArray_Response__Sequence__destroy(rr_msgs__srv__RobotArmArray_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rr_msgs__srv__RobotArmArray_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rr_msgs__srv__RobotArmArray_Response__Sequence__are_equal(const rr_msgs__srv__RobotArmArray_Response__Sequence * lhs, const rr_msgs__srv__RobotArmArray_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rr_msgs__srv__RobotArmArray_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rr_msgs__srv__RobotArmArray_Response__Sequence__copy(
  const rr_msgs__srv__RobotArmArray_Response__Sequence * input,
  rr_msgs__srv__RobotArmArray_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rr_msgs__srv__RobotArmArray_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rr_msgs__srv__RobotArmArray_Response * data =
      (rr_msgs__srv__RobotArmArray_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rr_msgs__srv__RobotArmArray_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rr_msgs__srv__RobotArmArray_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rr_msgs__srv__RobotArmArray_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

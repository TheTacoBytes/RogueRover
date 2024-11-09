// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rr_msgs:msg/ImageMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rr_msgs/msg/detail/image_msg__rosidl_typesupport_introspection_c.h"
#include "rr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rr_msgs/msg/detail/image_msg__functions.h"
#include "rr_msgs/msg/detail/image_msg__struct.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rr_msgs__msg__ImageMsg__init(message_memory);
}

void rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_fini_function(void * message_memory)
{
  rr_msgs__msg__ImageMsg__fini(message_memory);
}

size_t rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__size_function__ImageMsg__data(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__get_const_function__ImageMsg__data(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__get_function__ImageMsg__data(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__fetch_function__ImageMsg__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__get_const_function__ImageMsg__data(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__assign_function__ImageMsg__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__get_function__ImageMsg__data(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__resize_function__ImageMsg__data(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_message_member_array[4] = {
  {
    "height",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rr_msgs__msg__ImageMsg, height),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "width",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rr_msgs__msg__ImageMsg, width),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "channels",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rr_msgs__msg__ImageMsg, channels),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rr_msgs__msg__ImageMsg, data),  // bytes offset in struct
    NULL,  // default value
    rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__size_function__ImageMsg__data,  // size() function pointer
    rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__get_const_function__ImageMsg__data,  // get_const(index) function pointer
    rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__get_function__ImageMsg__data,  // get(index) function pointer
    rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__fetch_function__ImageMsg__data,  // fetch(index, &value) function pointer
    rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__assign_function__ImageMsg__data,  // assign(index, value) function pointer
    rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__resize_function__ImageMsg__data  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_message_members = {
  "rr_msgs__msg",  // message namespace
  "ImageMsg",  // message name
  4,  // number of fields
  sizeof(rr_msgs__msg__ImageMsg),
  rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_message_member_array,  // message members
  rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_message_type_support_handle = {
  0,
  &rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rr_msgs, msg, ImageMsg)() {
  if (!rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_message_type_support_handle.typesupport_identifier) {
    rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rr_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

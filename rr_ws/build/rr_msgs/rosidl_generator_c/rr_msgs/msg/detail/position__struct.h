// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rr_msgs:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef RR_MSGS__MSG__DETAIL__POSITION__STRUCT_H_
#define RR_MSGS__MSG__DETAIL__POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Position in the package rr_msgs.
typedef struct rr_msgs__msg__Position
{
  float angle_x;
  float angle_y;
  float distance;
} rr_msgs__msg__Position;

// Struct for a sequence of rr_msgs__msg__Position.
typedef struct rr_msgs__msg__Position__Sequence
{
  rr_msgs__msg__Position * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rr_msgs__msg__Position__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RR_MSGS__MSG__DETAIL__POSITION__STRUCT_H_

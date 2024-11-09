// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rr_msgs:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef RR_MSGS__MSG__DETAIL__POSITION__TRAITS_HPP_
#define RR_MSGS__MSG__DETAIL__POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rr_msgs/msg/detail/position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rr_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Position & msg,
  std::ostream & out)
{
  out << "{";
  // member: angle_x
  {
    out << "angle_x: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_x, out);
    out << ", ";
  }

  // member: angle_y
  {
    out << "angle_y: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_y, out);
    out << ", ";
  }

  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Position & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: angle_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle_x: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_x, out);
    out << "\n";
  }

  // member: angle_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle_y: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_y, out);
    out << "\n";
  }

  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Position & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace rr_msgs

namespace rosidl_generator_traits
{

[[deprecated("use rr_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rr_msgs::msg::Position & msg,
  std::ostream & out, size_t indentation = 0)
{
  rr_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rr_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const rr_msgs::msg::Position & msg)
{
  return rr_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rr_msgs::msg::Position>()
{
  return "rr_msgs::msg::Position";
}

template<>
inline const char * name<rr_msgs::msg::Position>()
{
  return "rr_msgs/msg/Position";
}

template<>
struct has_fixed_size<rr_msgs::msg::Position>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rr_msgs::msg::Position>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rr_msgs::msg::Position>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RR_MSGS__MSG__DETAIL__POSITION__TRAITS_HPP_

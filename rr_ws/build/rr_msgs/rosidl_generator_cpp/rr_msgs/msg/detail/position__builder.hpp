// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rr_msgs:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef RR_MSGS__MSG__DETAIL__POSITION__BUILDER_HPP_
#define RR_MSGS__MSG__DETAIL__POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rr_msgs/msg/detail/position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rr_msgs
{

namespace msg
{

namespace builder
{

class Init_Position_distance
{
public:
  explicit Init_Position_distance(::rr_msgs::msg::Position & msg)
  : msg_(msg)
  {}
  ::rr_msgs::msg::Position distance(::rr_msgs::msg::Position::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rr_msgs::msg::Position msg_;
};

class Init_Position_angle_y
{
public:
  explicit Init_Position_angle_y(::rr_msgs::msg::Position & msg)
  : msg_(msg)
  {}
  Init_Position_distance angle_y(::rr_msgs::msg::Position::_angle_y_type arg)
  {
    msg_.angle_y = std::move(arg);
    return Init_Position_distance(msg_);
  }

private:
  ::rr_msgs::msg::Position msg_;
};

class Init_Position_angle_x
{
public:
  Init_Position_angle_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Position_angle_y angle_x(::rr_msgs::msg::Position::_angle_x_type arg)
  {
    msg_.angle_x = std::move(arg);
    return Init_Position_angle_y(msg_);
  }

private:
  ::rr_msgs::msg::Position msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rr_msgs::msg::Position>()
{
  return rr_msgs::msg::builder::Init_Position_angle_x();
}

}  // namespace rr_msgs

#endif  // RR_MSGS__MSG__DETAIL__POSITION__BUILDER_HPP_

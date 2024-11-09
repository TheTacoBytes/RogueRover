// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rr_msgs:msg/TargetArray.idl
// generated code does not contain a copyright notice

#ifndef RR_MSGS__MSG__DETAIL__TARGET_ARRAY__BUILDER_HPP_
#define RR_MSGS__MSG__DETAIL__TARGET_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rr_msgs/msg/detail/target_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rr_msgs
{

namespace msg
{

namespace builder
{

class Init_TargetArray_data
{
public:
  Init_TargetArray_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rr_msgs::msg::TargetArray data(::rr_msgs::msg::TargetArray::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rr_msgs::msg::TargetArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rr_msgs::msg::TargetArray>()
{
  return rr_msgs::msg::builder::Init_TargetArray_data();
}

}  // namespace rr_msgs

#endif  // RR_MSGS__MSG__DETAIL__TARGET_ARRAY__BUILDER_HPP_

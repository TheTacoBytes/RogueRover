// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rr_msgs:msg/ImageMsg.idl
// generated code does not contain a copyright notice

#ifndef RR_MSGS__MSG__DETAIL__IMAGE_MSG__BUILDER_HPP_
#define RR_MSGS__MSG__DETAIL__IMAGE_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rr_msgs/msg/detail/image_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rr_msgs
{

namespace msg
{

namespace builder
{

class Init_ImageMsg_data
{
public:
  explicit Init_ImageMsg_data(::rr_msgs::msg::ImageMsg & msg)
  : msg_(msg)
  {}
  ::rr_msgs::msg::ImageMsg data(::rr_msgs::msg::ImageMsg::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rr_msgs::msg::ImageMsg msg_;
};

class Init_ImageMsg_channels
{
public:
  explicit Init_ImageMsg_channels(::rr_msgs::msg::ImageMsg & msg)
  : msg_(msg)
  {}
  Init_ImageMsg_data channels(::rr_msgs::msg::ImageMsg::_channels_type arg)
  {
    msg_.channels = std::move(arg);
    return Init_ImageMsg_data(msg_);
  }

private:
  ::rr_msgs::msg::ImageMsg msg_;
};

class Init_ImageMsg_width
{
public:
  explicit Init_ImageMsg_width(::rr_msgs::msg::ImageMsg & msg)
  : msg_(msg)
  {}
  Init_ImageMsg_channels width(::rr_msgs::msg::ImageMsg::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_ImageMsg_channels(msg_);
  }

private:
  ::rr_msgs::msg::ImageMsg msg_;
};

class Init_ImageMsg_height
{
public:
  Init_ImageMsg_height()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImageMsg_width height(::rr_msgs::msg::ImageMsg::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_ImageMsg_width(msg_);
  }

private:
  ::rr_msgs::msg::ImageMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rr_msgs::msg::ImageMsg>()
{
  return rr_msgs::msg::builder::Init_ImageMsg_height();
}

}  // namespace rr_msgs

#endif  // RR_MSGS__MSG__DETAIL__IMAGE_MSG__BUILDER_HPP_

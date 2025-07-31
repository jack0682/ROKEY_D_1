// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:msg/ServolStream.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__SERVOL_STREAM__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__SERVOL_STREAM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/msg/detail/servol_stream__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace msg
{

namespace builder
{

class Init_ServolStream_time
{
public:
  explicit Init_ServolStream_time(::doosan_m0609_msgs::msg::ServolStream & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::msg::ServolStream time(::doosan_m0609_msgs::msg::ServolStream::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::ServolStream msg_;
};

class Init_ServolStream_acc
{
public:
  explicit Init_ServolStream_acc(::doosan_m0609_msgs::msg::ServolStream & msg)
  : msg_(msg)
  {}
  Init_ServolStream_time acc(::doosan_m0609_msgs::msg::ServolStream::_acc_type arg)
  {
    msg_.acc = std::move(arg);
    return Init_ServolStream_time(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::ServolStream msg_;
};

class Init_ServolStream_vel
{
public:
  explicit Init_ServolStream_vel(::doosan_m0609_msgs::msg::ServolStream & msg)
  : msg_(msg)
  {}
  Init_ServolStream_acc vel(::doosan_m0609_msgs::msg::ServolStream::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_ServolStream_acc(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::ServolStream msg_;
};

class Init_ServolStream_pos
{
public:
  Init_ServolStream_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ServolStream_vel pos(::doosan_m0609_msgs::msg::ServolStream::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_ServolStream_vel(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::ServolStream msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::msg::ServolStream>()
{
  return doosan_m0609_msgs::msg::builder::Init_ServolStream_pos();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__SERVOL_STREAM__BUILDER_HPP_

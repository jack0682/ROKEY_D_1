// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:msg/ServolRtStream.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__SERVOL_RT_STREAM__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__SERVOL_RT_STREAM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/msg/detail/servol_rt_stream__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace msg
{

namespace builder
{

class Init_ServolRtStream_time
{
public:
  explicit Init_ServolRtStream_time(::doosan_m0609_msgs::msg::ServolRtStream & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::msg::ServolRtStream time(::doosan_m0609_msgs::msg::ServolRtStream::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::ServolRtStream msg_;
};

class Init_ServolRtStream_acc
{
public:
  explicit Init_ServolRtStream_acc(::doosan_m0609_msgs::msg::ServolRtStream & msg)
  : msg_(msg)
  {}
  Init_ServolRtStream_time acc(::doosan_m0609_msgs::msg::ServolRtStream::_acc_type arg)
  {
    msg_.acc = std::move(arg);
    return Init_ServolRtStream_time(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::ServolRtStream msg_;
};

class Init_ServolRtStream_vel
{
public:
  explicit Init_ServolRtStream_vel(::doosan_m0609_msgs::msg::ServolRtStream & msg)
  : msg_(msg)
  {}
  Init_ServolRtStream_acc vel(::doosan_m0609_msgs::msg::ServolRtStream::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_ServolRtStream_acc(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::ServolRtStream msg_;
};

class Init_ServolRtStream_pos
{
public:
  Init_ServolRtStream_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ServolRtStream_vel pos(::doosan_m0609_msgs::msg::ServolRtStream::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_ServolRtStream_vel(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::ServolRtStream msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::msg::ServolRtStream>()
{
  return doosan_m0609_msgs::msg::builder::Init_ServolRtStream_pos();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__SERVOL_RT_STREAM__BUILDER_HPP_

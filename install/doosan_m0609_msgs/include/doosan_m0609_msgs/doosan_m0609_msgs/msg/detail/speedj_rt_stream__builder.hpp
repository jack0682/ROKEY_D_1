// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:msg/SpeedjRtStream.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__SPEEDJ_RT_STREAM__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__SPEEDJ_RT_STREAM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/msg/detail/speedj_rt_stream__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace msg
{

namespace builder
{

class Init_SpeedjRtStream_time
{
public:
  explicit Init_SpeedjRtStream_time(::doosan_m0609_msgs::msg::SpeedjRtStream & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::msg::SpeedjRtStream time(::doosan_m0609_msgs::msg::SpeedjRtStream::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::SpeedjRtStream msg_;
};

class Init_SpeedjRtStream_acc
{
public:
  explicit Init_SpeedjRtStream_acc(::doosan_m0609_msgs::msg::SpeedjRtStream & msg)
  : msg_(msg)
  {}
  Init_SpeedjRtStream_time acc(::doosan_m0609_msgs::msg::SpeedjRtStream::_acc_type arg)
  {
    msg_.acc = std::move(arg);
    return Init_SpeedjRtStream_time(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::SpeedjRtStream msg_;
};

class Init_SpeedjRtStream_vel
{
public:
  Init_SpeedjRtStream_vel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SpeedjRtStream_acc vel(::doosan_m0609_msgs::msg::SpeedjRtStream::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_SpeedjRtStream_acc(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::SpeedjRtStream msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::msg::SpeedjRtStream>()
{
  return doosan_m0609_msgs::msg::builder::Init_SpeedjRtStream_vel();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__SPEEDJ_RT_STREAM__BUILDER_HPP_

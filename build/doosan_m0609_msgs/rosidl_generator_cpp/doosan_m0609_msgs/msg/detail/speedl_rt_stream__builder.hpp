// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:msg/SpeedlRtStream.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__SPEEDL_RT_STREAM__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__SPEEDL_RT_STREAM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/msg/detail/speedl_rt_stream__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace msg
{

namespace builder
{

class Init_SpeedlRtStream_time
{
public:
  explicit Init_SpeedlRtStream_time(::doosan_m0609_msgs::msg::SpeedlRtStream & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::msg::SpeedlRtStream time(::doosan_m0609_msgs::msg::SpeedlRtStream::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::SpeedlRtStream msg_;
};

class Init_SpeedlRtStream_acc
{
public:
  explicit Init_SpeedlRtStream_acc(::doosan_m0609_msgs::msg::SpeedlRtStream & msg)
  : msg_(msg)
  {}
  Init_SpeedlRtStream_time acc(::doosan_m0609_msgs::msg::SpeedlRtStream::_acc_type arg)
  {
    msg_.acc = std::move(arg);
    return Init_SpeedlRtStream_time(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::SpeedlRtStream msg_;
};

class Init_SpeedlRtStream_vel
{
public:
  Init_SpeedlRtStream_vel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SpeedlRtStream_acc vel(::doosan_m0609_msgs::msg::SpeedlRtStream::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_SpeedlRtStream_acc(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::SpeedlRtStream msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::msg::SpeedlRtStream>()
{
  return doosan_m0609_msgs::msg::builder::Init_SpeedlRtStream_vel();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__SPEEDL_RT_STREAM__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:msg/ServojRtStream.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__SERVOJ_RT_STREAM__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__SERVOJ_RT_STREAM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/msg/detail/servoj_rt_stream__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace msg
{

namespace builder
{

class Init_ServojRtStream_time
{
public:
  explicit Init_ServojRtStream_time(::doosan_m0609_msgs::msg::ServojRtStream & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::msg::ServojRtStream time(::doosan_m0609_msgs::msg::ServojRtStream::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::ServojRtStream msg_;
};

class Init_ServojRtStream_acc
{
public:
  explicit Init_ServojRtStream_acc(::doosan_m0609_msgs::msg::ServojRtStream & msg)
  : msg_(msg)
  {}
  Init_ServojRtStream_time acc(::doosan_m0609_msgs::msg::ServojRtStream::_acc_type arg)
  {
    msg_.acc = std::move(arg);
    return Init_ServojRtStream_time(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::ServojRtStream msg_;
};

class Init_ServojRtStream_vel
{
public:
  explicit Init_ServojRtStream_vel(::doosan_m0609_msgs::msg::ServojRtStream & msg)
  : msg_(msg)
  {}
  Init_ServojRtStream_acc vel(::doosan_m0609_msgs::msg::ServojRtStream::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_ServojRtStream_acc(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::ServojRtStream msg_;
};

class Init_ServojRtStream_pos
{
public:
  Init_ServojRtStream_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ServojRtStream_vel pos(::doosan_m0609_msgs::msg::ServojRtStream::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_ServojRtStream_vel(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::ServojRtStream msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::msg::ServojRtStream>()
{
  return doosan_m0609_msgs::msg::builder::Init_ServojRtStream_pos();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__SERVOJ_RT_STREAM__BUILDER_HPP_

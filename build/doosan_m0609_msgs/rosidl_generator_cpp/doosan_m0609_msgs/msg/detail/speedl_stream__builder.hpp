// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:msg/SpeedlStream.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__SPEEDL_STREAM__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__SPEEDL_STREAM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/msg/detail/speedl_stream__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace msg
{

namespace builder
{

class Init_SpeedlStream_time
{
public:
  explicit Init_SpeedlStream_time(::doosan_m0609_msgs::msg::SpeedlStream & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::msg::SpeedlStream time(::doosan_m0609_msgs::msg::SpeedlStream::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::SpeedlStream msg_;
};

class Init_SpeedlStream_acc
{
public:
  explicit Init_SpeedlStream_acc(::doosan_m0609_msgs::msg::SpeedlStream & msg)
  : msg_(msg)
  {}
  Init_SpeedlStream_time acc(::doosan_m0609_msgs::msg::SpeedlStream::_acc_type arg)
  {
    msg_.acc = std::move(arg);
    return Init_SpeedlStream_time(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::SpeedlStream msg_;
};

class Init_SpeedlStream_vel
{
public:
  Init_SpeedlStream_vel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SpeedlStream_acc vel(::doosan_m0609_msgs::msg::SpeedlStream::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_SpeedlStream_acc(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::SpeedlStream msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::msg::SpeedlStream>()
{
  return doosan_m0609_msgs::msg::builder::Init_SpeedlStream_vel();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__SPEEDL_STREAM__BUILDER_HPP_

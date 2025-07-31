// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:msg/TorqueRtStream.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__TORQUE_RT_STREAM__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__TORQUE_RT_STREAM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/msg/detail/torque_rt_stream__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace msg
{

namespace builder
{

class Init_TorqueRtStream_time
{
public:
  explicit Init_TorqueRtStream_time(::doosan_m0609_msgs::msg::TorqueRtStream & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::msg::TorqueRtStream time(::doosan_m0609_msgs::msg::TorqueRtStream::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::TorqueRtStream msg_;
};

class Init_TorqueRtStream_tor
{
public:
  Init_TorqueRtStream_tor()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TorqueRtStream_time tor(::doosan_m0609_msgs::msg::TorqueRtStream::_tor_type arg)
  {
    msg_.tor = std::move(arg);
    return Init_TorqueRtStream_time(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::TorqueRtStream msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::msg::TorqueRtStream>()
{
  return doosan_m0609_msgs::msg::builder::Init_TorqueRtStream_tor();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__TORQUE_RT_STREAM__BUILDER_HPP_

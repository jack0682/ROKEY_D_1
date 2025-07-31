// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:msg/JogMultiAxis.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__JOG_MULTI_AXIS__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__JOG_MULTI_AXIS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/msg/detail/jog_multi_axis__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace msg
{

namespace builder
{

class Init_JogMultiAxis_speed
{
public:
  explicit Init_JogMultiAxis_speed(::doosan_m0609_msgs::msg::JogMultiAxis & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::msg::JogMultiAxis speed(::doosan_m0609_msgs::msg::JogMultiAxis::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::JogMultiAxis msg_;
};

class Init_JogMultiAxis_move_reference
{
public:
  explicit Init_JogMultiAxis_move_reference(::doosan_m0609_msgs::msg::JogMultiAxis & msg)
  : msg_(msg)
  {}
  Init_JogMultiAxis_speed move_reference(::doosan_m0609_msgs::msg::JogMultiAxis::_move_reference_type arg)
  {
    msg_.move_reference = std::move(arg);
    return Init_JogMultiAxis_speed(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::JogMultiAxis msg_;
};

class Init_JogMultiAxis_jog_axis
{
public:
  Init_JogMultiAxis_jog_axis()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JogMultiAxis_move_reference jog_axis(::doosan_m0609_msgs::msg::JogMultiAxis::_jog_axis_type arg)
  {
    msg_.jog_axis = std::move(arg);
    return Init_JogMultiAxis_move_reference(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::JogMultiAxis msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::msg::JogMultiAxis>()
{
  return doosan_m0609_msgs::msg::builder::Init_JogMultiAxis_jog_axis();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__JOG_MULTI_AXIS__BUILDER_HPP_

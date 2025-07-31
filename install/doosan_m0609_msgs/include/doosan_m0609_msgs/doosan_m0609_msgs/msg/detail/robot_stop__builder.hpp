// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:msg/RobotStop.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_STOP__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_STOP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/msg/detail/robot_stop__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotStop_stop_mode
{
public:
  Init_RobotStop_stop_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::msg::RobotStop stop_mode(::doosan_m0609_msgs::msg::RobotStop::_stop_mode_type arg)
  {
    msg_.stop_mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotStop msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::msg::RobotStop>()
{
  return doosan_m0609_msgs::msg::builder::Init_RobotStop_stop_mode();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_STOP__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:msg/RobotError.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_ERROR__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_ERROR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/msg/detail/robot_error__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotError_msg3
{
public:
  explicit Init_RobotError_msg3(::doosan_m0609_msgs::msg::RobotError & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::msg::RobotError msg3(::doosan_m0609_msgs::msg::RobotError::_msg3_type arg)
  {
    msg_.msg3 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotError msg_;
};

class Init_RobotError_msg2
{
public:
  explicit Init_RobotError_msg2(::doosan_m0609_msgs::msg::RobotError & msg)
  : msg_(msg)
  {}
  Init_RobotError_msg3 msg2(::doosan_m0609_msgs::msg::RobotError::_msg2_type arg)
  {
    msg_.msg2 = std::move(arg);
    return Init_RobotError_msg3(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotError msg_;
};

class Init_RobotError_msg1
{
public:
  explicit Init_RobotError_msg1(::doosan_m0609_msgs::msg::RobotError & msg)
  : msg_(msg)
  {}
  Init_RobotError_msg2 msg1(::doosan_m0609_msgs::msg::RobotError::_msg1_type arg)
  {
    msg_.msg1 = std::move(arg);
    return Init_RobotError_msg2(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotError msg_;
};

class Init_RobotError_code
{
public:
  explicit Init_RobotError_code(::doosan_m0609_msgs::msg::RobotError & msg)
  : msg_(msg)
  {}
  Init_RobotError_msg1 code(::doosan_m0609_msgs::msg::RobotError::_code_type arg)
  {
    msg_.code = std::move(arg);
    return Init_RobotError_msg1(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotError msg_;
};

class Init_RobotError_group
{
public:
  explicit Init_RobotError_group(::doosan_m0609_msgs::msg::RobotError & msg)
  : msg_(msg)
  {}
  Init_RobotError_code group(::doosan_m0609_msgs::msg::RobotError::_group_type arg)
  {
    msg_.group = std::move(arg);
    return Init_RobotError_code(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotError msg_;
};

class Init_RobotError_level
{
public:
  Init_RobotError_level()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotError_group level(::doosan_m0609_msgs::msg::RobotError::_level_type arg)
  {
    msg_.level = std::move(arg);
    return Init_RobotError_group(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::RobotError msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::msg::RobotError>()
{
  return doosan_m0609_msgs::msg::builder::Init_RobotError_level();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_ERROR__BUILDER_HPP_

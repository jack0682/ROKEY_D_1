// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:msg/LogAlarm.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__LOG_ALARM__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__LOG_ALARM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/msg/detail/log_alarm__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace msg
{

namespace builder
{

class Init_LogAlarm_param
{
public:
  explicit Init_LogAlarm_param(::doosan_m0609_msgs::msg::LogAlarm & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::msg::LogAlarm param(::doosan_m0609_msgs::msg::LogAlarm::_param_type arg)
  {
    msg_.param = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::LogAlarm msg_;
};

class Init_LogAlarm_index
{
public:
  explicit Init_LogAlarm_index(::doosan_m0609_msgs::msg::LogAlarm & msg)
  : msg_(msg)
  {}
  Init_LogAlarm_param index(::doosan_m0609_msgs::msg::LogAlarm::_index_type arg)
  {
    msg_.index = std::move(arg);
    return Init_LogAlarm_param(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::LogAlarm msg_;
};

class Init_LogAlarm_group
{
public:
  explicit Init_LogAlarm_group(::doosan_m0609_msgs::msg::LogAlarm & msg)
  : msg_(msg)
  {}
  Init_LogAlarm_index group(::doosan_m0609_msgs::msg::LogAlarm::_group_type arg)
  {
    msg_.group = std::move(arg);
    return Init_LogAlarm_index(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::LogAlarm msg_;
};

class Init_LogAlarm_level
{
public:
  Init_LogAlarm_level()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LogAlarm_group level(::doosan_m0609_msgs::msg::LogAlarm::_level_type arg)
  {
    msg_.level = std::move(arg);
    return Init_LogAlarm_group(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::LogAlarm msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::msg::LogAlarm>()
{
  return doosan_m0609_msgs::msg::builder::Init_LogAlarm_level();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__LOG_ALARM__BUILDER_HPP_

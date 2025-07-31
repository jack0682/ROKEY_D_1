// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/GetLastAlarm.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_LAST_ALARM__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_LAST_ALARM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/get_last_alarm__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetLastAlarm_Request>()
{
  return ::doosan_m0609_msgs::srv::GetLastAlarm_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetLastAlarm_Response_success
{
public:
  explicit Init_GetLastAlarm_Response_success(::doosan_m0609_msgs::srv::GetLastAlarm_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::GetLastAlarm_Response success(::doosan_m0609_msgs::srv::GetLastAlarm_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetLastAlarm_Response msg_;
};

class Init_GetLastAlarm_Response_log_alarm
{
public:
  Init_GetLastAlarm_Response_log_alarm()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetLastAlarm_Response_success log_alarm(::doosan_m0609_msgs::srv::GetLastAlarm_Response::_log_alarm_type arg)
  {
    msg_.log_alarm = std::move(arg);
    return Init_GetLastAlarm_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetLastAlarm_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetLastAlarm_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetLastAlarm_Response_log_alarm();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_LAST_ALARM__BUILDER_HPP_

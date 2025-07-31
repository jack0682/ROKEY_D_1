// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/ServoOff.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SERVO_OFF__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SERVO_OFF__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/servo_off__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ServoOff_Request_stop_type
{
public:
  Init_ServoOff_Request_stop_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::ServoOff_Request stop_type(::doosan_m0609_msgs::srv::ServoOff_Request::_stop_type_type arg)
  {
    msg_.stop_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ServoOff_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ServoOff_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_ServoOff_Request_stop_type();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ServoOff_Response_success
{
public:
  Init_ServoOff_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::ServoOff_Response success(::doosan_m0609_msgs::srv::ServoOff_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ServoOff_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ServoOff_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_ServoOff_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SERVO_OFF__BUILDER_HPP_

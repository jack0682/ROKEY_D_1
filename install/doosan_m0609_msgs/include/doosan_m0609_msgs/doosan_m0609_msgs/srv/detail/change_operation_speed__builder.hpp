// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/ChangeOperationSpeed.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__CHANGE_OPERATION_SPEED__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__CHANGE_OPERATION_SPEED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/change_operation_speed__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ChangeOperationSpeed_Request_speed
{
public:
  Init_ChangeOperationSpeed_Request_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::ChangeOperationSpeed_Request speed(::doosan_m0609_msgs::srv::ChangeOperationSpeed_Request::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ChangeOperationSpeed_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ChangeOperationSpeed_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_ChangeOperationSpeed_Request_speed();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ChangeOperationSpeed_Response_success
{
public:
  Init_ChangeOperationSpeed_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::ChangeOperationSpeed_Response success(::doosan_m0609_msgs::srv::ChangeOperationSpeed_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ChangeOperationSpeed_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ChangeOperationSpeed_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_ChangeOperationSpeed_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__CHANGE_OPERATION_SPEED__BUILDER_HPP_

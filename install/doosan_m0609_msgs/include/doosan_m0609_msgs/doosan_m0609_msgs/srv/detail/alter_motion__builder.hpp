// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/AlterMotion.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__ALTER_MOTION__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__ALTER_MOTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/alter_motion__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_AlterMotion_Request_pos
{
public:
  Init_AlterMotion_Request_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::AlterMotion_Request pos(::doosan_m0609_msgs::srv::AlterMotion_Request::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::AlterMotion_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::AlterMotion_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_AlterMotion_Request_pos();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_AlterMotion_Response_success
{
public:
  Init_AlterMotion_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::AlterMotion_Response success(::doosan_m0609_msgs::srv::AlterMotion_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::AlterMotion_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::AlterMotion_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_AlterMotion_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__ALTER_MOTION__BUILDER_HPP_

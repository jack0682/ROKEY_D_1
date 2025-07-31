// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/ChangeCollisionSensitivity.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__CHANGE_COLLISION_SENSITIVITY__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__CHANGE_COLLISION_SENSITIVITY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/change_collision_sensitivity__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ChangeCollisionSensitivity_Request_sensitivity
{
public:
  Init_ChangeCollisionSensitivity_Request_sensitivity()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::ChangeCollisionSensitivity_Request sensitivity(::doosan_m0609_msgs::srv::ChangeCollisionSensitivity_Request::_sensitivity_type arg)
  {
    msg_.sensitivity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ChangeCollisionSensitivity_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ChangeCollisionSensitivity_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_ChangeCollisionSensitivity_Request_sensitivity();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ChangeCollisionSensitivity_Response_success
{
public:
  Init_ChangeCollisionSensitivity_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::ChangeCollisionSensitivity_Response success(::doosan_m0609_msgs::srv::ChangeCollisionSensitivity_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ChangeCollisionSensitivity_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ChangeCollisionSensitivity_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_ChangeCollisionSensitivity_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__CHANGE_COLLISION_SENSITIVITY__BUILDER_HPP_

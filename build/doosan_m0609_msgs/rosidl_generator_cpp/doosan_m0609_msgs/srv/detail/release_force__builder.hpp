// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/ReleaseForce.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__RELEASE_FORCE__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__RELEASE_FORCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/release_force__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ReleaseForce_Request_time
{
public:
  Init_ReleaseForce_Request_time()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::ReleaseForce_Request time(::doosan_m0609_msgs::srv::ReleaseForce_Request::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ReleaseForce_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ReleaseForce_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_ReleaseForce_Request_time();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ReleaseForce_Response_success
{
public:
  Init_ReleaseForce_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::ReleaseForce_Response success(::doosan_m0609_msgs::srv::ReleaseForce_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ReleaseForce_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ReleaseForce_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_ReleaseForce_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__RELEASE_FORCE__BUILDER_HPP_

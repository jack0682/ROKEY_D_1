// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/GetDesiredVelx.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_DESIRED_VELX__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_DESIRED_VELX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/get_desired_velx__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetDesiredVelx_Request_ref
{
public:
  Init_GetDesiredVelx_Request_ref()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::GetDesiredVelx_Request ref(::doosan_m0609_msgs::srv::GetDesiredVelx_Request::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetDesiredVelx_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetDesiredVelx_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetDesiredVelx_Request_ref();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetDesiredVelx_Response_success
{
public:
  explicit Init_GetDesiredVelx_Response_success(::doosan_m0609_msgs::srv::GetDesiredVelx_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::GetDesiredVelx_Response success(::doosan_m0609_msgs::srv::GetDesiredVelx_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetDesiredVelx_Response msg_;
};

class Init_GetDesiredVelx_Response_vel
{
public:
  Init_GetDesiredVelx_Response_vel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetDesiredVelx_Response_success vel(::doosan_m0609_msgs::srv::GetDesiredVelx_Response::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_GetDesiredVelx_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetDesiredVelx_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetDesiredVelx_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetDesiredVelx_Response_vel();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_DESIRED_VELX__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/SetRtControlOutput.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_RT_CONTROL_OUTPUT__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_RT_CONTROL_OUTPUT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/set_rt_control_output__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetRtControlOutput_Request_loss
{
public:
  explicit Init_SetRtControlOutput_Request_loss(::doosan_m0609_msgs::srv::SetRtControlOutput_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::SetRtControlOutput_Request loss(::doosan_m0609_msgs::srv::SetRtControlOutput_Request::_loss_type arg)
  {
    msg_.loss = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetRtControlOutput_Request msg_;
};

class Init_SetRtControlOutput_Request_period
{
public:
  explicit Init_SetRtControlOutput_Request_period(::doosan_m0609_msgs::srv::SetRtControlOutput_Request & msg)
  : msg_(msg)
  {}
  Init_SetRtControlOutput_Request_loss period(::doosan_m0609_msgs::srv::SetRtControlOutput_Request::_period_type arg)
  {
    msg_.period = std::move(arg);
    return Init_SetRtControlOutput_Request_loss(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetRtControlOutput_Request msg_;
};

class Init_SetRtControlOutput_Request_version
{
public:
  Init_SetRtControlOutput_Request_version()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetRtControlOutput_Request_period version(::doosan_m0609_msgs::srv::SetRtControlOutput_Request::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_SetRtControlOutput_Request_period(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetRtControlOutput_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetRtControlOutput_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetRtControlOutput_Request_version();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetRtControlOutput_Response_success
{
public:
  Init_SetRtControlOutput_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::SetRtControlOutput_Response success(::doosan_m0609_msgs::srv::SetRtControlOutput_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetRtControlOutput_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetRtControlOutput_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetRtControlOutput_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_RT_CONTROL_OUTPUT__BUILDER_HPP_

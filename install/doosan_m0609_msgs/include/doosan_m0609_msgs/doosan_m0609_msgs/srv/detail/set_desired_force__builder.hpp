// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/SetDesiredForce.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_DESIRED_FORCE__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_DESIRED_FORCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/set_desired_force__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetDesiredForce_Request_mod
{
public:
  explicit Init_SetDesiredForce_Request_mod(::doosan_m0609_msgs::srv::SetDesiredForce_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::SetDesiredForce_Request mod(::doosan_m0609_msgs::srv::SetDesiredForce_Request::_mod_type arg)
  {
    msg_.mod = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetDesiredForce_Request msg_;
};

class Init_SetDesiredForce_Request_time
{
public:
  explicit Init_SetDesiredForce_Request_time(::doosan_m0609_msgs::srv::SetDesiredForce_Request & msg)
  : msg_(msg)
  {}
  Init_SetDesiredForce_Request_mod time(::doosan_m0609_msgs::srv::SetDesiredForce_Request::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_SetDesiredForce_Request_mod(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetDesiredForce_Request msg_;
};

class Init_SetDesiredForce_Request_ref
{
public:
  explicit Init_SetDesiredForce_Request_ref(::doosan_m0609_msgs::srv::SetDesiredForce_Request & msg)
  : msg_(msg)
  {}
  Init_SetDesiredForce_Request_time ref(::doosan_m0609_msgs::srv::SetDesiredForce_Request::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return Init_SetDesiredForce_Request_time(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetDesiredForce_Request msg_;
};

class Init_SetDesiredForce_Request_dir
{
public:
  explicit Init_SetDesiredForce_Request_dir(::doosan_m0609_msgs::srv::SetDesiredForce_Request & msg)
  : msg_(msg)
  {}
  Init_SetDesiredForce_Request_ref dir(::doosan_m0609_msgs::srv::SetDesiredForce_Request::_dir_type arg)
  {
    msg_.dir = std::move(arg);
    return Init_SetDesiredForce_Request_ref(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetDesiredForce_Request msg_;
};

class Init_SetDesiredForce_Request_fd
{
public:
  Init_SetDesiredForce_Request_fd()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetDesiredForce_Request_dir fd(::doosan_m0609_msgs::srv::SetDesiredForce_Request::_fd_type arg)
  {
    msg_.fd = std::move(arg);
    return Init_SetDesiredForce_Request_dir(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetDesiredForce_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetDesiredForce_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetDesiredForce_Request_fd();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetDesiredForce_Response_success
{
public:
  Init_SetDesiredForce_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::SetDesiredForce_Response success(::doosan_m0609_msgs::srv::SetDesiredForce_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetDesiredForce_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetDesiredForce_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetDesiredForce_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_DESIRED_FORCE__BUILDER_HPP_

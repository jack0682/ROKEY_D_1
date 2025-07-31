// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/SetStiffnessx.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_STIFFNESSX__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_STIFFNESSX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/set_stiffnessx__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetStiffnessx_Request_time
{
public:
  explicit Init_SetStiffnessx_Request_time(::doosan_m0609_msgs::srv::SetStiffnessx_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::SetStiffnessx_Request time(::doosan_m0609_msgs::srv::SetStiffnessx_Request::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetStiffnessx_Request msg_;
};

class Init_SetStiffnessx_Request_ref
{
public:
  explicit Init_SetStiffnessx_Request_ref(::doosan_m0609_msgs::srv::SetStiffnessx_Request & msg)
  : msg_(msg)
  {}
  Init_SetStiffnessx_Request_time ref(::doosan_m0609_msgs::srv::SetStiffnessx_Request::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return Init_SetStiffnessx_Request_time(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetStiffnessx_Request msg_;
};

class Init_SetStiffnessx_Request_stx
{
public:
  Init_SetStiffnessx_Request_stx()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetStiffnessx_Request_ref stx(::doosan_m0609_msgs::srv::SetStiffnessx_Request::_stx_type arg)
  {
    msg_.stx = std::move(arg);
    return Init_SetStiffnessx_Request_ref(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetStiffnessx_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetStiffnessx_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetStiffnessx_Request_stx();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetStiffnessx_Response_success
{
public:
  Init_SetStiffnessx_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::SetStiffnessx_Response success(::doosan_m0609_msgs::srv::SetStiffnessx_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetStiffnessx_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetStiffnessx_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetStiffnessx_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_STIFFNESSX__BUILDER_HPP_

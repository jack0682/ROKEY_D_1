// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/SetAccxRt.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_ACCX_RT__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_ACCX_RT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/set_accx_rt__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetAccxRt_Request_rotation
{
public:
  explicit Init_SetAccxRt_Request_rotation(::doosan_m0609_msgs::srv::SetAccxRt_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::SetAccxRt_Request rotation(::doosan_m0609_msgs::srv::SetAccxRt_Request::_rotation_type arg)
  {
    msg_.rotation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetAccxRt_Request msg_;
};

class Init_SetAccxRt_Request_trans
{
public:
  Init_SetAccxRt_Request_trans()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetAccxRt_Request_rotation trans(::doosan_m0609_msgs::srv::SetAccxRt_Request::_trans_type arg)
  {
    msg_.trans = std::move(arg);
    return Init_SetAccxRt_Request_rotation(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetAccxRt_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetAccxRt_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetAccxRt_Request_trans();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetAccxRt_Response_success
{
public:
  Init_SetAccxRt_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::SetAccxRt_Response success(::doosan_m0609_msgs::srv::SetAccxRt_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetAccxRt_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetAccxRt_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetAccxRt_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_ACCX_RT__BUILDER_HPP_

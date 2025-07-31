// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/GetCurrentToolFlangePosx.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CURRENT_TOOL_FLANGE_POSX__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CURRENT_TOOL_FLANGE_POSX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/get_current_tool_flange_posx__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetCurrentToolFlangePosx_Request_ref
{
public:
  Init_GetCurrentToolFlangePosx_Request_ref()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::GetCurrentToolFlangePosx_Request ref(::doosan_m0609_msgs::srv::GetCurrentToolFlangePosx_Request::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetCurrentToolFlangePosx_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetCurrentToolFlangePosx_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetCurrentToolFlangePosx_Request_ref();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetCurrentToolFlangePosx_Response_success
{
public:
  explicit Init_GetCurrentToolFlangePosx_Response_success(::doosan_m0609_msgs::srv::GetCurrentToolFlangePosx_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::GetCurrentToolFlangePosx_Response success(::doosan_m0609_msgs::srv::GetCurrentToolFlangePosx_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetCurrentToolFlangePosx_Response msg_;
};

class Init_GetCurrentToolFlangePosx_Response_pos
{
public:
  Init_GetCurrentToolFlangePosx_Response_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetCurrentToolFlangePosx_Response_success pos(::doosan_m0609_msgs::srv::GetCurrentToolFlangePosx_Response::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_GetCurrentToolFlangePosx_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetCurrentToolFlangePosx_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetCurrentToolFlangePosx_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetCurrentToolFlangePosx_Response_pos();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CURRENT_TOOL_FLANGE_POSX__BUILDER_HPP_

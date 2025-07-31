// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/GetCurrentTcp.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CURRENT_TCP__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CURRENT_TCP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/get_current_tcp__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetCurrentTcp_Request>()
{
  return ::doosan_m0609_msgs::srv::GetCurrentTcp_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetCurrentTcp_Response_success
{
public:
  explicit Init_GetCurrentTcp_Response_success(::doosan_m0609_msgs::srv::GetCurrentTcp_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::GetCurrentTcp_Response success(::doosan_m0609_msgs::srv::GetCurrentTcp_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetCurrentTcp_Response msg_;
};

class Init_GetCurrentTcp_Response_info
{
public:
  Init_GetCurrentTcp_Response_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetCurrentTcp_Response_success info(::doosan_m0609_msgs::srv::GetCurrentTcp_Response::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetCurrentTcp_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetCurrentTcp_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetCurrentTcp_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetCurrentTcp_Response_info();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CURRENT_TCP__BUILDER_HPP_

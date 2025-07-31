// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/ConfigDeleteTcp.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_DELETE_TCP__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_DELETE_TCP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/config_delete_tcp__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ConfigDeleteTcp_Request_name
{
public:
  Init_ConfigDeleteTcp_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::ConfigDeleteTcp_Request name(::doosan_m0609_msgs::srv::ConfigDeleteTcp_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConfigDeleteTcp_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ConfigDeleteTcp_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_ConfigDeleteTcp_Request_name();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ConfigDeleteTcp_Response_success
{
public:
  Init_ConfigDeleteTcp_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::ConfigDeleteTcp_Response success(::doosan_m0609_msgs::srv::ConfigDeleteTcp_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConfigDeleteTcp_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ConfigDeleteTcp_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_ConfigDeleteTcp_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_DELETE_TCP__BUILDER_HPP_

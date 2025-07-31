// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/ConfigDeleteTool.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_DELETE_TOOL__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_DELETE_TOOL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/config_delete_tool__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ConfigDeleteTool_Request_name
{
public:
  Init_ConfigDeleteTool_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::ConfigDeleteTool_Request name(::doosan_m0609_msgs::srv::ConfigDeleteTool_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConfigDeleteTool_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ConfigDeleteTool_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_ConfigDeleteTool_Request_name();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ConfigDeleteTool_Response_success
{
public:
  Init_ConfigDeleteTool_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::ConfigDeleteTool_Response success(::doosan_m0609_msgs::srv::ConfigDeleteTool_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConfigDeleteTool_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ConfigDeleteTool_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_ConfigDeleteTool_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_DELETE_TOOL__BUILDER_HPP_

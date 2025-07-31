// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/ConfigCreateTool.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_CREATE_TOOL__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_CREATE_TOOL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/config_create_tool__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ConfigCreateTool_Request_inertia
{
public:
  explicit Init_ConfigCreateTool_Request_inertia(::doosan_m0609_msgs::srv::ConfigCreateTool_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::ConfigCreateTool_Request inertia(::doosan_m0609_msgs::srv::ConfigCreateTool_Request::_inertia_type arg)
  {
    msg_.inertia = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConfigCreateTool_Request msg_;
};

class Init_ConfigCreateTool_Request_cog
{
public:
  explicit Init_ConfigCreateTool_Request_cog(::doosan_m0609_msgs::srv::ConfigCreateTool_Request & msg)
  : msg_(msg)
  {}
  Init_ConfigCreateTool_Request_inertia cog(::doosan_m0609_msgs::srv::ConfigCreateTool_Request::_cog_type arg)
  {
    msg_.cog = std::move(arg);
    return Init_ConfigCreateTool_Request_inertia(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConfigCreateTool_Request msg_;
};

class Init_ConfigCreateTool_Request_weight
{
public:
  explicit Init_ConfigCreateTool_Request_weight(::doosan_m0609_msgs::srv::ConfigCreateTool_Request & msg)
  : msg_(msg)
  {}
  Init_ConfigCreateTool_Request_cog weight(::doosan_m0609_msgs::srv::ConfigCreateTool_Request::_weight_type arg)
  {
    msg_.weight = std::move(arg);
    return Init_ConfigCreateTool_Request_cog(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConfigCreateTool_Request msg_;
};

class Init_ConfigCreateTool_Request_name
{
public:
  Init_ConfigCreateTool_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ConfigCreateTool_Request_weight name(::doosan_m0609_msgs::srv::ConfigCreateTool_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_ConfigCreateTool_Request_weight(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConfigCreateTool_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ConfigCreateTool_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_ConfigCreateTool_Request_name();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ConfigCreateTool_Response_success
{
public:
  Init_ConfigCreateTool_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::ConfigCreateTool_Response success(::doosan_m0609_msgs::srv::ConfigCreateTool_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConfigCreateTool_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ConfigCreateTool_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_ConfigCreateTool_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_CREATE_TOOL__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/ConfigCreateTcp.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_CREATE_TCP__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_CREATE_TCP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/config_create_tcp__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ConfigCreateTcp_Request_pos
{
public:
  explicit Init_ConfigCreateTcp_Request_pos(::doosan_m0609_msgs::srv::ConfigCreateTcp_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::ConfigCreateTcp_Request pos(::doosan_m0609_msgs::srv::ConfigCreateTcp_Request::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConfigCreateTcp_Request msg_;
};

class Init_ConfigCreateTcp_Request_name
{
public:
  Init_ConfigCreateTcp_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ConfigCreateTcp_Request_pos name(::doosan_m0609_msgs::srv::ConfigCreateTcp_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_ConfigCreateTcp_Request_pos(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConfigCreateTcp_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ConfigCreateTcp_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_ConfigCreateTcp_Request_name();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ConfigCreateTcp_Response_success
{
public:
  Init_ConfigCreateTcp_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::ConfigCreateTcp_Response success(::doosan_m0609_msgs::srv::ConfigCreateTcp_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConfigCreateTcp_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ConfigCreateTcp_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_ConfigCreateTcp_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_CREATE_TCP__BUILDER_HPP_

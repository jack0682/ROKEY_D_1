// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/ConnectRtControl.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__CONNECT_RT_CONTROL__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__CONNECT_RT_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/connect_rt_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ConnectRtControl_Request_port
{
public:
  explicit Init_ConnectRtControl_Request_port(::doosan_m0609_msgs::srv::ConnectRtControl_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::ConnectRtControl_Request port(::doosan_m0609_msgs::srv::ConnectRtControl_Request::_port_type arg)
  {
    msg_.port = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConnectRtControl_Request msg_;
};

class Init_ConnectRtControl_Request_ip_address
{
public:
  Init_ConnectRtControl_Request_ip_address()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ConnectRtControl_Request_port ip_address(::doosan_m0609_msgs::srv::ConnectRtControl_Request::_ip_address_type arg)
  {
    msg_.ip_address = std::move(arg);
    return Init_ConnectRtControl_Request_port(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConnectRtControl_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ConnectRtControl_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_ConnectRtControl_Request_ip_address();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ConnectRtControl_Response_success
{
public:
  Init_ConnectRtControl_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::ConnectRtControl_Response success(::doosan_m0609_msgs::srv::ConnectRtControl_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConnectRtControl_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ConnectRtControl_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_ConnectRtControl_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__CONNECT_RT_CONTROL__BUILDER_HPP_

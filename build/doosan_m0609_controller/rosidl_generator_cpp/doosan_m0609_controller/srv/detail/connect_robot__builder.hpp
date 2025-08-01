// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_controller:srv/ConnectRobot.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_CONTROLLER__SRV__DETAIL__CONNECT_ROBOT__BUILDER_HPP_
#define DOOSAN_M0609_CONTROLLER__SRV__DETAIL__CONNECT_ROBOT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_controller/srv/detail/connect_robot__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_controller
{

namespace srv
{

namespace builder
{

class Init_ConnectRobot_Request_connect
{
public:
  explicit Init_ConnectRobot_Request_connect(::doosan_m0609_controller::srv::ConnectRobot_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_controller::srv::ConnectRobot_Request connect(::doosan_m0609_controller::srv::ConnectRobot_Request::_connect_type arg)
  {
    msg_.connect = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_controller::srv::ConnectRobot_Request msg_;
};

class Init_ConnectRobot_Request_robot_ip
{
public:
  Init_ConnectRobot_Request_robot_ip()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ConnectRobot_Request_connect robot_ip(::doosan_m0609_controller::srv::ConnectRobot_Request::_robot_ip_type arg)
  {
    msg_.robot_ip = std::move(arg);
    return Init_ConnectRobot_Request_connect(msg_);
  }

private:
  ::doosan_m0609_controller::srv::ConnectRobot_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_controller::srv::ConnectRobot_Request>()
{
  return doosan_m0609_controller::srv::builder::Init_ConnectRobot_Request_robot_ip();
}

}  // namespace doosan_m0609_controller


namespace doosan_m0609_controller
{

namespace srv
{

namespace builder
{

class Init_ConnectRobot_Response_message
{
public:
  explicit Init_ConnectRobot_Response_message(::doosan_m0609_controller::srv::ConnectRobot_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_controller::srv::ConnectRobot_Response message(::doosan_m0609_controller::srv::ConnectRobot_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_controller::srv::ConnectRobot_Response msg_;
};

class Init_ConnectRobot_Response_success
{
public:
  Init_ConnectRobot_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ConnectRobot_Response_message success(::doosan_m0609_controller::srv::ConnectRobot_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ConnectRobot_Response_message(msg_);
  }

private:
  ::doosan_m0609_controller::srv::ConnectRobot_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_controller::srv::ConnectRobot_Response>()
{
  return doosan_m0609_controller::srv::builder::Init_ConnectRobot_Response_success();
}

}  // namespace doosan_m0609_controller

#endif  // DOOSAN_M0609_CONTROLLER__SRV__DETAIL__CONNECT_ROBOT__BUILDER_HPP_

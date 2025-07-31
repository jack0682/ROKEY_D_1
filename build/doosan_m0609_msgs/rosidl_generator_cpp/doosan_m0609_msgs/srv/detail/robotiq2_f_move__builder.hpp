// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/Robotiq2FMove.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__ROBOTIQ2_F_MOVE__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__ROBOTIQ2_F_MOVE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/robotiq2_f_move__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_Robotiq2FMove_Request_width
{
public:
  Init_Robotiq2FMove_Request_width()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::Robotiq2FMove_Request width(::doosan_m0609_msgs::srv::Robotiq2FMove_Request::_width_type arg)
  {
    msg_.width = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Robotiq2FMove_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::Robotiq2FMove_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_Robotiq2FMove_Request_width();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_Robotiq2FMove_Response_success
{
public:
  Init_Robotiq2FMove_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::Robotiq2FMove_Response success(::doosan_m0609_msgs::srv::Robotiq2FMove_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Robotiq2FMove_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::Robotiq2FMove_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_Robotiq2FMove_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__ROBOTIQ2_F_MOVE__BUILDER_HPP_

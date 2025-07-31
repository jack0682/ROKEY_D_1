// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/Jog.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__JOG__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__JOG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/jog__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_Jog_Request_speed
{
public:
  explicit Init_Jog_Request_speed(::doosan_m0609_msgs::srv::Jog_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::Jog_Request speed(::doosan_m0609_msgs::srv::Jog_Request::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Jog_Request msg_;
};

class Init_Jog_Request_move_reference
{
public:
  explicit Init_Jog_Request_move_reference(::doosan_m0609_msgs::srv::Jog_Request & msg)
  : msg_(msg)
  {}
  Init_Jog_Request_speed move_reference(::doosan_m0609_msgs::srv::Jog_Request::_move_reference_type arg)
  {
    msg_.move_reference = std::move(arg);
    return Init_Jog_Request_speed(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Jog_Request msg_;
};

class Init_Jog_Request_jog_axis
{
public:
  Init_Jog_Request_jog_axis()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Jog_Request_move_reference jog_axis(::doosan_m0609_msgs::srv::Jog_Request::_jog_axis_type arg)
  {
    msg_.jog_axis = std::move(arg);
    return Init_Jog_Request_move_reference(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Jog_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::Jog_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_Jog_Request_jog_axis();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_Jog_Response_success
{
public:
  Init_Jog_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::Jog_Response success(::doosan_m0609_msgs::srv::Jog_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Jog_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::Jog_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_Jog_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__JOG__BUILDER_HPP_

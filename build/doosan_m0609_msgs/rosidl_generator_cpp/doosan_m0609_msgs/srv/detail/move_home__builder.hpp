// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/MoveHome.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_HOME__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_HOME__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/move_home__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_MoveHome_Request_target
{
public:
  Init_MoveHome_Request_target()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::MoveHome_Request target(::doosan_m0609_msgs::srv::MoveHome_Request::_target_type arg)
  {
    msg_.target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveHome_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::MoveHome_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_MoveHome_Request_target();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_MoveHome_Response_success
{
public:
  explicit Init_MoveHome_Response_success(::doosan_m0609_msgs::srv::MoveHome_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::MoveHome_Response success(::doosan_m0609_msgs::srv::MoveHome_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveHome_Response msg_;
};

class Init_MoveHome_Response_res
{
public:
  Init_MoveHome_Response_res()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveHome_Response_success res(::doosan_m0609_msgs::srv::MoveHome_Response::_res_type arg)
  {
    msg_.res = std::move(arg);
    return Init_MoveHome_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveHome_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::MoveHome_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_MoveHome_Response_res();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_HOME__BUILDER_HPP_

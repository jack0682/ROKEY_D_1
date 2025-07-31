// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/GetCurrentPose.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CURRENT_POSE__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CURRENT_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/get_current_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetCurrentPose_Request_space_type
{
public:
  Init_GetCurrentPose_Request_space_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::GetCurrentPose_Request space_type(::doosan_m0609_msgs::srv::GetCurrentPose_Request::_space_type_type arg)
  {
    msg_.space_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetCurrentPose_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetCurrentPose_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetCurrentPose_Request_space_type();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetCurrentPose_Response_success
{
public:
  explicit Init_GetCurrentPose_Response_success(::doosan_m0609_msgs::srv::GetCurrentPose_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::GetCurrentPose_Response success(::doosan_m0609_msgs::srv::GetCurrentPose_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetCurrentPose_Response msg_;
};

class Init_GetCurrentPose_Response_pos
{
public:
  Init_GetCurrentPose_Response_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetCurrentPose_Response_success pos(::doosan_m0609_msgs::srv::GetCurrentPose_Response::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_GetCurrentPose_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetCurrentPose_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetCurrentPose_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetCurrentPose_Response_pos();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CURRENT_POSE__BUILDER_HPP_

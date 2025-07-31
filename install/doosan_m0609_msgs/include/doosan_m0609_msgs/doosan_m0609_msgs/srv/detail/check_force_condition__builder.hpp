// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/CheckForceCondition.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__CHECK_FORCE_CONDITION__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__CHECK_FORCE_CONDITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/check_force_condition__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_CheckForceCondition_Request_ref
{
public:
  explicit Init_CheckForceCondition_Request_ref(::doosan_m0609_msgs::srv::CheckForceCondition_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::CheckForceCondition_Request ref(::doosan_m0609_msgs::srv::CheckForceCondition_Request::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CheckForceCondition_Request msg_;
};

class Init_CheckForceCondition_Request_max
{
public:
  explicit Init_CheckForceCondition_Request_max(::doosan_m0609_msgs::srv::CheckForceCondition_Request & msg)
  : msg_(msg)
  {}
  Init_CheckForceCondition_Request_ref max(::doosan_m0609_msgs::srv::CheckForceCondition_Request::_max_type arg)
  {
    msg_.max = std::move(arg);
    return Init_CheckForceCondition_Request_ref(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CheckForceCondition_Request msg_;
};

class Init_CheckForceCondition_Request_min
{
public:
  explicit Init_CheckForceCondition_Request_min(::doosan_m0609_msgs::srv::CheckForceCondition_Request & msg)
  : msg_(msg)
  {}
  Init_CheckForceCondition_Request_max min(::doosan_m0609_msgs::srv::CheckForceCondition_Request::_min_type arg)
  {
    msg_.min = std::move(arg);
    return Init_CheckForceCondition_Request_max(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CheckForceCondition_Request msg_;
};

class Init_CheckForceCondition_Request_axis
{
public:
  Init_CheckForceCondition_Request_axis()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CheckForceCondition_Request_min axis(::doosan_m0609_msgs::srv::CheckForceCondition_Request::_axis_type arg)
  {
    msg_.axis = std::move(arg);
    return Init_CheckForceCondition_Request_min(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CheckForceCondition_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::CheckForceCondition_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_CheckForceCondition_Request_axis();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_CheckForceCondition_Response_success
{
public:
  Init_CheckForceCondition_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::CheckForceCondition_Response success(::doosan_m0609_msgs::srv::CheckForceCondition_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CheckForceCondition_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::CheckForceCondition_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_CheckForceCondition_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__CHECK_FORCE_CONDITION__BUILDER_HPP_

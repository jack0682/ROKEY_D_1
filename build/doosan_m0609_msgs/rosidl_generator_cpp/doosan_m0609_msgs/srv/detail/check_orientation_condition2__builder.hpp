// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/CheckOrientationCondition2.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__CHECK_ORIENTATION_CONDITION2__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__CHECK_ORIENTATION_CONDITION2__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/check_orientation_condition2__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_CheckOrientationCondition2_Request_pos
{
public:
  explicit Init_CheckOrientationCondition2_Request_pos(::doosan_m0609_msgs::srv::CheckOrientationCondition2_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::CheckOrientationCondition2_Request pos(::doosan_m0609_msgs::srv::CheckOrientationCondition2_Request::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CheckOrientationCondition2_Request msg_;
};

class Init_CheckOrientationCondition2_Request_mode
{
public:
  explicit Init_CheckOrientationCondition2_Request_mode(::doosan_m0609_msgs::srv::CheckOrientationCondition2_Request & msg)
  : msg_(msg)
  {}
  Init_CheckOrientationCondition2_Request_pos mode(::doosan_m0609_msgs::srv::CheckOrientationCondition2_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_CheckOrientationCondition2_Request_pos(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CheckOrientationCondition2_Request msg_;
};

class Init_CheckOrientationCondition2_Request_ref
{
public:
  explicit Init_CheckOrientationCondition2_Request_ref(::doosan_m0609_msgs::srv::CheckOrientationCondition2_Request & msg)
  : msg_(msg)
  {}
  Init_CheckOrientationCondition2_Request_mode ref(::doosan_m0609_msgs::srv::CheckOrientationCondition2_Request::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return Init_CheckOrientationCondition2_Request_mode(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CheckOrientationCondition2_Request msg_;
};

class Init_CheckOrientationCondition2_Request_max
{
public:
  explicit Init_CheckOrientationCondition2_Request_max(::doosan_m0609_msgs::srv::CheckOrientationCondition2_Request & msg)
  : msg_(msg)
  {}
  Init_CheckOrientationCondition2_Request_ref max(::doosan_m0609_msgs::srv::CheckOrientationCondition2_Request::_max_type arg)
  {
    msg_.max = std::move(arg);
    return Init_CheckOrientationCondition2_Request_ref(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CheckOrientationCondition2_Request msg_;
};

class Init_CheckOrientationCondition2_Request_min
{
public:
  explicit Init_CheckOrientationCondition2_Request_min(::doosan_m0609_msgs::srv::CheckOrientationCondition2_Request & msg)
  : msg_(msg)
  {}
  Init_CheckOrientationCondition2_Request_max min(::doosan_m0609_msgs::srv::CheckOrientationCondition2_Request::_min_type arg)
  {
    msg_.min = std::move(arg);
    return Init_CheckOrientationCondition2_Request_max(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CheckOrientationCondition2_Request msg_;
};

class Init_CheckOrientationCondition2_Request_axis
{
public:
  Init_CheckOrientationCondition2_Request_axis()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CheckOrientationCondition2_Request_min axis(::doosan_m0609_msgs::srv::CheckOrientationCondition2_Request::_axis_type arg)
  {
    msg_.axis = std::move(arg);
    return Init_CheckOrientationCondition2_Request_min(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CheckOrientationCondition2_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::CheckOrientationCondition2_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_CheckOrientationCondition2_Request_axis();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_CheckOrientationCondition2_Response_success
{
public:
  Init_CheckOrientationCondition2_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::CheckOrientationCondition2_Response success(::doosan_m0609_msgs::srv::CheckOrientationCondition2_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CheckOrientationCondition2_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::CheckOrientationCondition2_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_CheckOrientationCondition2_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__CHECK_ORIENTATION_CONDITION2__BUILDER_HPP_

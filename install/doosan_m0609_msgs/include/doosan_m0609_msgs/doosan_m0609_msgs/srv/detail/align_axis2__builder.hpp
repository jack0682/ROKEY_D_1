// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/AlignAxis2.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__ALIGN_AXIS2__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__ALIGN_AXIS2__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/align_axis2__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_AlignAxis2_Request_ref
{
public:
  explicit Init_AlignAxis2_Request_ref(::doosan_m0609_msgs::srv::AlignAxis2_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::AlignAxis2_Request ref(::doosan_m0609_msgs::srv::AlignAxis2_Request::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::AlignAxis2_Request msg_;
};

class Init_AlignAxis2_Request_axis
{
public:
  explicit Init_AlignAxis2_Request_axis(::doosan_m0609_msgs::srv::AlignAxis2_Request & msg)
  : msg_(msg)
  {}
  Init_AlignAxis2_Request_ref axis(::doosan_m0609_msgs::srv::AlignAxis2_Request::_axis_type arg)
  {
    msg_.axis = std::move(arg);
    return Init_AlignAxis2_Request_ref(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::AlignAxis2_Request msg_;
};

class Init_AlignAxis2_Request_source_vect
{
public:
  explicit Init_AlignAxis2_Request_source_vect(::doosan_m0609_msgs::srv::AlignAxis2_Request & msg)
  : msg_(msg)
  {}
  Init_AlignAxis2_Request_axis source_vect(::doosan_m0609_msgs::srv::AlignAxis2_Request::_source_vect_type arg)
  {
    msg_.source_vect = std::move(arg);
    return Init_AlignAxis2_Request_axis(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::AlignAxis2_Request msg_;
};

class Init_AlignAxis2_Request_target_vect
{
public:
  Init_AlignAxis2_Request_target_vect()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AlignAxis2_Request_source_vect target_vect(::doosan_m0609_msgs::srv::AlignAxis2_Request::_target_vect_type arg)
  {
    msg_.target_vect = std::move(arg);
    return Init_AlignAxis2_Request_source_vect(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::AlignAxis2_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::AlignAxis2_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_AlignAxis2_Request_target_vect();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_AlignAxis2_Response_success
{
public:
  Init_AlignAxis2_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::AlignAxis2_Response success(::doosan_m0609_msgs::srv::AlignAxis2_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::AlignAxis2_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::AlignAxis2_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_AlignAxis2_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__ALIGN_AXIS2__BUILDER_HPP_

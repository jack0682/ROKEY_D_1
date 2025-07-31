// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/Trans.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__TRANS__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__TRANS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/trans__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_Trans_Request_ref_out
{
public:
  explicit Init_Trans_Request_ref_out(::doosan_m0609_msgs::srv::Trans_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::Trans_Request ref_out(::doosan_m0609_msgs::srv::Trans_Request::_ref_out_type arg)
  {
    msg_.ref_out = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Trans_Request msg_;
};

class Init_Trans_Request_ref
{
public:
  explicit Init_Trans_Request_ref(::doosan_m0609_msgs::srv::Trans_Request & msg)
  : msg_(msg)
  {}
  Init_Trans_Request_ref_out ref(::doosan_m0609_msgs::srv::Trans_Request::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return Init_Trans_Request_ref_out(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Trans_Request msg_;
};

class Init_Trans_Request_delta
{
public:
  explicit Init_Trans_Request_delta(::doosan_m0609_msgs::srv::Trans_Request & msg)
  : msg_(msg)
  {}
  Init_Trans_Request_ref delta(::doosan_m0609_msgs::srv::Trans_Request::_delta_type arg)
  {
    msg_.delta = std::move(arg);
    return Init_Trans_Request_ref(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Trans_Request msg_;
};

class Init_Trans_Request_pos
{
public:
  Init_Trans_Request_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Trans_Request_delta pos(::doosan_m0609_msgs::srv::Trans_Request::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_Trans_Request_delta(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Trans_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::Trans_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_Trans_Request_pos();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_Trans_Response_success
{
public:
  explicit Init_Trans_Response_success(::doosan_m0609_msgs::srv::Trans_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::Trans_Response success(::doosan_m0609_msgs::srv::Trans_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Trans_Response msg_;
};

class Init_Trans_Response_trans_pos
{
public:
  Init_Trans_Response_trans_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Trans_Response_success trans_pos(::doosan_m0609_msgs::srv::Trans_Response::_trans_pos_type arg)
  {
    msg_.trans_pos = std::move(arg);
    return Init_Trans_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Trans_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::Trans_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_Trans_Response_trans_pos();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__TRANS__BUILDER_HPP_

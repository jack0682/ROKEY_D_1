// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/IsDoneBoltTightening.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__IS_DONE_BOLT_TIGHTENING__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__IS_DONE_BOLT_TIGHTENING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/is_done_bolt_tightening__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_IsDoneBoltTightening_Request_axis
{
public:
  explicit Init_IsDoneBoltTightening_Request_axis(::doosan_m0609_msgs::srv::IsDoneBoltTightening_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::IsDoneBoltTightening_Request axis(::doosan_m0609_msgs::srv::IsDoneBoltTightening_Request::_axis_type arg)
  {
    msg_.axis = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::IsDoneBoltTightening_Request msg_;
};

class Init_IsDoneBoltTightening_Request_timeout
{
public:
  explicit Init_IsDoneBoltTightening_Request_timeout(::doosan_m0609_msgs::srv::IsDoneBoltTightening_Request & msg)
  : msg_(msg)
  {}
  Init_IsDoneBoltTightening_Request_axis timeout(::doosan_m0609_msgs::srv::IsDoneBoltTightening_Request::_timeout_type arg)
  {
    msg_.timeout = std::move(arg);
    return Init_IsDoneBoltTightening_Request_axis(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::IsDoneBoltTightening_Request msg_;
};

class Init_IsDoneBoltTightening_Request_m
{
public:
  Init_IsDoneBoltTightening_Request_m()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IsDoneBoltTightening_Request_timeout m(::doosan_m0609_msgs::srv::IsDoneBoltTightening_Request::_m_type arg)
  {
    msg_.m = std::move(arg);
    return Init_IsDoneBoltTightening_Request_timeout(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::IsDoneBoltTightening_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::IsDoneBoltTightening_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_IsDoneBoltTightening_Request_m();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_IsDoneBoltTightening_Response_success
{
public:
  Init_IsDoneBoltTightening_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::IsDoneBoltTightening_Response success(::doosan_m0609_msgs::srv::IsDoneBoltTightening_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::IsDoneBoltTightening_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::IsDoneBoltTightening_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_IsDoneBoltTightening_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__IS_DONE_BOLT_TIGHTENING__BUILDER_HPP_

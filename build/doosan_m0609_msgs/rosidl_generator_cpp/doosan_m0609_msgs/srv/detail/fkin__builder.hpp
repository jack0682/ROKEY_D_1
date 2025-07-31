// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/Fkin.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__FKIN__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__FKIN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/fkin__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_Fkin_Request_ref
{
public:
  explicit Init_Fkin_Request_ref(::doosan_m0609_msgs::srv::Fkin_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::Fkin_Request ref(::doosan_m0609_msgs::srv::Fkin_Request::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Fkin_Request msg_;
};

class Init_Fkin_Request_pos
{
public:
  Init_Fkin_Request_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Fkin_Request_ref pos(::doosan_m0609_msgs::srv::Fkin_Request::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_Fkin_Request_ref(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Fkin_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::Fkin_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_Fkin_Request_pos();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_Fkin_Response_success
{
public:
  explicit Init_Fkin_Response_success(::doosan_m0609_msgs::srv::Fkin_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::Fkin_Response success(::doosan_m0609_msgs::srv::Fkin_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Fkin_Response msg_;
};

class Init_Fkin_Response_conv_posx
{
public:
  Init_Fkin_Response_conv_posx()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Fkin_Response_success conv_posx(::doosan_m0609_msgs::srv::Fkin_Response::_conv_posx_type arg)
  {
    msg_.conv_posx = std::move(arg);
    return Init_Fkin_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Fkin_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::Fkin_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_Fkin_Response_conv_posx();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__FKIN__BUILDER_HPP_

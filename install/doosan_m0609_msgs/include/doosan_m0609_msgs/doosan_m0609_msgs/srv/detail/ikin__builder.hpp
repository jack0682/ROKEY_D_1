// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/Ikin.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__IKIN__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__IKIN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/ikin__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_Ikin_Request_ref
{
public:
  explicit Init_Ikin_Request_ref(::doosan_m0609_msgs::srv::Ikin_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::Ikin_Request ref(::doosan_m0609_msgs::srv::Ikin_Request::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Ikin_Request msg_;
};

class Init_Ikin_Request_sol_space
{
public:
  explicit Init_Ikin_Request_sol_space(::doosan_m0609_msgs::srv::Ikin_Request & msg)
  : msg_(msg)
  {}
  Init_Ikin_Request_ref sol_space(::doosan_m0609_msgs::srv::Ikin_Request::_sol_space_type arg)
  {
    msg_.sol_space = std::move(arg);
    return Init_Ikin_Request_ref(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Ikin_Request msg_;
};

class Init_Ikin_Request_pos
{
public:
  Init_Ikin_Request_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Ikin_Request_sol_space pos(::doosan_m0609_msgs::srv::Ikin_Request::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_Ikin_Request_sol_space(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Ikin_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::Ikin_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_Ikin_Request_pos();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_Ikin_Response_success
{
public:
  explicit Init_Ikin_Response_success(::doosan_m0609_msgs::srv::Ikin_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::Ikin_Response success(::doosan_m0609_msgs::srv::Ikin_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Ikin_Response msg_;
};

class Init_Ikin_Response_conv_posj
{
public:
  Init_Ikin_Response_conv_posj()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Ikin_Response_success conv_posj(::doosan_m0609_msgs::srv::Ikin_Response::_conv_posj_type arg)
  {
    msg_.conv_posj = std::move(arg);
    return Init_Ikin_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::Ikin_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::Ikin_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_Ikin_Response_conv_posj();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__IKIN__BUILDER_HPP_

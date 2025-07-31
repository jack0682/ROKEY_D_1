// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/CalcCoord.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__CALC_COORD__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__CALC_COORD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/calc_coord__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_CalcCoord_Request_mod
{
public:
  explicit Init_CalcCoord_Request_mod(::doosan_m0609_msgs::srv::CalcCoord_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::CalcCoord_Request mod(::doosan_m0609_msgs::srv::CalcCoord_Request::_mod_type arg)
  {
    msg_.mod = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CalcCoord_Request msg_;
};

class Init_CalcCoord_Request_ref
{
public:
  explicit Init_CalcCoord_Request_ref(::doosan_m0609_msgs::srv::CalcCoord_Request & msg)
  : msg_(msg)
  {}
  Init_CalcCoord_Request_mod ref(::doosan_m0609_msgs::srv::CalcCoord_Request::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return Init_CalcCoord_Request_mod(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CalcCoord_Request msg_;
};

class Init_CalcCoord_Request_x4
{
public:
  explicit Init_CalcCoord_Request_x4(::doosan_m0609_msgs::srv::CalcCoord_Request & msg)
  : msg_(msg)
  {}
  Init_CalcCoord_Request_ref x4(::doosan_m0609_msgs::srv::CalcCoord_Request::_x4_type arg)
  {
    msg_.x4 = std::move(arg);
    return Init_CalcCoord_Request_ref(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CalcCoord_Request msg_;
};

class Init_CalcCoord_Request_x3
{
public:
  explicit Init_CalcCoord_Request_x3(::doosan_m0609_msgs::srv::CalcCoord_Request & msg)
  : msg_(msg)
  {}
  Init_CalcCoord_Request_x4 x3(::doosan_m0609_msgs::srv::CalcCoord_Request::_x3_type arg)
  {
    msg_.x3 = std::move(arg);
    return Init_CalcCoord_Request_x4(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CalcCoord_Request msg_;
};

class Init_CalcCoord_Request_x2
{
public:
  explicit Init_CalcCoord_Request_x2(::doosan_m0609_msgs::srv::CalcCoord_Request & msg)
  : msg_(msg)
  {}
  Init_CalcCoord_Request_x3 x2(::doosan_m0609_msgs::srv::CalcCoord_Request::_x2_type arg)
  {
    msg_.x2 = std::move(arg);
    return Init_CalcCoord_Request_x3(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CalcCoord_Request msg_;
};

class Init_CalcCoord_Request_x1
{
public:
  explicit Init_CalcCoord_Request_x1(::doosan_m0609_msgs::srv::CalcCoord_Request & msg)
  : msg_(msg)
  {}
  Init_CalcCoord_Request_x2 x1(::doosan_m0609_msgs::srv::CalcCoord_Request::_x1_type arg)
  {
    msg_.x1 = std::move(arg);
    return Init_CalcCoord_Request_x2(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CalcCoord_Request msg_;
};

class Init_CalcCoord_Request_input_pos_cnt
{
public:
  Init_CalcCoord_Request_input_pos_cnt()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CalcCoord_Request_x1 input_pos_cnt(::doosan_m0609_msgs::srv::CalcCoord_Request::_input_pos_cnt_type arg)
  {
    msg_.input_pos_cnt = std::move(arg);
    return Init_CalcCoord_Request_x1(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CalcCoord_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::CalcCoord_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_CalcCoord_Request_input_pos_cnt();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_CalcCoord_Response_success
{
public:
  explicit Init_CalcCoord_Response_success(::doosan_m0609_msgs::srv::CalcCoord_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::CalcCoord_Response success(::doosan_m0609_msgs::srv::CalcCoord_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CalcCoord_Response msg_;
};

class Init_CalcCoord_Response_conv_posx
{
public:
  Init_CalcCoord_Response_conv_posx()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CalcCoord_Response_success conv_posx(::doosan_m0609_msgs::srv::CalcCoord_Response::_conv_posx_type arg)
  {
    msg_.conv_posx = std::move(arg);
    return Init_CalcCoord_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CalcCoord_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::CalcCoord_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_CalcCoord_Response_conv_posx();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__CALC_COORD__BUILDER_HPP_

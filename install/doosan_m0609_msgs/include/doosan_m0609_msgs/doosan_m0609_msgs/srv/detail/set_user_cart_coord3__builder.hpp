// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/SetUserCartCoord3.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_USER_CART_COORD3__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_USER_CART_COORD3__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/set_user_cart_coord3__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetUserCartCoord3_Request_ref
{
public:
  explicit Init_SetUserCartCoord3_Request_ref(::doosan_m0609_msgs::srv::SetUserCartCoord3_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::SetUserCartCoord3_Request ref(::doosan_m0609_msgs::srv::SetUserCartCoord3_Request::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetUserCartCoord3_Request msg_;
};

class Init_SetUserCartCoord3_Request_pos
{
public:
  explicit Init_SetUserCartCoord3_Request_pos(::doosan_m0609_msgs::srv::SetUserCartCoord3_Request & msg)
  : msg_(msg)
  {}
  Init_SetUserCartCoord3_Request_ref pos(::doosan_m0609_msgs::srv::SetUserCartCoord3_Request::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_SetUserCartCoord3_Request_ref(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetUserCartCoord3_Request msg_;
};

class Init_SetUserCartCoord3_Request_v1
{
public:
  explicit Init_SetUserCartCoord3_Request_v1(::doosan_m0609_msgs::srv::SetUserCartCoord3_Request & msg)
  : msg_(msg)
  {}
  Init_SetUserCartCoord3_Request_pos v1(::doosan_m0609_msgs::srv::SetUserCartCoord3_Request::_v1_type arg)
  {
    msg_.v1 = std::move(arg);
    return Init_SetUserCartCoord3_Request_pos(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetUserCartCoord3_Request msg_;
};

class Init_SetUserCartCoord3_Request_u1
{
public:
  Init_SetUserCartCoord3_Request_u1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetUserCartCoord3_Request_v1 u1(::doosan_m0609_msgs::srv::SetUserCartCoord3_Request::_u1_type arg)
  {
    msg_.u1 = std::move(arg);
    return Init_SetUserCartCoord3_Request_v1(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetUserCartCoord3_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetUserCartCoord3_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetUserCartCoord3_Request_u1();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetUserCartCoord3_Response_success
{
public:
  explicit Init_SetUserCartCoord3_Response_success(::doosan_m0609_msgs::srv::SetUserCartCoord3_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::SetUserCartCoord3_Response success(::doosan_m0609_msgs::srv::SetUserCartCoord3_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetUserCartCoord3_Response msg_;
};

class Init_SetUserCartCoord3_Response_id
{
public:
  Init_SetUserCartCoord3_Response_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetUserCartCoord3_Response_success id(::doosan_m0609_msgs::srv::SetUserCartCoord3_Response::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_SetUserCartCoord3_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetUserCartCoord3_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetUserCartCoord3_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetUserCartCoord3_Response_id();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_USER_CART_COORD3__BUILDER_HPP_

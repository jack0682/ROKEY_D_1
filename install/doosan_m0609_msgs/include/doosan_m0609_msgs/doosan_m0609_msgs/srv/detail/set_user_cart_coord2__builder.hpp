// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/SetUserCartCoord2.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_USER_CART_COORD2__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_USER_CART_COORD2__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/set_user_cart_coord2__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetUserCartCoord2_Request_ref
{
public:
  explicit Init_SetUserCartCoord2_Request_ref(::doosan_m0609_msgs::srv::SetUserCartCoord2_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::SetUserCartCoord2_Request ref(::doosan_m0609_msgs::srv::SetUserCartCoord2_Request::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetUserCartCoord2_Request msg_;
};

class Init_SetUserCartCoord2_Request_pos
{
public:
  explicit Init_SetUserCartCoord2_Request_pos(::doosan_m0609_msgs::srv::SetUserCartCoord2_Request & msg)
  : msg_(msg)
  {}
  Init_SetUserCartCoord2_Request_ref pos(::doosan_m0609_msgs::srv::SetUserCartCoord2_Request::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_SetUserCartCoord2_Request_ref(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetUserCartCoord2_Request msg_;
};

class Init_SetUserCartCoord2_Request_x3
{
public:
  explicit Init_SetUserCartCoord2_Request_x3(::doosan_m0609_msgs::srv::SetUserCartCoord2_Request & msg)
  : msg_(msg)
  {}
  Init_SetUserCartCoord2_Request_pos x3(::doosan_m0609_msgs::srv::SetUserCartCoord2_Request::_x3_type arg)
  {
    msg_.x3 = std::move(arg);
    return Init_SetUserCartCoord2_Request_pos(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetUserCartCoord2_Request msg_;
};

class Init_SetUserCartCoord2_Request_x2
{
public:
  explicit Init_SetUserCartCoord2_Request_x2(::doosan_m0609_msgs::srv::SetUserCartCoord2_Request & msg)
  : msg_(msg)
  {}
  Init_SetUserCartCoord2_Request_x3 x2(::doosan_m0609_msgs::srv::SetUserCartCoord2_Request::_x2_type arg)
  {
    msg_.x2 = std::move(arg);
    return Init_SetUserCartCoord2_Request_x3(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetUserCartCoord2_Request msg_;
};

class Init_SetUserCartCoord2_Request_x1
{
public:
  Init_SetUserCartCoord2_Request_x1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetUserCartCoord2_Request_x2 x1(::doosan_m0609_msgs::srv::SetUserCartCoord2_Request::_x1_type arg)
  {
    msg_.x1 = std::move(arg);
    return Init_SetUserCartCoord2_Request_x2(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetUserCartCoord2_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetUserCartCoord2_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetUserCartCoord2_Request_x1();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetUserCartCoord2_Response_success
{
public:
  explicit Init_SetUserCartCoord2_Response_success(::doosan_m0609_msgs::srv::SetUserCartCoord2_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::SetUserCartCoord2_Response success(::doosan_m0609_msgs::srv::SetUserCartCoord2_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetUserCartCoord2_Response msg_;
};

class Init_SetUserCartCoord2_Response_id
{
public:
  Init_SetUserCartCoord2_Response_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetUserCartCoord2_Response_success id(::doosan_m0609_msgs::srv::SetUserCartCoord2_Response::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_SetUserCartCoord2_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetUserCartCoord2_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetUserCartCoord2_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetUserCartCoord2_Response_id();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_USER_CART_COORD2__BUILDER_HPP_

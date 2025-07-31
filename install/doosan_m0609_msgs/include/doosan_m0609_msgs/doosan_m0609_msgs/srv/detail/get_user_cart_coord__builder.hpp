// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/GetUserCartCoord.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_USER_CART_COORD__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_USER_CART_COORD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/get_user_cart_coord__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetUserCartCoord_Request_id
{
public:
  Init_GetUserCartCoord_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::GetUserCartCoord_Request id(::doosan_m0609_msgs::srv::GetUserCartCoord_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetUserCartCoord_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetUserCartCoord_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetUserCartCoord_Request_id();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetUserCartCoord_Response_success
{
public:
  explicit Init_GetUserCartCoord_Response_success(::doosan_m0609_msgs::srv::GetUserCartCoord_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::GetUserCartCoord_Response success(::doosan_m0609_msgs::srv::GetUserCartCoord_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetUserCartCoord_Response msg_;
};

class Init_GetUserCartCoord_Response_ref
{
public:
  explicit Init_GetUserCartCoord_Response_ref(::doosan_m0609_msgs::srv::GetUserCartCoord_Response & msg)
  : msg_(msg)
  {}
  Init_GetUserCartCoord_Response_success ref(::doosan_m0609_msgs::srv::GetUserCartCoord_Response::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return Init_GetUserCartCoord_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetUserCartCoord_Response msg_;
};

class Init_GetUserCartCoord_Response_conv_posx
{
public:
  Init_GetUserCartCoord_Response_conv_posx()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetUserCartCoord_Response_ref conv_posx(::doosan_m0609_msgs::srv::GetUserCartCoord_Response::_conv_posx_type arg)
  {
    msg_.conv_posx = std::move(arg);
    return Init_GetUserCartCoord_Response_ref(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetUserCartCoord_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetUserCartCoord_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetUserCartCoord_Response_conv_posx();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_USER_CART_COORD__BUILDER_HPP_

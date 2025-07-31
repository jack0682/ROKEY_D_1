// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/OverwriteUserCartCoord.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__OVERWRITE_USER_CART_COORD__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__OVERWRITE_USER_CART_COORD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/overwrite_user_cart_coord__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_OverwriteUserCartCoord_Request_ref
{
public:
  explicit Init_OverwriteUserCartCoord_Request_ref(::doosan_m0609_msgs::srv::OverwriteUserCartCoord_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::OverwriteUserCartCoord_Request ref(::doosan_m0609_msgs::srv::OverwriteUserCartCoord_Request::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::OverwriteUserCartCoord_Request msg_;
};

class Init_OverwriteUserCartCoord_Request_pos
{
public:
  explicit Init_OverwriteUserCartCoord_Request_pos(::doosan_m0609_msgs::srv::OverwriteUserCartCoord_Request & msg)
  : msg_(msg)
  {}
  Init_OverwriteUserCartCoord_Request_ref pos(::doosan_m0609_msgs::srv::OverwriteUserCartCoord_Request::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_OverwriteUserCartCoord_Request_ref(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::OverwriteUserCartCoord_Request msg_;
};

class Init_OverwriteUserCartCoord_Request_id
{
public:
  Init_OverwriteUserCartCoord_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OverwriteUserCartCoord_Request_pos id(::doosan_m0609_msgs::srv::OverwriteUserCartCoord_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_OverwriteUserCartCoord_Request_pos(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::OverwriteUserCartCoord_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::OverwriteUserCartCoord_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_OverwriteUserCartCoord_Request_id();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_OverwriteUserCartCoord_Response_success
{
public:
  explicit Init_OverwriteUserCartCoord_Response_success(::doosan_m0609_msgs::srv::OverwriteUserCartCoord_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::OverwriteUserCartCoord_Response success(::doosan_m0609_msgs::srv::OverwriteUserCartCoord_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::OverwriteUserCartCoord_Response msg_;
};

class Init_OverwriteUserCartCoord_Response_id
{
public:
  Init_OverwriteUserCartCoord_Response_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OverwriteUserCartCoord_Response_success id(::doosan_m0609_msgs::srv::OverwriteUserCartCoord_Response::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_OverwriteUserCartCoord_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::OverwriteUserCartCoord_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::OverwriteUserCartCoord_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_OverwriteUserCartCoord_Response_id();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__OVERWRITE_USER_CART_COORD__BUILDER_HPP_

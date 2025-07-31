// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/SetRefCoord.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_REF_COORD__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_REF_COORD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/set_ref_coord__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetRefCoord_Request_coord
{
public:
  Init_SetRefCoord_Request_coord()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::SetRefCoord_Request coord(::doosan_m0609_msgs::srv::SetRefCoord_Request::_coord_type arg)
  {
    msg_.coord = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetRefCoord_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetRefCoord_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetRefCoord_Request_coord();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_SetRefCoord_Response_success
{
public:
  Init_SetRefCoord_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::SetRefCoord_Response success(::doosan_m0609_msgs::srv::SetRefCoord_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::SetRefCoord_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::SetRefCoord_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_SetRefCoord_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_REF_COORD__BUILDER_HPP_

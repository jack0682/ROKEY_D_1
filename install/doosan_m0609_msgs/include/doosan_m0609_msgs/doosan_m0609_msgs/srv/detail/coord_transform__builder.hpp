// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/CoordTransform.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__COORD_TRANSFORM__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__COORD_TRANSFORM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/coord_transform__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_CoordTransform_Request_ref_out
{
public:
  explicit Init_CoordTransform_Request_ref_out(::doosan_m0609_msgs::srv::CoordTransform_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::CoordTransform_Request ref_out(::doosan_m0609_msgs::srv::CoordTransform_Request::_ref_out_type arg)
  {
    msg_.ref_out = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CoordTransform_Request msg_;
};

class Init_CoordTransform_Request_ref_in
{
public:
  explicit Init_CoordTransform_Request_ref_in(::doosan_m0609_msgs::srv::CoordTransform_Request & msg)
  : msg_(msg)
  {}
  Init_CoordTransform_Request_ref_out ref_in(::doosan_m0609_msgs::srv::CoordTransform_Request::_ref_in_type arg)
  {
    msg_.ref_in = std::move(arg);
    return Init_CoordTransform_Request_ref_out(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CoordTransform_Request msg_;
};

class Init_CoordTransform_Request_pos_in
{
public:
  Init_CoordTransform_Request_pos_in()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CoordTransform_Request_ref_in pos_in(::doosan_m0609_msgs::srv::CoordTransform_Request::_pos_in_type arg)
  {
    msg_.pos_in = std::move(arg);
    return Init_CoordTransform_Request_ref_in(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CoordTransform_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::CoordTransform_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_CoordTransform_Request_pos_in();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_CoordTransform_Response_success
{
public:
  explicit Init_CoordTransform_Response_success(::doosan_m0609_msgs::srv::CoordTransform_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::CoordTransform_Response success(::doosan_m0609_msgs::srv::CoordTransform_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CoordTransform_Response msg_;
};

class Init_CoordTransform_Response_conv_posx
{
public:
  Init_CoordTransform_Response_conv_posx()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CoordTransform_Response_success conv_posx(::doosan_m0609_msgs::srv::CoordTransform_Response::_conv_posx_type arg)
  {
    msg_.conv_posx = std::move(arg);
    return Init_CoordTransform_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::CoordTransform_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::CoordTransform_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_CoordTransform_Response_conv_posx();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__COORD_TRANSFORM__BUILDER_HPP_

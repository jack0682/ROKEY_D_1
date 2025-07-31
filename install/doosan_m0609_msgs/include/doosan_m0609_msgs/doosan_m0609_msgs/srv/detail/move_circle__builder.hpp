// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/MoveCircle.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_CIRCLE__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_CIRCLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/move_circle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_MoveCircle_Request_sync_type
{
public:
  explicit Init_MoveCircle_Request_sync_type(::doosan_m0609_msgs::srv::MoveCircle_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::MoveCircle_Request sync_type(::doosan_m0609_msgs::srv::MoveCircle_Request::_sync_type_type arg)
  {
    msg_.sync_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveCircle_Request msg_;
};

class Init_MoveCircle_Request_blend_type
{
public:
  explicit Init_MoveCircle_Request_blend_type(::doosan_m0609_msgs::srv::MoveCircle_Request & msg)
  : msg_(msg)
  {}
  Init_MoveCircle_Request_sync_type blend_type(::doosan_m0609_msgs::srv::MoveCircle_Request::_blend_type_type arg)
  {
    msg_.blend_type = std::move(arg);
    return Init_MoveCircle_Request_sync_type(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveCircle_Request msg_;
};

class Init_MoveCircle_Request_angle2
{
public:
  explicit Init_MoveCircle_Request_angle2(::doosan_m0609_msgs::srv::MoveCircle_Request & msg)
  : msg_(msg)
  {}
  Init_MoveCircle_Request_blend_type angle2(::doosan_m0609_msgs::srv::MoveCircle_Request::_angle2_type arg)
  {
    msg_.angle2 = std::move(arg);
    return Init_MoveCircle_Request_blend_type(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveCircle_Request msg_;
};

class Init_MoveCircle_Request_angle1
{
public:
  explicit Init_MoveCircle_Request_angle1(::doosan_m0609_msgs::srv::MoveCircle_Request & msg)
  : msg_(msg)
  {}
  Init_MoveCircle_Request_angle2 angle1(::doosan_m0609_msgs::srv::MoveCircle_Request::_angle1_type arg)
  {
    msg_.angle1 = std::move(arg);
    return Init_MoveCircle_Request_angle2(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveCircle_Request msg_;
};

class Init_MoveCircle_Request_mode
{
public:
  explicit Init_MoveCircle_Request_mode(::doosan_m0609_msgs::srv::MoveCircle_Request & msg)
  : msg_(msg)
  {}
  Init_MoveCircle_Request_angle1 mode(::doosan_m0609_msgs::srv::MoveCircle_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_MoveCircle_Request_angle1(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveCircle_Request msg_;
};

class Init_MoveCircle_Request_ref
{
public:
  explicit Init_MoveCircle_Request_ref(::doosan_m0609_msgs::srv::MoveCircle_Request & msg)
  : msg_(msg)
  {}
  Init_MoveCircle_Request_mode ref(::doosan_m0609_msgs::srv::MoveCircle_Request::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return Init_MoveCircle_Request_mode(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveCircle_Request msg_;
};

class Init_MoveCircle_Request_radius
{
public:
  explicit Init_MoveCircle_Request_radius(::doosan_m0609_msgs::srv::MoveCircle_Request & msg)
  : msg_(msg)
  {}
  Init_MoveCircle_Request_ref radius(::doosan_m0609_msgs::srv::MoveCircle_Request::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return Init_MoveCircle_Request_ref(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveCircle_Request msg_;
};

class Init_MoveCircle_Request_time
{
public:
  explicit Init_MoveCircle_Request_time(::doosan_m0609_msgs::srv::MoveCircle_Request & msg)
  : msg_(msg)
  {}
  Init_MoveCircle_Request_radius time(::doosan_m0609_msgs::srv::MoveCircle_Request::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_MoveCircle_Request_radius(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveCircle_Request msg_;
};

class Init_MoveCircle_Request_acc
{
public:
  explicit Init_MoveCircle_Request_acc(::doosan_m0609_msgs::srv::MoveCircle_Request & msg)
  : msg_(msg)
  {}
  Init_MoveCircle_Request_time acc(::doosan_m0609_msgs::srv::MoveCircle_Request::_acc_type arg)
  {
    msg_.acc = std::move(arg);
    return Init_MoveCircle_Request_time(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveCircle_Request msg_;
};

class Init_MoveCircle_Request_vel
{
public:
  explicit Init_MoveCircle_Request_vel(::doosan_m0609_msgs::srv::MoveCircle_Request & msg)
  : msg_(msg)
  {}
  Init_MoveCircle_Request_acc vel(::doosan_m0609_msgs::srv::MoveCircle_Request::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_MoveCircle_Request_acc(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveCircle_Request msg_;
};

class Init_MoveCircle_Request_pos
{
public:
  Init_MoveCircle_Request_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveCircle_Request_vel pos(::doosan_m0609_msgs::srv::MoveCircle_Request::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_MoveCircle_Request_vel(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveCircle_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::MoveCircle_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_MoveCircle_Request_pos();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_MoveCircle_Response_success
{
public:
  Init_MoveCircle_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::MoveCircle_Response success(::doosan_m0609_msgs::srv::MoveCircle_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveCircle_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::MoveCircle_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_MoveCircle_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_CIRCLE__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/MoveJoint.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_JOINT__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_JOINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/move_joint__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_MoveJoint_Request_sync_type
{
public:
  explicit Init_MoveJoint_Request_sync_type(::doosan_m0609_msgs::srv::MoveJoint_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::MoveJoint_Request sync_type(::doosan_m0609_msgs::srv::MoveJoint_Request::_sync_type_type arg)
  {
    msg_.sync_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveJoint_Request msg_;
};

class Init_MoveJoint_Request_blend_type
{
public:
  explicit Init_MoveJoint_Request_blend_type(::doosan_m0609_msgs::srv::MoveJoint_Request & msg)
  : msg_(msg)
  {}
  Init_MoveJoint_Request_sync_type blend_type(::doosan_m0609_msgs::srv::MoveJoint_Request::_blend_type_type arg)
  {
    msg_.blend_type = std::move(arg);
    return Init_MoveJoint_Request_sync_type(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveJoint_Request msg_;
};

class Init_MoveJoint_Request_mode
{
public:
  explicit Init_MoveJoint_Request_mode(::doosan_m0609_msgs::srv::MoveJoint_Request & msg)
  : msg_(msg)
  {}
  Init_MoveJoint_Request_blend_type mode(::doosan_m0609_msgs::srv::MoveJoint_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_MoveJoint_Request_blend_type(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveJoint_Request msg_;
};

class Init_MoveJoint_Request_radius
{
public:
  explicit Init_MoveJoint_Request_radius(::doosan_m0609_msgs::srv::MoveJoint_Request & msg)
  : msg_(msg)
  {}
  Init_MoveJoint_Request_mode radius(::doosan_m0609_msgs::srv::MoveJoint_Request::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return Init_MoveJoint_Request_mode(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveJoint_Request msg_;
};

class Init_MoveJoint_Request_time
{
public:
  explicit Init_MoveJoint_Request_time(::doosan_m0609_msgs::srv::MoveJoint_Request & msg)
  : msg_(msg)
  {}
  Init_MoveJoint_Request_radius time(::doosan_m0609_msgs::srv::MoveJoint_Request::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_MoveJoint_Request_radius(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveJoint_Request msg_;
};

class Init_MoveJoint_Request_acc
{
public:
  explicit Init_MoveJoint_Request_acc(::doosan_m0609_msgs::srv::MoveJoint_Request & msg)
  : msg_(msg)
  {}
  Init_MoveJoint_Request_time acc(::doosan_m0609_msgs::srv::MoveJoint_Request::_acc_type arg)
  {
    msg_.acc = std::move(arg);
    return Init_MoveJoint_Request_time(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveJoint_Request msg_;
};

class Init_MoveJoint_Request_vel
{
public:
  explicit Init_MoveJoint_Request_vel(::doosan_m0609_msgs::srv::MoveJoint_Request & msg)
  : msg_(msg)
  {}
  Init_MoveJoint_Request_acc vel(::doosan_m0609_msgs::srv::MoveJoint_Request::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_MoveJoint_Request_acc(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveJoint_Request msg_;
};

class Init_MoveJoint_Request_pos
{
public:
  Init_MoveJoint_Request_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveJoint_Request_vel pos(::doosan_m0609_msgs::srv::MoveJoint_Request::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_MoveJoint_Request_vel(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveJoint_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::MoveJoint_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_MoveJoint_Request_pos();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_MoveJoint_Response_success
{
public:
  Init_MoveJoint_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::MoveJoint_Response success(::doosan_m0609_msgs::srv::MoveJoint_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveJoint_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::MoveJoint_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_MoveJoint_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_JOINT__BUILDER_HPP_

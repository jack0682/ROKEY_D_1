// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/MoveSplineJoint.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_SPLINE_JOINT__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_SPLINE_JOINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/move_spline_joint__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_MoveSplineJoint_Request_sync_type
{
public:
  explicit Init_MoveSplineJoint_Request_sync_type(::doosan_m0609_msgs::srv::MoveSplineJoint_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::MoveSplineJoint_Request sync_type(::doosan_m0609_msgs::srv::MoveSplineJoint_Request::_sync_type_type arg)
  {
    msg_.sync_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveSplineJoint_Request msg_;
};

class Init_MoveSplineJoint_Request_mode
{
public:
  explicit Init_MoveSplineJoint_Request_mode(::doosan_m0609_msgs::srv::MoveSplineJoint_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSplineJoint_Request_sync_type mode(::doosan_m0609_msgs::srv::MoveSplineJoint_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_MoveSplineJoint_Request_sync_type(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveSplineJoint_Request msg_;
};

class Init_MoveSplineJoint_Request_time
{
public:
  explicit Init_MoveSplineJoint_Request_time(::doosan_m0609_msgs::srv::MoveSplineJoint_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSplineJoint_Request_mode time(::doosan_m0609_msgs::srv::MoveSplineJoint_Request::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_MoveSplineJoint_Request_mode(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveSplineJoint_Request msg_;
};

class Init_MoveSplineJoint_Request_acc
{
public:
  explicit Init_MoveSplineJoint_Request_acc(::doosan_m0609_msgs::srv::MoveSplineJoint_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSplineJoint_Request_time acc(::doosan_m0609_msgs::srv::MoveSplineJoint_Request::_acc_type arg)
  {
    msg_.acc = std::move(arg);
    return Init_MoveSplineJoint_Request_time(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveSplineJoint_Request msg_;
};

class Init_MoveSplineJoint_Request_vel
{
public:
  explicit Init_MoveSplineJoint_Request_vel(::doosan_m0609_msgs::srv::MoveSplineJoint_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSplineJoint_Request_acc vel(::doosan_m0609_msgs::srv::MoveSplineJoint_Request::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_MoveSplineJoint_Request_acc(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveSplineJoint_Request msg_;
};

class Init_MoveSplineJoint_Request_pos_cnt
{
public:
  explicit Init_MoveSplineJoint_Request_pos_cnt(::doosan_m0609_msgs::srv::MoveSplineJoint_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSplineJoint_Request_vel pos_cnt(::doosan_m0609_msgs::srv::MoveSplineJoint_Request::_pos_cnt_type arg)
  {
    msg_.pos_cnt = std::move(arg);
    return Init_MoveSplineJoint_Request_vel(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveSplineJoint_Request msg_;
};

class Init_MoveSplineJoint_Request_pos
{
public:
  Init_MoveSplineJoint_Request_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveSplineJoint_Request_pos_cnt pos(::doosan_m0609_msgs::srv::MoveSplineJoint_Request::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_MoveSplineJoint_Request_pos_cnt(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveSplineJoint_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::MoveSplineJoint_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_MoveSplineJoint_Request_pos();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_MoveSplineJoint_Response_success
{
public:
  Init_MoveSplineJoint_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::MoveSplineJoint_Response success(::doosan_m0609_msgs::srv::MoveSplineJoint_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveSplineJoint_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::MoveSplineJoint_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_MoveSplineJoint_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_SPLINE_JOINT__BUILDER_HPP_

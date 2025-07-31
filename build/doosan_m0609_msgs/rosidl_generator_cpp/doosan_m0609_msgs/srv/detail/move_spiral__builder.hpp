// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/MoveSpiral.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_SPIRAL__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_SPIRAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/move_spiral__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_MoveSpiral_Request_sync_type
{
public:
  explicit Init_MoveSpiral_Request_sync_type(::doosan_m0609_msgs::srv::MoveSpiral_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::MoveSpiral_Request sync_type(::doosan_m0609_msgs::srv::MoveSpiral_Request::_sync_type_type arg)
  {
    msg_.sync_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveSpiral_Request msg_;
};

class Init_MoveSpiral_Request_ref
{
public:
  explicit Init_MoveSpiral_Request_ref(::doosan_m0609_msgs::srv::MoveSpiral_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSpiral_Request_sync_type ref(::doosan_m0609_msgs::srv::MoveSpiral_Request::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return Init_MoveSpiral_Request_sync_type(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveSpiral_Request msg_;
};

class Init_MoveSpiral_Request_task_axis
{
public:
  explicit Init_MoveSpiral_Request_task_axis(::doosan_m0609_msgs::srv::MoveSpiral_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSpiral_Request_ref task_axis(::doosan_m0609_msgs::srv::MoveSpiral_Request::_task_axis_type arg)
  {
    msg_.task_axis = std::move(arg);
    return Init_MoveSpiral_Request_ref(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveSpiral_Request msg_;
};

class Init_MoveSpiral_Request_time
{
public:
  explicit Init_MoveSpiral_Request_time(::doosan_m0609_msgs::srv::MoveSpiral_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSpiral_Request_task_axis time(::doosan_m0609_msgs::srv::MoveSpiral_Request::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_MoveSpiral_Request_task_axis(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveSpiral_Request msg_;
};

class Init_MoveSpiral_Request_acc
{
public:
  explicit Init_MoveSpiral_Request_acc(::doosan_m0609_msgs::srv::MoveSpiral_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSpiral_Request_time acc(::doosan_m0609_msgs::srv::MoveSpiral_Request::_acc_type arg)
  {
    msg_.acc = std::move(arg);
    return Init_MoveSpiral_Request_time(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveSpiral_Request msg_;
};

class Init_MoveSpiral_Request_vel
{
public:
  explicit Init_MoveSpiral_Request_vel(::doosan_m0609_msgs::srv::MoveSpiral_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSpiral_Request_acc vel(::doosan_m0609_msgs::srv::MoveSpiral_Request::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_MoveSpiral_Request_acc(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveSpiral_Request msg_;
};

class Init_MoveSpiral_Request_max_length
{
public:
  explicit Init_MoveSpiral_Request_max_length(::doosan_m0609_msgs::srv::MoveSpiral_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSpiral_Request_vel max_length(::doosan_m0609_msgs::srv::MoveSpiral_Request::_max_length_type arg)
  {
    msg_.max_length = std::move(arg);
    return Init_MoveSpiral_Request_vel(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveSpiral_Request msg_;
};

class Init_MoveSpiral_Request_max_radius
{
public:
  explicit Init_MoveSpiral_Request_max_radius(::doosan_m0609_msgs::srv::MoveSpiral_Request & msg)
  : msg_(msg)
  {}
  Init_MoveSpiral_Request_max_length max_radius(::doosan_m0609_msgs::srv::MoveSpiral_Request::_max_radius_type arg)
  {
    msg_.max_radius = std::move(arg);
    return Init_MoveSpiral_Request_max_length(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveSpiral_Request msg_;
};

class Init_MoveSpiral_Request_revolution
{
public:
  Init_MoveSpiral_Request_revolution()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveSpiral_Request_max_radius revolution(::doosan_m0609_msgs::srv::MoveSpiral_Request::_revolution_type arg)
  {
    msg_.revolution = std::move(arg);
    return Init_MoveSpiral_Request_max_radius(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveSpiral_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::MoveSpiral_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_MoveSpiral_Request_revolution();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_MoveSpiral_Response_success
{
public:
  Init_MoveSpiral_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::MoveSpiral_Response success(::doosan_m0609_msgs::srv::MoveSpiral_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::MoveSpiral_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::MoveSpiral_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_MoveSpiral_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_SPIRAL__BUILDER_HPP_

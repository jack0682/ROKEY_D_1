// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_controller:srv/MoveJ.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_CONTROLLER__SRV__DETAIL__MOVE_J__BUILDER_HPP_
#define DOOSAN_M0609_CONTROLLER__SRV__DETAIL__MOVE_J__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_controller/srv/detail/move_j__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_controller
{

namespace srv
{

namespace builder
{

class Init_MoveJ_Request_time_out
{
public:
  explicit Init_MoveJ_Request_time_out(::doosan_m0609_controller::srv::MoveJ_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_controller::srv::MoveJ_Request time_out(::doosan_m0609_controller::srv::MoveJ_Request::_time_out_type arg)
  {
    msg_.time_out = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_controller::srv::MoveJ_Request msg_;
};

class Init_MoveJ_Request_acceleration_ratio
{
public:
  explicit Init_MoveJ_Request_acceleration_ratio(::doosan_m0609_controller::srv::MoveJ_Request & msg)
  : msg_(msg)
  {}
  Init_MoveJ_Request_time_out acceleration_ratio(::doosan_m0609_controller::srv::MoveJ_Request::_acceleration_ratio_type arg)
  {
    msg_.acceleration_ratio = std::move(arg);
    return Init_MoveJ_Request_time_out(msg_);
  }

private:
  ::doosan_m0609_controller::srv::MoveJ_Request msg_;
};

class Init_MoveJ_Request_velocity_ratio
{
public:
  explicit Init_MoveJ_Request_velocity_ratio(::doosan_m0609_controller::srv::MoveJ_Request & msg)
  : msg_(msg)
  {}
  Init_MoveJ_Request_acceleration_ratio velocity_ratio(::doosan_m0609_controller::srv::MoveJ_Request::_velocity_ratio_type arg)
  {
    msg_.velocity_ratio = std::move(arg);
    return Init_MoveJ_Request_acceleration_ratio(msg_);
  }

private:
  ::doosan_m0609_controller::srv::MoveJ_Request msg_;
};

class Init_MoveJ_Request_target_joints
{
public:
  Init_MoveJ_Request_target_joints()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveJ_Request_velocity_ratio target_joints(::doosan_m0609_controller::srv::MoveJ_Request::_target_joints_type arg)
  {
    msg_.target_joints = std::move(arg);
    return Init_MoveJ_Request_velocity_ratio(msg_);
  }

private:
  ::doosan_m0609_controller::srv::MoveJ_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_controller::srv::MoveJ_Request>()
{
  return doosan_m0609_controller::srv::builder::Init_MoveJ_Request_target_joints();
}

}  // namespace doosan_m0609_controller


namespace doosan_m0609_controller
{

namespace srv
{

namespace builder
{

class Init_MoveJ_Response_message
{
public:
  explicit Init_MoveJ_Response_message(::doosan_m0609_controller::srv::MoveJ_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_controller::srv::MoveJ_Response message(::doosan_m0609_controller::srv::MoveJ_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_controller::srv::MoveJ_Response msg_;
};

class Init_MoveJ_Response_success
{
public:
  Init_MoveJ_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveJ_Response_message success(::doosan_m0609_controller::srv::MoveJ_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_MoveJ_Response_message(msg_);
  }

private:
  ::doosan_m0609_controller::srv::MoveJ_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_controller::srv::MoveJ_Response>()
{
  return doosan_m0609_controller::srv::builder::Init_MoveJ_Response_success();
}

}  // namespace doosan_m0609_controller

#endif  // DOOSAN_M0609_CONTROLLER__SRV__DETAIL__MOVE_J__BUILDER_HPP_

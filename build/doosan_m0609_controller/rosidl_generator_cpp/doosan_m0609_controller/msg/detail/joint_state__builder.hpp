// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_controller:msg/JointState.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_CONTROLLER__MSG__DETAIL__JOINT_STATE__BUILDER_HPP_
#define DOOSAN_M0609_CONTROLLER__MSG__DETAIL__JOINT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_controller/msg/detail/joint_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_controller
{

namespace msg
{

namespace builder
{

class Init_JointState_effort
{
public:
  explicit Init_JointState_effort(::doosan_m0609_controller::msg::JointState & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_controller::msg::JointState effort(::doosan_m0609_controller::msg::JointState::_effort_type arg)
  {
    msg_.effort = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_controller::msg::JointState msg_;
};

class Init_JointState_velocity
{
public:
  explicit Init_JointState_velocity(::doosan_m0609_controller::msg::JointState & msg)
  : msg_(msg)
  {}
  Init_JointState_effort velocity(::doosan_m0609_controller::msg::JointState::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_JointState_effort(msg_);
  }

private:
  ::doosan_m0609_controller::msg::JointState msg_;
};

class Init_JointState_position
{
public:
  explicit Init_JointState_position(::doosan_m0609_controller::msg::JointState & msg)
  : msg_(msg)
  {}
  Init_JointState_velocity position(::doosan_m0609_controller::msg::JointState::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_JointState_velocity(msg_);
  }

private:
  ::doosan_m0609_controller::msg::JointState msg_;
};

class Init_JointState_header
{
public:
  Init_JointState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JointState_position header(::doosan_m0609_controller::msg::JointState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_JointState_position(msg_);
  }

private:
  ::doosan_m0609_controller::msg::JointState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_controller::msg::JointState>()
{
  return doosan_m0609_controller::msg::builder::Init_JointState_header();
}

}  // namespace doosan_m0609_controller

#endif  // DOOSAN_M0609_CONTROLLER__MSG__DETAIL__JOINT_STATE__BUILDER_HPP_

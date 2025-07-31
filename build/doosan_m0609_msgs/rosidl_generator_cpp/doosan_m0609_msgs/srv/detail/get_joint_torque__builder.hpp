// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/GetJointTorque.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_JOINT_TORQUE__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_JOINT_TORQUE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/get_joint_torque__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetJointTorque_Request>()
{
  return ::doosan_m0609_msgs::srv::GetJointTorque_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetJointTorque_Response_success
{
public:
  explicit Init_GetJointTorque_Response_success(::doosan_m0609_msgs::srv::GetJointTorque_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::GetJointTorque_Response success(::doosan_m0609_msgs::srv::GetJointTorque_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetJointTorque_Response msg_;
};

class Init_GetJointTorque_Response_jts
{
public:
  Init_GetJointTorque_Response_jts()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetJointTorque_Response_success jts(::doosan_m0609_msgs::srv::GetJointTorque_Response::_jts_type arg)
  {
    msg_.jts = std::move(arg);
    return Init_GetJointTorque_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetJointTorque_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetJointTorque_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetJointTorque_Response_jts();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_JOINT_TORQUE__BUILDER_HPP_

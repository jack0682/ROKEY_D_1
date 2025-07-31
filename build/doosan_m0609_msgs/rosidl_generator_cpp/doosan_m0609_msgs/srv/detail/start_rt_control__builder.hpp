// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/StartRtControl.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__START_RT_CONTROL__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__START_RT_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/start_rt_control__struct.hpp"
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
auto build<::doosan_m0609_msgs::srv::StartRtControl_Request>()
{
  return ::doosan_m0609_msgs::srv::StartRtControl_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_StartRtControl_Response_success
{
public:
  Init_StartRtControl_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::StartRtControl_Response success(::doosan_m0609_msgs::srv::StartRtControl_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::StartRtControl_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::StartRtControl_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_StartRtControl_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__START_RT_CONTROL__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/GetRtControlOutputVersionList.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_RT_CONTROL_OUTPUT_VERSION_LIST__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_RT_CONTROL_OUTPUT_VERSION_LIST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/get_rt_control_output_version_list__struct.hpp"
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
auto build<::doosan_m0609_msgs::srv::GetRtControlOutputVersionList_Request>()
{
  return ::doosan_m0609_msgs::srv::GetRtControlOutputVersionList_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetRtControlOutputVersionList_Response_version
{
public:
  explicit Init_GetRtControlOutputVersionList_Response_version(::doosan_m0609_msgs::srv::GetRtControlOutputVersionList_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::GetRtControlOutputVersionList_Response version(::doosan_m0609_msgs::srv::GetRtControlOutputVersionList_Response::_version_type arg)
  {
    msg_.version = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetRtControlOutputVersionList_Response msg_;
};

class Init_GetRtControlOutputVersionList_Response_success
{
public:
  Init_GetRtControlOutputVersionList_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetRtControlOutputVersionList_Response_version success(::doosan_m0609_msgs::srv::GetRtControlOutputVersionList_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GetRtControlOutputVersionList_Response_version(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetRtControlOutputVersionList_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetRtControlOutputVersionList_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetRtControlOutputVersionList_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_RT_CONTROL_OUTPUT_VERSION_LIST__BUILDER_HPP_

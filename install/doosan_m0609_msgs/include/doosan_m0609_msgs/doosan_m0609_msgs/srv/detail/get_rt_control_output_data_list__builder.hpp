// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/GetRtControlOutputDataList.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_RT_CONTROL_OUTPUT_DATA_LIST__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_RT_CONTROL_OUTPUT_DATA_LIST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/get_rt_control_output_data_list__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetRtControlOutputDataList_Request_version
{
public:
  Init_GetRtControlOutputDataList_Request_version()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::GetRtControlOutputDataList_Request version(::doosan_m0609_msgs::srv::GetRtControlOutputDataList_Request::_version_type arg)
  {
    msg_.version = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetRtControlOutputDataList_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetRtControlOutputDataList_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetRtControlOutputDataList_Request_version();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetRtControlOutputDataList_Response_data
{
public:
  explicit Init_GetRtControlOutputDataList_Response_data(::doosan_m0609_msgs::srv::GetRtControlOutputDataList_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::GetRtControlOutputDataList_Response data(::doosan_m0609_msgs::srv::GetRtControlOutputDataList_Response::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetRtControlOutputDataList_Response msg_;
};

class Init_GetRtControlOutputDataList_Response_success
{
public:
  Init_GetRtControlOutputDataList_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetRtControlOutputDataList_Response_data success(::doosan_m0609_msgs::srv::GetRtControlOutputDataList_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GetRtControlOutputDataList_Response_data(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetRtControlOutputDataList_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetRtControlOutputDataList_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetRtControlOutputDataList_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_RT_CONTROL_OUTPUT_DATA_LIST__BUILDER_HPP_

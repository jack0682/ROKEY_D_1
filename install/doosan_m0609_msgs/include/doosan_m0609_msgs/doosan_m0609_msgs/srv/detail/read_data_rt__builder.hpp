// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/ReadDataRt.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__READ_DATA_RT__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__READ_DATA_RT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/read_data_rt__struct.hpp"
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
auto build<::doosan_m0609_msgs::srv::ReadDataRt_Request>()
{
  return ::doosan_m0609_msgs::srv::ReadDataRt_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ReadDataRt_Response_data
{
public:
  Init_ReadDataRt_Response_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::ReadDataRt_Response data(::doosan_m0609_msgs::srv::ReadDataRt_Response::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ReadDataRt_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ReadDataRt_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_ReadDataRt_Response_data();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__READ_DATA_RT__BUILDER_HPP_

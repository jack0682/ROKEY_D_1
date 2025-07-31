// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/TaskComplianceCtrl.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__TASK_COMPLIANCE_CTRL__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__TASK_COMPLIANCE_CTRL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/task_compliance_ctrl__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_TaskComplianceCtrl_Request_time
{
public:
  explicit Init_TaskComplianceCtrl_Request_time(::doosan_m0609_msgs::srv::TaskComplianceCtrl_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::TaskComplianceCtrl_Request time(::doosan_m0609_msgs::srv::TaskComplianceCtrl_Request::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::TaskComplianceCtrl_Request msg_;
};

class Init_TaskComplianceCtrl_Request_ref
{
public:
  explicit Init_TaskComplianceCtrl_Request_ref(::doosan_m0609_msgs::srv::TaskComplianceCtrl_Request & msg)
  : msg_(msg)
  {}
  Init_TaskComplianceCtrl_Request_time ref(::doosan_m0609_msgs::srv::TaskComplianceCtrl_Request::_ref_type arg)
  {
    msg_.ref = std::move(arg);
    return Init_TaskComplianceCtrl_Request_time(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::TaskComplianceCtrl_Request msg_;
};

class Init_TaskComplianceCtrl_Request_stx
{
public:
  Init_TaskComplianceCtrl_Request_stx()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskComplianceCtrl_Request_ref stx(::doosan_m0609_msgs::srv::TaskComplianceCtrl_Request::_stx_type arg)
  {
    msg_.stx = std::move(arg);
    return Init_TaskComplianceCtrl_Request_ref(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::TaskComplianceCtrl_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::TaskComplianceCtrl_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_TaskComplianceCtrl_Request_stx();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_TaskComplianceCtrl_Response_success
{
public:
  Init_TaskComplianceCtrl_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::TaskComplianceCtrl_Response success(::doosan_m0609_msgs::srv::TaskComplianceCtrl_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::TaskComplianceCtrl_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::TaskComplianceCtrl_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_TaskComplianceCtrl_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__TASK_COMPLIANCE_CTRL__BUILDER_HPP_

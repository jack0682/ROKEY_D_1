// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/WriteDataRt.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__WRITE_DATA_RT__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__WRITE_DATA_RT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/write_data_rt__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_WriteDataRt_Request_external_analog_output
{
public:
  explicit Init_WriteDataRt_Request_external_analog_output(::doosan_m0609_msgs::srv::WriteDataRt_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::WriteDataRt_Request external_analog_output(::doosan_m0609_msgs::srv::WriteDataRt_Request::_external_analog_output_type arg)
  {
    msg_.external_analog_output = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::WriteDataRt_Request msg_;
};

class Init_WriteDataRt_Request_external_analog_input
{
public:
  explicit Init_WriteDataRt_Request_external_analog_input(::doosan_m0609_msgs::srv::WriteDataRt_Request & msg)
  : msg_(msg)
  {}
  Init_WriteDataRt_Request_external_analog_output external_analog_input(::doosan_m0609_msgs::srv::WriteDataRt_Request::_external_analog_input_type arg)
  {
    msg_.external_analog_input = std::move(arg);
    return Init_WriteDataRt_Request_external_analog_output(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::WriteDataRt_Request msg_;
};

class Init_WriteDataRt_Request_external_digital_output
{
public:
  explicit Init_WriteDataRt_Request_external_digital_output(::doosan_m0609_msgs::srv::WriteDataRt_Request & msg)
  : msg_(msg)
  {}
  Init_WriteDataRt_Request_external_analog_input external_digital_output(::doosan_m0609_msgs::srv::WriteDataRt_Request::_external_digital_output_type arg)
  {
    msg_.external_digital_output = std::move(arg);
    return Init_WriteDataRt_Request_external_analog_input(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::WriteDataRt_Request msg_;
};

class Init_WriteDataRt_Request_external_digital_input
{
public:
  explicit Init_WriteDataRt_Request_external_digital_input(::doosan_m0609_msgs::srv::WriteDataRt_Request & msg)
  : msg_(msg)
  {}
  Init_WriteDataRt_Request_external_digital_output external_digital_input(::doosan_m0609_msgs::srv::WriteDataRt_Request::_external_digital_input_type arg)
  {
    msg_.external_digital_input = std::move(arg);
    return Init_WriteDataRt_Request_external_digital_output(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::WriteDataRt_Request msg_;
};

class Init_WriteDataRt_Request_external_force_torque
{
public:
  Init_WriteDataRt_Request_external_force_torque()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WriteDataRt_Request_external_digital_input external_force_torque(::doosan_m0609_msgs::srv::WriteDataRt_Request::_external_force_torque_type arg)
  {
    msg_.external_force_torque = std::move(arg);
    return Init_WriteDataRt_Request_external_digital_input(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::WriteDataRt_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::WriteDataRt_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_WriteDataRt_Request_external_force_torque();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_WriteDataRt_Response_success
{
public:
  Init_WriteDataRt_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::WriteDataRt_Response success(::doosan_m0609_msgs::srv::WriteDataRt_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::WriteDataRt_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::WriteDataRt_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_WriteDataRt_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__WRITE_DATA_RT__BUILDER_HPP_

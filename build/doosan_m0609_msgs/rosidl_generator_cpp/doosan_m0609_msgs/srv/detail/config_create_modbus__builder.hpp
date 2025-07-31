// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/ConfigCreateModbus.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_CREATE_MODBUS__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_CREATE_MODBUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/config_create_modbus__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ConfigCreateModbus_Request_slave_id
{
public:
  explicit Init_ConfigCreateModbus_Request_slave_id(::doosan_m0609_msgs::srv::ConfigCreateModbus_Request & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::ConfigCreateModbus_Request slave_id(::doosan_m0609_msgs::srv::ConfigCreateModbus_Request::_slave_id_type arg)
  {
    msg_.slave_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConfigCreateModbus_Request msg_;
};

class Init_ConfigCreateModbus_Request_value
{
public:
  explicit Init_ConfigCreateModbus_Request_value(::doosan_m0609_msgs::srv::ConfigCreateModbus_Request & msg)
  : msg_(msg)
  {}
  Init_ConfigCreateModbus_Request_slave_id value(::doosan_m0609_msgs::srv::ConfigCreateModbus_Request::_value_type arg)
  {
    msg_.value = std::move(arg);
    return Init_ConfigCreateModbus_Request_slave_id(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConfigCreateModbus_Request msg_;
};

class Init_ConfigCreateModbus_Request_index
{
public:
  explicit Init_ConfigCreateModbus_Request_index(::doosan_m0609_msgs::srv::ConfigCreateModbus_Request & msg)
  : msg_(msg)
  {}
  Init_ConfigCreateModbus_Request_value index(::doosan_m0609_msgs::srv::ConfigCreateModbus_Request::_index_type arg)
  {
    msg_.index = std::move(arg);
    return Init_ConfigCreateModbus_Request_value(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConfigCreateModbus_Request msg_;
};

class Init_ConfigCreateModbus_Request_reg_type
{
public:
  explicit Init_ConfigCreateModbus_Request_reg_type(::doosan_m0609_msgs::srv::ConfigCreateModbus_Request & msg)
  : msg_(msg)
  {}
  Init_ConfigCreateModbus_Request_index reg_type(::doosan_m0609_msgs::srv::ConfigCreateModbus_Request::_reg_type_type arg)
  {
    msg_.reg_type = std::move(arg);
    return Init_ConfigCreateModbus_Request_index(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConfigCreateModbus_Request msg_;
};

class Init_ConfigCreateModbus_Request_port
{
public:
  explicit Init_ConfigCreateModbus_Request_port(::doosan_m0609_msgs::srv::ConfigCreateModbus_Request & msg)
  : msg_(msg)
  {}
  Init_ConfigCreateModbus_Request_reg_type port(::doosan_m0609_msgs::srv::ConfigCreateModbus_Request::_port_type arg)
  {
    msg_.port = std::move(arg);
    return Init_ConfigCreateModbus_Request_reg_type(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConfigCreateModbus_Request msg_;
};

class Init_ConfigCreateModbus_Request_ip
{
public:
  explicit Init_ConfigCreateModbus_Request_ip(::doosan_m0609_msgs::srv::ConfigCreateModbus_Request & msg)
  : msg_(msg)
  {}
  Init_ConfigCreateModbus_Request_port ip(::doosan_m0609_msgs::srv::ConfigCreateModbus_Request::_ip_type arg)
  {
    msg_.ip = std::move(arg);
    return Init_ConfigCreateModbus_Request_port(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConfigCreateModbus_Request msg_;
};

class Init_ConfigCreateModbus_Request_name
{
public:
  Init_ConfigCreateModbus_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ConfigCreateModbus_Request_ip name(::doosan_m0609_msgs::srv::ConfigCreateModbus_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_ConfigCreateModbus_Request_ip(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConfigCreateModbus_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ConfigCreateModbus_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_ConfigCreateModbus_Request_name();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_ConfigCreateModbus_Response_success
{
public:
  Init_ConfigCreateModbus_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::ConfigCreateModbus_Response success(::doosan_m0609_msgs::srv::ConfigCreateModbus_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::ConfigCreateModbus_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::ConfigCreateModbus_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_ConfigCreateModbus_Response_success();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_CREATE_MODBUS__BUILDER_HPP_

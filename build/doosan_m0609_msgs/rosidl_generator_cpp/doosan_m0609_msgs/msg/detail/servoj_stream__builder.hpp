// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:msg/ServojStream.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__SERVOJ_STREAM__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__SERVOJ_STREAM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/msg/detail/servoj_stream__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace msg
{

namespace builder
{

class Init_ServojStream_mode
{
public:
  explicit Init_ServojStream_mode(::doosan_m0609_msgs::msg::ServojStream & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::msg::ServojStream mode(::doosan_m0609_msgs::msg::ServojStream::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::ServojStream msg_;
};

class Init_ServojStream_time
{
public:
  explicit Init_ServojStream_time(::doosan_m0609_msgs::msg::ServojStream & msg)
  : msg_(msg)
  {}
  Init_ServojStream_mode time(::doosan_m0609_msgs::msg::ServojStream::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_ServojStream_mode(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::ServojStream msg_;
};

class Init_ServojStream_acc
{
public:
  explicit Init_ServojStream_acc(::doosan_m0609_msgs::msg::ServojStream & msg)
  : msg_(msg)
  {}
  Init_ServojStream_time acc(::doosan_m0609_msgs::msg::ServojStream::_acc_type arg)
  {
    msg_.acc = std::move(arg);
    return Init_ServojStream_time(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::ServojStream msg_;
};

class Init_ServojStream_vel
{
public:
  explicit Init_ServojStream_vel(::doosan_m0609_msgs::msg::ServojStream & msg)
  : msg_(msg)
  {}
  Init_ServojStream_acc vel(::doosan_m0609_msgs::msg::ServojStream::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_ServojStream_acc(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::ServojStream msg_;
};

class Init_ServojStream_pos
{
public:
  Init_ServojStream_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ServojStream_vel pos(::doosan_m0609_msgs::msg::ServojStream::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_ServojStream_vel(msg_);
  }

private:
  ::doosan_m0609_msgs::msg::ServojStream msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::msg::ServojStream>()
{
  return doosan_m0609_msgs::msg::builder::Init_ServojStream_pos();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__SERVOJ_STREAM__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/GetSolutionSpace.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_SOLUTION_SPACE__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_SOLUTION_SPACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/get_solution_space__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetSolutionSpace_Request_pos
{
public:
  Init_GetSolutionSpace_Request_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::doosan_m0609_msgs::srv::GetSolutionSpace_Request pos(::doosan_m0609_msgs::srv::GetSolutionSpace_Request::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetSolutionSpace_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetSolutionSpace_Request>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetSolutionSpace_Request_pos();
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetSolutionSpace_Response_success
{
public:
  explicit Init_GetSolutionSpace_Response_success(::doosan_m0609_msgs::srv::GetSolutionSpace_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::GetSolutionSpace_Response success(::doosan_m0609_msgs::srv::GetSolutionSpace_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetSolutionSpace_Response msg_;
};

class Init_GetSolutionSpace_Response_sol_space
{
public:
  Init_GetSolutionSpace_Response_sol_space()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetSolutionSpace_Response_success sol_space(::doosan_m0609_msgs::srv::GetSolutionSpace_Response::_sol_space_type arg)
  {
    msg_.sol_space = std::move(arg);
    return Init_GetSolutionSpace_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetSolutionSpace_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetSolutionSpace_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetSolutionSpace_Response_sol_space();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_SOLUTION_SPACE__BUILDER_HPP_

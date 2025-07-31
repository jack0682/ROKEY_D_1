// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from doosan_m0609_msgs:srv/GetCurrentSolutionSpace.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CURRENT_SOLUTION_SPACE__BUILDER_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CURRENT_SOLUTION_SPACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "doosan_m0609_msgs/srv/detail/get_current_solution_space__struct.hpp"
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
auto build<::doosan_m0609_msgs::srv::GetCurrentSolutionSpace_Request>()
{
  return ::doosan_m0609_msgs::srv::GetCurrentSolutionSpace_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace doosan_m0609_msgs


namespace doosan_m0609_msgs
{

namespace srv
{

namespace builder
{

class Init_GetCurrentSolutionSpace_Response_success
{
public:
  explicit Init_GetCurrentSolutionSpace_Response_success(::doosan_m0609_msgs::srv::GetCurrentSolutionSpace_Response & msg)
  : msg_(msg)
  {}
  ::doosan_m0609_msgs::srv::GetCurrentSolutionSpace_Response success(::doosan_m0609_msgs::srv::GetCurrentSolutionSpace_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetCurrentSolutionSpace_Response msg_;
};

class Init_GetCurrentSolutionSpace_Response_sol_space
{
public:
  Init_GetCurrentSolutionSpace_Response_sol_space()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetCurrentSolutionSpace_Response_success sol_space(::doosan_m0609_msgs::srv::GetCurrentSolutionSpace_Response::_sol_space_type arg)
  {
    msg_.sol_space = std::move(arg);
    return Init_GetCurrentSolutionSpace_Response_success(msg_);
  }

private:
  ::doosan_m0609_msgs::srv::GetCurrentSolutionSpace_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::doosan_m0609_msgs::srv::GetCurrentSolutionSpace_Response>()
{
  return doosan_m0609_msgs::srv::builder::Init_GetCurrentSolutionSpace_Response_sol_space();
}

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_CURRENT_SOLUTION_SPACE__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from doosan_m0609_msgs:srv/GetSolutionSpace.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__GET_SOLUTION_SPACE__STRUCT_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__GET_SOLUTION_SPACE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__doosan_m0609_msgs__srv__GetSolutionSpace_Request __attribute__((deprecated))
#else
# define DEPRECATED__doosan_m0609_msgs__srv__GetSolutionSpace_Request __declspec(deprecated)
#endif

namespace doosan_m0609_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetSolutionSpace_Request_
{
  using Type = GetSolutionSpace_Request_<ContainerAllocator>;

  explicit GetSolutionSpace_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 6>::iterator, double>(this->pos.begin(), this->pos.end(), 0.0);
    }
  }

  explicit GetSolutionSpace_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pos(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 6>::iterator, double>(this->pos.begin(), this->pos.end(), 0.0);
    }
  }

  // field types and members
  using _pos_type =
    std::array<double, 6>;
  _pos_type pos;

  // setters for named parameter idiom
  Type & set__pos(
    const std::array<double, 6> & _arg)
  {
    this->pos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    doosan_m0609_msgs::srv::GetSolutionSpace_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const doosan_m0609_msgs::srv::GetSolutionSpace_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::GetSolutionSpace_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::GetSolutionSpace_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::GetSolutionSpace_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::GetSolutionSpace_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::GetSolutionSpace_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::GetSolutionSpace_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::GetSolutionSpace_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::GetSolutionSpace_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doosan_m0609_msgs__srv__GetSolutionSpace_Request
    std::shared_ptr<doosan_m0609_msgs::srv::GetSolutionSpace_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doosan_m0609_msgs__srv__GetSolutionSpace_Request
    std::shared_ptr<doosan_m0609_msgs::srv::GetSolutionSpace_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetSolutionSpace_Request_ & other) const
  {
    if (this->pos != other.pos) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetSolutionSpace_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetSolutionSpace_Request_

// alias to use template instance with default allocator
using GetSolutionSpace_Request =
  doosan_m0609_msgs::srv::GetSolutionSpace_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace doosan_m0609_msgs


#ifndef _WIN32
# define DEPRECATED__doosan_m0609_msgs__srv__GetSolutionSpace_Response __attribute__((deprecated))
#else
# define DEPRECATED__doosan_m0609_msgs__srv__GetSolutionSpace_Response __declspec(deprecated)
#endif

namespace doosan_m0609_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetSolutionSpace_Response_
{
  using Type = GetSolutionSpace_Response_<ContainerAllocator>;

  explicit GetSolutionSpace_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sol_space = 0;
      this->success = false;
    }
  }

  explicit GetSolutionSpace_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sol_space = 0;
      this->success = false;
    }
  }

  // field types and members
  using _sol_space_type =
    int8_t;
  _sol_space_type sol_space;
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__sol_space(
    const int8_t & _arg)
  {
    this->sol_space = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    doosan_m0609_msgs::srv::GetSolutionSpace_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const doosan_m0609_msgs::srv::GetSolutionSpace_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::GetSolutionSpace_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::GetSolutionSpace_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::GetSolutionSpace_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::GetSolutionSpace_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::GetSolutionSpace_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::GetSolutionSpace_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::GetSolutionSpace_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::GetSolutionSpace_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doosan_m0609_msgs__srv__GetSolutionSpace_Response
    std::shared_ptr<doosan_m0609_msgs::srv::GetSolutionSpace_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doosan_m0609_msgs__srv__GetSolutionSpace_Response
    std::shared_ptr<doosan_m0609_msgs::srv::GetSolutionSpace_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetSolutionSpace_Response_ & other) const
  {
    if (this->sol_space != other.sol_space) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetSolutionSpace_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetSolutionSpace_Response_

// alias to use template instance with default allocator
using GetSolutionSpace_Response =
  doosan_m0609_msgs::srv::GetSolutionSpace_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace doosan_m0609_msgs

namespace doosan_m0609_msgs
{

namespace srv
{

struct GetSolutionSpace
{
  using Request = doosan_m0609_msgs::srv::GetSolutionSpace_Request;
  using Response = doosan_m0609_msgs::srv::GetSolutionSpace_Response;
};

}  // namespace srv

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__GET_SOLUTION_SPACE__STRUCT_HPP_

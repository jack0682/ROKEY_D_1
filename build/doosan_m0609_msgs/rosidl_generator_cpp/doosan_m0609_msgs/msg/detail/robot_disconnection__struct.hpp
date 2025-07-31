// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from doosan_m0609_msgs:msg/RobotDisconnection.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_DISCONNECTION__STRUCT_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_DISCONNECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__doosan_m0609_msgs__msg__RobotDisconnection __attribute__((deprecated))
#else
# define DEPRECATED__doosan_m0609_msgs__msg__RobotDisconnection __declspec(deprecated)
#endif

namespace doosan_m0609_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotDisconnection_
{
  using Type = RobotDisconnection_<ContainerAllocator>;

  explicit RobotDisconnection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit RobotDisconnection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    doosan_m0609_msgs::msg::RobotDisconnection_<ContainerAllocator> *;
  using ConstRawPtr =
    const doosan_m0609_msgs::msg::RobotDisconnection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doosan_m0609_msgs::msg::RobotDisconnection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doosan_m0609_msgs::msg::RobotDisconnection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::msg::RobotDisconnection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::msg::RobotDisconnection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::msg::RobotDisconnection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::msg::RobotDisconnection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doosan_m0609_msgs::msg::RobotDisconnection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doosan_m0609_msgs::msg::RobotDisconnection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doosan_m0609_msgs__msg__RobotDisconnection
    std::shared_ptr<doosan_m0609_msgs::msg::RobotDisconnection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doosan_m0609_msgs__msg__RobotDisconnection
    std::shared_ptr<doosan_m0609_msgs::msg::RobotDisconnection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotDisconnection_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotDisconnection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotDisconnection_

// alias to use template instance with default allocator
using RobotDisconnection =
  doosan_m0609_msgs::msg::RobotDisconnection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__ROBOT_DISCONNECTION__STRUCT_HPP_

// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from doosan_m0609_controller:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_CONTROLLER__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_
#define DOOSAN_M0609_CONTROLLER__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__doosan_m0609_controller__msg__RobotStatus __attribute__((deprecated))
#else
# define DEPRECATED__doosan_m0609_controller__msg__RobotStatus __declspec(deprecated)
#endif

namespace doosan_m0609_controller
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotStatus_
{
  using Type = RobotStatus_<ContainerAllocator>;

  explicit RobotStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_connected = false;
      this->is_enabled = false;
      this->has_control_authority = false;
      this->robot_state = "";
      this->error_message = "";
    }
  }

  explicit RobotStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    robot_state(_alloc),
    error_message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_connected = false;
      this->is_enabled = false;
      this->has_control_authority = false;
      this->robot_state = "";
      this->error_message = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _is_connected_type =
    bool;
  _is_connected_type is_connected;
  using _is_enabled_type =
    bool;
  _is_enabled_type is_enabled;
  using _has_control_authority_type =
    bool;
  _has_control_authority_type has_control_authority;
  using _robot_state_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_state_type robot_state;
  using _error_message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _error_message_type error_message;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__is_connected(
    const bool & _arg)
  {
    this->is_connected = _arg;
    return *this;
  }
  Type & set__is_enabled(
    const bool & _arg)
  {
    this->is_enabled = _arg;
    return *this;
  }
  Type & set__has_control_authority(
    const bool & _arg)
  {
    this->has_control_authority = _arg;
    return *this;
  }
  Type & set__robot_state(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_state = _arg;
    return *this;
  }
  Type & set__error_message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->error_message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    doosan_m0609_controller::msg::RobotStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const doosan_m0609_controller::msg::RobotStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doosan_m0609_controller::msg::RobotStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doosan_m0609_controller::msg::RobotStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_controller::msg::RobotStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_controller::msg::RobotStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_controller::msg::RobotStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_controller::msg::RobotStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doosan_m0609_controller::msg::RobotStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doosan_m0609_controller::msg::RobotStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doosan_m0609_controller__msg__RobotStatus
    std::shared_ptr<doosan_m0609_controller::msg::RobotStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doosan_m0609_controller__msg__RobotStatus
    std::shared_ptr<doosan_m0609_controller::msg::RobotStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->is_connected != other.is_connected) {
      return false;
    }
    if (this->is_enabled != other.is_enabled) {
      return false;
    }
    if (this->has_control_authority != other.has_control_authority) {
      return false;
    }
    if (this->robot_state != other.robot_state) {
      return false;
    }
    if (this->error_message != other.error_message) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotStatus_

// alias to use template instance with default allocator
using RobotStatus =
  doosan_m0609_controller::msg::RobotStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace doosan_m0609_controller

#endif  // DOOSAN_M0609_CONTROLLER__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_

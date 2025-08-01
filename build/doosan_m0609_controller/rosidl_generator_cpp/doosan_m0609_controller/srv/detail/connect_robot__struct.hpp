// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from doosan_m0609_controller:srv/ConnectRobot.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_CONTROLLER__SRV__DETAIL__CONNECT_ROBOT__STRUCT_HPP_
#define DOOSAN_M0609_CONTROLLER__SRV__DETAIL__CONNECT_ROBOT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__doosan_m0609_controller__srv__ConnectRobot_Request __attribute__((deprecated))
#else
# define DEPRECATED__doosan_m0609_controller__srv__ConnectRobot_Request __declspec(deprecated)
#endif

namespace doosan_m0609_controller
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ConnectRobot_Request_
{
  using Type = ConnectRobot_Request_<ContainerAllocator>;

  explicit ConnectRobot_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_ip = "";
      this->connect = false;
    }
  }

  explicit ConnectRobot_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_ip(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_ip = "";
      this->connect = false;
    }
  }

  // field types and members
  using _robot_ip_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_ip_type robot_ip;
  using _connect_type =
    bool;
  _connect_type connect;

  // setters for named parameter idiom
  Type & set__robot_ip(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_ip = _arg;
    return *this;
  }
  Type & set__connect(
    const bool & _arg)
  {
    this->connect = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    doosan_m0609_controller::srv::ConnectRobot_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const doosan_m0609_controller::srv::ConnectRobot_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doosan_m0609_controller::srv::ConnectRobot_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doosan_m0609_controller::srv::ConnectRobot_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_controller::srv::ConnectRobot_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_controller::srv::ConnectRobot_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_controller::srv::ConnectRobot_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_controller::srv::ConnectRobot_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doosan_m0609_controller::srv::ConnectRobot_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doosan_m0609_controller::srv::ConnectRobot_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doosan_m0609_controller__srv__ConnectRobot_Request
    std::shared_ptr<doosan_m0609_controller::srv::ConnectRobot_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doosan_m0609_controller__srv__ConnectRobot_Request
    std::shared_ptr<doosan_m0609_controller::srv::ConnectRobot_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ConnectRobot_Request_ & other) const
  {
    if (this->robot_ip != other.robot_ip) {
      return false;
    }
    if (this->connect != other.connect) {
      return false;
    }
    return true;
  }
  bool operator!=(const ConnectRobot_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ConnectRobot_Request_

// alias to use template instance with default allocator
using ConnectRobot_Request =
  doosan_m0609_controller::srv::ConnectRobot_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace doosan_m0609_controller


#ifndef _WIN32
# define DEPRECATED__doosan_m0609_controller__srv__ConnectRobot_Response __attribute__((deprecated))
#else
# define DEPRECATED__doosan_m0609_controller__srv__ConnectRobot_Response __declspec(deprecated)
#endif

namespace doosan_m0609_controller
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ConnectRobot_Response_
{
  using Type = ConnectRobot_Response_<ContainerAllocator>;

  explicit ConnectRobot_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit ConnectRobot_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    doosan_m0609_controller::srv::ConnectRobot_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const doosan_m0609_controller::srv::ConnectRobot_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doosan_m0609_controller::srv::ConnectRobot_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doosan_m0609_controller::srv::ConnectRobot_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_controller::srv::ConnectRobot_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_controller::srv::ConnectRobot_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_controller::srv::ConnectRobot_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_controller::srv::ConnectRobot_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doosan_m0609_controller::srv::ConnectRobot_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doosan_m0609_controller::srv::ConnectRobot_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doosan_m0609_controller__srv__ConnectRobot_Response
    std::shared_ptr<doosan_m0609_controller::srv::ConnectRobot_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doosan_m0609_controller__srv__ConnectRobot_Response
    std::shared_ptr<doosan_m0609_controller::srv::ConnectRobot_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ConnectRobot_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const ConnectRobot_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ConnectRobot_Response_

// alias to use template instance with default allocator
using ConnectRobot_Response =
  doosan_m0609_controller::srv::ConnectRobot_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace doosan_m0609_controller

namespace doosan_m0609_controller
{

namespace srv
{

struct ConnectRobot
{
  using Request = doosan_m0609_controller::srv::ConnectRobot_Request;
  using Response = doosan_m0609_controller::srv::ConnectRobot_Response;
};

}  // namespace srv

}  // namespace doosan_m0609_controller

#endif  // DOOSAN_M0609_CONTROLLER__SRV__DETAIL__CONNECT_ROBOT__STRUCT_HPP_

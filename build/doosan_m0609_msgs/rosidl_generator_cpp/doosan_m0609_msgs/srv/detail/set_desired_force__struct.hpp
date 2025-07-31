// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from doosan_m0609_msgs:srv/SetDesiredForce.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SET_DESIRED_FORCE__STRUCT_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SET_DESIRED_FORCE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__doosan_m0609_msgs__srv__SetDesiredForce_Request __attribute__((deprecated))
#else
# define DEPRECATED__doosan_m0609_msgs__srv__SetDesiredForce_Request __declspec(deprecated)
#endif

namespace doosan_m0609_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetDesiredForce_Request_
{
  using Type = SetDesiredForce_Request_<ContainerAllocator>;

  explicit SetDesiredForce_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 6>::iterator, double>(this->fd.begin(), this->fd.end(), 0.0);
      std::fill<typename std::array<int8_t, 6>::iterator, int8_t>(this->dir.begin(), this->dir.end(), 0);
      this->ref = 0;
      this->time = 0.0;
      this->mod = 0;
    }
  }

  explicit SetDesiredForce_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : fd(_alloc),
    dir(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 6>::iterator, double>(this->fd.begin(), this->fd.end(), 0.0);
      std::fill<typename std::array<int8_t, 6>::iterator, int8_t>(this->dir.begin(), this->dir.end(), 0);
      this->ref = 0;
      this->time = 0.0;
      this->mod = 0;
    }
  }

  // field types and members
  using _fd_type =
    std::array<double, 6>;
  _fd_type fd;
  using _dir_type =
    std::array<int8_t, 6>;
  _dir_type dir;
  using _ref_type =
    int8_t;
  _ref_type ref;
  using _time_type =
    double;
  _time_type time;
  using _mod_type =
    int8_t;
  _mod_type mod;

  // setters for named parameter idiom
  Type & set__fd(
    const std::array<double, 6> & _arg)
  {
    this->fd = _arg;
    return *this;
  }
  Type & set__dir(
    const std::array<int8_t, 6> & _arg)
  {
    this->dir = _arg;
    return *this;
  }
  Type & set__ref(
    const int8_t & _arg)
  {
    this->ref = _arg;
    return *this;
  }
  Type & set__time(
    const double & _arg)
  {
    this->time = _arg;
    return *this;
  }
  Type & set__mod(
    const int8_t & _arg)
  {
    this->mod = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    doosan_m0609_msgs::srv::SetDesiredForce_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const doosan_m0609_msgs::srv::SetDesiredForce_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::SetDesiredForce_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::SetDesiredForce_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::SetDesiredForce_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::SetDesiredForce_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::SetDesiredForce_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::SetDesiredForce_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::SetDesiredForce_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::SetDesiredForce_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doosan_m0609_msgs__srv__SetDesiredForce_Request
    std::shared_ptr<doosan_m0609_msgs::srv::SetDesiredForce_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doosan_m0609_msgs__srv__SetDesiredForce_Request
    std::shared_ptr<doosan_m0609_msgs::srv::SetDesiredForce_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetDesiredForce_Request_ & other) const
  {
    if (this->fd != other.fd) {
      return false;
    }
    if (this->dir != other.dir) {
      return false;
    }
    if (this->ref != other.ref) {
      return false;
    }
    if (this->time != other.time) {
      return false;
    }
    if (this->mod != other.mod) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetDesiredForce_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetDesiredForce_Request_

// alias to use template instance with default allocator
using SetDesiredForce_Request =
  doosan_m0609_msgs::srv::SetDesiredForce_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace doosan_m0609_msgs


#ifndef _WIN32
# define DEPRECATED__doosan_m0609_msgs__srv__SetDesiredForce_Response __attribute__((deprecated))
#else
# define DEPRECATED__doosan_m0609_msgs__srv__SetDesiredForce_Response __declspec(deprecated)
#endif

namespace doosan_m0609_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetDesiredForce_Response_
{
  using Type = SetDesiredForce_Response_<ContainerAllocator>;

  explicit SetDesiredForce_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit SetDesiredForce_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    doosan_m0609_msgs::srv::SetDesiredForce_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const doosan_m0609_msgs::srv::SetDesiredForce_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::SetDesiredForce_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::SetDesiredForce_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::SetDesiredForce_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::SetDesiredForce_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::SetDesiredForce_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::SetDesiredForce_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::SetDesiredForce_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::SetDesiredForce_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doosan_m0609_msgs__srv__SetDesiredForce_Response
    std::shared_ptr<doosan_m0609_msgs::srv::SetDesiredForce_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doosan_m0609_msgs__srv__SetDesiredForce_Response
    std::shared_ptr<doosan_m0609_msgs::srv::SetDesiredForce_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetDesiredForce_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetDesiredForce_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetDesiredForce_Response_

// alias to use template instance with default allocator
using SetDesiredForce_Response =
  doosan_m0609_msgs::srv::SetDesiredForce_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace doosan_m0609_msgs

namespace doosan_m0609_msgs
{

namespace srv
{

struct SetDesiredForce
{
  using Request = doosan_m0609_msgs::srv::SetDesiredForce_Request;
  using Response = doosan_m0609_msgs::srv::SetDesiredForce_Response;
};

}  // namespace srv

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SET_DESIRED_FORCE__STRUCT_HPP_

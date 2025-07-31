// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from doosan_m0609_msgs:srv/ServoOff.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__SERVO_OFF__STRUCT_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__SERVO_OFF__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__doosan_m0609_msgs__srv__ServoOff_Request __attribute__((deprecated))
#else
# define DEPRECATED__doosan_m0609_msgs__srv__ServoOff_Request __declspec(deprecated)
#endif

namespace doosan_m0609_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ServoOff_Request_
{
  using Type = ServoOff_Request_<ContainerAllocator>;

  explicit ServoOff_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->stop_type = 0;
    }
  }

  explicit ServoOff_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->stop_type = 0;
    }
  }

  // field types and members
  using _stop_type_type =
    int8_t;
  _stop_type_type stop_type;

  // setters for named parameter idiom
  Type & set__stop_type(
    const int8_t & _arg)
  {
    this->stop_type = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int8_t STOP_TYPE_QUICK_STO =
    0;
  static constexpr int8_t STOP_TYPE_QUICK =
    1;
  static constexpr int8_t STOP_TYPE_SLOW =
    2;
  static constexpr int8_t STOP_TYPE_HOLD =
    3;
  static constexpr int8_t STOP_TYPE_EMERGENCY =
    3;

  // pointer types
  using RawPtr =
    doosan_m0609_msgs::srv::ServoOff_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const doosan_m0609_msgs::srv::ServoOff_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::ServoOff_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::ServoOff_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::ServoOff_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::ServoOff_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::ServoOff_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::ServoOff_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::ServoOff_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::ServoOff_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doosan_m0609_msgs__srv__ServoOff_Request
    std::shared_ptr<doosan_m0609_msgs::srv::ServoOff_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doosan_m0609_msgs__srv__ServoOff_Request
    std::shared_ptr<doosan_m0609_msgs::srv::ServoOff_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ServoOff_Request_ & other) const
  {
    if (this->stop_type != other.stop_type) {
      return false;
    }
    return true;
  }
  bool operator!=(const ServoOff_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ServoOff_Request_

// alias to use template instance with default allocator
using ServoOff_Request =
  doosan_m0609_msgs::srv::ServoOff_Request_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ServoOff_Request_<ContainerAllocator>::STOP_TYPE_QUICK_STO;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ServoOff_Request_<ContainerAllocator>::STOP_TYPE_QUICK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ServoOff_Request_<ContainerAllocator>::STOP_TYPE_SLOW;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ServoOff_Request_<ContainerAllocator>::STOP_TYPE_HOLD;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ServoOff_Request_<ContainerAllocator>::STOP_TYPE_EMERGENCY;
#endif  // __cplusplus < 201703L

}  // namespace srv

}  // namespace doosan_m0609_msgs


#ifndef _WIN32
# define DEPRECATED__doosan_m0609_msgs__srv__ServoOff_Response __attribute__((deprecated))
#else
# define DEPRECATED__doosan_m0609_msgs__srv__ServoOff_Response __declspec(deprecated)
#endif

namespace doosan_m0609_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ServoOff_Response_
{
  using Type = ServoOff_Response_<ContainerAllocator>;

  explicit ServoOff_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit ServoOff_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    doosan_m0609_msgs::srv::ServoOff_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const doosan_m0609_msgs::srv::ServoOff_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::ServoOff_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::ServoOff_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::ServoOff_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::ServoOff_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::ServoOff_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::ServoOff_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::ServoOff_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::ServoOff_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doosan_m0609_msgs__srv__ServoOff_Response
    std::shared_ptr<doosan_m0609_msgs::srv::ServoOff_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doosan_m0609_msgs__srv__ServoOff_Response
    std::shared_ptr<doosan_m0609_msgs::srv::ServoOff_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ServoOff_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const ServoOff_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ServoOff_Response_

// alias to use template instance with default allocator
using ServoOff_Response =
  doosan_m0609_msgs::srv::ServoOff_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace doosan_m0609_msgs

namespace doosan_m0609_msgs
{

namespace srv
{

struct ServoOff
{
  using Request = doosan_m0609_msgs::srv::ServoOff_Request;
  using Response = doosan_m0609_msgs::srv::ServoOff_Response;
};

}  // namespace srv

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__SERVO_OFF__STRUCT_HPP_

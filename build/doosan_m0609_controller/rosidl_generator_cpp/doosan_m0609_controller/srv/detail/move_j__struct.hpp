// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from doosan_m0609_controller:srv/MoveJ.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_CONTROLLER__SRV__DETAIL__MOVE_J__STRUCT_HPP_
#define DOOSAN_M0609_CONTROLLER__SRV__DETAIL__MOVE_J__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__doosan_m0609_controller__srv__MoveJ_Request __attribute__((deprecated))
#else
# define DEPRECATED__doosan_m0609_controller__srv__MoveJ_Request __declspec(deprecated)
#endif

namespace doosan_m0609_controller
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveJ_Request_
{
  using Type = MoveJ_Request_<ContainerAllocator>;

  explicit MoveJ_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 6>::iterator, double>(this->target_joints.begin(), this->target_joints.end(), 0.0);
      this->velocity_ratio = 0.0;
      this->acceleration_ratio = 0.0;
      this->time_out = 0.0;
    }
  }

  explicit MoveJ_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_joints(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 6>::iterator, double>(this->target_joints.begin(), this->target_joints.end(), 0.0);
      this->velocity_ratio = 0.0;
      this->acceleration_ratio = 0.0;
      this->time_out = 0.0;
    }
  }

  // field types and members
  using _target_joints_type =
    std::array<double, 6>;
  _target_joints_type target_joints;
  using _velocity_ratio_type =
    double;
  _velocity_ratio_type velocity_ratio;
  using _acceleration_ratio_type =
    double;
  _acceleration_ratio_type acceleration_ratio;
  using _time_out_type =
    double;
  _time_out_type time_out;

  // setters for named parameter idiom
  Type & set__target_joints(
    const std::array<double, 6> & _arg)
  {
    this->target_joints = _arg;
    return *this;
  }
  Type & set__velocity_ratio(
    const double & _arg)
  {
    this->velocity_ratio = _arg;
    return *this;
  }
  Type & set__acceleration_ratio(
    const double & _arg)
  {
    this->acceleration_ratio = _arg;
    return *this;
  }
  Type & set__time_out(
    const double & _arg)
  {
    this->time_out = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    doosan_m0609_controller::srv::MoveJ_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const doosan_m0609_controller::srv::MoveJ_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doosan_m0609_controller::srv::MoveJ_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doosan_m0609_controller::srv::MoveJ_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_controller::srv::MoveJ_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_controller::srv::MoveJ_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_controller::srv::MoveJ_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_controller::srv::MoveJ_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doosan_m0609_controller::srv::MoveJ_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doosan_m0609_controller::srv::MoveJ_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doosan_m0609_controller__srv__MoveJ_Request
    std::shared_ptr<doosan_m0609_controller::srv::MoveJ_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doosan_m0609_controller__srv__MoveJ_Request
    std::shared_ptr<doosan_m0609_controller::srv::MoveJ_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveJ_Request_ & other) const
  {
    if (this->target_joints != other.target_joints) {
      return false;
    }
    if (this->velocity_ratio != other.velocity_ratio) {
      return false;
    }
    if (this->acceleration_ratio != other.acceleration_ratio) {
      return false;
    }
    if (this->time_out != other.time_out) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveJ_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveJ_Request_

// alias to use template instance with default allocator
using MoveJ_Request =
  doosan_m0609_controller::srv::MoveJ_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace doosan_m0609_controller


#ifndef _WIN32
# define DEPRECATED__doosan_m0609_controller__srv__MoveJ_Response __attribute__((deprecated))
#else
# define DEPRECATED__doosan_m0609_controller__srv__MoveJ_Response __declspec(deprecated)
#endif

namespace doosan_m0609_controller
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveJ_Response_
{
  using Type = MoveJ_Response_<ContainerAllocator>;

  explicit MoveJ_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit MoveJ_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    doosan_m0609_controller::srv::MoveJ_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const doosan_m0609_controller::srv::MoveJ_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doosan_m0609_controller::srv::MoveJ_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doosan_m0609_controller::srv::MoveJ_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_controller::srv::MoveJ_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_controller::srv::MoveJ_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_controller::srv::MoveJ_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_controller::srv::MoveJ_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doosan_m0609_controller::srv::MoveJ_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doosan_m0609_controller::srv::MoveJ_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doosan_m0609_controller__srv__MoveJ_Response
    std::shared_ptr<doosan_m0609_controller::srv::MoveJ_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doosan_m0609_controller__srv__MoveJ_Response
    std::shared_ptr<doosan_m0609_controller::srv::MoveJ_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveJ_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveJ_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveJ_Response_

// alias to use template instance with default allocator
using MoveJ_Response =
  doosan_m0609_controller::srv::MoveJ_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace doosan_m0609_controller

namespace doosan_m0609_controller
{

namespace srv
{

struct MoveJ
{
  using Request = doosan_m0609_controller::srv::MoveJ_Request;
  using Response = doosan_m0609_controller::srv::MoveJ_Response;
};

}  // namespace srv

}  // namespace doosan_m0609_controller

#endif  // DOOSAN_M0609_CONTROLLER__SRV__DETAIL__MOVE_J__STRUCT_HPP_

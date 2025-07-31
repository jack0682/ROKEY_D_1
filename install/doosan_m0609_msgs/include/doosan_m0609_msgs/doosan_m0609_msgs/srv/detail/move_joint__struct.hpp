// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from doosan_m0609_msgs:srv/MoveJoint.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_JOINT__STRUCT_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_JOINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__doosan_m0609_msgs__srv__MoveJoint_Request __attribute__((deprecated))
#else
# define DEPRECATED__doosan_m0609_msgs__srv__MoveJoint_Request __declspec(deprecated)
#endif

namespace doosan_m0609_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveJoint_Request_
{
  using Type = MoveJoint_Request_<ContainerAllocator>;

  explicit MoveJoint_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 6>::iterator, double>(this->pos.begin(), this->pos.end(), 0.0);
      this->vel = 0.0;
      this->acc = 0.0;
      this->time = 0.0;
      this->radius = 0.0;
      this->mode = 0;
      this->blend_type = 0;
      this->sync_type = 0;
    }
  }

  explicit MoveJoint_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pos(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 6>::iterator, double>(this->pos.begin(), this->pos.end(), 0.0);
      this->vel = 0.0;
      this->acc = 0.0;
      this->time = 0.0;
      this->radius = 0.0;
      this->mode = 0;
      this->blend_type = 0;
      this->sync_type = 0;
    }
  }

  // field types and members
  using _pos_type =
    std::array<double, 6>;
  _pos_type pos;
  using _vel_type =
    double;
  _vel_type vel;
  using _acc_type =
    double;
  _acc_type acc;
  using _time_type =
    double;
  _time_type time;
  using _radius_type =
    double;
  _radius_type radius;
  using _mode_type =
    int8_t;
  _mode_type mode;
  using _blend_type_type =
    int8_t;
  _blend_type_type blend_type;
  using _sync_type_type =
    int8_t;
  _sync_type_type sync_type;

  // setters for named parameter idiom
  Type & set__pos(
    const std::array<double, 6> & _arg)
  {
    this->pos = _arg;
    return *this;
  }
  Type & set__vel(
    const double & _arg)
  {
    this->vel = _arg;
    return *this;
  }
  Type & set__acc(
    const double & _arg)
  {
    this->acc = _arg;
    return *this;
  }
  Type & set__time(
    const double & _arg)
  {
    this->time = _arg;
    return *this;
  }
  Type & set__radius(
    const double & _arg)
  {
    this->radius = _arg;
    return *this;
  }
  Type & set__mode(
    const int8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__blend_type(
    const int8_t & _arg)
  {
    this->blend_type = _arg;
    return *this;
  }
  Type & set__sync_type(
    const int8_t & _arg)
  {
    this->sync_type = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    doosan_m0609_msgs::srv::MoveJoint_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const doosan_m0609_msgs::srv::MoveJoint_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::MoveJoint_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::MoveJoint_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::MoveJoint_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::MoveJoint_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::MoveJoint_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::MoveJoint_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::MoveJoint_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::MoveJoint_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doosan_m0609_msgs__srv__MoveJoint_Request
    std::shared_ptr<doosan_m0609_msgs::srv::MoveJoint_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doosan_m0609_msgs__srv__MoveJoint_Request
    std::shared_ptr<doosan_m0609_msgs::srv::MoveJoint_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveJoint_Request_ & other) const
  {
    if (this->pos != other.pos) {
      return false;
    }
    if (this->vel != other.vel) {
      return false;
    }
    if (this->acc != other.acc) {
      return false;
    }
    if (this->time != other.time) {
      return false;
    }
    if (this->radius != other.radius) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    if (this->blend_type != other.blend_type) {
      return false;
    }
    if (this->sync_type != other.sync_type) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveJoint_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveJoint_Request_

// alias to use template instance with default allocator
using MoveJoint_Request =
  doosan_m0609_msgs::srv::MoveJoint_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace doosan_m0609_msgs


#ifndef _WIN32
# define DEPRECATED__doosan_m0609_msgs__srv__MoveJoint_Response __attribute__((deprecated))
#else
# define DEPRECATED__doosan_m0609_msgs__srv__MoveJoint_Response __declspec(deprecated)
#endif

namespace doosan_m0609_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveJoint_Response_
{
  using Type = MoveJoint_Response_<ContainerAllocator>;

  explicit MoveJoint_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit MoveJoint_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    doosan_m0609_msgs::srv::MoveJoint_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const doosan_m0609_msgs::srv::MoveJoint_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::MoveJoint_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::MoveJoint_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::MoveJoint_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::MoveJoint_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::MoveJoint_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::MoveJoint_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::MoveJoint_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::MoveJoint_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doosan_m0609_msgs__srv__MoveJoint_Response
    std::shared_ptr<doosan_m0609_msgs::srv::MoveJoint_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doosan_m0609_msgs__srv__MoveJoint_Response
    std::shared_ptr<doosan_m0609_msgs::srv::MoveJoint_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveJoint_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveJoint_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveJoint_Response_

// alias to use template instance with default allocator
using MoveJoint_Response =
  doosan_m0609_msgs::srv::MoveJoint_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace doosan_m0609_msgs

namespace doosan_m0609_msgs
{

namespace srv
{

struct MoveJoint
{
  using Request = doosan_m0609_msgs::srv::MoveJoint_Request;
  using Response = doosan_m0609_msgs::srv::MoveJoint_Response;
};

}  // namespace srv

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_JOINT__STRUCT_HPP_

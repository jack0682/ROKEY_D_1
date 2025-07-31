// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from doosan_m0609_msgs:srv/MoveSplineJoint.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_SPLINE_JOINT__STRUCT_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_SPLINE_JOINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pos'
#include "std_msgs/msg/detail/float64_multi_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__doosan_m0609_msgs__srv__MoveSplineJoint_Request __attribute__((deprecated))
#else
# define DEPRECATED__doosan_m0609_msgs__srv__MoveSplineJoint_Request __declspec(deprecated)
#endif

namespace doosan_m0609_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveSplineJoint_Request_
{
  using Type = MoveSplineJoint_Request_<ContainerAllocator>;

  explicit MoveSplineJoint_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pos_cnt = 0;
      std::fill<typename std::array<double, 6>::iterator, double>(this->vel.begin(), this->vel.end(), 0.0);
      std::fill<typename std::array<double, 6>::iterator, double>(this->acc.begin(), this->acc.end(), 0.0);
      this->time = 0.0;
      this->mode = 0;
      this->sync_type = 0;
    }
  }

  explicit MoveSplineJoint_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : vel(_alloc),
    acc(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pos_cnt = 0;
      std::fill<typename std::array<double, 6>::iterator, double>(this->vel.begin(), this->vel.end(), 0.0);
      std::fill<typename std::array<double, 6>::iterator, double>(this->acc.begin(), this->acc.end(), 0.0);
      this->time = 0.0;
      this->mode = 0;
      this->sync_type = 0;
    }
  }

  // field types and members
  using _pos_type =
    std::vector<std_msgs::msg::Float64MultiArray_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std_msgs::msg::Float64MultiArray_<ContainerAllocator>>>;
  _pos_type pos;
  using _pos_cnt_type =
    int8_t;
  _pos_cnt_type pos_cnt;
  using _vel_type =
    std::array<double, 6>;
  _vel_type vel;
  using _acc_type =
    std::array<double, 6>;
  _acc_type acc;
  using _time_type =
    double;
  _time_type time;
  using _mode_type =
    int8_t;
  _mode_type mode;
  using _sync_type_type =
    int8_t;
  _sync_type_type sync_type;

  // setters for named parameter idiom
  Type & set__pos(
    const std::vector<std_msgs::msg::Float64MultiArray_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std_msgs::msg::Float64MultiArray_<ContainerAllocator>>> & _arg)
  {
    this->pos = _arg;
    return *this;
  }
  Type & set__pos_cnt(
    const int8_t & _arg)
  {
    this->pos_cnt = _arg;
    return *this;
  }
  Type & set__vel(
    const std::array<double, 6> & _arg)
  {
    this->vel = _arg;
    return *this;
  }
  Type & set__acc(
    const std::array<double, 6> & _arg)
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
  Type & set__mode(
    const int8_t & _arg)
  {
    this->mode = _arg;
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
    doosan_m0609_msgs::srv::MoveSplineJoint_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const doosan_m0609_msgs::srv::MoveSplineJoint_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::MoveSplineJoint_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::MoveSplineJoint_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::MoveSplineJoint_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::MoveSplineJoint_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::MoveSplineJoint_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::MoveSplineJoint_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::MoveSplineJoint_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::MoveSplineJoint_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doosan_m0609_msgs__srv__MoveSplineJoint_Request
    std::shared_ptr<doosan_m0609_msgs::srv::MoveSplineJoint_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doosan_m0609_msgs__srv__MoveSplineJoint_Request
    std::shared_ptr<doosan_m0609_msgs::srv::MoveSplineJoint_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveSplineJoint_Request_ & other) const
  {
    if (this->pos != other.pos) {
      return false;
    }
    if (this->pos_cnt != other.pos_cnt) {
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
    if (this->mode != other.mode) {
      return false;
    }
    if (this->sync_type != other.sync_type) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveSplineJoint_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveSplineJoint_Request_

// alias to use template instance with default allocator
using MoveSplineJoint_Request =
  doosan_m0609_msgs::srv::MoveSplineJoint_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace doosan_m0609_msgs


#ifndef _WIN32
# define DEPRECATED__doosan_m0609_msgs__srv__MoveSplineJoint_Response __attribute__((deprecated))
#else
# define DEPRECATED__doosan_m0609_msgs__srv__MoveSplineJoint_Response __declspec(deprecated)
#endif

namespace doosan_m0609_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveSplineJoint_Response_
{
  using Type = MoveSplineJoint_Response_<ContainerAllocator>;

  explicit MoveSplineJoint_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit MoveSplineJoint_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    doosan_m0609_msgs::srv::MoveSplineJoint_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const doosan_m0609_msgs::srv::MoveSplineJoint_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::MoveSplineJoint_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::MoveSplineJoint_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::MoveSplineJoint_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::MoveSplineJoint_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::MoveSplineJoint_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::MoveSplineJoint_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::MoveSplineJoint_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::MoveSplineJoint_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doosan_m0609_msgs__srv__MoveSplineJoint_Response
    std::shared_ptr<doosan_m0609_msgs::srv::MoveSplineJoint_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doosan_m0609_msgs__srv__MoveSplineJoint_Response
    std::shared_ptr<doosan_m0609_msgs::srv::MoveSplineJoint_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveSplineJoint_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveSplineJoint_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveSplineJoint_Response_

// alias to use template instance with default allocator
using MoveSplineJoint_Response =
  doosan_m0609_msgs::srv::MoveSplineJoint_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace doosan_m0609_msgs

namespace doosan_m0609_msgs
{

namespace srv
{

struct MoveSplineJoint
{
  using Request = doosan_m0609_msgs::srv::MoveSplineJoint_Request;
  using Response = doosan_m0609_msgs::srv::MoveSplineJoint_Response;
};

}  // namespace srv

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__MOVE_SPLINE_JOINT__STRUCT_HPP_

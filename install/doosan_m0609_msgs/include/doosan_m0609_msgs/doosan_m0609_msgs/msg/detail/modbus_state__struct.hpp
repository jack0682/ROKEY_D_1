// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from doosan_m0609_msgs:msg/ModbusState.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__MSG__DETAIL__MODBUS_STATE__STRUCT_HPP_
#define DOOSAN_M0609_MSGS__MSG__DETAIL__MODBUS_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__doosan_m0609_msgs__msg__ModbusState __attribute__((deprecated))
#else
# define DEPRECATED__doosan_m0609_msgs__msg__ModbusState __declspec(deprecated)
#endif

namespace doosan_m0609_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ModbusState_
{
  using Type = ModbusState_<ContainerAllocator>;

  explicit ModbusState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->modbus_symbol = "";
      this->modbus_value = 0l;
    }
  }

  explicit ModbusState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : modbus_symbol(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->modbus_symbol = "";
      this->modbus_value = 0l;
    }
  }

  // field types and members
  using _modbus_symbol_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _modbus_symbol_type modbus_symbol;
  using _modbus_value_type =
    int32_t;
  _modbus_value_type modbus_value;

  // setters for named parameter idiom
  Type & set__modbus_symbol(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->modbus_symbol = _arg;
    return *this;
  }
  Type & set__modbus_value(
    const int32_t & _arg)
  {
    this->modbus_value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    doosan_m0609_msgs::msg::ModbusState_<ContainerAllocator> *;
  using ConstRawPtr =
    const doosan_m0609_msgs::msg::ModbusState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doosan_m0609_msgs::msg::ModbusState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doosan_m0609_msgs::msg::ModbusState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::msg::ModbusState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::msg::ModbusState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::msg::ModbusState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::msg::ModbusState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doosan_m0609_msgs::msg::ModbusState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doosan_m0609_msgs::msg::ModbusState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doosan_m0609_msgs__msg__ModbusState
    std::shared_ptr<doosan_m0609_msgs::msg::ModbusState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doosan_m0609_msgs__msg__ModbusState
    std::shared_ptr<doosan_m0609_msgs::msg::ModbusState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ModbusState_ & other) const
  {
    if (this->modbus_symbol != other.modbus_symbol) {
      return false;
    }
    if (this->modbus_value != other.modbus_value) {
      return false;
    }
    return true;
  }
  bool operator!=(const ModbusState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ModbusState_

// alias to use template instance with default allocator
using ModbusState =
  doosan_m0609_msgs::msg::ModbusState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__MSG__DETAIL__MODBUS_STATE__STRUCT_HPP_

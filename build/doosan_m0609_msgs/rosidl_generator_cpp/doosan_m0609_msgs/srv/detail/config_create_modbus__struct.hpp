// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from doosan_m0609_msgs:srv/ConfigCreateModbus.idl
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_CREATE_MODBUS__STRUCT_HPP_
#define DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_CREATE_MODBUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__doosan_m0609_msgs__srv__ConfigCreateModbus_Request __attribute__((deprecated))
#else
# define DEPRECATED__doosan_m0609_msgs__srv__ConfigCreateModbus_Request __declspec(deprecated)
#endif

namespace doosan_m0609_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ConfigCreateModbus_Request_
{
  using Type = ConfigCreateModbus_Request_<ContainerAllocator>;

  explicit ConfigCreateModbus_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->ip = "";
      this->port = 0l;
      this->reg_type = 0;
      this->index = 0;
      this->value = 0;
      this->slave_id = 0l;
    }
  }

  explicit ConfigCreateModbus_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    ip(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->ip = "";
      this->port = 0l;
      this->reg_type = 0;
      this->index = 0;
      this->value = 0;
      this->slave_id = 0l;
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _ip_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _ip_type ip;
  using _port_type =
    int32_t;
  _port_type port;
  using _reg_type_type =
    int8_t;
  _reg_type_type reg_type;
  using _index_type =
    int8_t;
  _index_type index;
  using _value_type =
    int8_t;
  _value_type value;
  using _slave_id_type =
    int32_t;
  _slave_id_type slave_id;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__ip(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->ip = _arg;
    return *this;
  }
  Type & set__port(
    const int32_t & _arg)
  {
    this->port = _arg;
    return *this;
  }
  Type & set__reg_type(
    const int8_t & _arg)
  {
    this->reg_type = _arg;
    return *this;
  }
  Type & set__index(
    const int8_t & _arg)
  {
    this->index = _arg;
    return *this;
  }
  Type & set__value(
    const int8_t & _arg)
  {
    this->value = _arg;
    return *this;
  }
  Type & set__slave_id(
    const int32_t & _arg)
  {
    this->slave_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    doosan_m0609_msgs::srv::ConfigCreateModbus_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const doosan_m0609_msgs::srv::ConfigCreateModbus_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::ConfigCreateModbus_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::ConfigCreateModbus_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::ConfigCreateModbus_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::ConfigCreateModbus_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::ConfigCreateModbus_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::ConfigCreateModbus_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::ConfigCreateModbus_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::ConfigCreateModbus_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doosan_m0609_msgs__srv__ConfigCreateModbus_Request
    std::shared_ptr<doosan_m0609_msgs::srv::ConfigCreateModbus_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doosan_m0609_msgs__srv__ConfigCreateModbus_Request
    std::shared_ptr<doosan_m0609_msgs::srv::ConfigCreateModbus_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ConfigCreateModbus_Request_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->ip != other.ip) {
      return false;
    }
    if (this->port != other.port) {
      return false;
    }
    if (this->reg_type != other.reg_type) {
      return false;
    }
    if (this->index != other.index) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    if (this->slave_id != other.slave_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const ConfigCreateModbus_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ConfigCreateModbus_Request_

// alias to use template instance with default allocator
using ConfigCreateModbus_Request =
  doosan_m0609_msgs::srv::ConfigCreateModbus_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace doosan_m0609_msgs


#ifndef _WIN32
# define DEPRECATED__doosan_m0609_msgs__srv__ConfigCreateModbus_Response __attribute__((deprecated))
#else
# define DEPRECATED__doosan_m0609_msgs__srv__ConfigCreateModbus_Response __declspec(deprecated)
#endif

namespace doosan_m0609_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ConfigCreateModbus_Response_
{
  using Type = ConfigCreateModbus_Response_<ContainerAllocator>;

  explicit ConfigCreateModbus_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit ConfigCreateModbus_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    doosan_m0609_msgs::srv::ConfigCreateModbus_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const doosan_m0609_msgs::srv::ConfigCreateModbus_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::ConfigCreateModbus_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<doosan_m0609_msgs::srv::ConfigCreateModbus_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::ConfigCreateModbus_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::ConfigCreateModbus_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      doosan_m0609_msgs::srv::ConfigCreateModbus_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<doosan_m0609_msgs::srv::ConfigCreateModbus_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::ConfigCreateModbus_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<doosan_m0609_msgs::srv::ConfigCreateModbus_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__doosan_m0609_msgs__srv__ConfigCreateModbus_Response
    std::shared_ptr<doosan_m0609_msgs::srv::ConfigCreateModbus_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__doosan_m0609_msgs__srv__ConfigCreateModbus_Response
    std::shared_ptr<doosan_m0609_msgs::srv::ConfigCreateModbus_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ConfigCreateModbus_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const ConfigCreateModbus_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ConfigCreateModbus_Response_

// alias to use template instance with default allocator
using ConfigCreateModbus_Response =
  doosan_m0609_msgs::srv::ConfigCreateModbus_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace doosan_m0609_msgs

namespace doosan_m0609_msgs
{

namespace srv
{

struct ConfigCreateModbus
{
  using Request = doosan_m0609_msgs::srv::ConfigCreateModbus_Request;
  using Response = doosan_m0609_msgs::srv::ConfigCreateModbus_Response;
};

}  // namespace srv

}  // namespace doosan_m0609_msgs

#endif  // DOOSAN_M0609_MSGS__SRV__DETAIL__CONFIG_CREATE_MODBUS__STRUCT_HPP_

// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from doosan_m0609_controller:srv/MoveJ.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "doosan_m0609_controller/srv/detail/move_j__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace doosan_m0609_controller
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoveJ_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveJ_Request_type_support_ids_t;

static const _MoveJ_Request_type_support_ids_t _MoveJ_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MoveJ_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveJ_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveJ_Request_type_support_symbol_names_t _MoveJ_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, doosan_m0609_controller, srv, MoveJ_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, doosan_m0609_controller, srv, MoveJ_Request)),
  }
};

typedef struct _MoveJ_Request_type_support_data_t
{
  void * data[2];
} _MoveJ_Request_type_support_data_t;

static _MoveJ_Request_type_support_data_t _MoveJ_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveJ_Request_message_typesupport_map = {
  2,
  "doosan_m0609_controller",
  &_MoveJ_Request_message_typesupport_ids.typesupport_identifier[0],
  &_MoveJ_Request_message_typesupport_symbol_names.symbol_name[0],
  &_MoveJ_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveJ_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveJ_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace doosan_m0609_controller

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<doosan_m0609_controller::srv::MoveJ_Request>()
{
  return &::doosan_m0609_controller::srv::rosidl_typesupport_cpp::MoveJ_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, doosan_m0609_controller, srv, MoveJ_Request)() {
  return get_message_type_support_handle<doosan_m0609_controller::srv::MoveJ_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "doosan_m0609_controller/srv/detail/move_j__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace doosan_m0609_controller
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoveJ_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveJ_Response_type_support_ids_t;

static const _MoveJ_Response_type_support_ids_t _MoveJ_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MoveJ_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveJ_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveJ_Response_type_support_symbol_names_t _MoveJ_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, doosan_m0609_controller, srv, MoveJ_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, doosan_m0609_controller, srv, MoveJ_Response)),
  }
};

typedef struct _MoveJ_Response_type_support_data_t
{
  void * data[2];
} _MoveJ_Response_type_support_data_t;

static _MoveJ_Response_type_support_data_t _MoveJ_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveJ_Response_message_typesupport_map = {
  2,
  "doosan_m0609_controller",
  &_MoveJ_Response_message_typesupport_ids.typesupport_identifier[0],
  &_MoveJ_Response_message_typesupport_symbol_names.symbol_name[0],
  &_MoveJ_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveJ_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveJ_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace doosan_m0609_controller

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<doosan_m0609_controller::srv::MoveJ_Response>()
{
  return &::doosan_m0609_controller::srv::rosidl_typesupport_cpp::MoveJ_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, doosan_m0609_controller, srv, MoveJ_Response)() {
  return get_message_type_support_handle<doosan_m0609_controller::srv::MoveJ_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "doosan_m0609_controller/srv/detail/move_j__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace doosan_m0609_controller
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoveJ_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveJ_type_support_ids_t;

static const _MoveJ_type_support_ids_t _MoveJ_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MoveJ_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveJ_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveJ_type_support_symbol_names_t _MoveJ_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, doosan_m0609_controller, srv, MoveJ)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, doosan_m0609_controller, srv, MoveJ)),
  }
};

typedef struct _MoveJ_type_support_data_t
{
  void * data[2];
} _MoveJ_type_support_data_t;

static _MoveJ_type_support_data_t _MoveJ_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveJ_service_typesupport_map = {
  2,
  "doosan_m0609_controller",
  &_MoveJ_service_typesupport_ids.typesupport_identifier[0],
  &_MoveJ_service_typesupport_symbol_names.symbol_name[0],
  &_MoveJ_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t MoveJ_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveJ_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace doosan_m0609_controller

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<doosan_m0609_controller::srv::MoveJ>()
{
  return &::doosan_m0609_controller::srv::rosidl_typesupport_cpp::MoveJ_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, doosan_m0609_controller, srv, MoveJ)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<doosan_m0609_controller::srv::MoveJ>();
}

#ifdef __cplusplus
}
#endif

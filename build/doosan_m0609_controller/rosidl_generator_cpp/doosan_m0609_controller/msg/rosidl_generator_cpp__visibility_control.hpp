// generated from rosidl_generator_cpp/resource/rosidl_generator_cpp__visibility_control.hpp.in
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_CONTROLLER__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
#define DOOSAN_M0609_CONTROLLER__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_GENERATOR_CPP_EXPORT_doosan_m0609_controller __attribute__ ((dllexport))
    #define ROSIDL_GENERATOR_CPP_IMPORT_doosan_m0609_controller __attribute__ ((dllimport))
  #else
    #define ROSIDL_GENERATOR_CPP_EXPORT_doosan_m0609_controller __declspec(dllexport)
    #define ROSIDL_GENERATOR_CPP_IMPORT_doosan_m0609_controller __declspec(dllimport)
  #endif
  #ifdef ROSIDL_GENERATOR_CPP_BUILDING_DLL_doosan_m0609_controller
    #define ROSIDL_GENERATOR_CPP_PUBLIC_doosan_m0609_controller ROSIDL_GENERATOR_CPP_EXPORT_doosan_m0609_controller
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_doosan_m0609_controller ROSIDL_GENERATOR_CPP_IMPORT_doosan_m0609_controller
  #endif
#else
  #define ROSIDL_GENERATOR_CPP_EXPORT_doosan_m0609_controller __attribute__ ((visibility("default")))
  #define ROSIDL_GENERATOR_CPP_IMPORT_doosan_m0609_controller
  #if __GNUC__ >= 4
    #define ROSIDL_GENERATOR_CPP_PUBLIC_doosan_m0609_controller __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_doosan_m0609_controller
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // DOOSAN_M0609_CONTROLLER__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_

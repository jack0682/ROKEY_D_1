// generated from
// rosidl_typesupport_fastrtps_c/resource/rosidl_typesupport_fastrtps_c__visibility_control.h.in
// generated code does not contain a copyright notice

#ifndef DOOSAN_M0609_CONTROLLER__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C__VISIBILITY_CONTROL_H_
#define DOOSAN_M0609_CONTROLLER__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C__VISIBILITY_CONTROL_H_

#if __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_doosan_m0609_controller __attribute__ ((dllexport))
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_doosan_m0609_controller __attribute__ ((dllimport))
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_doosan_m0609_controller __declspec(dllexport)
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_doosan_m0609_controller __declspec(dllimport)
  #endif
  #ifdef ROSIDL_TYPESUPPORT_FASTRTPS_C_BUILDING_DLL_doosan_m0609_controller
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_doosan_m0609_controller ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_doosan_m0609_controller
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_doosan_m0609_controller ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_doosan_m0609_controller
  #endif
#else
  #define ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_doosan_m0609_controller __attribute__ ((visibility("default")))
  #define ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_doosan_m0609_controller
  #if __GNUC__ >= 4
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_doosan_m0609_controller __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_doosan_m0609_controller
  #endif
#endif

#if __cplusplus
}
#endif

#endif  // DOOSAN_M0609_CONTROLLER__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C__VISIBILITY_CONTROL_H_

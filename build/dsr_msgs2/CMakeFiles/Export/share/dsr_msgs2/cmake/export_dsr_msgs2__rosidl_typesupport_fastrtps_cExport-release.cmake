#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "dsr_msgs2::dsr_msgs2__rosidl_typesupport_fastrtps_c" for configuration "Release"
set_property(TARGET dsr_msgs2::dsr_msgs2__rosidl_typesupport_fastrtps_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(dsr_msgs2::dsr_msgs2__rosidl_typesupport_fastrtps_c PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libdsr_msgs2__rosidl_typesupport_fastrtps_c.so"
  IMPORTED_SONAME_RELEASE "libdsr_msgs2__rosidl_typesupport_fastrtps_c.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS dsr_msgs2::dsr_msgs2__rosidl_typesupport_fastrtps_c )
list(APPEND _IMPORT_CHECK_FILES_FOR_dsr_msgs2::dsr_msgs2__rosidl_typesupport_fastrtps_c "${_IMPORT_PREFIX}/lib/libdsr_msgs2__rosidl_typesupport_fastrtps_c.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

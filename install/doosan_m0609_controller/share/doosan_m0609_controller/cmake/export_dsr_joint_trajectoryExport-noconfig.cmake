#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "doosan_m0609_controller::dsr_joint_trajectory" for configuration ""
set_property(TARGET doosan_m0609_controller::dsr_joint_trajectory APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(doosan_m0609_controller::dsr_joint_trajectory PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libdsr_joint_trajectory.so"
  IMPORTED_SONAME_NOCONFIG "libdsr_joint_trajectory.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS doosan_m0609_controller::dsr_joint_trajectory )
list(APPEND _IMPORT_CHECK_FILES_FOR_doosan_m0609_controller::dsr_joint_trajectory "${_IMPORT_PREFIX}/lib/libdsr_joint_trajectory.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

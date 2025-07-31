#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "doosan_m0609_hardware::doosan_m0609_hardware" for configuration ""
set_property(TARGET doosan_m0609_hardware::doosan_m0609_hardware APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(doosan_m0609_hardware::doosan_m0609_hardware PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libdoosan_m0609_hardware.so"
  IMPORTED_SONAME_NOCONFIG "libdoosan_m0609_hardware.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS doosan_m0609_hardware::doosan_m0609_hardware )
list(APPEND _IMPORT_CHECK_FILES_FOR_doosan_m0609_hardware::doosan_m0609_hardware "${_IMPORT_PREFIX}/lib/libdoosan_m0609_hardware.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

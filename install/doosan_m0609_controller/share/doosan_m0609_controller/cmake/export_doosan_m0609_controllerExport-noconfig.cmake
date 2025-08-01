#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "doosan_m0609_controller::doosan_m0609_controller" for configuration ""
set_property(TARGET doosan_m0609_controller::doosan_m0609_controller APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(doosan_m0609_controller::doosan_m0609_controller PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libdoosan_m0609_controller.so"
  IMPORTED_SONAME_NOCONFIG "libdoosan_m0609_controller.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS doosan_m0609_controller::doosan_m0609_controller )
list(APPEND _IMPORT_CHECK_FILES_FOR_doosan_m0609_controller::doosan_m0609_controller "${_IMPORT_PREFIX}/lib/libdoosan_m0609_controller.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

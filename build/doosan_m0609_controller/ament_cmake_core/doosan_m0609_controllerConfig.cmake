# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_doosan_m0609_controller_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED doosan_m0609_controller_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(doosan_m0609_controller_FOUND FALSE)
  elseif(NOT doosan_m0609_controller_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(doosan_m0609_controller_FOUND FALSE)
  endif()
  return()
endif()
set(_doosan_m0609_controller_CONFIG_INCLUDED TRUE)

# output package information
if(NOT doosan_m0609_controller_FIND_QUIETLY)
  message(STATUS "Found doosan_m0609_controller: 2.33.0 (${doosan_m0609_controller_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'doosan_m0609_controller' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${doosan_m0609_controller_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(doosan_m0609_controller_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_targets-extras.cmake;ament_cmake_export_dependencies-extras.cmake")
foreach(_extra ${_extras})
  include("${doosan_m0609_controller_DIR}/${_extra}")
endforeach()

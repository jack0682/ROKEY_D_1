# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_sugar_water_experiment_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED sugar_water_experiment_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(sugar_water_experiment_FOUND FALSE)
  elseif(NOT sugar_water_experiment_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(sugar_water_experiment_FOUND FALSE)
  endif()
  return()
endif()
set(_sugar_water_experiment_CONFIG_INCLUDED TRUE)

# output package information
if(NOT sugar_water_experiment_FIND_QUIETLY)
  message(STATUS "Found sugar_water_experiment: 0.1.0 (${sugar_water_experiment_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'sugar_water_experiment' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${sugar_water_experiment_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(sugar_water_experiment_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${sugar_water_experiment_DIR}/${_extra}")
endforeach()

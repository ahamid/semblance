cmake_minimum_required (VERSION 2.6)
project (Semblance)
# The version number.
set (Tutorial_VERSION_MAJOR 0)
set (Tutorial_VERSION_MINOR 1)
 
# configure a header file to pass some of the CMake settings to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/src/config/SemblanceConfig.h.in"
  "${PROJECT_BINARY_DIR}/src/config/SemblanceConfig.h"
)

# add the binary tree to the search path for include files
# so that we will find SemblanceConfig.h
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_BINARY_DIR}/src/config")
 
add_subdirectory("${PROJECT_SOURCE_DIR}/src/parser")
add_subdirectory("${PROJECT_SOURCE_DIR}/src/ooc")

# add the executable
#add_executable(Semblance semblance.cxx)
#add_library(Semblance ${CMAKE_CURRENT_BINARY_DIR}/lexer.c)

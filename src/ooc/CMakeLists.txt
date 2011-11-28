cmake_minimum_required (VERSION 2.6)

find_program(ROCK rock)

set(SEMBLANCE ${CMAKE_CURRENT_BINARY_DIR}/semblance)
# ridiculous hacks
#get_directory_property(INCLUDE_DIRECTORIES INCLUDE_DIRECTORIES)
#string(REPLACE ";" " -I" INCLUDE_PATHS "${INCLUDE_DIRECTORIES}")

# add the command to generate the source code
add_custom_command (
  OUTPUT ${SEMBLANCE}
  COMMAND ${ROCK} -v -I${CMAKE_CURRENT_SOURCE_DIR} -I${CMAKE_CURRENT_SOURCE_DIR}/../config -I${CMAKE_CURRENT_SOURCE_DIR}/../parser -sourcepath=${CMAKE_CURRENT_SOURCE_DIR} -L${PROJECT_BINARY_DIR} -lparser -o=semblance semblance.ooc
)

add_custom_target(semblance ALL DEPENDS ${SEMBLANCE})

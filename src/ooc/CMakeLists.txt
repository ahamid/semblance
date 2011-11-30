cmake_minimum_required (VERSION 2.6)

find_program(ROCK rock)

set(SEMBLANCE ${PROJECT_BINARY_DIR}/semblance)
# ridiculous hacks
#get_directory_property(INCLUDE_DIRECTORIES INCLUDE_DIRECTORIES)
#string(REPLACE ";" " -I" INCLUDE_PATHS "${INCLUDE_DIRECTORIES}")

add_custom_command (
  OUTPUT ${SEMBLANCE}
  COMMAND ${ROCK} -v -noclean -nolibcache -I${CMAKE_CURRENT_SOURCE_DIR} -I${CMAKE_CURRENT_SOURCE_DIR}/../config -I${CMAKE_CURRENT_SOURCE_DIR}/../parser -sourcepath=${CMAKE_CURRENT_SOURCE_DIR} -L${PROJECT_BINARY_DIR} -lparser -o=semblance semblance.ooc
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.ooc ${CMAKE_CURRENT_SOURCE_DIR}/**/*.ooc
)

add_custom_target(build_semblance ALL DEPENDS ${SEMBLANCE})
target_link_libraries(build_semblance parser)

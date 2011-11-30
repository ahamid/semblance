cmake_minimum_required (VERSION 2.6)

find_program(ROCK rock)

set(SBLTEST ${PROJECT_BINARY_DIR}/sbltest)

add_custom_command (
  OUTPUT ${SBLTEST}
  COMMAND ${ROCK} -v -noclean -nolibcache -I${CMAKE_CURRENT_SOURCE_DIR}/../src/parser -sourcepath=${CMAKE_CURRENT_SOURCE_DIR}:${CMAKE_CURRENT_SOURCE_DIR}/../src/ooc -L${PROJECT_BINARY_DIR} -lparser -o=sbltest TestParser.ooc
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.ooc
)

add_custom_target(build_sbltest ALL DEPENDS ${SBLTEST})
target_link_libraries(build_sbltest parser)

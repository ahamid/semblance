cmake_minimum_required (VERSION 2.6)

find_program(RAGEL ragel)
find_program(LEMON lemon)

set(LEXER_C ${CMAKE_CURRENT_SOURCE_DIR}/lexer.c)
set(GRAMMAR_C ${CMAKE_CURRENT_SOURCE_DIR}/grammar.c)

# add the command to generate the source code
add_custom_command (
  OUTPUT ${LEXER_C}
  COMMAND ${RAGEL} -o ${LEXER_C} ${CMAKE_CURRENT_SOURCE_DIR}/lexer.rl
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/lexer.rl # build when lexer.rl is newer
  DEPENDS ${GRAMMAR_C}
) 

add_custom_command(
  OUTPUT ${GRAMMAR_C}
  COMMAND ${LEMON} -q ${CMAKE_CURRENT_SOURCE_DIR}/grammar.y
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/grammar.y
)

add_definitions(-g -O0)
# add the executable
#add_executable(Semblance semblance.cxx)
add_library(parser STATIC ${GRAMMAR_C} ${LEXER_C} token.c)
add_executable(main main.c)
target_link_libraries(main parser)
set_target_properties(parser PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

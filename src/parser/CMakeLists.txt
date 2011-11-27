cmake_minimum_required (VERSION 2.6)

find_program(RAGEL ragel)

set(LEXER_C ${CMAKE_CURRENT_SOURCE_DIR}/lexer.c)

# add the command to generate the source code
add_custom_command (
  OUTPUT ${LEXER_C}
  COMMAND ${RAGEL} -o ${LEXER_C} ${CMAKE_CURRENT_SOURCE_DIR}/lexer.rl
) 

# add the executable
#add_executable(Semblance semblance.cxx)
add_library(parser ${LEXER_C})

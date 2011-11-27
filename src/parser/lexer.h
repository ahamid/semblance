#ifndef lexer_h
#define lexer_h

#include "token.h"

int parse(const char * const source);

#define IDENT() Parse(pParser, TK_IDENT, IDENTIFIER)
#define DIRECTIVE_START() Parse(pParser, TK_DIRECTIVE_START, DIRECTIVE_START) 

#endif

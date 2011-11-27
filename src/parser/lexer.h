#ifndef lexer_h
#define lexer_h

#include "token.h"

#define IDENT() Parse(pParser, TK_IDENT, token_create(IDENTIFIER, ts, te))
#define DIRECTIVE_START() Parse(pParser, TK_DIRECTIVE_START, token_create(DIRECTIVE_START, ts, te)) 

#endif

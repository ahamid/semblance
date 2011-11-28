#ifndef lexer_h
#define lexer_h

#include "token.h"

#define TK(I) (token_create(I, ts, te)) 
#define EMIT(T) Parse(pParser, TK_##T, TK(TK_##T), callbacks)
#define EMIT_BLANK(T) Parse(pParser, TK_##T, token_create(TK_##T, NULL, NULL), callbacks)

#endif

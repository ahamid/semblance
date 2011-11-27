#ifndef lexer_h
#define lexer_h

#include "token.h"

typedef struct {
} ParserCallbacks;

int parse(const char * const source, const ParserCallbacks * const);

#endif

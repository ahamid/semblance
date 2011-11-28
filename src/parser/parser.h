#ifndef parser_h
#define parser_h

#include "token.h"

typedef struct _ParserCallbacks {
  void (*createArg)(void *, const Token* const tok);
} ParserCallbacks;

int parse(const char * const source, const ParserCallbacks * const);

#endif

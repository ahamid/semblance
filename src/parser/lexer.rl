#include "grammar.h"
#include "lexer.h"
#include "parser.h"
// lemon doesn't provide prototypes for parser API, brute force include here
// and let the compiler sort it out
#include "grammar.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gc/gc.h>

%%{
  machine semblance_lexer;

  action starts_line {
    ts == source || (*(ts - 1) == '\n')
  }
  action newline {
    lineno++;
    EMIT(EOL);
  }

  newline = '\n' @newline;

  directive_start = '!' when starts_line;

  alnum_u = alnum | '_';
  alpha_u = alpha | '_';
  identifier = alpha_u alnum_u*;

  main := |*
    directive_start { PRINT_MATCH("directive_start"); EMIT(DIRECTIVE_START); };
    identifier      { PRINT_MATCH("identifier"); EMIT(IDENT); };
    space;
    newline;
    ',' { PRINT_MATCH("COMMA"); EMIT(COMMA); };
    '-'? digit+ { EMIT(INT); };
    '-'? digit+ '.' digit+ { EMIT(FLOAT); };
    '0x' xdigit+ { EMIT(HEX); };
  *|;

}%%

#define PRINT_MATCH(T) print_match(T, lineno, ts, te)

static void print_match(const char const * type, int line, const char const * start, const char const * end) {
  printf("line %i, type %s, len: %i: '%.*s'\n", line, type, end - start, end - start, start);
}

%% write data;

int parse(const char * const source, const ParserCallbacks * const callbacks) {
  int cs, act, lineno = 0;
  const char *ts = 0, *te = 0;

  const char * p = &source[0];
  printf("source %i chars: '%s'\n", strlen(source), source);

  void *pParser = ParseAlloc(malloc);

    %% write init;

  const char * pe = source + strlen(source);
  const char * eof = pe;
  
    %% write exec;

  int error = 0;
  if (cs == semblance_lexer_error) {
    printf("invalid character '%c'\n", ts[0]);
    error = 1;
  } else {
    printf("emitting synthetic eol\n");
    EMIT_BLANK(EOL);
    printf("final parse\n");
    Parse(pParser, 0, NULL, callbacks);
  }

  ParseFree(pParser, free);

  return error;
}

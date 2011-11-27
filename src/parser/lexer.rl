#include "grammar.h"
#include "lexer.h"
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
  }

  alnum_u = alnum | '_';
  alpha_u = alpha | '_';
  identifier = alpha_u alnum_u*;
  register = '%' identifier;
  #directive = '!' identifier when starts_line;
  directive_start = '!' when starts_line;
  comma = ',';
  newline = '\n' @newline;

  main := |*
    identifier { print_match("identifier", lineno, ts, te); IDENT(); };
    directive_start  { print_match("directive", lineno, ts, te); DIRECTIVE_START(); };
    newline;
    comma;
    space;
  *|;
}%%

static void print_match(const char const * type, int line, const char const * start, const char const * end) {
  printf("line %i, type %s, len: %i: '%.*s'\n", line, type, end - start, end - start, start);
}

%% write data;

int parse(const char * const source) {
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
    Parse(pParser, 0, NULL);
  }

  ParseFree(pParser, free);

  return error;
}

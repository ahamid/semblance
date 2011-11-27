#include "SemblanceConfig.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

%%{
  machine semblance_lexer;

  action starts_line {
    ts == p || (*(ts - 1) == '\n')
  }
  action newline {
    lineno++;
  }

  alnum_u = alnum | '_';
  alpha_u = alpha | '_';
  identifier = alpha_u alnum_u*;
  register = '%' identifier;
  directive = '!' identifier when starts_line;
  comma = ',';
  newline = '\n' @newline;

  main := |*
    identifier { print_match("identifier", lineno, ts, te); };
    directive  { print_match("directive", lineno, ts, te); };
    newline;
    comma;
    space;
  *|;
}%%

%% write data;

static void print_match(const char const * type, int line, const char const * start, const char const * end) {
  printf("line %i, type %s, len: %i: '%.*s'\n", line, type, end - start, end - start, start);
}

int main(int argc, const char const * const * argv) {
  int cs, act, lineno = 0;
  const char *ts = 0, *te = 0;

  const char * const source = argv[1];
  const char * p = &source[0];
  printf("source %i chars: '%s'\n", strlen(source), source);

  %% write init;

  const char * pe = source + strlen(source);
  const char * eof = pe;
  
  %% write exec;

  if (cs == semblance_lexer_error) {
    printf("invalid character '%c'\n", ts[0]);
  }
}

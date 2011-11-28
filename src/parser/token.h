#ifndef token_h
#define token_h

#define MAX_VALUE_SIZE 2047

typedef struct _Token {
  int type;
  char value[MAX_VALUE_SIZE + 1];
} Token;

Token* token_create(int type, const char * const start, const char * const end);
void token_free(Token* token);

#endif

#ifndef token_h
#define token_h

typedef enum TokenType {
  IDENTIFIER,
  DIRECTIVE_START
} TokenType;

#define MAX_VALUE_SIZE 2047

typedef struct Token {
  TokenType type;
  char value[MAX_VALUE_SIZE + 1];
} Token;

Token* token_create(TokenType type, const char * const start, const char * const end);
void token_free(Token* token);

#endif

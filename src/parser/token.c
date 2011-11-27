#include "token.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Token* token_create(TokenType type, const char * const start, const char * const end) {
    Token *tk = malloc(sizeof(Token));
    tk->type = type;
    int value_size = end - start;
    int min = value_size < MAX_VALUE_SIZE ? value_size : MAX_VALUE_SIZE;
    strncpy(tk->value, start, min);
    tk->value[MAX_VALUE_SIZE] = '\0';
    printf("TOKEN: %s\n", tk->value);
    return tk;
}

void token_free(Token* token) {
  free(token);
}
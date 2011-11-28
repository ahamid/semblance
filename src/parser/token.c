#include "token.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

Token* token_create(int type, const char * const start, const char * const end) {
    printf("Creating token: type: %i, start: %p, end: %p\n", type, start, end);
    Token *tk = calloc(1, sizeof(Token));
    tk->type = type;
    int value_size = end - start;
    int min = value_size < MAX_VALUE_SIZE ? value_size : MAX_VALUE_SIZE;
    strncpy(tk->value, start, min);
    tk->value[MAX_VALUE_SIZE] = '\0';
    printf("Created token: type: %i, value: %s\n", tk->type, tk->value);
    return tk;
}

void token_free(Token* token) {
  if (token == NULL) return;
  printf("Freeing token: type: %i, value: %s\n", token->type, token->value);
  free(token);
}

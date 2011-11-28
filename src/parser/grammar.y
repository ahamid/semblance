%include {
  #include "SemblanceConfig.h"
  #include "token.h"
  #include "parser.h"
  #include <string.h>
}

%token_type { Token* }
%token_destructor { token_free($$); }
%extra_argument { const ParserCallbacks * callbacks }

%token_prefix TK_

%parse_accept {
  printf("Parsing complete.\n");
}

%parse_failure {
  fprintf(stderr, "Parsing failed.\n");
}

%syntax_error {
  printf("error at token %s\n", yyTokenName[yymajor]);

  int i;
  for(i=1; i<=yypParser->yyidx; i++)
    printf(" %s",yyTokenName[yypParser->yystack[i].major]);

  printf(" | %s ] unexpected '%.*s'\n",
         yyTokenName[yymajor],
         (yymajor != 0 && TOKEN != NULL) ? strlen(TOKEN->value) : 7, 
         (yymajor != 0 && TOKEN != NULL) ? TOKEN->value : "$ (EOF)");
}

module ::= directives operations end.

directives ::= directives directive.
directives ::= .

directive ::= DIRECTIVE_START IDENT(I). { printf("directive: %s\n", I->value); token_free(I); }

operations ::= operations operation.
operations ::= .

operation ::= IDENT(I) parameters EOL. { printf("operation: %s\n", I->value); token_free(I); }

parameters ::= arguments.
parameters ::= .

arguments ::= arguments COMMA expr. { printf("arguments\n"); }
arguments(A) ::= expr(E). { printf("Callback: %p %p\n", callbacks->context, callbacks->createArg); A = callbacks->createArg(callbacks->context, E); }

// assign token as object for terminals
expr(E) ::= HEX(I). { E = I; }
expr(E) ::= INT(I). { E = I; }
expr(E) ::= FLOAT(I). { E = I; }
expr(E) ::= IDENT(I). { E = I; }

end ::= EOL.
end ::= .

%include {
  #include "SemblanceConfig.h"
  #include "token.h"
  #include <string.h>
}

%token_type { Token* }
%token_destructor { token_free($$); }
%default_type { Token * }
%type directive { Token * }
%type IDENT { Token * }
%type statement { Token * }

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
         yymajor != 0 ? strlen(TOKEN->value) : 7, 
         yymajor != 0 ? TOKEN->value : "$ (EOF)");
}

module ::= directives statements.

directives ::= directives directive.
directives ::= .

directive ::= DIRECTIVE_START IDENT(I). { printf("directive: %s\n", I->value); token_free(I); }

statements ::= statements statement.
statements ::= .

statement ::= IDENT(I). { printf("statement: %s\n", I->value); token_free(I); }

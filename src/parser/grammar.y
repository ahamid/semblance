%include {
  #include "SemblanceConfig.h"
  #include "token.h"
}

%token_type { Token }
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
         yyTokenName[yymajor]);
       //  yymajor != 0 ? TOKEN->len : 7, 
       //  yymajor != 0 ? TOKEN->start : "$ (EOF)");
}

module ::= directives statements.

directives ::= directives directive.
directives ::= .

directive ::= DIRECTIVE_START IDENT(I). { printf("directive: %i\n", I); }

statements ::= statements statement.
statements ::= .

statement ::= IDENT(I). { printf("statement: %i\n", I); }


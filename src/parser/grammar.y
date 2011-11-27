%include { #include "token.h" }

%token_type { Token }

module ::= directives statements.

directives ::= directive.
directives ::= directives directive.

directive ::= EXCLAMATION IDENT(I). { printf("directive: %i\n", I); }

statements ::= statement.
statements ::= statements statement.

statement ::= IDENT(I). { printf("statement: %i\n", I); }


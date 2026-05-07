%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token A B

%%

input:
      S '\n'      { printf("Valid String\n"); }
    ;

S:
      A S B B
    |
    ;

%%

void yyerror(const char *s) {
    printf("Invalid String\n");
}

int main() {
    printf("Enter string: ");
    yyparse();
    return 0;
}
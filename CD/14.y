%{
#include<stdio.h>
#include<stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token NUMBER

%left '+' '-'
%left '*' '/'
%right UMINUS

%%

ArithemeticExpression : 
    E {
        printf("\nResult = %d\n", $1);
        exit(0);
    }

E : 
    E '+' E     {$$ = $1 + $3;} |
    E '-' E     {$$ = $1 - $3;} |
    E '*' E     {$$ = $1 * $3;} |
    E '/' E     {$$ = $1 / $3;} |
    E '%' E     {$$ = $1 % $3;} |
    '('E ')'    {$$ = $2;} |
    NUMBER      {$$ = $1;}

%%

int main() {
    printf("Enter your Arithemetic Expression: ");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf("\nInvalid Arithemetic Expression!\n");
    exit(0);
}

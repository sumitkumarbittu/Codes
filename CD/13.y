%{
    #include<stdio.h>
    #include<stdlib.h>

    int yylex();
    void yyerror(const char *s);
%}

%token NUMBER

%left '+' '-'
%left '*' '/'

%%
ArithemeticExpression : 
    E {
        printf("\nValid Expression\n");
        exit(0);
    }

E : E '+' E |
    E '-' E |
    E '*' E |
    E '/' E |
    '(' E ')' |
    NUMBER;
%%

void yyerror(const char *s) {
    printf("\nInvalid Arithemetic Expression!\n");
    exit(0);
}

int main() {
    printf("Enter Arithemetic Expression: ");
    yyparse();
    return 0;
}
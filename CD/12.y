%{
    #include<stdio.h>
    #include<stdlib.h>    

    int yylex();
    void yyerror(const char *s);

%}

%token A B

%%
input :
    S '\n' {
        printf("Valid String\n");
        exit(0);
    }

S : 
    A B |
    A S B;
%%

void yyerror(const char *s) {
    printf("Invalid String!\n");
    exit(0);
}

int main() {
    printf("Input String: ");
    yyparse();
    return 0;
}
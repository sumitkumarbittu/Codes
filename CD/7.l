%{
#include<stdio.h>
%}

%%

"//".*                 ;          /* ignore single line comments */

"/*"([^*]|\n|(\*+([^*/]|\n)))*"*"+"/"    ;   /* ignore multi-line comments */

.|\n                   { fprintf(yyout,"%s",yytext); }

%%

int main()
{
    yyin = fopen("in.txt","r");
    yyout = fopen("out.txt","w");

    yylex();

    return 0;
}

int yywrap()
{
    return 1;
}
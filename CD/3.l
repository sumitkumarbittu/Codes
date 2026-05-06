%{
#include<stdio.h>
%}

%%

[0-9]+"."[0-9]+      { fprintf(yyout,"Float: %s\n",yytext); }

[0-9]+               { fprintf(yyout,"Integer: %s\n",yytext); }

.                    ;

%%

int main()
{
    yyin = fopen("input.txt","r");
    yyout = fopen("output.txt","w");

    yylex();

    return 0;
}

int yywrap()
{
    return 1;
}
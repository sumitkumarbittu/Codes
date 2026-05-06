%{
#include<stdio.h>
%}

%%

^(a|b)*a(a|b)(a|b)\n   { printf("Accepted\n"); }

^(a|b)*\n              { printf("Rejected\n"); }

. ;

%%

int main()
{
    printf("Enter a string: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}

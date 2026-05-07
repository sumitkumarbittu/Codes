%{
#include <stdio.h>
%}

%s Q1 Q2 DEAD

%%

<INITIAL>0        { BEGIN(INITIAL); }
<INITIAL>1        { BEGIN(Q1); }
<INITIAL>\n       { printf("Rejected\n"); BEGIN(INITIAL); }
<INITIAL>.        { BEGIN(DEAD); }

<Q1>0             { BEGIN(INITIAL); }
<Q1>1             { BEGIN(Q2); }
<Q1>\n            { printf("Rejected\n"); BEGIN(INITIAL); }
<Q1>.             { BEGIN(DEAD); }

<Q2>0             { BEGIN(INITIAL); }
<Q2>1             { BEGIN(Q2); }
<Q2>\n            { printf("Accepted\n"); BEGIN(INITIAL); }
<Q2>.             { BEGIN(DEAD); }

<DEAD>[01]        { BEGIN(DEAD); }
<DEAD>.           { BEGIN(DEAD); }
<DEAD>\n          { printf("Invalid / Rejected\n"); BEGIN(INITIAL); }

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter binary string: ");
    yylex();
    return 0;
}
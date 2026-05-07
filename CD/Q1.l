%{
#include <stdio.h>
%}

%s q1 q2 DEAD

%%

<INITIAL>0        BEGIN(q1);
<INITIAL>1        BEGIN(INITIAL);

<q1>0             BEGIN(q2);
<q1>1             BEGIN(INITIAL);

<q2>0             BEGIN(DEAD);
<q2>1             BEGIN(INITIAL);

<DEAD>[01]        BEGIN(DEAD);

<INITIAL>\n       { printf("Accepted\n"); BEGIN(INITIAL); }
<q1>\n            { printf("Accepted\n"); BEGIN(INITIAL); }
<q2>\n            { printf("Accepted\n"); BEGIN(INITIAL); }
<DEAD>\n          { printf("Rejected\n"); BEGIN(INITIAL); }

[ \t]             ;
.                 { printf("Invalid character\n"); BEGIN(DEAD); }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter binary string: ");
    yylex();
    return 0;
}
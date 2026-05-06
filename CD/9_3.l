%{
#include<stdio.h>    
%}

%s q1 q2 q3 DEAD

%%
<INITIAL>a          BEGIN q1;
<INITIAL>b          BEGIN q2;
<INITIAL>[^ab\n]    BEGIN DEAD;
<INITIAL>\n         {   BEGIN INITIAL; printf("Valid!\n");   }

<q1>a               BEGIN INITIAL;
<q1>b               BEGIN q3;
<q1>[^ab\n]         BEGIN DEAD;
<q1>\n              {   BEGIN INITIAL; printf("Not Valid!\n");   }

<q2>a               BEGIN q3;
<q2>b               BEGIN INITIAL;
<q2>[^ab\n]         BEGIN DEAD;
<q2>\n              {   BEGIN INITIAL; printf("Not Valid!\n");   }

<q3>a               BEGIN q2;
<q3>b               BEGIN q1;
<q3>[^ab\n]         BEGIN DEAD;
<q3>\n              {   BEGIN INITIAL; printf("Not Valid!\n");   }

<DEAD>a               BEGIN DEAD;
<DEAD>b               BEGIN DEAD;
<DEAD>[^ab\n]         BEGIN DEAD;
<DEAD>\n              {   BEGIN INITIAL; printf("InValid!\n");   }

%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}
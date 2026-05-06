%{
    #include<stdio.h>    
%}

%s BBA BAB BAA AAA AAB ABA ABB DEAD

%%
<INITIAL>a          BEGIN BBA;
<INITIAL>b          BEGIN INITIAL;
<INITIAL>[^ab\n]    BEGIN DEAD;
<INITIAL>\n         {   BEGIN INITIAL; printf("Rejected!\n");   }

<BBA>a          BEGIN BAA;
<BBA>b          BEGIN BAB;
<BBA>[^ab\n]    BEGIN DEAD;
<BBA>\n         {   BEGIN INITIAL; printf("Rejected!\n");   }

<BAB>a          BEGIN ABA;
<BAB>b          BEGIN ABB;
<BAB>[^ab\n]    BEGIN DEAD;
<BAB>\n         {   BEGIN INITIAL; printf("Rejected!\n");   }

<BAA>a          BEGIN AAA;
<BAA>b          BEGIN AAB;
<BAA>[^ab\n]    BEGIN DEAD;
<BAA>\n         {   BEGIN INITIAL; printf("Rejected!\n");   }

<AAA>a          BEGIN AAA;
<AAA>b          BEGIN AAB;
<AAA>[^ab\n]    BEGIN DEAD;
<AAA>\n         {   BEGIN INITIAL; printf("Accepted!\n");   }

<AAB>a          BEGIN ABA;
<AAB>b          BEGIN ABB;
<AAB>[^ab\n]    BEGIN DEAD;
<AAB>\n         {   BEGIN INITIAL; printf("Accepted!\n");   }

<ABA>a          BEGIN BAA;
<ABA>b          BEGIN BAB;
<ABA>[^ab\n]    BEGIN DEAD;
<ABA>\n         {   BEGIN INITIAL; printf("Accepted!\n");   }

<ABB>a          BEGIN BBA;
<ABB>b          BEGIN INITIAL;
<ABB>[^ab\n]    BEGIN DEAD;
<ABB>\n         {   BEGIN INITIAL; printf("Accepted!\n");   }

<DEAD>a          BEGIN DEAD;
<DEAD>b          BEGIN DEAD;
<DEAD>[^ab\n]    BEGIN DEAD;
<DEAD>\n         {   BEGIN INITIAL; printf("Invalid Input!\n");   }
%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 1;
}
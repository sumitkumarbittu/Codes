%{
#include<stdio.h>
#include<string.h>

char buffer[100];
int i;
%}

%s INT FLOAT ID DEAD

%%
<INITIAL>[0-9]      {   i=0;    buffer[i++]=yytext[0];  BEGIN INT;  }
<INITIAL>[a-zA-Z_]  {   i=0;    buffer[i++]=yytext[0];  BEGIN ID;   }
<INITIAL>[ \t\n]    ;
<INITIAL>.          BEGIN DEAD;

<INT>[0-9]          {   buffer[i++]=yytext[0];  }
<INT>[.]            {   buffer[i++]='.';    BEGIN FLOAT;    }
<INT>[ \t\n]        {   buffer[i++]='\0';  printf("Integers: %s\n", buffer);  BEGIN INITIAL;  }
<INT>.              {   BEGIN DEAD; }

<FLOAT>[0-9]        {   buffer[i++]=yytext[0];  }
<FLOAT>[ \t\n]      {   buffer[i++]='\0';    printf("Float: %s\n", buffer);    BEGIN INITIAL;  }
<FLOAT>.            {   BEGIN DEAD; }

<ID>[a-zA-Z0-9_]    {   buffer[i++]=yytext[0];   }
<ID>[ \t\n]         {   buffer[i++]='\0';    printf("Identifer: %s\n", buffer);    BEGIN INITIAL;}
<ID>.               {   BEGIN DEAD; }

<DEAD>[ \t\n]       {   printf("Invalid Token!\n"); BEGIN INITIAL;  }
<DEAD>.             {   BEGIN DEAD; }

%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}

//lex 11_2.l && gcc lex.yy.c -o 1 && ./1
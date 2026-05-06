%{
#include<stdio.h>

int state = 0;

%}

%%

a {
    if(state==0) state=1;
    else if(state==1) state=0;
    else if(state==2) state=3;
    else if(state==3) state=2;
}

b {
    if(state==0) state=2;
    else if(state==1) state=3;
    else if(state==2) state=0;
    else if(state==3) state=1;
}

\n {
    if(state==3)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    state=0;
}

. ;

%%

int main()
{
printf("Enter string:\n");
yylex();
}

int yywrap()
{
return 1;
}
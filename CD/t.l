%{
    #include<stdio.h>
    int a=0,b=0;
%}

%%
a a++;

b b++;

\n {
    if(a%2==0 && b%2==0)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    a=0, b=0;
}

. ;
%%

int main() {
    yylex();

    return 0;
}

int yywrap() {
    return 1;
}

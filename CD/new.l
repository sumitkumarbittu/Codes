%{
#include <stdio.h>

int characters = 0;
int words = 0;
int whitespaces = 0;
int lines = 0;
%}

%%

\n              {
                    lines++;
                    whitespaces++;
                    characters++;
                }

[ \t]           {
                    whitespaces++;
                    characters++;
                }

[^ \t\n]+       {
                    words++;
                    characters += yyleng;
                }

%%

int yywrap() {
    return 1;
}

int main() {
    FILE *fp;

    fp = fopen("Input.txt", "r");

    if (fp == NULL) {
        printf("Error: Cannot open Input.txt\n");
        return 1;
    }

    yyin = fp;

    yylex();

    fclose(fp);

    printf("Total Characters: %d\n", characters);
    printf("Total Words: %d\n", words);
    printf("Total White Spaces: %d\n", whitespaces);
    printf("Total Lines: %d\n", lines);

    return 0;
}




%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

[ \t\n]+        {
                    fprintf(yyout, " ");
                }

.               {
                    fprintf(yyout, "%s", yytext);
                }

%%

int yywrap() {
    return 1;
}

int main() {
    FILE *fp1, *fp2;

    fp1 = fopen("Input.txt", "r");
    fp2 = fopen("Output.txt", "w");

    if (fp1 == NULL) {
        printf("Error: Cannot open Input.txt\n");
        return 1;
    }

    if (fp2 == NULL) {
        printf("Error: Cannot create Output.txt\n");
        fclose(fp1);
        return 1;
    }

    yyin = fp1;
    yyout = fp2;

    yylex();

    fclose(fp1);
    fclose(fp2);

    printf("White spaces replaced successfully. Check Output.txt\n");

    return 0;
}

%{
#include <stdio.h>
#include <stdlib.h>
%}

%x COMMENT LINECOMMENT STRING CHAR

%%

"//"                    { BEGIN(LINECOMMENT); }

<LINECOMMENT>\n         {
                            fprintf(yyout, "\n");
                            BEGIN(INITIAL);
                        }

<LINECOMMENT>.          { /* remove single line comment */ }


"/*"                    { BEGIN(COMMENT); }

<COMMENT>"*/"           { BEGIN(INITIAL); }

<COMMENT>\n             {
                            fprintf(yyout, "\n");
                        }

<COMMENT>.              { /* remove multi line comment */ }


\"                      {
                            fprintf(yyout, "%s", yytext);
                            BEGIN(STRING);
                        }

<STRING>\\.             {
                            fprintf(yyout, "%s", yytext);
                        }

<STRING>\"              {
                            fprintf(yyout, "%s", yytext);
                            BEGIN(INITIAL);
                        }

<STRING>\n              {
                            fprintf(yyout, "%s", yytext);
                            BEGIN(INITIAL);
                        }

<STRING>.               {
                            fprintf(yyout, "%s", yytext);
                        }


\'                      {
                            fprintf(yyout, "%s", yytext);
                            BEGIN(CHAR);
                        }

<CHAR>\\.               {
                            fprintf(yyout, "%s", yytext);
                        }

<CHAR>\'                {
                            fprintf(yyout, "%s", yytext);
                            BEGIN(INITIAL);
                        }

<CHAR>\n                {
                            fprintf(yyout, "%s", yytext);
                            BEGIN(INITIAL);
                        }

<CHAR>.                 {
                            fprintf(yyout, "%s", yytext);
                        }


\n                      {
                            fprintf(yyout, "\n");
                        }

.                       {
                            fprintf(yyout, "%s", yytext);
                        }

%%

int yywrap() {
    return 1;
}

int main() {
    char inputFile[100];

    printf("Enter input C file name: ");
    scanf("%s", inputFile);

    yyin = fopen(inputFile, "r");
    yyout = fopen("out.c", "w");

    if (yyin == NULL) {
        printf("Error: Cannot open input file\n");
        return 1;
    }

    if (yyout == NULL) {
        printf("Error: Cannot create out.c file\n");
        fclose(yyin);
        return 1;
    }

    yylex();

    fclose(yyin);
    fclose(yyout);

    printf("Comments removed successfully. Check out.c\n");

    return 0;
}


%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

"<"[^>]*">"        {
                        fprintf(yyout, "%s\n", yytext);
                    }

\n                  {
                        /* ignore new lines */
                    }

.                   {
                        /* ignore other text */
                    }

%%

int yywrap() {
    return 1;
}

int main() {
    char inputFile[100];
    char outputFile[100];

    printf("Enter HTML input file name: ");
    scanf("%s", inputFile);

    printf("Enter output text file name: ");
    scanf("%s", outputFile);

    yyin = fopen(inputFile, "r");
    yyout = fopen(outputFile, "w");

    if (yyin == NULL) {
        printf("Error: Cannot open input HTML file\n");
        return 1;
    }

    if (yyout == NULL) {
        printf("Error: Cannot create output text file\n");
        fclose(yyin);
        return 1;
    }

    yylex();

    fclose(yyin);
    fclose(yyout);

    printf("HTML tags extracted successfully.\n");

    return 0;
}


%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

[ \t\n]+        {
                    fprintf(yyout, " ");
                }

.               {
                    fprintf(yyout, "%s", yytext);
                }

%%

int yywrap() {
    return 1;
}

int main() {
    FILE *fp1, *fp2;

    fp1 = fopen("Input.txt", "r");
    fp2 = fopen("Output.txt", "w");

    if (fp1 == NULL) {
        printf("Error: Cannot open Input.txt\n");
        return 1;
    }

    if (fp2 == NULL) {
        printf("Error: Cannot create Output.txt\n");
        fclose(fp1);
        return 1;
    }

    yyin = fp1;
    yyout = fp2;

    yylex();

    fclose(fp1);
    fclose(fp2);

    printf("White spaces replaced successfully. Check Output.txt\n");

    return 0;
}
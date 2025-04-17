%{
    #include <stdio.h>
%}

%%
"//".*                              { /* Ignore single-line comments */ }
"/*"(.|\n)*?"*/"                 { /* Ignore multi-line comments */ }
[^\n]+                          { fprintf(yyout, "%s", yytext); }  // Print non-comment lines
\n                              { fprintf(yyout, "\n"); }           // Keep line structure
%%

int main() {
    yyin = fopen("TestOne.c", "r");
    yyout = fopen("WithOutComment.c", "w");
    yylex();

    printf("Task done\n");

    return 0;
}

int yywrap() {
    return 1;
}

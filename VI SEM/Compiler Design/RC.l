%{
#include <stdio.h>
%}

%x COMMENT
%%
"//".*                       { /* do nothing */ }
"/*"                         { BEGIN(COMMENT); }
<COMMENT>"*/"                { BEGIN(INITIAL); }
<COMMENT>.|\n                { /* consume content */ }
.|\n                         { fprintf(yyout, "%s", yytext); }
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

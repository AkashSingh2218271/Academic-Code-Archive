%{
    #include <stdio.h>

    FILE *yyin, *yyout;
%}

%%

\<[^>]+\>    { fprintf(yyout, "%s\n", yytext); }

.|\n         { /* Ignore everything else */ }

%%

int main() {
    yyin = fopen("Test.html", "r");
    if (!yyin) {
        perror("Failed to open input file");
        return 1;
    }

    yyout = fopen("HtmlTags.html", "w");
    if (!yyout) {
        perror("Failed to open output file");
        return 1;
    }

    yylex();

    fclose(yyin);
    fclose(yyout);

    printf("Task done\n");

    return 0;
}

int yywrap() {
    return 1;
}

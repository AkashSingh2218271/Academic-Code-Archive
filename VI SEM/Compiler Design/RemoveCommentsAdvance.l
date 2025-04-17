%{
    #include <stdio.h>
    #include <string.h>
%}

%%
.*"//".*     {
    char *comment_pos = strstr(yytext, "//");
    if (comment_pos != NULL) {
        *comment_pos = '\0'; // Truncate at //
        fprintf(yyout, "%s\n", yytext); // Print code before //
    }
}
.*"/*".*"*/" {
    char temp[1024];
    strcpy(temp, yytext);
    char *start = strstr(temp, "/*");
    char *end = strstr(temp, "*/");
    if (start && end && end > start) {
        *start = '\0'; // Truncate before block comment
        fprintf(yyout, "%s\n", temp); // Print code before comment
    } else {
        fprintf(yyout, "%s\n", yytext); // fallback
    }
}
\/\*([^*]|\*+[^*/])*\*+\/   { /* ignore block comment */ }
[^\n]+       { fprintf(yyout, "%s", yytext); }  // Print normal code
\n           { fprintf(yyout, "\n"); }          // Preserve line breaks

%%

int main() {
    yyin = fopen("TestOne.c", "r");
    yyout = fopen("WithOutComment.c", "w");
    yylex();

    fclose(yyin);
    fclose(yyout);

    printf("Task done\n");
    return 0;
}

int yywrap() {
    return 1;
}

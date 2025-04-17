%{
    #include <stdio.h>
%}

%%
[" "\t\n]+    { fprintf(yyout, " "); }
[^" "\t\n]+   { fprintf(yyout, "%s", yytext); }
%%

int main() {
    yyin = fopen("extraSpaces.txt", "r");
    yyout = fopen("singleSpaces.txt", "w");

    if (!yyin || !yyout) {
        printf("Error opening files.\n");
        return 1;
    }

    yylex();

    fclose(yyin);
    fclose(yyout);

    printf("File processing completed!\n");

    return 0;
}

int yywrap() {
    return 1;
}

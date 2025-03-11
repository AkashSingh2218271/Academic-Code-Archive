%{
    #include <stdio.h>
%}

%%
^[a-zA-Z_][a-zA-Z0-9_]* {printf("Valid Identifier");}
^[^a-zA-Z_\n]+ {printf("Invalid Identifier");}
.* {printf("Invalid Identifier");}
\n {return 0;}
%%

int main() {
    printf("Enter string you want to check: ");
    yylex();

    return 0;
}

int yywrap() {
    return 1;
}

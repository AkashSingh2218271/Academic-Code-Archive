%{
    #include <stdio.h>
%}

%%
^[a-z.0-9]+@[a-z]+.com { printf("%s is a valid email address", yytext); }
.* { printf("%s is not a valid email address", yytext); }
\n { return 0; }
%%

int main() {
    printf("Enter a sting to check email or not ");
    yylex();

    return 0;
}

int yywrap() {
    return 1;
}
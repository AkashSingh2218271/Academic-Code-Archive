%{
    #include <stdio.h>
%}

%%
[0-9]*[13579] { printf("%s is odd number.", yytext); }
[0-9]*[02468] { printf("%s is even number.", yytext); }
.* { printf("%s is invalid number.", yytext); }
\n { return 0; }
%%

int main() {
    printf("Enter a number to check ");
    yylex();

    return 0;
}

int yywrap() {
    return 1;
}
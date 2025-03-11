%{
    #include <stdio.h>
%}

%%
^[-+]?[0-9]+ { printf("Valid Integer"); }
^[-+]?[0-9]*[.][0-9]+ { printf("Valid Floating point number"); }
.* { printf("Not a valid number"); }
\n { return 0; }
%%

int main() {
    printf("Enter a number to check weather it is floating point number or not ");
    yylex();

    return 0;
}

int yywrap() {
    return 1;
}
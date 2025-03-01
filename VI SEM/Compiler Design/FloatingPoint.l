%{
    #include <stdio.h>
%}

%%
[0-9]*[.][0-9]+ {printf("Floating point number\n");}
[0-9]+ {printf("Integer\n");}
. {printf("Not a floating point number\n");}
\n exit(0);
%%

int main() {
    printf("Enter a number to check weather it ismfloating point number or not ");
    yylex();

    return 0;
}

int yywrap() {
    return 1;
}
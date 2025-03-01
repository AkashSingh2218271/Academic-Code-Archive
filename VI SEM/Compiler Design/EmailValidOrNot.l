%{
    #include <stdio.h>
%}

%%
"0" {return 0;}
^[a-z.0-9]+"@"[a-z]+".com" {printf("This is a valid email address\n");}
.* {printf("This is not a valid email address\n");}
%%

int main() {
    printf("Enter a sting to check email or not and 0 to break/exit ");
    yylex();

    exit(0);

    return 0;
}

int yywrap() {
    return 1;
}
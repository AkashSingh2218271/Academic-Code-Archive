%{
    #include <stdio.h>
%}

%% 
^[a-zA-Z_][a-zA-Z0-9_]* {printf("Identifier\n");}   
^[0-9]+ {printf("Not a Identifier\n");}
\n {return 0;}
%%

int main() {
    printf("Enter string you want to check ");
    yylex();
    
    exit(0);

    return 0;
}

int yywrap() {
    return 1;
}



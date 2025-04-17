%{
    #include <stdio.h>
%}

%%
"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"inline"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while" { printf("keyword is %s\n", yytext); }
\"(\\.|[^\\"])*\" { printf("String Literal %s\n", yytext); }
[0-9]+                { printf("Constant (Integer) %s\n", yytext); }
[0-9]*\.[0-9]+        { printf("Constant (Float) %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("Identifier %s\n", yytext); }
[ \t]+ { /* Ignore whitespace */ }
. { printf("Others %s\n", yytext); }
\n { return 0; }
%%

int main() {
    printf("Enter your code (CTRL + Z + enter to end input)\n");
    yylex(); // Start lexical analysis
    return 0;
}

int yywrap() {
    return 1;
}

%{
	#include <stdio.h>
%}

%%
"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"inline"|"int"|"long"|"register"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"_Alignas"|"_Alignof"|"_Atomic"|"_Bool"|"_Complex"|"_Generic"|"_Imaginary"|"_Noreturn"|"_Static_assert"|"_Thread_local" { printf("keyword: %s\n", yytext); }
"+"|"-"|"*"|"/"|"%"|"=" { printf("Operator: %s\n",yytext); }
"{"|"}"|"("|")"|";"|"," { printf("Seperator: %s\n",yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("Identifier: %s\n",yytext); }
[ \t] { }
. { printf("Unknown: %s\n",yytext); }
\n { return 0; }
%%

int main() {
	printf("Enter a expression to check \n");
	yylex();
	
	return 0;
}

int yywrap() {
	return 1;
}

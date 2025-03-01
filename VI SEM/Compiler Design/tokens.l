%{
	#include <stdio.h>
%}

%%
[auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|inline|int|long|register|restrict|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while]+ { printf("This is a keyword %s\n", yytext);}
[a-zA-Z]+ { printf("This is a variable %s\n", yytext);}
[,;(){}]+ { printf("This is a separator %s\n", yytext);}
[0-9]+ { printf("This is a constant %s\n", yytext);}
[+-/*%=]+ { printf("This is a operator %s\n", yytext);}
[" "]+ {printf("This is a space %s\n", yytext);}
\n {exit(0);}
%%

int main() {
	printf("Enter a expression to check \n");
	yylex();
	
	return 0;
}

int yywrap() {
	return 1;
}

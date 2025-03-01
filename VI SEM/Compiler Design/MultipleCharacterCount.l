%{
    #include <stdio.h>
    int line_count = 0, space_count = 0, tab_count = 0, rest_count = 0;
%}

%%
"0" {return 0;}
[\n] {++line_count;}
[" "] {++space_count;}
[\t] {++tab_count;}
[^\n" "\t] {++rest_count;}
%%

int main() {
    printf("Enter a sting to count different character and 0 to break ");
    yylex();
    
    printf("Line count is %d\n", line_count);
    printf("Space count is %d\n", space_count);
    printf("Tab count is %d\n", tab_count);
    printf("Rest count is %d\n", rest_count);
    exit(0);

    return 0;
}

int yywrap() {
    return 1;
}
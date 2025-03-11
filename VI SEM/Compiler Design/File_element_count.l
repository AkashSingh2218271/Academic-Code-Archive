/* 
Program to count the number of characters, words, and spaces in a file
Sample input: Hello and welcome to CD lab.
Expected output: 
no. of words: 6
no. of characters: 27
no. of spaces: 5
*/

%{
    #include <stdio.h>
    int space_count = 0, word_count = 0, char_count = 0;
%}

%%
[a-zA-Z0-9]+ { 
    word_count++;
    char_count += yyleng;
}
[ \t]+ {
    space_count += yyleng;
    char_count += yyleng;
}
\n {
    char_count++;
}
. {
    char_count++;
}
%%

int main() {
    yyin = fopen("file.txt", "r");

    if (!yyin) {
        printf("Failed to open file.\n");
        return 1;
    }

    yylex();

    printf("no. of words: %d\n", word_count);
    printf("no. of characters: %d\n", char_count);
    printf("no. of spaces: %d\n", space_count);

    fclose(yyin);
    return 0;
}

int yywrap() {
    return 1;
}

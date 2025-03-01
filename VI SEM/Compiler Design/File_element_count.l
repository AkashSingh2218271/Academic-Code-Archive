%{
    #include <stdio.h>
    int space_count = 0, word_count = 0, char_count = 0;
%} 

%%
[a-zA-Z0-9] {char_count++;}
\n|\t {word_count++;}
" " {word_count++; space_count++;  char_count++;}
%%

int main() {
    // Extern file *yyin, *yyout;
    yyin = fopen("file.txt", "r");
    //("Enter a string to check ");
    yylex();
    printf("Number of space in file is %d\n", space_count);
    printf("Number of word in file is %d\n", ++word_count);
    printf("Number of character in file is %d\n", char_count);

    return 0;
}

int yywrap() {
    return 1;
}
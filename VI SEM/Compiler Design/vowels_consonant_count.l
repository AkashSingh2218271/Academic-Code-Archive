%{
    #include <stdio.h>
    int vowels_count = 0, consonant_count = 0;
%} 

%%
[a|e|i|o|u|A|E|I|O|U] {vowels_count++;}
" "|\n|\t {consonant_count;}
[^a|e|i|o|u|A|E|I|O|U] {consonant_count++;}
%%

int main() {
    yyin = fopen("vowelAndCons.txt", "r");
    yylex();
    printf("Number of vowels in file is %d\n", vowels_count);
    printf("Number of consonant in file is %d\n", consonant_count);

    return 0;
}

int yywrap() {
    return 1;
}
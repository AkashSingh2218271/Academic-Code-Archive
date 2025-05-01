%{
    #include <stdio.h>
%}
%s A B C DEAD
%%
<INITIAL>\n printf("Accepted\n"); BEGIN INITIAL;
<INITIAL>a BEGIN A;
<INITIAL>b BEGIN B;
<A>a BEGIN INITIAL;
<A>b BEGIN C;
<A>\n BEGIN INITIAL; printf("not accepted\n");
<B>a BEGIN C;
<B>b BEGIN INITIAL;
<B>\n BEGIN INITIAL; printf("not accepted\n");
<C>a BEGIN B;
<C>b BEGIN A;
<C>\n BEGIN INITIAL; printf("not accepted\n");
<A>[^ab\n] BEGIN DEAD;
<B>[^ab\n] BEGIN DEAD;
<C>[^ab\n] BEGIN DEAD;
<INITIAL>[^ab\n] BEGIN DEAD;
<DEAD>[^\n] BEGIN DEAD;
<DEAD>[\n] BEGIN INITIAL; printf("Invalid Input\n");
%%
int main(){
  printf("Enter the String of a and b only:\n");
  yylex();
}
int yywrap() {
    return 1;
}





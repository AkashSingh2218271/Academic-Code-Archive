%{
#include<stdio.h>
%}
%s B C  E DEAD
%%
<INITIAL>\n  BEGIN  INITIAL; { printf("Accepted\n"); }
<INITIAL>a  BEGIN B;
<INITIAL>b BEGIN B;
<INITIAL>[^ab\n]  BEGIN DEAD;
<B>\n BEGIN INITIAL; { printf("Accepted\n"); }
<B>a  BEGIN C;
<B>b  BEGIN C;
<B>[^ab\n] BEGIN DEAD;
<C>\n  BEGIN INITIAL; { printf("Accepted\n"); }
<C>a  BEGIN E;
<C>b  BEGIN E; 
<C>[^ab\n]  BEGIN DEAD;
<E>\n  BEGIN INITIAL; { printf("Not Accepted\n"); }
<E>a BEGIN E; 
<E>b  BEGIN E; 
<E>[^ab\n]  BEGIN DEAD; 
<DEAD>. BEGIN DEAD;
<DEAD>\n BEGIN INITIAL; { printf("Invalid input\n"); }
%%
int main() {
printf("Enter the string to check\n");
yylex();
return 0;
}
int yywrap() {
 return 1;
}
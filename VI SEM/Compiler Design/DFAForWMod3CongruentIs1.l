%{
#include<stdio.h>
%}
%s B C DEAD
%%
<INITIAL>\n  BEGIN  INITIAL; { printf("Not Accepted\n"); }
<INITIAL>a  BEGIN B;
<INITIAL>b BEGIN B;
<INITIAL>[^ab\n]  BEGIN DEAD;
<B>\n BEGIN INITIAL; { printf("Accepted\n"); }
<B>a  BEGIN C;
<B>b  BEGIN C;
<B>[^ab\n] BEGIN DEAD;
<C>\n BEGIN INITIAL;  { printf("Not Accepted\n"); }
<C>a  BEGIN INITIAL;
<C>b  BEGIN INITIAL;
<C>[^ab\n]  BEGIN DEAD;
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

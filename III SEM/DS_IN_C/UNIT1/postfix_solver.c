#include <stdio.h>
#include <stdlib.h>
# define M 100
int stack[100];
int top = -1;
//char postfix[M];
void push(int ch) {
    if (top == M -1)
    {
        printf("stack overflow.\n");
    }
    stack[++top] = ch;
}
int pop() {
    if (top == -1)
    {
        return -1;
    }
    return stack[top--];
}
int is_operator(char ch) {
    if(ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-') {
        return 1;
    }
    return 0;
}
int postfix_solver(char postfix[]){
    int i = 0;
    char ch = postfix[i];
    int operand1, operand2, result = 0;
    while (ch != '\0')
    {
    if (ch >= '0'&& ch <= '9')
    {
        int num = ch - '0';
        push(num);
    }
    else if (is_operator(ch))
    {
        operand2 = pop();
        operand1 = pop();
        switch (ch)
        {
        case '^':
            result =  operand1 ^ operand2;
            break;
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            result = operand1 / operand2;
            break;
        }
        push(result);
    }
    i++;
    ch = postfix[i];
}
result = pop();
return result;
}
int main() {
    char postfix[] = "5 6 7 + * 8 -";
    printf("solution of postfix expression is -> %d", postfix_solver(postfix));
    return 0;
}
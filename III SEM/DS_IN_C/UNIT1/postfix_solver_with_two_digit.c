#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 100
// todo postfix solver ->>
int stack[M];
int top = -1;
void push(int m)
{
    if (top == M - 1)
    {
        printf("Stack is full.\n");
    }
    stack[++top] = m;
}
int pop()
{
    if (top == -1)
    {
        printf("stack is empty.\n");
    }
    return stack[top--];
}
int is_operator(char ch)
{
    if (ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-')
    {
        return 1;
    }
    return 0;
}
int postfix_sovlver(char postfix[])
{
    int i = 0;
    char ch = postfix[i];
    int operand1, operand2, result = 0;
    while (ch != '\0')
    {

        int num = 0;
        if (isdigit(ch))
        {
            while (isdigit(ch))
            {
                num = num * 10 + (ch - '0');
                //printf("%d\n", num);
                i++;
                ch = postfix[i];
            }
            push(num);
        }
        else if (is_operator(ch))
        {
            operand2 = pop();
            // printf("op2 = %d\n", operand2);
            operand1 = pop();
            // printf("op1 = %d\n", operand1);
            switch (ch)
            {
            case '^':
                result = pow(operand1, operand2);
                break;
            case '+':
                result = operand1 + operand2;
                // printf("%d\n", result);
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
int main()
{
    char postfix[100];
    printf("Enter postfix->>\n");
    scanf("%[^\n]s", postfix);
    int x = postfix_sovlver(postfix);
    printf("result ->> %d", x);
    return 0;
}
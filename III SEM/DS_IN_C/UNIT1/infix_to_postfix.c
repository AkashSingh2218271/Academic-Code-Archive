#include <stdio.h>
#define M 100
#define N 30
// todo infix to postfix conversion ->> 
int top = -1;
char stack[M];
char infix[N];
char postfix[N];

int isEmpty()
{
    return top == -1;
}
int isFull()
{
    return top == M - 1;
}
char peek()
{
    return stack[top];
}
void push(char ch)
{
    if (isFull())
    {
        printf("stack overflow.\n");
    }
    stack[++top] = ch;
}
char pop()
{
    if (top == -1)
    {
        return -1;
    }
    return stack[top--];
}
int check_if_operand(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}
int precedence(char ch)
{
    switch (ch)
    {
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    case '^':
        return 3;
    }
    return -1;
}
void convert_infix_to_postfix()
{
    int i, j;
    for (i = 0, j = -1; infix[i] != '\0'; i++)
    {
        if (check_if_operand(infix[i]))
        {
            postfix[++j] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                postfix[++j] = pop();
            }
            pop();
            /* if (!isEmpty() && peek() != '(')
            {
                return -1;
            }
            else
            {
                pop();
            } */
        }
            else
            {
                while (!isEmpty() && precedence(infix[i]) <= precedence(peek()))
                { 
                    postfix[++j] = pop();
                }
                push(infix[i]);
            }
    }
         while (!isEmpty())
        {
            postfix[++j] = pop();
        }
    postfix[++j] = '\0';
}
int main()
{
    printf("Enter infix expression\n");
    scanf("%[^\n]s", infix);
    convert_infix_to_postfix();
    printf("postfix expression is -> %s", postfix);
    return 0;
}
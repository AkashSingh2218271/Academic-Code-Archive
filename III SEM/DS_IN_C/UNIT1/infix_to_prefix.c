#include <stdio.h>
#include <string.h>
#define M 30
#define N 30
// todo infix to prefix conversion ->>
char stack[M];
char infix[N];
char prefix[N];
int top = -1;
int isEmpty()
{
    return top == -1;
}
void push(char ch)
{
    if (top == M - 1)
    {
        printf("stack is full.\n");
    }
    stack[++top] = ch;
}
char pop()
{
    if (top == -1)
    {
        printf("stack is empty.\n");
    }
    return stack[top--];
}
char peek()
{
    return stack[top];
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
// ~ reverse infix()
void reverse_infix()
{
    int n = strlen(infix);
    // ! using two pointer approach to reverse array ->>
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        if (infix[s] == '(')
        {
            infix[s] = ')';
        } else if (infix[s] == ')')
        {
            infix[s] = '(';
        }
        if (infix[e] == ')')
        {
            infix[e] = '(';
        } else if (infix[e] == '(')
        {
            infix[e] = ')';
        }
        char ch = infix[s];
        infix[s] = infix[e];
        infix[e] = ch;
        s++;
        e--;
    }
}
void reverse_prefix() 
{
    int size = strlen(prefix);
    // ! two pointer approach -->>
    int s = 0;
    int e = size - 1;
    while (s < e)
    {
        char ch = prefix[s];
        prefix[s] = prefix[e];
        prefix[e] = ch;
        s++;
        e--;
    }
}
int convert_infix_to_prefix()
{
    int i, j;
    for (i = 0, j = -1; infix[i] != '\0'; i++)
    {
        if (check_if_operand(infix[i]))
        {
            prefix[++j] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                prefix[++j] = pop();
            }
            if (!isEmpty() && peek() != '(')
            {
                return -1;
            }
            else
            {
                pop();
            }
        }
        else
        {
            while (!isEmpty() && precedence(infix[i]) < precedence(peek()))
            {
                prefix[++j] = pop();
            }
            push(infix[i]);
        }
    }
    while (!isEmpty())
    {
        prefix[++j] = pop();
    }
    prefix[++j] = '\0';
}
int main()
{
    printf("Enter infix expresion.\n");
    scanf("%[^\n]s", &infix);
    reverse_infix();
    // ! printf("reverse infix expression is -->> %s\n", infix);
    convert_infix_to_prefix();
    // ! printf("prefix without reverse ->> %s\n", prefix);
    reverse_prefix();
    printf("prefix expression is -->> %s\n", prefix);
    return 0;
}
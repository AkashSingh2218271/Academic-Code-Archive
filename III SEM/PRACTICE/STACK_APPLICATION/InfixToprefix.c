#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 30
// todo /* stack application infix to prefix conversion */
char stack[M];
int top = -1;
// info /* stack implementation */
// ! /* Push , Pop , isEmpty, Peek */
// ~ Push()
void Push(char x)
{
    if (top == M - 1)
    {
        printf("Stack overflow.\n");
    }
    stack[++top] = x;
}
// ~ Pop()
char Pop()
{
    if (top == -1)
    {
        printf("Stack underflow.\n");
    }
    return stack[top--];
}
// ~ isEmpty()
int isEmpty()
{
    return top == -1;
}
// ~ Peek()
char peek()
{
    return stack[top];
}
// * Precedence()
int check_precedence(char x)
{
    switch (x)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}
// * isOperand()
int isOperand(char x)
{
    return ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') || (x >= '0' && x <= '9'));
}
// * reverse prefix()
void reverse_prefix(char prefix[])
{
    // ! /* using two pointer approach */
    int s = 0;
    int e = strlen(prefix) - 1;
    while (s < e)
    {
        char c = prefix[s];
        prefix[s] = prefix[e];
        prefix[e] = c;
        s++;
        e--;
    }
}
// * revrese infix()
void reverse_infix(char infix[])
{
    // ! /* using two pointer approach */
    int s = 0;
    int e = strlen(infix) - 1;
    while (s < e)
    {
        if (infix[s] == '(')
        {
            infix[s] = ')';
        }
        else if (infix[s] == ')')
        {
            infix[s] = '(';
        }
        if (infix[e] == '(')
        {
            infix[e] = ')';
        }
        else if (infix[e] == ')')
        {
            infix[e] = '(';
        }
        char c = infix[s];
        infix[s] = infix[e];
        infix[e] = c;
        s++;
        e--;
    }
}
// ! infix_to_preprefix()
void infix_to_preprefix(char infix[], char prefix[])
{
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            prefix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            Push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                prefix[j++] = Pop();
            }
            Pop();
        }
        else
        {
            while (!isEmpty() && check_precedence(peek()) > check_precedence(infix[i]))
            {
                prefix[j++] = Pop();
            }
            Push(infix[i]);
        }
        i++;
    }
    while (!isEmpty())
    {
        prefix[j++] = Pop();
    }
    prefix[j] = '\0';
}
// * Main function()
int main()
{
    char infix[M], prefix[M];
    printf("Enter a Infix Expression: ");
    scanf("%[^\n]s", &infix);
    printf("Entered Infix Expression: %s\n", infix);
    reverse_infix(infix);
    printf("Entered Infix Expression after reversing: %s\n", infix);
    infix_to_preprefix(infix, prefix);
    reverse_prefix(prefix);
    printf("Corresponding prefix Expression: %s\n", prefix);
    return 0;
}
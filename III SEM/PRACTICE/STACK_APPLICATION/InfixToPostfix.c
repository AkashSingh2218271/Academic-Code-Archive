#include <stdio.h>
#include <stdlib.h>
#define M 30
// todo /* stack application infix to postfix conversion */
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
// ! infix_to_postfix()
void infix_to_postfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            Push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                postfix[j++] = Pop();
            }
            Pop();
        }
        else
        {
            while (!isEmpty() && check_precedence(peek()) >= check_precedence(infix[i]))
            {
                postfix[j++] = Pop();
            }
            Push(infix[i]);
        }
        i++;
    }
    while (!isEmpty())
    {
        postfix[j++] = Pop();
    }
    postfix[j] = '\0';
}
// * Main()
int main()
{
    char infix[M], postfix[M];
    printf("Enter a Infix Expression: ");
    scanf("%[^\n]s", &infix);
    printf("Entered Infix Expression: %s\n", infix);
    infix_to_postfix(infix, postfix);
    printf("Corresponding postfix Expression: %s\n", postfix);
    return 0;
}
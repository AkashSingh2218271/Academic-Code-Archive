#include <stdio.h>
// todo -> infix to postfix conversion ->
#define M 50
#define N 30
char stack[M];
int top = -1;
char infix[N];
char postfix[N];
void push(char ch)
{
    if (top == M - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        stack[++top] = ch;
    }
}
char pop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}
char peek()
{
    // ? printf("peek element is %c\n", stack[top]);
    return stack[top];
}
void display()
{
    printf("\n stack is ->\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%c\n", stack[i]);
    }
}
int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    if (ch == '*' || ch == '/')
    {
        return 2;
    }
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int is_operator(char ch)
{
    if ( ch == ')' || ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
void infix_to_postfix()
{
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        //char ch = infix[i];
        if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (!is_operator(infix[i]))
        {
            printf("%c\n", infix[i]);
            //printf("var\n");
            postfix[j++] = infix[i];
        }
        else if (is_operator(infix[i]))
        {
            if (precedence(infix[i]) >= precedence(peek()))
            {
                //printf("op\n");
                push(infix[i]);
            }
        }
        if (infix[i] == ')')
        {
            //printf("yes\n");
            while (!isEmpty() && peek() != '(')
            {
                postfix[++j] = pop();
            }
           if (!isEmpty() && peek() != '(')
            {
                return ;
            }
            else
            {
                pop();
            }
        }
        
        
        /* else if (ch == ')')
        {
            while (peek() != ')')
            {
                postfix[j++] = pop();
            }
        }
        else if (is_operator(ch))
        {
            if (top > -1)
            {
                while (precedence(ch) >= precedence(peek()))
                {
                    push(ch);
                }
            }
        }
        else
        {
            postfix[j++] = ch;
        } */
        i++;
    }
    /* 
    printf("%d\n", isEmpty());
    printf("%c\n", pop()); */
    while(!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
int main()
{
    printf("Enter value in infix.\n");
    scanf("%[^\n]s", infix);
    infix_to_postfix();
    printf("Postfix is -> ");
    printf("%s", postfix);
}
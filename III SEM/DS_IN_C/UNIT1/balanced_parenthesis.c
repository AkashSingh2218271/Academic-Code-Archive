#include <stdio.h>
#define M 50
char stack[M];
char expression[M];
int top = -1;
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

void balanced_parenthesis()
{
    int i = 0, flag = 0;
    char ch = expression[i];
    while (ch != '\0')
    {
        if (ch == '(')
        {
            push(')');
        }
        else if (ch == '{')
        {
            push('}');
        }
        else if (ch == '[')
        {
            push(']');
        }
        else if (top == -1)
        {
            flag = 0;
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (ch == pop())
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        i++;
        ch = expression[i];
    }
     if(top != -1){
       flag = 0;
    }
    if (flag)
    {
        printf("Balanced.\n");
    }
    else
    {
        printf("not balanced.\n");
    }
}

int main()
{
    printf("Enter expression.\n");
    scanf("%[^\n]s", &expression);
    balanced_parenthesis();
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#define M 30

int stack[M];
int top = -1;

void Push(int x)
{
    if (top == M - 1)
    {
        printf("Stack overflow.\n");
    }
    stack[++top] = x;
}

int Pop()
{
    if (top == -1)
    {
        printf("Stack underflow.\n");
    }
    return stack[top--];
}

int peek()
{
    return stack[top];
}

int isEmpty()
{
    return top == -1;
}

int isOperand(char x)
{
    return (x >= '0' && x <= '9');
}

int isOperator(char x)
{
    return (x == '^' || x == '/' || x == '*' || x == '-' || x == '+');
}

int evaluateExpression(char expr[])
{
    int len = strlen(expr);
    for (int i = len - 1; i >= 0; i--)
    {
        if (expr[i] == ' ')
        {
            // Skip spaces
            continue;
        }

        if (isOperand(expr[i]))
        {
            int num = 0;
            int digitPosition = 1;
            while (i >= 0 && isOperand(expr[i]))
            {       
                num = num + (expr[i] - '0') * digitPosition;
                // ? printf("di p = %d\n", digitPosition);
                // ? printf("num = %d\n", num);
                digitPosition *= 10;
                // ? printf("di p = %d\n", digitPosition);
                i--;
            }
            Push(num);
        }
        else if (isOperator(expr[i]))
        {
            int operand1 = Pop();
            int operand2 = Pop();
            int result;

            switch (expr[i])
            {
                case '^':
                    result = pow(operand1, operand2);
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '+':
                    result = operand1 + operand2;
                    break;
            }
            Push(result);
        }
    }
    return Pop();
}

int main()
{
    char expr[M];
    printf("Enter prefix expression: ");
    fgets(expr, sizeof(expr), stdin);
    int result = evaluateExpression(expr);
    printf("Result is: %d\n", result);
    
    return 0;
}

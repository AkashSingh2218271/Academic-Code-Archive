#include <stdio.h>
#include <string.h>
#include <math.h>
#define M 30
// todo /* Solving prefix prefixession */
int stack[M];
int top = -1;
// info /* implementation of stack */
// ! /* Push , Pop , isEmpty, Peek */
// ~ Push()
void Push(int x)
{
    if (top == M - 1)
    {
        printf("Stack overflow.\n");
    }
    stack[++top] = x;
}
// ~ Pop()
int Pop()
{
    if (top == -1)
    {
        printf("Stack underflow.\n");
    }
    return stack[top--];
}
// ~ Peek()
int peek()
{
    return stack[top];
}
// ~ isEmpty()
int isEmpty()
{
    return top == -1;
}
// * isOperand()
int isOperand(int x)
{
    return ((x >= '0' && x <= '9'));
}
// * isOpreator()
int isOpreator(char x)
{
    if (x == '^' || x == '/' || x == '*' || x == '-' || x == '+')
    {
        return 1;
    }
    return 0;
}
// ! PostfisSolver
void prefix_solver(char prefix[])
{
    int n = strlen(prefix) - 1;
    int operand1, operand2, result = 0;
    for (int i = n; i >= 0; i--)
    {
        
        if (prefix[i] == ' ')
        {
            // * Skip spaces
            continue;
        }
        if (isOperand(prefix[i]))
        {
            int num = 0;
            int digitPosition = 1;
            while (i >= 0 && isOperand(prefix[i]))
            {       
                num = num + (prefix[i] - '0') * digitPosition;
                // ? printf("di p = %d\n", digitPosition);
                // ? printf("num = %d\n", num);
                digitPosition *= 10;
                // ? printf("di p = %d\n", digitPosition);
                i--;
            }
            Push(num);
        }
        else if (isOpreator(prefix[i]))
        {  
            operand2 = Pop();
            // ? printf("op2 = %d\n", operand2);
            operand1 = Pop();
            // ? printf("op1 = %d\n", operand1);
            switch (prefix[i])
            {
            case '^':
                result = pow(operand1,operand2);
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
    result = Pop();
    printf("Result is : %d\n", result);
}
// * main()
int main()
{
    char prefix[M];
    printf("Enter prefix->>\n");
    scanf("%[^\n]s", prefix);
    prefix_solver(prefix);
    return 0;
}
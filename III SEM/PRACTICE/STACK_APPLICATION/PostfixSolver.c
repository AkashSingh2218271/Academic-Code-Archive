#include <stdio.h>
#include <math.h>
#define M 30
// todo /* Solving postfix expression */
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
void Postfix_solver(char postfix[])
{
    int operand1, operand2, result = 0;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (postfix[i] == ' ')
        {
            // ? Skip spaces
            continue;
        }
        if (isOperand(postfix[i]))
        {
            int num = 0;
            while (isOperand(postfix[i]))
            {
                num = num * 10 + (postfix[i] - '0');
                i++;
                // ? printf("n = %d\n", num);
            }
            Push(num);
        }
        else if (isOpreator(postfix[i]))
        {  
            operand2 = Pop();
            // ? printf("op2 = %d\n", operand2);
            operand1 = Pop();
            // ? printf("op1 = %d\n", operand1);
            switch (postfix[i])
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
    char postfix[M];
    printf("Enter postfix->>\n");
    scanf("%[^\n]s", postfix);
    Postfix_solver(postfix);
    return 0;
}
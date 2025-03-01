#include <stdio.h>
#define M 20
// todo /* depth of parenthesis */
char stack[M];
int top = -1;
// ~ /* push function */
void push(char x)
{
    if (top == M - 1)
    {
        printf("Stack is full.\n");
    }
    stack[++top] = x;
}
// ~ /* pop function */
char pop()
{
    if (top == -1)
    {
        printf("Stack is Empty.\n");
    }
    return stack[top--];
}
// ~ /* is empty function */
int is_Empty()
{
    return top == -1;
}
// ! /* function for checking depth of prrenthesis */
int check_depth_of_parenthesis(char expression[])
{
    int max, count, x;
    max = count = x = 0;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(')
        {
            push(expression[i]);
           // x++;
        }
        else if (expression[i] == ')')
        {
            
            while (!is_Empty())
            {
                pop();
                count++;
            }
            if (count > max)
            {
                // ? printf("c = %d\n", x);
                max = count;
                // ? printf("m = %d\n", x);
            }
            count--; 
            /*
            if (x > max)
            {
                max = x;
            }
            x--; */
        }
    }
    return max;
}
int main()
{
    char expression[M];
    printf("Enter expression for '(' ')' brackets : \n");
    scanf("%[^\n]s", &expression);
    printf("Depth of parenthesis is %d", check_depth_of_parenthesis(expression));
    return 0;
}
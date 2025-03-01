#include <stdio.h>
#include <stdlib.h>
#define N 5
// todo implementation of statck using array -> 
// ! LIFO -> last in first out 
int stack[N];
int top = -1;
void push()
{
    int n;
    printf("Enter a element to input in stack\n");
    scanf("%d", &n);
    if (top == N - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = n;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("stack underflow\n");
    }
    else
    {
        top--;
    }
}
void peek()
{
    printf("peek element is %d\n", stack[top]);
}
void display()
{
    printf("\n stack is ->\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}
int main()
{
    int ch=1;
    do
    {
        printf("Enter choice for stack operation\n");
        printf(" 1 for push\n2 for pop\n3 for peek\n4 for display\n0 for exit.\n");
        scanf("%d", &ch);
        //system("cls");
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            printf("Invalid input\n");
            break;
        }
    } while (ch != 0);
    //fflush(stdin); 
    /*for (int i = 0; i < N; i++)
    {
        push();
    }
    display();
    pop();
    pop();
    peek();
    display(); */
}
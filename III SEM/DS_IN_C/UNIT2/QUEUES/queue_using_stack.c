#include <stdio.h>
#include <stdlib.h>
#define N 20
// todo /* implement queue using stacks */
int stack[N];
int s[N];
int top = -1;
int t = -1;
// ~ /* push in stack */
void push_in_stack(int x)
{
    if (top == N - 1)
    {
        printf("stack is full.\n");
    }
    stack[++top] = x;
}
void push_in_s(int x)
{
    if (t == N - 1)
    {
        printf("stack is full. \n");
    }
    s[++t] = x;
}
// ~ /* pop in stack */
int pop_in_stack()
{
    if (top == -1)
    {
        printf("stack is empty.\n");
    }
    return stack[top--];
}
int pop_in_s()
{
    if (t == -1)
    {
        printf("stack is empty.\n");
    }
    return s[t--];
}
// ~ /* isEmpty in stack */
int isEmpty_stack()
{
    return top == -1;
}
int isEmpty_s()
{
    return t == -1;
}
// ~ /* display / traverse stack */
void display_stack()
{
    int i = 0;
    while (i < top)
    {
        printf("element in stack is -->> %d\n", stack[i++]);
    }
}
// ~ /* enqueue in queue using stack */
void enqueue(int x)
{
    push_in_stack(x);
}
// ~ /* dequeue in queue using stack */
void dequeue()
{
    while (!isEmpty_stack())
    {
        push_in_s(pop_in_stack());
    }
    pop_in_s();
    while (!isEmpty_s())
    {
        push_in_stack(pop_in_s());
    }
}
// ~ /* display queue using stack */
void display_queue()
{
    printf("Displaying queue -->>\n");
    display_stack();
}
int main()
{
    for (int i = 3; i < 9; i++)
    {
        enqueue(i);
    }
    display_queue();
    dequeue();
    dequeue();
    display_queue();
    enqueue(10);
    dequeue();
    display_queue();
    return 0;
}
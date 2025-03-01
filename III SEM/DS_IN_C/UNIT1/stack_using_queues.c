#include <stdio.h>
#define M 20
// todo implementation of stack using queues -->>
int queue[M];
int q[M];
int f = -1;
int r = -1;
int F = -1;
int R = -1;
void enqueue_in_q(int x)
{
    if (R != M - 1)
    {
        if (F == -1)
        {
            F = 0;
        }
        q[++R] = x;
    }
    else
    {
        printf("queue is full.\n");
    }
}
void enqueue(int x)
{
    if (r != M - 1)
    {
        if (f == -1)
        {
            f = 0;
        }
        queue[++r] = x;
    }
    else
    {
        printf("queue is full.\n");
    }
}
int dequeue()
{
    if (f == -1 || f > r)
    {
        printf("queue is empty.\n");
    }
    // ! printf("dequeue element is -->> %d\n", queue[f]);
    return queue[f++];
}
int dequeue_in_q()
{
    if (F == -1 || F > R)
    {
        printf("q is empty.\n");
    }
    // ! printf("dequeue element in q is -->> %d\n", q[F]);
    return q[F++];
}
int isEmpty_queue()
{
    return f == -1 || f > r;
}
int isEmpty_q()
{
    return F == -1 || F > R;
}
void display_queue()
{
    int t = f;
    while (t != r + 1)
    {
        printf("data in queue is -->> %d\n", queue[t]);
        t++;
    }
}
void pop()
{
    printf("popped element is -->> %d\n", dequeue());
}
void push(int x)
{
    while (!isEmpty_queue())
    {
        enqueue_in_q(dequeue());
    }
    enqueue(x);
    while (!isEmpty_q())
    {
        enqueue(dequeue_in_q());
    }
}
int peek()
{
    return queue[f];
}
int isEmpty()
{
    return isEmpty_queue();
}
int main()
{
    for (int i = 4; i < 8; i++)
    {
        push(i);
    }
    display_queue();
    pop();
    pop();
    printf("queue after poopping -->> \n");
    display_queue();
    return 0;
}
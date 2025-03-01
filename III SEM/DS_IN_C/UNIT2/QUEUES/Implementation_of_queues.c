#include <stdio.h>
#define M 5
// todo Implementation of queues ->>
// ! linear queue -> ! FIFO -> first in first out 
int f = -1;
int r = -1;
int queue[M];
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
    return queue[f++];
}
void display()
{
    printf("queue is ->\n");
    int t = f;
    while (t != r + 1)
    {
        printf("data in queue is -> %d\n", queue[t]);
        t++;
    }
}
int main()
{
    /* int ch = 1, x;
    printf("Enter 1 -> enqueue , 2 -> dequeue \n");
    printf("Enter choice .\n"); */
    for (int i = 1; i < 6; i++)
    {
        enqueue(i);
    }
    display();
    printf("dq data is -> %d\n", dequeue());
    printf("dq data is -> %d\n", dequeue());
    enqueue(11);
    enqueue(7);
    display();
    return 0;
}
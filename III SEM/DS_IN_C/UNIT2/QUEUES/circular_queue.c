#include <stdio.h>
#define M 5
// todo implementation of circular queue ==<>
int queue[M];
int f = -1;
int r = -1;
// ~ enqueue in circular queue --<>
void enqueue(int x)
{
    if (f == (r + 1) % M)
    {
        printf("queue is full.\n");
    }
    else
    {
        if (f == -1)
        {
            f = r = 0;
            queue[r] = x;
        }
        else
        {
            r = (r + 1) % M;
            queue[r] = x;
        }
    }
}
// ~ dequeue in circular queue --<>
int dequeue()
{
    int x;
    if (f == -1 && r == -1)
    {
        printf("queue is empty.\n");
    }
    else
    {
        if (f % M == r % M)
        {
            x = queue[f];
            f = r = -1;
            return x;
        }
        else
        {
            x = queue[f];
            f = (f + 1) % M;
            return x;
        }
    }
}
// ~ display circular queue --<>
void display_circular_queue()
{
    int t = f;
    printf("queue is -->>\n");
    while (t != r)
    {
        printf("element in queue is %d\n", queue[t]);
        t = (t + 1) % M;
    }
}
int main()
{
    int x;
    printf("Enter elements in queue -->>\n");
    for (int i = 0; i < M; i++)
    {
        printf("Enter element for queue -->>\n");
        scanf("%d", &x);
        enqueue(x);
    }
    display_circular_queue();
    printf("dequeue element is -->> %d\n", dequeue());
    return 0;
}
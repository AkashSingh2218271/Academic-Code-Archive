#include <stdio.h>

void enqueue(int *q, int *f, int *r, int x, int M)
{
    if (*r == M - 1)
    {
        printf("Queue is full.\n");
    }
    else if (*f == -1 && *r == -1)
    {
        (*f) = (*r) = 0;
    }
    else
    {
        (*r)++;
    }
    q[*r] = x;
}

int dequeue(int *q, int *f, int *r)
{
    if (*f == -1 && *r == -1)
    {
        printf("Queue is empty.\n");
    }
    else if (f == r)
    {
        (*f) = (*r) = -1;
    }
    else
    {
        return q[(*f)++];
    }
    return -1;
}

int peek(int *q, int *f)
{
    if (*f == -1)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return q[*f];
}

void display(int *q, int *f, int *r)
{
    printf("Queue is -> ");
    for (int i = (*f); i <= (*r); i++)
    {
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main()
{
    int queue[5], f = -1, r = -1, m;
    m = sizeof(queue) / sizeof(queue[0]);

    for (int i = 1; i <= 5; i++)
    {
        enqueue(queue, &f, &r, i, m);
    }

    display(queue, &f, &r);
    printf("peeked element is -> %d\n", peek(queue, &f));
    printf("Dequeue element is -> %d\n", dequeue(queue, &f, &r));
    display(queue, &f, &r);

    return 0;
}
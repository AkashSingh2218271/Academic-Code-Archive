#include <stdio.h>

void enqueue(int *q, int *f, int *r, int x, int M){
    if (((*r)+1) % M == (*f)) 
    {
        printf("Queue is full.\n");
    }
    else if ((*f) == -1 && (*r) == -1)
    {
        (*f) = (*r) = 0;
    }
    else
    {
        (*r) = ((*r) + 1) % M;
    }
    q[(*r)] = x;
}

int dequeue(int *q, int *f, int *r, int M){
    if ((*f) == -1 && (*r) == -1)
    {
        printf("Queue is empty.\n");
    }
    else if ((*f) == (*r))
    {
        (*f) = (*r) = -1;
    }
    else
    {
        int temp = q[(*f)];
        (*f) = ((*f) + 1) % M;
        return temp;
    }
    return -1;
}

int main(){
    int queue[5], f = -1, r = -1, m;
    m = sizeof(queue)/sizeof(queue[0]);
    
    for (int i = 1; i <= 5; i++)
    {
        enqueue(queue, &f, &r, i, m);
    }
    
    printf("dequeue element is -> %d", dequeue(queue, &f, &r, m));

    return 0;
}
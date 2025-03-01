#include <stdio.h>
#include <stdlib.h>
// todo queue using linked list --<>
// info FIFO --<>
struct queue
{
    int data;
    struct queue *next;
};
struct queue *temp, *newnode, *head = 0;
// ~ insertion at beginning ->
void insertion_at_beginning()
{
    int x = 1;
    while (x)
    {
        newnode = (struct queue *)malloc(sizeof(struct queue));
        printf("Enter a data to insert at beginning-->> \n");
        scanf("%d", &newnode->data);
        if (head == 0)
        {
            head = newnode;
            newnode->next = 0;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
        printf("Enter 1 for continue or 0 for exit.\n");
        scanf("%d", &x);
    }
}

// ~ deletion at end ->
void deletion_at_beginnig()
{
    if (head == 0)
    {
        printf("queue is empty.\n");
    }
    else
    {
        temp = head;
        head = head->next;
        printf("deleted data at beginning of queue is -->> %d\n", temp->data);
        free(temp);
    }
}
void enqueue()
{
    insertion_at_beginning();
}
void dequeue()
{
    deletion_at_beginnig();
}
int isEmpty()
{
    return head == 0;
}
void traverse_queue()
{
    temp = head;
    printf("queue is ->> \n");
    while (temp != 0)
    {
        printf("data in queue is ->> %d\n", temp->data);
        temp = temp->next;
    }
}
int main()
{
    enqueue();
    dequeue();
    traverse_queue();
    return 0;
}
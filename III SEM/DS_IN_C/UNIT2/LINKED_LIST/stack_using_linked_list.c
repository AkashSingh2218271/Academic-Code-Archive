#include <stdio.h>
#include <stdlib.h>
// todo Implementation of stack using linked list ==<>
// info LIFO >>==<<
struct stack
{
    int data;
    struct stack *next;
};
struct stack *temp, *newnode, *head = 0;
// ~ insertion at end --<>
void insertion_at_end()
{
    newnode = (struct stack *)malloc(sizeof(struct stack));
    printf("Enter data for newnode -->> \n");
    scanf("%d", &newnode->data);
    if (head == 0)
    {
        head = temp = newnode;
        newnode->next = 0;
    }
    else
    {
        temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = 0;
    }
}
// ~ deletion at end --<>
void deletion_at_end()
{
    struct stack *prev;
    if (head == 0)
    {
        printf("stack is empty.\n");
    }
    else
    {
        temp = head;
        while (temp->next != 0)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = 0;
        printf("deleted data at end of stack is -->> %d\n", temp->data);
        free(temp);
    }
}
int isEmpty()
{
    return head == 0;
}
void pop()
{
    deletion_at_end();
}
void push()
{
    insertion_at_end();
}

void traverse_stack()
{
    temp = head;
    printf("stack is ->> \n");
    while (temp != 0)
    {
        printf("data in stack is ->> %d\n", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int n, x;
    printf("Enter size of stack -->>\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        push();
    }
    pop();
    traverse_stack();
    return 0;
}

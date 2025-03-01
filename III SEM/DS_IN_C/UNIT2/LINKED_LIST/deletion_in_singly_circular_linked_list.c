#include <stdio.h>
#include <stdlib.h>
// todo deletion in singly circular linked list --<>
// ! singly circular linked list --<>
struct circular_linked_list
{
    int data;
    struct circular_linked_list *next;
};
struct circular_linked_list *temp, *newnode, *tail, *head = 0;
void singly_circular_linked_list()
{
    int x = 1;
    while (x)
    {
        newnode = (struct circular_linked_list *)malloc(sizeof(struct circular_linked_list));
        printf("Enter data for newnode -->> \n");
        scanf("%d", &newnode->data);
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Enter 1 -> continue or 0 -> exit\n");
        scanf("%d", &x);
    }
    temp->next = head;
}
// ~ length of singly circular linked list --<>
int length_of_linked_list()
{
    int count = 0;
    if (head == 0)
    {
        return count;
    }
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
        count++;
    }
    return ++count;
}
// ~ deletion at beginning --<>
void deletion_at_beginning()
{
    if (head == 0)
    {
        printf("linked list is empty. \n");
    }
    else if (head == temp)
    {
        head = 0;
        free(temp);
    }
    else if (head == tail)
    {
        head = 0;
        free(tail);
    }
    
    else
    {
        temp = tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }
        head = head->next;
        tail->next = head;
        free(temp);
    }
}
// ~ deletion at end --<>
void deletion_at_end()
{
    if (head == 0)
    {
        printf("linked list is empty. \n");
    }
    else if (head == temp)
    {
        head = 0;
        free(temp);
    }
    else if (tail == head)
    {
        head = 0;
        free(tail);
    }
    else
    {
        tail = head;
        while (tail->next != head)
        {
            temp = tail;
            tail = tail->next;
        }
        temp->next = head;
        free(tail);
    }
}
// ~ deletion at specific position --<>
void deletion_at_specific_position() 
{
    int pos;
    printf("Enter position for deletion of node.\n");
    scanf("%d", &pos);
    if (head == 0)
    {
        printf("linked list is empty. \n");
    }
    else if (pos > length_of_linked_list() || pos < 1)
    {
        printf("Invalid position.\n");
    }
    else if (pos == 1)
    {
        deletion_at_beginning();
    }
    else if (pos > length_of_linked_list() + 1)
    {
        deletion_at_end();
    }
    else
    {
        int i = 1;
        temp = head;
        while (i < pos)
        {
            tail = temp;
            temp = temp->next;
            i++;
        }
        tail->next = temp->next;
        free(temp);
    }
} 
// ~ traverse singly circular linked list --<>
void traverse_singly_circular_linked_list()
{
    printf("circular linked list -->> \n");
    if (head == 0)
    {
        printf("linked list is empty. \n");
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            printf("data in circular linked list is -->> %d\n", temp->data);
            temp = temp->next;
        }
        printf("data in circular linked list is -->> %d\n", temp->data);
    }
}
int main()
{
    // ! function call --<>
    singly_circular_linked_list();
    deletion_at_beginning();
    //deletion_at_beginning();
    //deletion_at_beginning();
    deletion_at_end();
    deletion_at_specific_position();
    //deletion_at_end();
    traverse_singly_circular_linked_list();
    return 0;
}
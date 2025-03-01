#include <stdio.h>
#include <stdlib.h>
// todo insertion in singly circular linked list --<>
// info singly circular linked list --<>
struct circular_linked_list
{
    int data;
    struct circular_linked_list *next;
};
struct circular_linked_list *temp, *newnode, *head = 0;
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
// ~ insertion at beginning --<>
void insert_beginning()
{
    newnode = (struct circular_linked_list *)malloc(sizeof(struct circular_linked_list));
    printf("Enter data for newnode to insert at beginning -->> \n");
    scanf("%d", &newnode->data);
    if (head == 0)
    {
        head = temp = newnode;
        temp->next = head;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newnode->next = head;
        head = newnode;
        temp->next = head;
    }
}
// ~ insertion at end ---<>
void insertion_at_end()
{
    newnode = (struct circular_linked_list *)malloc(sizeof(struct circular_linked_list));
    printf("Enter data for newnode to insert at end -->> \n");
    scanf("%d", &newnode->data);
    if (head == 0)
    {
        head = temp = newnode;
        temp->next = head;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newnode->next = head;
        temp->next = newnode;
        temp = newnode;
    }
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
// ~ insertion in between or specific position --<>
void insert_specific_position()
{
    int pos;
    printf("Enter position to insert newnode -->> \n");
    scanf("%d", &pos);
    newnode = (struct circular_linked_list *)malloc(sizeof(struct circular_linked_list));
    printf("Enter data for newnode to insert at specific position -->> \n");
    scanf("%d", &newnode->data);
    if (head == 0)
    {
        head = temp = newnode;
        temp->next = newnode;
    }
    else if (pos > length_of_linked_list() || pos < 1)
    {
        printf("Invalid position.\n");
    }
    else if (pos == 1)
    {
        insert_beginning();
    }
    else if (pos == length_of_linked_list() + 1)
    {
        insertion_at_end();
    }
    else
    {
        int i = 1;
        temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
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
    // ! function call -->>
    singly_circular_linked_list();
    insert_beginning();
    insertion_at_end();
    insert_specific_position();
    insertion_at_end();
    traverse_singly_circular_linked_list();
    return 0;
}
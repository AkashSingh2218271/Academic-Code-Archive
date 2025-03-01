#include <stdio.h>
#include <stdlib.h>
// todo Insertion at beginning of linked list ->>
// ! create linked list ->>
struct insertion_in_ll
{
    int data;
    struct insertion_in_ll *next;
};
struct insertion_in_ll *head, *temp, *newnode;
void singly_linked_list()
{
    int x = 1;
    head = 0;
    while (x)
    {
        newnode = (struct insertion_in_ll *)malloc(sizeof(struct insertion_in_ll));
        printf("Enter element for newnode.\n");
        scanf("%d", &newnode->data);
        // ? newnode->next = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Enter choice if continue -> 1 else 0 -> exit. \n");
        scanf("%d", &x);
    }
    newnode->next = 0; 
}
void insert_at_beginning()
{
    newnode = (struct insertion_in_ll *)malloc(sizeof(struct insertion_in_ll)); 
    printf("Enter a value for newnode to insert.\n");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}
// ! traverse a linked list ->>
void traverse_linked_list()
{
    temp = head;
    while (temp != 0)
    {
        printf("data is ->> %d\n", temp->data);
        temp = temp->next;
    }
}
int main()
{
    // ? function calling ..
    singly_linked_list();
    traverse_linked_list();
    insert_at_beginning();
    traverse_linked_list();
}
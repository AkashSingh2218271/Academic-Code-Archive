#include <stdio.h>
#include <stdlib.h>
// todo implementation of doubly linked list -->>
struct implementation_of_doubly_linked_list
{
    int data;
    struct implementation_of_doubly_linked_list *next, *prev;
};
struct implementation_of_doubly_linked_list *head, *temp, *newnode;
void doubly_linked_list()
{
    int x = 1;
    head = 0;
    while (x)
    {
        newnode = (struct implementation_of_doubly_linked_list *)malloc(sizeof(struct implementation_of_doubly_linked_list));
        printf("Enter data -->> \n");
        scanf("%d", &newnode->data);
        newnode->prev = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("Enter choice 1 for continue or 0 for exit.\n");
        scanf("%d", &x);
    }
    newnode->next = 0;
}
// ! traverse doubly linked list -->>
void traverse_doubly_linked_list()
{
    temp = head;
    printf("doubly linked list -->>\n");
    while (temp != 0)
    {
        printf("data in doubly linked list is -->> %d\n", temp->data);
        temp = temp->next;
    }
}
int main()
{
    doubly_linked_list();
    traverse_doubly_linked_list();
    return 0;
}
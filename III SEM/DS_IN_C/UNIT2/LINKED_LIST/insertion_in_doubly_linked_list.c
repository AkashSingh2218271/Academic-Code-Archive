#include <stdio.h>
#include <stdlib.h>

// todo insertion in doubly linked list -->>
// ! doubly linked list -->>
struct doubly_linked_list
{
    int data;
    struct doubly_linked_list *next, *prev;
};
struct doubly_linked_list *head, *temp, *newnode;
void doubly_linked_list()
{
    int x = 1;
    head = 0;
    while (x)
    {
        newnode = (struct doubly_linked_list *)malloc(sizeof(struct doubly_linked_list));
        printf("Enter data -->> \n");
        scanf("%d", newnode->data);
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
        printf("Enter 1 for continue or 0 for exit. \n");
        scanf("%d", &x);
    }
    newnode->next = 0;
}
// ! 
int main()
{

    return 0;
}
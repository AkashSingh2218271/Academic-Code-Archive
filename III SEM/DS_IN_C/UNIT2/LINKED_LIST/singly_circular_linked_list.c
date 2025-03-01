#include <stdio.h>
#include <stdlib.h>
// todo implementation of singly circular linked list -->>
// info structure defination -->>
struct singly_circular_linked_list
{
    int data;
    struct singly_circular_linked_list *next;
};
struct singly_circular_linked_list *head, *temp, *newnode;
void circular_linked_list()
{
    int x = 1;
    head = 0;
    while (x)
    {
        newnode = (struct singly_circular_linked_list *)malloc(sizeof(struct singly_circular_linked_list));
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
        printf("Enter 1 for continue or 0 for exit .\n");
        scanf("%d", &x);
    }
    temp->next = head;
}
// ~ traverse circular linked list -->>
void traverse_circular_linked_list()
{
    printf("circular linked list -->>\n");
    temp = head;
    while (temp->next != head)
    {
        printf("data is -->> %d\n", temp->data);
        temp = temp->next;
    }
    printf("data is -->> %d\n", temp->data);
}
int main()
{
    // ! function call -->>
    circular_linked_list();
    traverse_circular_linked_list();
    return 0;
}
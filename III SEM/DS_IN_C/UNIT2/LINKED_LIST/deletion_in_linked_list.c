#include <stdio.h>
#include <stdlib.h>
// todo deletion in linked list -->>
// ! linked list -->>
struct linked_list
{
    int data;
    struct linked_list *next;
};
struct linked_list *head, *temp, *newnode;
void linke_list()
{
    int x = 1;
    head = 0;
    while (x)
    {
        newnode = (struct linked_list *)malloc(sizeof(struct linked_list));
        printf("Enter data -->> \n");
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
        printf("Enter 1 for continue or 0 for exit.\n");
        scanf("%d", &x);
    }
    newnode->next = 0;
}
// ! deletion at beginning -->>
void deletion_at_beginning()
{
    temp = head;
    head = head->next;
    printf("deleted data at beginning is -->> %d\n", temp->data);
    free(temp);
}
// ! deletion at end -->>
void deletion_at_end()
{
    struct linked_list *prev;
    temp = head;
    if (head == 0)
    {
        printf("Empty list.\n");
    }
    else
    {
        while (temp->next != 0)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = 0;
        printf("deleted data at end is -->> %d\n", temp->data);
        free(temp);
    }
}
// ! length of linked list ->>
int length_of_linked_list()
{
    temp = head;
    int count = 0;
    while (temp->next != 0)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
// ! deletion at specific position -->>
void deletion_at_specific_position()
{
    struct linked_list *nextnode;
    int pos;
    printf("Enter postion -->> \n");
    scanf("%d", &pos);
    if (head == 0)
    {
        printf("list is empty.\n");
    }
    else if (pos > length_of_linked_list() || pos < 1)
    {
        printf("Invalid postion.\n");
    }
    else if (pos == 1)
    {
        deletion_at_beginning();
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
        nextnode = temp->next;
        temp->next = nextnode->next;
        printf("deleted data at specific position is -->> %d\n", nextnode->data);
        free(nextnode);
    }
}
// ! traversek / display linked list -->>
void display_linked_list() 
{
    temp = head;
    printf("linked list -->>\n");
    while (temp != 0)
    {
        printf("data in linked list is -->> %d\n", temp->data);
        temp = temp->next;
    }
}
int main()
{
    linke_list();
    display_linked_list();
    deletion_at_beginning();
    display_linked_list();
    deletion_at_end();
    display_linked_list();
    deletion_at_specific_position();
    display_linked_list();
    deletion_at_specific_position();
    return 0;
}
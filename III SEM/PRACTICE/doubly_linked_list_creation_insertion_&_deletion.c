#include <stdio.h>
#include <stdlib.h>
// todo creation insertion & deletion in doubly linked list ==<>
// info doubly linked list ==<>
struct doubly_linked_list
{
    int data;
    struct doubly_linked_list *prev, *next;
};
struct doubly_linked_list *temp, *newnode, *prevnode, *head = 0;
void create_doubly_linked_list()
{
    int x;
    while (x)
    {
        newnode = (struct doubly_linked_list *)malloc(sizeof(struct doubly_linked_list));
        printf("Enter data for newnode -->>\n");
        scanf("%d", &newnode->data);
        newnode->prev = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue or not (1 -> continue or 0 -> exit)\n");
        scanf("%d", &x);
    }
    newnode->next = 0;
}
// ~ length of doubly linked list >>--<<
int length_of_doubly_linked_list()
{
    int count = 0;
    temp = head;
    while (temp != 0)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
// ! insertion in doubly linked list ==<>
// ~ insertion at beginning --<>
void insert_at_beginning()
{
    newnode = (struct doubly_linked_list *)malloc(sizeof(struct doubly_linked_list));
    printf("Enter data for newnode to insert at beginning -->>\n");
    scanf("%d", &newnode->data);
    if (head == 0)
    {
        head = temp = newnode;
        newnode->prev = 0;
        newnode->next = 0;
    }
    else
    {
        newnode->next = head;
        newnode->prev = 0;
        head = newnode;
    }
}
// ~ insertion at end --<>
void insertion_at_end()
{
    newnode = (struct doubly_linked_list *)malloc(sizeof(struct doubly_linked_list));
    printf("Enter data for newnode to insert at end -->>\n");
    scanf("%d", &newnode->data);
    if (head == 0)
    {
        head = temp = newnode;
        newnode->prev = 0;
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
        newnode->prev = temp;
        newnode->next = 0;
    }
}
// ~ insertion at specific position --<>
void insertion_at_specific_position()
{
    int pos;
    printf("Enter a position to insert newnode -->\n");
    scanf("%d", &pos);
    if (pos > length_of_doubly_linked_list() + 1 || pos < 0)
    {
        printf("Invalid position.\n");
    }
    else if (pos == 1)
    {
        insert_at_beginning();
    }
    else if (pos == length_of_doubly_linked_list() + 1)
    {
        insertion_at_end();
    }
    else
    {
        int i = 1;
        newnode = (struct doubly_linked_list *)malloc(sizeof(struct doubly_linked_list));
        printf("Enter data for newnode to insert at specific position -->>\n");
        scanf("%d", &newnode->data);
        temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        temp->next->prev = newnode;
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
// ! deletion in doubly linked list ==<>
// ~ deletion at beginning --<>
void deletion_at_beginning()
{
    if (head == 0)
    {
        printf("doubly linked list is empty.\n");
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = 0;
        free(temp);
    }
}
// ~ deletion at end --<>
void deletion_at_end()
{
    if (head == 0)
    {
        printf("doubly linked list is empty. \n");
    }
    else
    {
        temp = head;
        while (temp->next != 0)
        {
            prevnode = temp;
            temp = temp->next;
        }
        prevnode->next = 0;
        free(temp);
    }
}
// ~ deletion at specific position --<>
void deletion_at_specific_position()
{
    int pos;
    printf("Enter a secific position for deletion -->> \n");
    scanf("%d", &pos);
    if (pos > length_of_doubly_linked_list() || pos < 0)
    {
        printf("Invalid position.\n");
    }
    else if (pos == 1)
    {
        deletion_at_beginning();
    }
    else if (pos == length_of_doubly_linked_list())
    {
        deletion_at_end();
    }
    else
    {
        int i = 1;
        temp = head;
        while (i < pos)
        {
            prevnode = temp;
            temp = temp->next;
            i++;
        }
        prevnode->next = temp->next;
        temp->next->prev = prevnode;
        free(temp);
    }
}
// ~ traverse doubly linked list --<>
void traverse_doubly_linked_list()
{
    temp = head;
    printf("doubly linked list -->> \n");
    while (temp != 0)
    {
        printf("data in doubly linked list is -> %d \n", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int x = 1;
    while (x)
    {
        int ch;
        printf("Enter 2 for creation of doubly linked list.\n");
        printf("Enter 3 for insertion at beginning in doubly linked list.\n");
        printf("Enter 4 for insertion at end in doubly linked list.\n");
        printf("Enter 5 for insertion at specific position in doubly linked list.\n");
        printf("Enter 6 for deletion at beginning in doubly linked list. \n");
        printf("Enter 7 for deletion at end in doubly linked list. \n");
        printf("Enter 8 for deletion at specific position in doubly linked list. \n");
        printf("Enter 9 for traversal of doubly linked list. \n");
        printf("Enter choice for opertion present in between (2 to 9).\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 2:
            create_doubly_linked_list();
            break;
        case 3:
            insert_at_beginning();
            break;
        case 4:
            insertion_at_end();
            break;
        case 5:
            insertion_at_specific_position();
            break;
        case 6:
            deletion_at_beginning();
            break;
        case 7:
            deletion_at_end();
            break;
        case 8:
            deletion_at_specific_position();
            break;
        case 9:
            traverse_doubly_linked_list();
            break;
        }
        printf("Enter 1 for continue or 0 -> for exit.\n");
        scanf("%d", &x);
    }
    return 0;
}
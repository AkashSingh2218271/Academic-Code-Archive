#include <stdio.h>
#include <stdlib.h>
// todo Implementation of linked list --<>
struct Implementation_of_linked_list
{
    int data;
    struct Implementation_of_linked_list *next;
};
struct Implementation_of_linked_list *head, *temp, *newnode;
void linear_linked_list() 
{
    int ch = 1;
    head = 0;
    while (ch)
    {
    newnode = (struct Implementation_of_linked_list *) malloc(sizeof(struct Implementation_of_linked_list));
    printf("Enter data ->\n");
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
    printf("Enter 1 for continue or 0 for exit\n");
    scanf("%d", &ch);
    }
    newnode->next = 0;
}
void traverse_linked_list(int given_data) {
    temp = head;
    int flag = 0;
    printf("linked list ->> \n");
    while (temp != 0)
    {
        if (given_data == temp->data)
        {
           flag = 1;
        }
        temp = temp->next;
    }
    if (flag)
    {
        printf("data is prestent.\n");
    }
    else
    {
        printf("data is not prestent.\n");
    }
    
}
int main() {
    int data;
    printf("Enter a data  to check -->> \n");
    scanf("%d", &data);
    linear_linked_list();
    traverse_linked_list(data);
    return 0;
}
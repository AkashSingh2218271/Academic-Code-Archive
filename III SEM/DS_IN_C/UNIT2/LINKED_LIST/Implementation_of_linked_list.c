#include <stdio.h>
#include <stdlib.h>
// todo Implementation of linked list ->> 
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
void traverse_linked_list() {
    temp = head;
    printf("linked list ->> \n");
    int m = -1;
    while (temp != 0)
    {
       printf("data is ->> %d\n", temp->data);
        /*if(m < temp->data){
        m = temp->data;
       } */
        temp = temp->next;
    }
    // printf("largest : %d\n", m);
}
int main() {
    linear_linked_list();
    traverse_linked_list();
    return 0;
}
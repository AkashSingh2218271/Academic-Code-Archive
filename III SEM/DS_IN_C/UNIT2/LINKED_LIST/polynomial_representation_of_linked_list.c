#include <stdio.h>
#include <stdlib.h>
// todo polynomial representation of linked list -->>
struct polynomial_representation_of_linked_list
{
    float coeff;
    int expo;
    struct polynomial_representation_of_linked_list *link;
};
struct polynomial_representation_of_linked_list *temp, *newnode;
struct polynomial_representation_of_linked_list *insert(struct polynomial_representation_of_linked_list *head, float co, int ex)
{
    newnode = (struct polynomial_representation_of_linked_list *)malloc(sizeof(struct polynomial_representation_of_linked_list));
    newnode->coeff = co;
    newnode->expo = ex;
    newnode->link = 0;
    if (head == 0 || ex > head->expo)
    {
        newnode->link = head;
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->link != 0 && temp->link->expo >= ex)
        {
            temp = temp->link;
        }
        newnode->link = temp->link;
        temp->link = newnode;
    }
    return head;
}
struct polynomial_representation_of_linked_list *create_polynomial_linked_list(struct polynomial_representation_of_linked_list *head)
{
    int n;
    float coeff;
    int expo;
    printf("Enter no of terms in polynomial -->>\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficient for term  -->> %d\n", i + 1);
        scanf("%f", &coeff);
        printf("Enter the exponent for term  -->> %d\n", i + 1);
        scanf("%d", &expo);
        head = insert(head, coeff, expo);
    }
    return head;
}
void print_polynomial(struct polynomial_representation_of_linked_list *head)
{
    if (head == 0)
    {
        printf("no polynomial.\n");
    }
    else
    {
        temp = head;
        while (temp != 0)
        {
            printf("%.1f(x^%d)", temp->coeff, temp->expo);
            temp = temp->link;
            if (temp != 0)
            {
                printf(" + ");
            }
            else
            {
                printf("\n");
            }
        }
    }
}
int main()
{
    struct polynomial_representation_of_linked_list *head = 0;
    head = create_polynomial_linked_list(head);
    printf("polynomial is -->> ");
    print_polynomial(head);
    return 0;
}
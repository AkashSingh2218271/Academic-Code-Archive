#include <stdio.h>
#include <stdlib.h>
// todo addition of two polynomial using linked list ==<>
// info polynomial create and insertion ==<>
struct polynomial_linked_list
{
    float coffe;
    int expo;
    struct polynomial_linked_list *link;
};
struct polynomial_linked_list *temp, *newnode;
// ~ insertion in polynomial --<>
struct polynomial_linked_list *insert_in_polynomial(struct polynomial_linked_list *head, float co, int ex)
{
    newnode = (struct polynomial_linked_list *)malloc(sizeof(struct polynomial_linked_list));
    newnode->coffe = co;
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
        while (temp->link != 0 && head->link->expo >= ex)
        {
            temp = temp->link;
        }
        newnode->link = temp->link;
        temp->link = newnode;
    }
    return head;
}
// ~ creation of polynomial --<>
struct polynomial_linked_list *create_polynomial(struct polynomial_linked_list *head)
{
    int n;
    float coffe;
    int expo;
    printf("Enter number of terms in polynomial.\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the cofficient for term -->> %d\n", i + 1);
        scanf("%f", &coffe);
        printf("Enter the exponent for term -->> %d\n", i + 1);
        scanf("%d", &expo);
        head = insert_in_polynomial(head, coffe, expo);
    }
    return head;
}
// ~ print polynomial expression --<>
void print_polynomial(struct polynomial_linked_list *head)
{
    if (head == 0)
    {
        printf("No polynomial.\n");
    }
    else
    {
        temp = head;
        while (temp != 0)
        {
            printf("%f(x^%d)", temp->coffe, temp->expo);
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
// ! function for addtion of polynomials <>==<>
void add_polynomial(struct polynomial_linked_list *head1, struct polynomial_linked_list *head2)
{
    struct polynomial_linked_list *ptr1, *ptr2, *ans = 0;
    ptr1 = head1;
    ptr2 = head2;
    while (ptr1 != 0 && ptr2 != 0)
    {
        if (ptr1->expo == ptr2->expo)
        {
            ans = insert_in_polynomial(ans, ptr1->coffe + ptr2->coffe, ptr1->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            ans = insert_in_polynomial(ans, ptr1->coffe, ptr1->expo);
            ptr1 = ptr1->link;
        }
        else if (ptr1->expo < ptr2->expo)
        {
            ans = insert_in_polynomial(ans, ptr2->coffe, ptr2->expo);
            ptr2 = ptr2->link;
        }
    }
    while (ptr1 != 0)
    {
        ans = insert_in_polynomial(ans, ptr1->coffe, ptr1->expo);
        ptr1 = ptr1->link;
    }
    while (ptr2 != 0)
    {
        ans = insert_in_polynomial(ans, ptr2->coffe, ptr2->expo);
        ptr2 = ptr2->link;
    }
    printf("Added polynomial is -->> \n");
    print_polynomial(ans);
}
int main()
{
    struct polynomial_linked_list *polynomial1 = 0, *polynomial2 = 0;
    polynomial1 = create_polynomial(polynomial1);
    printf("First polynomial is -->>\n");
    print_polynomial(polynomial1);
    polynomial2 = create_polynomial(polynomial2);
    printf("second polynomial is -->>\n");
    print_polynomial(polynomial2);
    add_polynomial(polynomial1,polynomial2);
    return 0;
}
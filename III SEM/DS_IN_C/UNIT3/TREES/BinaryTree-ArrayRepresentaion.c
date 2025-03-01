#include <stdio.h>
#include <string.h>
// todo /* BINARY TREES ARRAY REPERSENTATION */
// info array for tree
char tree[20];
void Setroot()
{
    if (tree[0] != '\0')
    {
        printf("Tree already had root.\n");
    }
    else
    {
        char c;
        printf("Enter root for tree.\n");
        fflush(stdin);
        scanf("%c", &c);
        tree[0] = c;
    }
}
void leftchild()
{
    int p, lc;
    printf("Enter parent for left child.\n");
    scanf("%d", &p);
    if (tree[0] == '\0')
    {
        printf("First set root to make a tree.\n");
        Setroot();
    }
    else if (tree[p] == '\0')
    {
        printf("Can not set child no parent exist.\n");
    }
    else
    {
        char c;
        lc = (2 * p) + 1;
        printf("Enter left child.\n");
        fflush(stdin);
        scanf("%c", &c);
        tree[lc] = c;
    }
}
void rightchild()
{
    int p, rc;
    printf("Enter parent for right child.\n");
    scanf("%d", &p);
    if (tree[0] == '\0')
    {
        printf("First set root to make a tree.\n");
        Setroot();
    }
    else if (tree[p] == '\0')
    {
        printf("Can not set child no parent exsit.\n");
    }
    else
    {
        char c;
        rc = (2 * p) + 2;
        printf("Enter right child.\n");
        fflush(stdin);
        scanf("%c", &c);
        tree[rc] = c;
    }
}
void TraverseTree()
{
    int n;
    printf("Enter the size of tree.\n");
    scanf("%d", &n);
    // ? n = strlen(tree);
    // ? printf("N = %d\n", n);
    printf("TREE IS :\n");
    for (int i = 0; i < n; i++)
    {
        if (tree[i] != '\0')
        {
            printf("%c", tree[i]);
        }
        else
        {
            printf("-");
        }
    }
    printf("\n");
}
int main()
{
    int x = 1;
    while (x)
    {
        printf("Enter one of the following \n 2 for root\n 3 for leftchild\n 4 for rightchild\n 5 for traversal\n");
        switch (x)
        {
        case 2:
            Setroot();
            break;
        case 3:
            leftchild();
            break;
        case 4:
            rightchild();
            break;
        case 5:
            TraverseTree();
            break;
        }
        printf("Enter 1 for continue and 0 for exit.\n");
        scanf("%d", &x);
    }
    return 0;
}
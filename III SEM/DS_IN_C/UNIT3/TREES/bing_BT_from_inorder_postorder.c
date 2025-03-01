#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

int search(int arr[], int strt, int end, int value);
struct node* newNode(int data);

struct node* buildTree(int in[], int post[], int inStrt, int inEnd, int* postIndex)
{
    if (inStrt > inEnd)
        return NULL;

    struct node* node = newNode(post[*postIndex]);
    (*postIndex)--;

    if (inStrt == inEnd)
        return node;

    int inIndex = search(in, inStrt, inEnd, node->data);

    node->right = buildTree(in, post, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(in, post, inStrt, inIndex - 1, postIndex);

    return node;
}

int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            break;
    }
    return i;
}

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

void printInorder(struct node* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main()
{
    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
    int n = sizeof(in) / sizeof(in[0]);
    int postIndex = n - 1;

    struct node* root = buildTree(in, post, 0, n - 1, &postIndex);

    printf("Inorder traversal of the constructed tree is \n");
    printInorder(root);

    return 0;
}

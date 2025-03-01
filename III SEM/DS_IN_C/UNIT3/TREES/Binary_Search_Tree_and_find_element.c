#include <stdio.h>
#include <stdlib.h>
// todo /* CREATE BST AND FIND AN ELEMENT IN  IT */
// info  ~ Structure for Binary Search Tree node
struct Binary_Search_Tree
{
    int data;
    struct Binary_Search_Tree *left, *right;
};

// ! Function to insert a node in the BST
struct Binary_Search_Tree *insertNode(struct Binary_Search_Tree *root, int data)
{
    if (root == NULL)
    {
        struct Binary_Search_Tree *newNode = (struct Binary_Search_Tree *)malloc(sizeof(struct Binary_Search_Tree));
        if (newNode == NULL)
        {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// ! Function to perform inorder traversal of the BST
void inorder(struct Binary_Search_Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// ! Function to find the in-order successor
struct Binary_Search_Tree *findSuccessor(struct Binary_Search_Tree *node)
{
    struct Binary_Search_Tree *current = node->right;
    while (current != NULL && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// ! Function to delete a node in the BST
struct Binary_Search_Tree *deleteNode(struct Binary_Search_Tree *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            struct Binary_Search_Tree *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Binary_Search_Tree *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the in-order successor (smallest in the right subtree)
        struct Binary_Search_Tree *temp = findSuccessor(root);

        // Copy the in-order successor's data to this node
        root->data = temp->data;

        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// ! Function to search for an element in the BST
int search(struct Binary_Search_Tree *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->data == key)
    {
        return 1;
    }

    if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
    return 0;
}

int main()
{
    struct Binary_Search_Tree *root = NULL;
    int data, check;

    printf("Enter data for BST and for no data enter (-1).\n");
    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
        {
            break;
        }
        root = insertNode(root, data);
    }

    printf("\nInorder tree is: ");
    inorder(root);

    printf("\nEnter element to delete:\n");
    scanf("%d", &check);

    if (search(root, check) == 1)
    {
        root = deleteNode(root, check);
        printf("Element %d is deleted from the BST.\n", check);
    }
    else
    {
        printf("Element %d is not present in the BST. Cannot delete.\n", check);
    }

    printf("\nInorder tree after deletion is: ");
    inorder(root);

    return 0;
}

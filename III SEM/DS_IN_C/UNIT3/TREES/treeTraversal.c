#include <stdio.h>
#include <stdlib.h>
// todo /* implementation of binary tree using linked list */
// info /* structure definition */
struct BinaryTree_using_LinkedList
{
   char data;
   struct BinaryTree_using_LinkedList *left, *right;
};
struct BinaryTree_using_LinkedList * createTree(){
    struct BinaryTree_using_LinkedList *newnode;
    char x;
    newnode = (struct BinaryTree_using_LinkedList *)malloc(sizeof(struct BinaryTree_using_LinkedList));
    printf("Enter Data for newnode of tree for no data enter n. \n");
    fflush(stdin);
    scanf("%c", &x);
     if (x == 'n')
    {
        free(newnode); // ! not tested
        return 0;
    }
    newnode->data = x;
    printf("Enter data for left child. \n");
    newnode->left = createTree();
    printf("Enter data for right child. \n");
    newnode->right = createTree();
    return newnode;
}
void inorder(struct BinaryTree_using_LinkedList *root){
    if (root == 0)
    {
        return;
    }
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}
void Preorder(struct BinaryTree_using_LinkedList *root){
    if (root == 0)
    {
        return;
    }
    printf("%c ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(struct BinaryTree_using_LinkedList *root){
    if (root == 0)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    printf("%c ", root->data);
}
int main()
{
    struct BinaryTree_using_LinkedList *root;
    root = createTree();
    //printf("root data = %c\n", root->data);
    printf("Inorder tree is :");
    inorder(root);
    printf("\nPreorder tree is :");
    Preorder(root);
    printf("\nPostorder tree is :");
    Postorder(root);
    return 0;
}
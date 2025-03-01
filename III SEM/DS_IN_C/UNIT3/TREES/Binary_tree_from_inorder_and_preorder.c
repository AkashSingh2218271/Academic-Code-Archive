#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// todo /* Binary tree inorder and preoder . */

struct Binarytree
{
    char data;
    struct Binarytree *left, *right;
};

int seachNxtRoot(char in[], int instart, int inend, char data){
    int i;
    for (i = instart; i < inend; i++)
    {
        if (in[i] == data)
        {
            break;
        } 
    }
    return i;
}

struct Binarytree * createBT(char in[], char pre[], int instart, int inend){
    static int preidx = 0;    
    struct Binarytree *newnode;
    newnode = (struct Binarytree *)malloc(sizeof(struct Binarytree));
    newnode->left = NULL;
    newnode->right = NULL;
    if (instart > inend)
    {
        return NULL;
    }
    newnode->data = pre[preidx++]; 
    if(instart == inend){
        return newnode;
    }
    int inRootIdx = seachNxtRoot(in, instart, inend, newnode->data);
    newnode->left = createBT(in, pre, instart, inRootIdx - 1);
    newnode->right = createBT(in, pre, inRootIdx + 1, inend);
    return newnode;
}

void inorder(struct Binarytree *root){
    if (root == 0)
    {
        return;
    }
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

int main()
{
    char in[50];
    char pre[50];
    printf("Enter inorder and preorder respectively.\n");
    scanf("%[^\n]s", in);
    fflush(stdin);
    scanf("%[^\n]s", pre);
    int len1 = strlen(in);
    //printf("len1 = %d\n", len1);
    struct Binarytree *root;
    root = createBT(in, pre, 0, len1 - 1);
    printf("\nInorder tree is : ");
    inorder(root);
    return 0;
}
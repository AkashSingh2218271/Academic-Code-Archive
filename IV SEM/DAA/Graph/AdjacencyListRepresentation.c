#include <stdio.h>
#include <stdlib.h>
#define maxNode 4
typedef struct Node
{
    int vNum;
    struct Node *next;
}Node;
typedef struct List {
    Node *head;
}List;
List *adjlist[maxNode];
void addNode(int s, int d) {
    Node *src, *tmp, *dest;
    if (adjlist[s]->head == NULL)
    {
        src = (Node *)malloc(sizeof(Node));
        src->vNum = s;
        src->next = NULL;
        adjlist[s]->head = src;
    }
    dest = (Node *)malloc(sizeof(Node));
    dest->vNum = d;
    dest->next = NULL;
    tmp = adjlist[s]->head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = dest;
}

void printList() {
    for (int i = 0; i < maxNode; i++)
    {
        Node *p = adjlist[i]->head;
        printf("Adjacency List of vertex %d is ", i);
        while (p)
        {
            printf("%d ", p->vNum);
            p = p->next;
        }
        printf("\n");
    }
    
}

int main() {
    for (int i = 0; i < maxNode; i++)
    {
        adjlist[i] = (List *)malloc(sizeof(List));
        adjlist[i]->head = NULL;
    }
    addNode(0,1);
    addNode(0,2);
    addNode(0,3);
    addNode(1,0);
    addNode(1,2);
    addNode(2,0);
    addNode(2,1);
    addNode(2,3);
    addNode(3,0);
    addNode(3,2);
    printList();

    return 0;
}
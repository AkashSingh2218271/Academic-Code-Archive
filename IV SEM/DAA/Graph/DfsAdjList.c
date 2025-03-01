#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxNode 4

typedef struct Node {
    int vNum;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

List *adjlist[maxNode];

void addNode(int s, int d) {
    Node *src, *tmp, *dest;
    if (adjlist[s]->head == NULL) {
        src = (Node *)malloc(sizeof(Node));
        src->vNum = s;
        src->next = NULL;
        adjlist[s]->head = src;
    }
    dest = (Node *)malloc(sizeof(Node));
    dest->vNum = d;
    dest->next = NULL;
    tmp = adjlist[s]->head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = dest;
}

void printList() {
    for (int i = 0; i < maxNode; i++) {
        Node *p = adjlist[i]->head;
        printf("Adjacency List of vertex %d is ", i);
        while (p) {
            printf("%d ", p->vNum);
            p = p->next;
        }
        printf("\n");
    }
}

// Stack implementation
typedef struct Stack {
    int top;
    unsigned capacity;
    int* array;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

bool isStackFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

bool isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isStackFull(stack)) return;
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isStackEmpty(stack)) return -1;
    return stack->array[stack->top--];
}

// DFS traversal using stack
void dfs(int start) {
    bool visited[maxNode];
    for (int i = 0; i < maxNode; i++) {
        visited[i] = false;
    }

    Stack* stack = createStack(maxNode);
    visited[start] = true;
    push(stack, start);

    while (!isStackEmpty(stack)) {
        int current = pop(stack);
        printf("%d ", current);

        Node *p = adjlist[current]->head;
        while (p) {
            int neighbor = p->vNum;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                push(stack, neighbor);
            }
            p = p->next;
        }
    }

    free(stack->array);
    free(stack);
}

int main() {
    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < maxNode; i++) {
        adjlist[i] = (List *)malloc(sizeof(List));
        adjlist[i]->head = NULL;
    }

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int source, destination;
        scanf("%d %d", &source, &destination);
        if (source < 0 || source >= maxNode || destination < 0 || destination >= maxNode) {
            printf("Invalid vertex numbers\n");
            exit(EXIT_FAILURE);
        }
        addNode(source, destination);
    }

    printList();

    printf("DFS traversal starting from vertex 0: ");
    dfs(0);
    
    return 0;
}

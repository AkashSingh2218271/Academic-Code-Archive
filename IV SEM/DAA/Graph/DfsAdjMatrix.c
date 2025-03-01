#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Structure to represent a stack
struct Stack {
    struct StackNode* top;
};

// Function to create a new stack node
struct StackNode* createStackNode(int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct StackNode* newNode = createStackNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    struct StackNode* temp = stack->top;
    int popped = temp->data;
    stack->top = temp->next;
    free(temp);
    return popped;
}

struct Graph {
    int v, e;
    int** adj;
};

struct Graph* adjMatrix() {
    int v, u;
    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    if (g == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter number of vertices and edges respectively : ");
    scanf("%d %d", &g->v, &g->e);

    // Allocate memory for the adjacency matrix
    g->adj = (int**)malloc(sizeof(int*) * g->v);
    if (g->adj == NULL) {
        printf("Memory allocation failed\n");
        free(g);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < g->v; i++) {
        g->adj[i] = (int*)malloc(sizeof(int) * g->v);
        if (g->adj[i] == NULL) {
            printf("Memory allocation failed\n");
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(g->adj[j]);
            }
            free(g->adj);
            free(g);
            exit(EXIT_FAILURE);
        }
    }

    // Initialize adjacency matrix to 0
    for (int i = 0; i < g->v; i++) {
        for (int j = 0; j < g->v; j++) {
            g->adj[i][j] = 0;
        }
    }

    printf("Enter pairs of nodes for each edge : ");
    for (int i = 0; i < g->e; i++) {
        scanf("%d %d", &v, &u);
        g->adj[v][u] = 1; // Assuming it's an undirected graph
        g->adj[u][v] = 1; // If it's directed, remove this line
    }
    return g;
}

void printGraph(struct Graph* g) {
    printf("Adjacency Matrix is\n");
    for (int i = 0; i < g->v; i++) {
        for (int j = 0; j < g->v; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

void DFS(struct Graph* g, int start) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    
    int* visited = (int*)calloc(g->v, sizeof(int));
    if (visited == NULL) {
        printf("Memory allocation failed\n");
        free(stack);
        exit(EXIT_FAILURE);
    }

    push(stack, start);
    visited[start] = 1;

    printf("\nDFS Traversal: ");

    while (!isEmpty(stack)) {
        int current = pop(stack);
        printf("%d ", current);

        for (int i = 0; i < g->v; i++) {
            if (g->adj[current][i] && !visited[i]) {
                push(stack, i);
                visited[i] = 1;
            }
        }
    }

    free(stack);
    free(visited);
}

int main() {
    struct Graph* g = adjMatrix();
    if (g != NULL) {
        printGraph(g);
        DFS(g, 0);
        
        // Free allocated memory
        for (int i = 0; i < g->v; i++) {
            free(g->adj[i]);
        }
        free(g->adj);
        free(g);
    }
    return 0;
}

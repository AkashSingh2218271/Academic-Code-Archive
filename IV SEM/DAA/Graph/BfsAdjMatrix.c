#include <stdio.h>
#include <stdlib.h>

// Structure for the Graph
struct Graph {
    int v, e;
    int **adj;
};

// Queue structure for BFS
struct Queue {
    int front, rear;
    int *array;
    unsigned capacity;
};

// Function to create a queue
struct Queue *createQueue(unsigned capacity) {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if queue is full
int isFull(struct Queue *queue) {
    return (queue->rear == queue->capacity - 1);
}

// Function to check if queue is empty
int isEmpty(struct Queue *queue) {
    return (queue->front == -1);
}

// Function to add an item to the queue
void enqueue(struct Queue *queue, int item) {
    if (isFull(queue))
        return;
    queue->array[++queue->rear] = item;
    if (queue->front == -1)
        ++queue->front;
}

// Function to remove an item from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        ++queue->front;
    return item;
}

// Breadth-First Search function
void BFS(struct Graph *g, int startVertex) {
    struct Queue *queue = createQueue(g->v);
    int *visited = (int *)calloc(g->v, sizeof(int));
    
    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < g->v; ++i) {
            if (g->adj[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
    
    free(visited);
    free(queue->array);
    free(queue);
}

// Function to create adjacency matrix representation of graph
struct Graph *adjMatrix() {
    int v, u;
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
    if (g == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    printf("Enter number of vertices and edges respectively : ");
    scanf("%d %d", &g->v, &g->e);

    // Allocate memory for the adjacency matrix
    g->adj = (int **)malloc(sizeof(int *) * g->v);
    if (g->adj == NULL) {
        printf("Memory allocation failed\n");
        free(g);
        return NULL;
    }
    for (int i = 0; i < g->v; i++) {
        g->adj[i] = (int *)malloc(sizeof(int) * g->v);
        if (g->adj[i] == NULL) {
            printf("Memory allocation failed\n");
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(g->adj[j]);
            }
            free(g->adj);
            free(g);
            return NULL;
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

// Function to print adjacency matrix
void printGraph(struct Graph *g) {
    printf("Adjacency Matrix is\n");
    for (int i = 0; i < g->v; i++) {
        for (int j = 0; j < g->v; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Graph *g = adjMatrix();
    if (g != NULL) {
        printf("BFS Traversal starting from vertex 0: ");
        BFS(g, 0);
        printf("\n");

        // Print adjacency matrix
        printGraph(g);

        // Free allocated memory
        for (int i = 0; i < g->v; i++) {
            free(g->adj[i]);
        }
        free(g->adj);
        free(g);
    }
    return 0;
}

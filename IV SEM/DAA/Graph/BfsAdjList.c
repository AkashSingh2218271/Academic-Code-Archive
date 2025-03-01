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

// Queue implementation
typedef struct Queue {
    int front, rear, size;
    unsigned capacity;
    int *array;
} Queue;

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

bool isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

bool isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// BFS traversal using queue
void bfs(int start) {
    bool visited[maxNode];
    for (int i = 0; i < maxNode; i++) {
        visited[i] = false;
    }

    Queue* queue = createQueue(maxNode);
    visited[start] = true;
    enqueue(queue, start);

    while (!isEmpty(queue)) {
        int current = dequeue(queue);
        printf("%d ", current);

        Node *p = adjlist[current]->head;
        while (p) {
            int neighbor = p->vNum;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                enqueue(queue, neighbor);
            }
            p = p->next;
        }
    }

    free(queue->array);
    free(queue);
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
        addNode(destination, source);
    }

    printList();

    printf("BFS traversal starting from vertex 0: ");
    bfs(0);
    
    return 0;
}

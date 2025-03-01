#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjList;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Create an array of adjacency lists
    graph->adjList = (struct Node**)malloc(numVertices * sizeof(struct Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int from, int to) {
    // Add an edge from 'from' to 'to'
    struct Node* newNode = createNode(to);
    newNode->next = graph->adjList[from];
    graph->adjList[from] = newNode;

    // For an undirected graph, add an edge from 'to' to 'from' as well
    newNode = createNode(from);
    newNode->next = graph->adjList[to];
    graph->adjList[to] = newNode;
}

// Depth-First Search function
void dfs(struct Graph* graph, int vertex, bool visited[]) {
    printf("%d ", vertex);
    visited[vertex] = true;

    struct Node* temp = graph->adjList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            dfs(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

int main() {
    printf("Enter the number of vertices in the graph: ");
    int numVertices;
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices);

    printf("Enter the edges (from to) in the graph, and enter -1 -1 to stop:\n");

    int from, to;
    while (1) {
        scanf("%d %d", &from, &to);
        if (from == -1 || to == -1) {
            break;
        }

        if (from < 0 || from >= numVertices || to < 0 || to >= numVertices) {
            printf("Invalid input. Vertex does not exist.\n");
            continue;
        }

        addEdge(graph, from, to);
    }

    bool* visited = (bool*)malloc(numVertices * sizeof(bool));
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    printf("DFS traversal starting from vertex 0: ");
    dfs(graph, 0, visited);

    // Free allocated memory
    free(visited);
    free(graph->adjList);
    free(graph);

    return 0;
}

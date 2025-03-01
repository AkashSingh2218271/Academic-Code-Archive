#include <stdio.h>
#include <stdlib.h>

struct Graph {
    int v, e;
    int **adj;
};

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

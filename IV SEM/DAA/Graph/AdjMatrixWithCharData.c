#include <stdio.h>
#include <stdlib.h>

struct Graph {
    int v, e;
    char *vertices;
    int **adj;
};

struct Graph *adjMatrix() {
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
    if (g == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    printf("Enter number of vertices and edges respectively : ");
    scanf("%d %d", &g->v, &g->e);

    // Allocate memory for vertices array
    g->vertices = (char *)malloc(sizeof(char) * g->v);
    if (g->vertices == NULL) {
        printf("Memory allocation failed\n");
        free(g);
        return NULL;
    }

    // Input vertex labels
    printf("Enter labels for each vertex (characters separated by space): ");
    for (int i = 0; i < g->v; i++) {
        scanf(" %c", &g->vertices[i]);
    }

    // Allocate memory for the adjacency matrix
    g->adj = (int **)malloc(sizeof(int *) * g->v);
    if (g->adj == NULL) {
        printf("Memory allocation failed\n");
        free(g->vertices);
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
            free(g->vertices);
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
        char v, u;
        scanf(" %c %c", &v, &u);
        // Find indices of vertices v and u
        int indexV = -1, indexU = -1;
        for (int j = 0; j < g->v; j++) {
            if (g->vertices[j] == v) {
                indexV = j;
            }
            if (g->vertices[j] == u) {
                indexU = j;
            }
        }
        if (indexV == -1 || indexU == -1) {
            printf("Invalid vertices\n");
            continue;
        }
        g->adj[indexV][indexU] = 1; // Assuming it's an undirected graph
        g->adj[indexU][indexV] = 1; // If it's directed, remove this line
    }
    return g;
}

void printGraph(struct Graph *g) {
    printf("Adjacency Matrix is\n");
    printf("  ");
    for (int i = 0; i < g->v; i++) {
        printf("%c ", g->vertices[i]);
    }
    printf("\n");
    for (int i = 0; i < g->v; i++) {
        printf("%c ", g->vertices[i]);
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
        free(g->vertices);
        free(g);
    }
    return 0;
}

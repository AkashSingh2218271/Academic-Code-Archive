#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Graph
{
    int v, e;
    int **adj;
};

struct Graph *adjMatrix()
{
    int v, u;
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
    if (g == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    printf("Enter number of vertices and edges respectively : ");
    scanf("%d %d", &g->v, &g->e);

    g->adj = (int **)malloc(sizeof(int *) * g->v);
    if (g->adj == NULL)
    {
        printf("Memory allocation failed\n");
        free(g);
        return NULL;
    }
    for (int i = 0; i < g->v; i++)
    {
        g->adj[i] = (int *)malloc(sizeof(int) * g->v);
    }

    // Initialize adjacency matrix to 0
    for (int i = 0; i < g->v; i++)
    {
        for (int j = 0; j < g->v; j++)
        {
            g->adj[i][j] = 0;
        }
    }

    printf("Enter pairs of nodes for each edge with weight: ");
    for (int i = 0; i < g->e; i++)
    {
        int weight;
        scanf("%d %d %d", &v, &u, &weight);
        g->adj[v][u] = weight;
        g->adj[u][v] = weight;
    }
    return g;
}

void printGraph(struct Graph *g)
{
    printf("Adjacency Matrix is\n");
    for (int i = 0; i < g->v; i++)
    {
        for (int j = 0; j < g->v; j++)
        {
            printf("%d\t", g->adj[i][j]);
        }
        printf("\n");
    }
}

void primsMST(struct Graph *g)
{
    int parent[g->v]; // Array to store constructed MST
    int key[g->v];    // Key values used to pick minimum weight edge in cut
    int mstSet[g->v]; // To represent set of vertices not yet included in MST
    // Initialize all keys as INFINITE
    for (int i = 0; i < g->v; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < g->v - 1; count++)
    {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int minKey = INT_MAX, minIndex;
        for (int v = 0; v < g->v; v++)
        {
            if (mstSet[v] == 0 && key[v] < minKey)
            {
                minKey = key[v];
                minIndex = v;
            }
        }
        // Add the picked vertex to the MST Set
        mstSet[minIndex] = 1;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < g->v; v++)
            // g->adj[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if g->adj[u][v] is smaller than key[v]
            if (g->adj[minIndex][v] && mstSet[v] == 0 && g->adj[minIndex][v] < key[v])
            {
                parent[v] = minIndex;
                key[v] = g->adj[minIndex][v];
            }
    }

    // print the constructed MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < g->v; i++)
        printf("%d - %d \t%d \n", parent[i], i, g->adj[i][parent[i]]);
}

int main()
{
    struct Graph *g = adjMatrix();
    if (g != NULL)
    {
        printGraph(g);
        primsMST(g);
        // Free allocated memory
        for (int i = 0; i < g->v; i++)
        {
            free(g->adj[i]);
        }
        free(g->adj);
        free(g);
    }
    return 0;
}

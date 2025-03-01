#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int find(int parent[], int i);
void Union(int parent[], int x, int y);
void KruskalMST(int V, int E, int edges[][3]);

// Find the subset of an element 'i'
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// Union of two subsets
void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Compare two edges according to their weights
int compare(const void* a, const void* b) {
    return (*(int(*)[3])a)[2] - (*(int(*)[3])b)[2];
}

// Apply Kruskal's algorithm to find the Minimum Spanning Tree
void KruskalMST(int V, int E, int edges[][3]) {
    int result[V - 1][2]; // This will store the resultant MST
    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = -1;
    
    // Sort all the edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compare);
    
    int e = 0; // An index variable, used for result[]
    int i = 0; // An index variable, used for sorted edges
    while (e < V - 1 && i < E) {
        int src = edges[i][0];
        int dest = edges[i][1];
        
        int x = find(parent, src);
        int y = find(parent, dest);
        
        if (x != y) {
            result[e][0] = src;
            result[e][1] = dest;
            Union(parent, x, y);
            e++;
        }
        i++;
    }
    
    printf("Edges in the MST:\n");
    int totalWeight = 0;
    for (int j = 0; j < e; j++) {
        printf("%d -- %d Weight: %d\n", result[j][0], result[j][1], edges[j][2]);
        totalWeight += edges[j][2];
    }
    printf("Total Weight of MST: %d\n", totalWeight);
}

int main() {
    int V, E;
    printf("Enter the number of vertices and edges for the graph: ");
    scanf("%d %d", &V, &E);
    
    // Dynamically allocate memory for edges array
    int (*edges)[3] = malloc(E * sizeof(*edges));
    if (edges == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }
    
    printf("Enter the edges (source destination weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }
    
    printf("\nMinimum Spanning Tree for the graph:\n");
    KruskalMST(V, E, edges);
    
    // Free dynamically allocated memory
    free(edges);
    
    return 0;
}

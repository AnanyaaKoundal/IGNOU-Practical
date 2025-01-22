#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 7
#define MAX_EDGES 10  // Adjust according to the number of edges

// Structure to represent an edge
typedef struct {
    int u, v, weight;
} Edge;

// Structure to represent a disjoint-set (Union-Find)
typedef struct {
    int parent[MAX_VERTICES];
    int rank[MAX_VERTICES];
} DisjointSet;

// Function to initialize a disjoint-set
void makeSet(DisjointSet *ds, int V) {
    for (int i = 0; i < V; i++) {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }
}

// Find function with path compression
int findSet(DisjointSet *ds, int v) {
    if (ds->parent[v] != v) {
        ds->parent[v] = findSet(ds, ds->parent[v]);  // Path compression
    }
    return ds->parent[v];
}

// Union function by rank
void unionSets(DisjointSet *ds, int u, int v) {
    int rootU = findSet(ds, u);
    int rootV = findSet(ds, v);
    
    if (rootU != rootV) {
        // Union by rank
        if (ds->rank[rootU] > ds->rank[rootV]) {
            ds->parent[rootV] = rootU;
        } else if (ds->rank[rootU] < ds->rank[rootV]) {
            ds->parent[rootU] = rootV;
        } else {
            ds->parent[rootV] = rootU;
            ds->rank[rootU]++;
        }
    }
}

// Function to compare two edges for sorting by weight
int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

// Kruskal's algorithm to find the MST
void kruskal(int V, Edge edges[], int E) {
    DisjointSet ds;
    makeSet(&ds, V);
    
    qsort(edges, E, sizeof(Edge), compareEdges);  // Sort edges by weight
    
    printf("Edges in MST:\n");
    
    // Iterate through edges and add to MST if they don't form a cycle
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        
        // If u and v belong to different sets, add edge to MST
        if (findSet(&ds, u) != findSet(&ds, v)) {
            printf("%d - %d: %d\n", u, v, edges[i].weight);
            unionSets(&ds, u, v);  // Union the sets
        }
    }
}

int main() {
    // Number of vertices and edges
    int V = 7;  // There are 7 vertices (0 to 6)
    int E = 10; // We have 10 edges
    
    // List of edges (u, v, weight)
    Edge edges[MAX_EDGES] = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 3, 4},
        {1, 4, 3},
        {2, 3, 7},
        {2, 5, 6},
        {3, 4, 5},
        {3, 5, 9},
        {3, 6, 2},
        {5, 6, 8}
    };
    
    // Call Kruskal's algorithm to find the MST
    kruskal(V, edges, E);
    
    return 0;
}

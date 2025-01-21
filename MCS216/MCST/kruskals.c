#include <stdio.h>
#include <stdlib.h>

#define V 6  // Number of vertices
#define E 9  // Number of edges

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to find the subset of an element (with path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);  // Path compression
    }
    return subsets[i].parent;
}

// Function to do the union of two subsets
void union_sets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Union by rank
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to compare two edges for sorting (used in qsort)
int compare(const void *a, const void *b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal's algorithm to find the Minimum Cost Spanning Tree (MCST)
void kruskalMST(struct Edge edges[], int graph[V][V]) {
    struct Edge result[V - 1];  // To store the resulting MST
    int e = 0;  // Count of edges in MST
    int i = 0;  // Initial index for sorted edges

    // Step 1: Sort the edges in non-decreasing order of their weights
    qsort(edges, E, sizeof(edges[0]), compare);

    // Display the sorted edges
    printf("Sorted edges based on weight:\n");
    for (int i = 0; i < E; i++) {
        printf("Edge(%d-%d) with weight: %d\n", edges[i].src, edges[i].dest, edges[i].weight);
    }

    // Create `V` subsets with single elements
    struct Subset *subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Step 2: Pick the smallest edge. If it forms a cycle, discard it. Otherwise, include it in the MST.
    printf("\nIterating through edges and adding them to MST if they don't form a cycle:\n");
    while (e < V - 1 && i < E) {
        struct Edge next_edge = edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not cause a cycle, include it in the result
        printf("Checking edge(%d-%d) with weight %d:\n", next_edge.src, next_edge.dest, next_edge.weight);
        if (x != y) {
            printf("  Edge(%d-%d) is added to MST.\n", next_edge.src, next_edge.dest);
            result[e++] = next_edge;
            union_sets(subsets, x, y);
        } else {
            printf("  Edge(%d-%d) would form a cycle, so it's discarded.\n", next_edge.src, next_edge.dest);
        }

        // Print current subsets (union-find sets)
        printf("Current subsets:\n");
        for (int j = 0; j < V; j++) {
            printf("Subset %d: Parent = %d, Rank = %d\n", j, subsets[j].parent, subsets[j].rank);
        }
    }

    // Step 3: Print the constructed MST
    printf("\nMinimum Cost Spanning Tree (MCST) edges and their weights:\n");
    int totalWeight = 0;
    for (i = 0; i < e; i++) {
        printf("%d - %d : %d\n", result[i].src, result[i].dest, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("\nTotal weight of the Minimum Cost Spanning Tree: %d\n", totalWeight);

    // Free memory for subsets
    free(subsets);
}

int main() {
    // Graph with edges (src, dest, weight)
    struct Edge edges[E] = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5},
        {2, 4, 7}, {3, 4, 9}, {4, 5, 4}, {5, 3, 0}
    };

    // Call Kruskal's algorithm
    kruskalMST(edges, NULL);

    return 0;
}

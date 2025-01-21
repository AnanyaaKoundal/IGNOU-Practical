#include <stdio.h>
#include <limits.h>

#define V 6  // Number of vertices

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

// Function to implement Prim's Algorithm to find the Minimum Cost Spanning Tree (MCST)
void primMST(int graph[V][V]) {
    int parent[V];  // Array to store the constructed MST
    int key[V];     // Key values used to pick the minimum weight edge
    int mstSet[V];  // mstSet[v] will be 1 if vertex v is included in MST, else 0

    // Initialize all keys as INFINITE and mstSet[] as 0
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Always include the first vertex in the MST
    key[0] = 0;  // Make key 0 for the first vertex
    parent[0] = -1;  // First node has no parent

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet processed
        int u = minKey(key, mstSet);
        mstSet[u] = 1;  // Include the picked vertex in the MST

        // Update the key and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update the key value and parent if the vertex v is not in mstSet, and if
            // the edge u-v has a smaller weight than the current key value of vertex v
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }

        // Print the key values and parent vertices for the current iteration
        printf("\nIteration %d:\n", count + 1);
        printf("Vertex\tKey\tParent\n");
        for (int i = 0; i < V; i++) {
            printf("%d\t%d\t%d\n", i, key[i], parent[i]);
        }
    }

    // Print the constructed Minimum Cost Spanning Tree (MCST)
    printf("\nMinimum Cost Spanning Tree (MCST) edges and their weights:\n");
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        printf("%d - %d : %d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("\nTotal weight of the Minimum Cost Spanning Tree: %d\n", totalWeight);
}

int main() {
    // Example graph represented as an adjacency matrix (Weighted Undirected Graph)
    int graph[V][V] = {
        {0, 2, 0, 6, 0, 0},
        {2, 0, 3, 8, 5, 0},
        {0, 3, 0, 0, 7, 0},
        {6, 8, 0, 0, 9, 0},
        {0, 5, 7, 9, 0, 4},
        {0, 0, 0, 0, 4, 0}
    };

    primMST(graph);

    return 0;
}

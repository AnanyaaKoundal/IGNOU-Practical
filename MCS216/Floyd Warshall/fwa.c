#include <stdio.h>
#include <limits.h>

#define V 4  // Number of vertices
#define INF INT_MAX  // Representation of infinity

// Function to print the matrix
void printMatrix(int dist[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to implement Floyd-Warshall Algorithm
void floydWarshall(int graph[V][V]) {
    int dist[V][V], i, j, k;

    // Initialize the distance matrix same as the input graph matrix
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Print initial matrix D_0
    printf("Initial matrix D_0:\n");
    printMatrix(dist);

    // Applying Floyd-Warshall Algorithm
    for (k = 0; k < V; k++) {
        // Update distance matrix considering vertex k as intermediate
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        // Print the matrix D_k after considering vertex k as intermediate
        printf("Matrix D_%d (After considering vertex %d as intermediate):\n", k + 1, k);
        printMatrix(dist);
    }

    // Final matrix with shortest distances between all pairs of vertices
    printf("Final shortest distance matrix after applying Floyd-Warshall:\n");
    printMatrix(dist);
}

int main() {
    // Initialize the graph as an adjacency matrix
    int graph[V][V] = {
        {0, 9, -4, INF},
        {6, 0, INF, 2},
        {INF, 5, 0, INF},
        {INF, INF, 1, 0}
    };

    // Call the Floyd-Warshall algorithm
    floydWarshall(graph);

    return 0;
}

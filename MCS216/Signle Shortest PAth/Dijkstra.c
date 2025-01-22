#include <stdio.h>
#include <limits.h>

#define INF 9999
#define MAX 10

void DijkstraAlgorithm(int Graph[MAX][MAX], int size, int start) {
    int cost[MAX][MAX], distance[MAX], previous[MAX], visited[MAX] = {0};
    int i, j, counter = 1, min_dist, next_node;

    // Initialize cost matrix and distance array
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            cost[i][j] = (Graph[i][j] == 0) ? INF : Graph[i][j];
        }
        distance[i] = (i == start) ? 0 : cost[start][i];
        previous[i] = start;
    }

    visited[start] = 1;

    // Dijkstra's algorithm
    while (counter < size - 1) {
        min_dist = INF;
        for (i = 0; i < size; i++) {
            if (!visited[i] && distance[i] < min_dist) {
                min_dist = distance[i];
                next_node = i;
            }
        }

        visited[next_node] = 1;
        for (i = 0; i < size; i++) {
            if (!visited[i] && min_dist + cost[next_node][i] < distance[i]) {
                distance[i] = min_dist + cost[next_node][i];
                previous[i] = next_node;
            }
        }
        counter++;
    }

    // Print the shortest distances
    for (i = 0; i < size; i++) {
        if (i != start) {
            printf("\nDistance from node %d to node %d: %d", start, i, distance[i]);
        }
    }
}

int main() {
    int Graph[MAX][MAX] = {
        {0, 4, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0},
        {0, 0, 7, 0, 9, 14, 0},
        {0, 0, 0, 9, 0, 10, 2},
        {0, 0, 4, 14, 10, 0, 2},
        {0, 0, 0, 0, 2, 0, 1}
    };
    
    int size = 7, source = 0;
    DijkstraAlgorithm(Graph, size, source);
    return 0;
}

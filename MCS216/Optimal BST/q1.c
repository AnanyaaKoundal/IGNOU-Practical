#include <stdio.h>
#include <limits.h>

#define N 7  // Number of keys

// Function to compute the optimal binary search tree and its cost
void optimalBST(double p[], double q[], int n) {
    // Cost and root tables for dynamic programming
    double C[n + 1][n + 1];
    int root[n + 1][n + 1];

    // Initialize the C and root tables
    for (int i = 0; i <= n; i++) {
        C[i][i] = q[i];  // Cost of an empty subtree
        root[i][i] = i;  // Root for an empty subtree is itself
    }

    // Compute the cost for all lengths of subarrays
    for (int length = 1; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length;
            C[i][j] = INT_MAX;
            double totalProb = 0.0;
            
            // Calculate total probability sum for the range
            for (int k = i; k <= j; k++) {
                totalProb += p[k];
            }
            for (int k = i - 1; k < j; k++) {
                totalProb += q[k];
            }

            // Find the optimal root
            for (int r = i; r <= j; r++) {
                double cost = (r > i ? C[i][r - 1] : 0) + (r < j ? C[r + 1][j] : 0) + totalProb;
                if (cost < C[i][j]) {
                    C[i][j] = cost;
                    root[i][j] = r;  // Store the root of the optimal subtree
                }
            }
        }
    }

    // Print the minimum cost
    printf("Minimum cost of the optimal binary search tree: %.2f\n", C[0][n]);

    // Function to print the structure of the tree
    printf("Optimal binary search tree structure:\n");
    printOptimalBST(root, 0, n - 1, n);
}

// Function to print the structure of the optimal binary search tree
void printOptimalBST(int root[][N + 1], int i, int j, int n) {
    if (i <= j) {
        printf("Root of subtree [%d, %d]: Key %d\n", i + 1, j + 1, root[i][j] + 1);
        printOptimalBST(root, i, root[i][j] - 1, n);
        printOptimalBST(root, root[i][j] + 1, j, n);
    }
}

int main() {
    // Key probabilities
    double p[] = {0.15, 0.10, 0.05, 0.10, 0.20, 0.05, 0.05};  // Probabilities for keys k1, k2, ..., k7
    double q[] = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10, 0.05, 0.05};  // Probabilities for dummy keys

    int n = 7;  // Number of keys

    // Call the function to calculate the OBST
    optimalBST(p, q, n);

    return 0;
}

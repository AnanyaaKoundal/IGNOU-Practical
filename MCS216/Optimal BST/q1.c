#include <stdio.h>
#include <limits.h>

void OPTIMAL_BST(int p[], int q[], int n) {
    int i, j, l, r;
    int t;

    // Declare tables e, w, and root locally within the function
    int e[n+2][n+1], w[n+2][n+1], root[n+1][n+1];

    // Initialize the tables e, w, and root
    for (i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    // Fill the tables e, w, and root
    for (l = 1; l <= n; l++) {
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;

            e[i][j] = INT_MAX; // Initialize e[i][j] to a large number
            w[i][j] = w[i][j - 1] + p[j] + q[j]; // Calculate w[i][j]

            // Try all possible roots for the interval (i, j)
            for (r = i; r <= j; r++) {
                t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;         // Update minimum cost
                    root[i][j] = r;      // Store the root of the optimal subtree
                }
            }
        }
    }
    printf("root: %d\n", root[1][n]);
}

int main() {
    int n = 4; // Example number of nodes
    int p[] = {0,3,3,1,1}; // Example probabilities for keys
    int q[] = {2, 3, 1,1,1}; // Example probabilities for dummy keys

    // Call the function to compute the optimal BST
    OPTIMAL_BST(p, q, n);

    return 0;
}

#include <stdio.h>
#include <limits.h>

#define N 6  // Adjusted size to accommodate the dimensions of 5 matrices

// Function to find the minimum number of scalar multiplications
int matrixChainOrder(int p[], int n, int split[][N]) {
    int dp[n][n];

    // Initialize the dp array to store the minimum number of multiplications
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;  // No multiplication needed for a single matrix
    }

    // Chain length l varies from 2 to n-1
    for (int l = 2; l < n; l++) {
        for (int i = 0; i < n - l; i++) {
            int j = i + l;
            dp[i][j] = INT_MAX; // Set dp[i][j] to a large number initially

            // Try all possible positions to split the chain
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j];

                if (q < dp[i][j]) {
                    dp[i][j] = q;
                    split[i][j] = k; // Store the split point
                }
            }
        }
    }

    // Printing the optimal number of multiplications
    printf("Minimum number of scalar multiplications: %d\n", dp[0][n - 1]);
    return dp[0][n - 1];
}

// Function to print the optimal parenthesization
void printOptimalParenthesis(int split[][N], int i, int j) {
    if (i == j) {
        printf("A%d", i + 1);  // Print matrix A1, A2, etc.
    } else {
        printf("(");
        printOptimalParenthesis(split, i, split[i][j]);
        printOptimalParenthesis(split, split[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    // Dimensions of the matrices (10x4), (4x5), (5x20), (20x2), (2x50)
    int p[] = {10, 4, 5, 20, 2, 50};  // The dimensions of matrices A, B, C, D, E

    // The number of matrices
    int n = sizeof(p) / sizeof(p[0]) - 1;  // n matrices, so n+1 dimensions

    // Split table to store the optimal split points
    int split[N][N] = {0};

    // Call the matrixChainOrder function to get the optimal number of multiplications
    matrixChainOrder(p, n + 1, split);

    // Now, print the optimal parenthesization of the matrices
    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(split, 0, n - 1);

    return 0;
}

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
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX; // Set dp[i][j] to a large number initially

            // Try all possible positions to split the chain
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < dp[i][j]) {
                    dp[i][j] = q;
                    split[i][j] = k; // Store the split point
                    printf("dp[%d][%d] = %d, split=%d\n", i, j, dp[i][j], split[i][j]);
                }
            }
        }
    }

    // Printing the optimal number of multiplications
    printf("Minimum number of scalar multiplications: %d\n", dp[1][n - 1]);
    return dp[1][n - 1];
}

// Function to print the optimal parenthesization
void printOptimalParenthesis(int split[][N], int i, int j) {
    if (i == j) {
        printf("A%d", i);  // Print matrix A1, A2, etc.
    } else {
        printf("(");
        printOptimalParenthesis(split, i, split[i][j]);
        printf(" x ");
        printOptimalParenthesis(split, split[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    // Dimensions of the matrices (30x35), (35x15), (15x5), (5x10), (10x20)
    int p[] = {30, 35, 15, 5, 10, 20};  // The dimensions of matrices A, B, C, D, E

    // The number of matrices
    int n = sizeof(p) / sizeof(p[0]) - 1;  // n matrices, so n+1 dimensions

    // Split table to store the optimal split points
    int split[N][N] = {0};

    // Call the matrixChainOrder function to get the optimal number of multiplications
    matrixChainOrder(p, n + 1, split);

    // Now, print the optimal parenthesization of the matrices
    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(split, 1, n);  // We need to print the matrices from 0 to n-1

    return 0;
}

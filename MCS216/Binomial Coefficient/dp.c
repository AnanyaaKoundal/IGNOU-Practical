#include <stdio.h>

// Function to calculate binomial coefficient C(n, k) using Dynamic Programming
int binomialCoefficient(int n, int k) {
    // Create a 2D table to store binomial coefficients
    int dp[n + 1][k + 1];

    // Calculate binomial coefficient using Dynamic Programming approach
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= (i < k ? i : k); j++) {
            // Base cases
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                // Recurrence relation
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }
    
    // Return the result of C(n, k)
    return dp[n][k];
}

int main() {
    int n=5, k=2;
    
    // Take input for n and k
    // printf("Enter n (number of elements): ");
    // scanf("%d", &n);
    // printf("Enter k (number of choices): ");
    // scanf("%d", &k);

    // Calculate and print the binomial coefficient C(n, k)
    int result = binomialCoefficient(n, k);
    printf("Binomial Coefficient C(%d, %d) = %d\n", n, k, result);

    return 0;
}

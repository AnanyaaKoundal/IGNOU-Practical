#include <stdio.h>

// Function to calculate binomial coefficient C(n, k) using Divide and Conquer
int binomialCoefficient(int n, int k) {
    // Base case: If k is 0 or k is equal to n, return 1
    if (k == 0 || k == n)
        return 1;
    
    // Divide and conquer: Apply the recurrence relation
    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
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

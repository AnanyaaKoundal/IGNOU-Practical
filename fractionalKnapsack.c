#include <stdio.h>

// Function to perform the fractional knapsack algorithm
double fractionalKnapsack(int values[], int weights[], int n, int capacity) {
    // Create an array to store value-to-weight ratio for each item
    double ratios[n];
    for (int i = 0; i < n; i++) {
        ratios[i] = (double)values[i] / weights[i];
    }

    // Simple Greedy approach: pick items based on the ratio
    double totalValue = 0.0;
    int remainingCapacity = capacity;

    // Repeat for each item based on sorted ratio (just doing this in order of given input)
    for (int i = 0; i < n; i++) {
        if (remainingCapacity == 0) break;  // No more space in the knapsack
        
        if (weights[i] <= remainingCapacity) {
            // Take the entire item
            totalValue += values[i];
            remainingCapacity -= weights[i];
        } else {
            // Take the fraction of the item
            totalValue += values[i] * ((double)remainingCapacity / weights[i]);
            break;  // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    // Given values and weights of items
    int values[] = {15, 5, 20, 8, 7, 20, 6};
    int weights[] = {3, 4, 6, 8, 2, 2, 3};
    int n = sizeof(values) / sizeof(values[0]);
    int capacity = 18;
    
    // Call the fractional knapsack function and get the maximum value
    double maxValue = fractionalKnapsack(values, weights, n, capacity);
    
    // Output the maximum value that can be obtained
    printf("Maximum value that can be obtained: %.2f\n", maxValue);
    
    return 0;
}

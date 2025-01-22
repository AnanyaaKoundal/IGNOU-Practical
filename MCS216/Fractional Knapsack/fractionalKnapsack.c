#include <stdio.h>
#include <stdlib.h>

// Function to perform the fractional knapsack algorithm
double fractionalKnapsack(int values[], int weights[], int n, int capacity) {
    // Create an array to store value-to-weight ratio for each item
    double ratios[n];
    for (int i = 0; i < n; i++) {
        ratios[i] = (double)values[i] / weights[i];
    }

    // Create an array to store the order of the indices after sorting by ratio
    int index[n];
    for (int i = 0; i < n; i++) {
        index[i] = i;
    }

    // Sort indices based on ratios in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratios[index[i]] < ratios[index[j]]) {
                // Swap indices
                int temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }

    // Greedy approach: pick items based on sorted ratio
    double totalValue = 0.0;
    int remainingCapacity = capacity;

    for (int i = 0; i < n; i++) {
        int currentIndex = index[i];

        if (remainingCapacity == 0) break;  // No more space in the knapsack
        
        if (weights[currentIndex] <= remainingCapacity) {
            // Take the entire item
            totalValue += values[currentIndex];
            remainingCapacity -= weights[currentIndex];
        } else {
            // Take the fraction of the item
            totalValue += values[currentIndex] * ((double)remainingCapacity / weights[currentIndex]);
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

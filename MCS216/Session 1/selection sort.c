#include <stdio.h>

// Function for Selection Sort
void selectionSort(int arr[], int n, int *comparisons, int *exchanges) {
    int i, j, minIndex, temp;
    
    // Outer loop: n-1 iterations (for each element in the array)
    for (i = 0; i < n - 1; i++) {
        minIndex = i;  // Assume the current element is the smallest
        
        // Inner loop: find the smallest element in the remaining unsorted portion
        for (j = i + 1; j < n; j++) {
            (*comparisons)++;  // Increment number of comparisons
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // Update minIndex if a smaller element is found
            }
        }
        
        // If minIndex is not the index of the current element, swap
        if (minIndex != i) {
            // Swap the elements
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            (*exchanges)++;  // Increment number of exchanges
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {55, 25, 15, 40, 60, 35, 17, 65, 75, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0, exchanges = 0;

    printf("Original array: ");
    printArray(arr, n);

    // Perform Selection Sort
    selectionSort(arr, n, &comparisons, &exchanges);

    printf("Sorted array: ");
    printArray(arr, n);

    // Output the results
    printf("Number of comparisons: %d\n", comparisons);
    printf("Number of exchanges: %d\n", exchanges);
    printf("Outer loop iterations: %d\n", n - 1);
    printf("Inner loop iterations: %d\n", comparisons);

    return 0;
}

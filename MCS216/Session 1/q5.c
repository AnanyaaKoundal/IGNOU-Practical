#include <stdio.h>

void bubbleSort(int arr[], int n, int *comparisons, int *exchanges) {
    int i, j, temp;
    
    // Outer loop: n-1 passes
    for (i = 0; i < n - 1; i++) {
        // Inner loop: compares each pair of adjacent elements
        for (j = 0; j < n - i - 1; j++) {
            (*comparisons)++;  // Increment number of comparisons
            if (arr[j] > arr[j + 1]) {
                // Swap the elements if they are in the wrong order
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*exchanges)++;  // Increment number of exchanges
            }
        }
    }
}

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

    // Perform bubble sort
    bubbleSort(arr, n, &comparisons, &exchanges);

    printf("Sorted array: ");
    printArray(arr, n);

    // Output the results
    printf("Number of comparisons: %d\n", comparisons);
    printf("Number of exchanges: %d\n", exchanges);
    printf("Outer loop iterations: %d\n", n - 1);
    printf("Inner loop iterations: %d\n", comparisons);

    return 0;
}

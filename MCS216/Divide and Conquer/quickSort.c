#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Select the last element as the pivot
    int i = low - 1;  // Index of smaller element

    // Traverse through all elements, compare each with the pivot
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);  // Swap elements at i and j
        }
    }

    // Swap the pivot element with the element at i + 1
    swap(&arr[i + 1], &arr[high]);
    printf("After partition: ");
    for (int k = low; k <= high; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");

    return (i + 1);  // Return the partition index
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find the partition index
        int pi = partition(arr, low, high);

        // Recursively sort the left and right subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {12, 20, 22, 16, 25, 18, 8, 10, 6, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, n - 1);  // Call quickSort

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

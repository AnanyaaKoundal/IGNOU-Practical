#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    printf("Searching in range: [%d, %d]\n", left, right);  // Showing the range being searched

    if (left > right) {
        return -1; // Target not found
    }

    int mid = left + (right - left) / 2;
    printf("Mid index: %d, Mid element: %d\n", mid, arr[mid]);

    // Check if the target is at mid
    if (arr[mid] == target) {
        return mid;
    }

    // If target is smaller, search the left half
    if (arr[mid] > target) {
        return binarySearch(arr, left, mid - 1, target);
    }

    // If target is larger, search the right half
    return binarySearch(arr, mid + 1, right, target);
}

int main() {
    int arr[] = {10, 35, 40, 45, 50, 55, 60, 65, 70, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 100;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}

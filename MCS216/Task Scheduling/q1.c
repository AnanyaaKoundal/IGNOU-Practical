#include <stdio.h>
#include <stdlib.h>

// Function to calculate the total completion time for a given job schedule
int calculateTotalTime(int jobs[], int serviceTimes[], int n) {
    int totalTime = 0;
    int currentTime = 0;

    // Calculate the total time by summing up the service times in the order of jobs
    for (int i = 0; i < n; i++) {
        currentTime += serviceTimes[jobs[i]];  // Add the service time of the current job
        totalTime = currentTime;  // Keep track of the total time
    }

    return totalTime;
}

// Function to generate all permutations of the job schedule
void generatePermutations(int jobs[], int start, int end, int serviceTimes[], int n) {
    if (start == end) {
        // If we have a complete permutation, calculate the total time for this schedule
        int totalTime = calculateTotalTime(jobs, serviceTimes, n);
        printf("Schedule: ");
        for (int i = 0; i < n; i++) {
            printf("J%d ", jobs[i] + 1);  // Print job numbers (1-based index)
        }
        printf(" | Total Time: %d\n", totalTime);
    } else {
        for (int i = start; i <= end; i++) {
            // Swap jobs[start] with jobs[i]
            int temp = jobs[start];
            jobs[start] = jobs[i];
            jobs[i] = temp;

            // Recurse with the next position
            generatePermutations(jobs, start + 1, end, serviceTimes, n);

            // Swap back to restore the order for the next iteration
            temp = jobs[start];
            jobs[start] = jobs[i];
            jobs[i] = temp;
        }
    }
}

int main() {
    // Job service times
    int serviceTimes[] = {5, 8, 12};  // J1 = 5, J2 = 8, J3 = 12
    int n = sizeof(serviceTimes) / sizeof(serviceTimes[0]);

    // Job numbers (0-based indexing for easier handling in arrays)
    int jobs[] = {0, 1, 2};  // J1 = 0, J2 = 1, J3 = 2

    // Print all possible schedules and their total times
    printf("All possible job schedules and their total times:\n");
    generatePermutations(jobs, 0, n - 1, serviceTimes, n);

    return 0;
}

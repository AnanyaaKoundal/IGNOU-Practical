#include <stdio.h>

// Function to calculate the total time spent in the system
void scheduleJobs(int jobs[], int serviceTimes[], int n) {
    // Sorting jobs based on service times (Shortest Job First)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (serviceTimes[i] > serviceTimes[j]) {
                // Swap the service times
                int temp = serviceTimes[i];
                serviceTimes[i] = serviceTimes[j];
                serviceTimes[j] = temp;

                // Swap the corresponding jobs
                temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    int totalTime = 0; // Total time spent in the system
    int currentTime = 0; // Current time at which a job finishes

    // Calculate completion time for each job and total time spent
    for (int i = 0; i < n; i++) {
        currentTime += serviceTimes[i];  // Update the current time
        totalTime += currentTime;         // Add current time to total time
        printf("Job %d completed at time %d\n", jobs[i], currentTime);
    }

    // Output the total time spent in the system
    printf("Total time spent in the system: %d\n", totalTime);
}

int main() {
    // Job IDs
    int jobs[] = {1, 2, 3, 4};
    
    // Corresponding service times for each job
    int serviceTimes[] = {5, 10, 7, 8};
    
    // Number of jobs
    int n = sizeof(serviceTimes) / sizeof(serviceTimes[0]);

    // Print the initial job list
    printf("Jobs before scheduling:\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: Service time = %d\n", jobs[i], serviceTimes[i]);
    }

    // Call the scheduling function
    scheduleJobs(jobs, serviceTimes, n);

    return 0;
}

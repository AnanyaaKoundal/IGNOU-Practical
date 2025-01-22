#include <stdio.h>
#include <stdlib.h>

// Function to calculate waiting and turnaround times for a given schedule
void calculateTimes(int serviceTimes[], int n) {
    int schedules[6][3] = {
        {0, 1, 2},  // Job 1 -> Job 2 -> Job 3
        {0, 2, 1},  // Job 1 -> Job 3 -> Job 2
        {1, 0, 2},  // Job 2 -> Job 1 -> Job 3
        {1, 2, 0},  // Job 2 -> Job 3 -> Job 1
        {2, 0, 1},  // Job 3 -> Job 1 -> Job 2
        {2, 1, 0}   // Job 3 -> Job 2 -> Job 1
    };

    printf("Job schedules with Waiting Time and Turnaround Time:\n");
    
    int minTurnaroundTime = 0;
    int bestSchedule[n];
    int totalTime = 0;

    // Loop over all schedules
    for (int i = 0; i < 6; i++) {
        int completionTime = 0;
        int totalWaitingTime = 0;
        int totalTurnaroundTime = 0;
        totalTime = 0;
        
        // Calculate times for this schedule
        for (int j = 0; j < n; j++) {
            int job = schedules[i][j];
            
            // Turnaround time for current job (time till completion)
            completionTime += serviceTimes[job];
            totalTurnaroundTime += completionTime;
            totalTime += serviceTimes[job];
            
            // Waiting time (turnaround time - service time)
            totalWaitingTime += (completionTime - serviceTimes[job]);
        }

        // Print schedule, waiting time and turnaround time
        printf("Schedule: ");
        for (int j = 0; j < n; j++) {
            printf("J%d ", schedules[i][j] + 1); // +1 to make it 1-based index
        }
        printf("| Total Waiting Time: %d | Total Turnaround Time: %d\n", totalWaitingTime, totalTurnaroundTime);

        // Track minimum turnaround time
        if (i == 0 || totalTurnaroundTime < minTurnaroundTime) {
            minTurnaroundTime = totalTurnaroundTime;
            for (int j = 0; j < n; j++) {
                bestSchedule[j] = schedules[i][j];
            }
        }
    }

    // Print the best schedule
    printf("\nOptimal Schedule (minimized Turnaround Time): ");
    for (int i = 0; i < n; i++) {
        printf("J%d ", bestSchedule[i] + 1);
    }
    printf("| Total Time: %d ", totalTime);
    printf("| Optimal Total Turnaround Time: %d\n", minTurnaroundTime);
}

int main() {
    int serviceTimes[] = {5, 8, 12};  // Service times for J1, J2, J3
    int n = sizeof(serviceTimes) / sizeof(serviceTimes[0]);

    // Calculate and print schedules, waiting times, and turnaround times
    calculateTimes(serviceTimes, n);

    return 0;
}

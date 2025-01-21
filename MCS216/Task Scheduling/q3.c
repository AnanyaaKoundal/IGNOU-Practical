#include <stdio.h>

// Function to find the maximum profit
void scheduleJobs(int jobs[], int deadlines[], int profits[], int n) {
    // Find the maximum deadline to determine the number of slots
    int maxDeadline = deadlines[0];
    for (int i = 1; i < n; i++) {
        if (deadlines[i] > maxDeadline) {
            maxDeadline = deadlines[i];
        }
    }

    // Create an array to keep track of available time slots
    int slots[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        slots[i] = -1; // Initialize all slots as empty
    }

    // Sort jobs in descending order of profit
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (profits[i] < profits[j]) {
                // Swap jobs based on profit
                int tempJob = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = tempJob;

                int tempDeadline = deadlines[i];
                deadlines[i] = deadlines[j];
                deadlines[j] = tempDeadline;

                int tempProfit = profits[i];
                profits[i] = profits[j];
                profits[j] = tempProfit;
            }
        }
    }

    int totalProfit = 0; // Total profit from scheduled jobs
    printf("Job Scheduling Order (Job, Deadline, Profit):\n");

    // Try to schedule jobs in the available time slots
    for (int i = 0; i < n; i++) {
        // Find the latest available slot before the job's deadline
        for (int j = deadlines[i] - 1; j >= 0; j--) {
            if (slots[j] == -1) { // If slot is available
                slots[j] = jobs[i];  // Schedule the job
                totalProfit += profits[i];  // Add the profit
                printf("Job %d (Deadline: %d, Profit: %d) scheduled at time slot %d\n", jobs[i], deadlines[i], profits[i], j + 1);
                break;
            }
        }
    }

    // Output the total profit
    printf("Total Profit: %d\n", totalProfit);
}

int main() {
    // Jobs, deadlines and profits arrays
    int jobs[] = {1, 2, 3, 4, 5, 6, 7};
    int deadlines[] = {3, 4, 5, 3, 2, 1, 1};
    int profits[] = {50, 20, 70, 15, 10, 47, 60};

    int n = sizeof(jobs) / sizeof(jobs[0]);

    // Call the scheduling function
    scheduleJobs(jobs, deadlines, profits, n);

    return 0;
}

#include <stdio.h>

// Function to multiply two 4x4 matrices
void multiplyMatrices(int A[4][4], int B[4][4], int C[4][4], int *multiplications, int *additions, int *outerLoopRuns, int *innerLoopRuns) {

    // Multiply matrices
    for (int i = 0; i < 4; i++) {
        (*outerLoopRuns)++;
        for (int j = 0; j < 4; j++) {
            C[i][j] = 0; // Initialize the result matrix element
            for (int k = 0; k < 4; k++) {
                (*innerLoopRuns)++;
                C[i][j] += A[i][k] * B[k][j];
                (*multiplications)++; // Increment multiplication count
                (*additions)++;       // Increment addition count
            }
            (*additions)--; // Subtract one as the last addition didn't happen (reset to 0 doesn't count)
        }
    }
}

int main() {
    // Input matrices A and B
    int A[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int B[4][4] = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1}
    };

    int C[4][4]; // Result matrix
    int multiplications=0, additions=0, outerLoopRuns=0, innerLoopRuns=0;

    // Perform matrix multiplication
    multiplyMatrices(A, B, C, &multiplications, &additions, &outerLoopRuns, &innerLoopRuns);

    // Display the result matrix
    printf("Resultant Matrix C:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Display the computed metrics
    printf("\nMetrics:\n");
    printf("Outer loop iterations: %d\n", outerLoopRuns);
    printf("Inner loop iterations: %d\n", innerLoopRuns);
    printf("Total multiplications: %d\n", multiplications);
    printf("Total additions: %d\n", additions);

    return 0;
}

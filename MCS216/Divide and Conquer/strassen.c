#include <stdio.h>
#include <stdlib.h>

void add(int n, int A[n][n], int B[n][n], int result[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract(int n, int A[n][n], int B[n][n], int result[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int n, int A[n][n], int B[n][n], int result[n][n], int* mul_count, int* add_count) {
    if (n == 1) {
        result[0][0] = A[0][0] * B[0][0]; 
        (*mul_count)++;
        return;
    }

    int half = n / 2;
    int A11[half][half], A12[half][half], A21[half][half], A22[half][half];
    int B11[half][half], B12[half][half], B21[half][half], B22[half][half];
    
    // Dividing matrices into 4 submatrices
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];
            
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    // Calculate P1 to P7 using Strassen's formulas
    int M1[half][half], M2[half][half], M3[half][half], M4[half][half], M5[half][half], M6[half][half], M7[half][half];
    int temp1[half][half], temp2[half][half];

    add(half, A11, A22, temp1);  // A11 + A22
    add(half, B11, B22, temp2);  // B11 + B22
    strassen(half, temp1, temp2, M1, mul_count, add_count);  // P1 = (A11 + A22) * (B11 + B22)

    add(half, A21, A22, temp1);  // A21 + A22
    strassen(half, temp1, B11, M2, mul_count, add_count);  // P2 = (A21 + A22) * B11

    subtract(half, B12, B22, temp2);  // B12 - B22
    strassen(half, A11, temp2, M3, mul_count, add_count);  // P3 = A11 * (B12 - B22)

    subtract(half, B21, B11, temp2);  // B21 - B11
    strassen(half, A22, temp2, M4, mul_count, add_count);  // P4 = A22 * (B21 - B11)

    add(half, A11, A12, temp1);  // A11 + A12
    strassen(half, temp1, B22, M5, mul_count, add_count);  // P5 = (A11 + A12) * B22

    subtract(half, A21, A11, temp1);  // A21 - A11
    add(half, B11, B12, temp2);  // B11 + B12
    strassen(half, temp1, temp2, M6, mul_count, add_count);  // P6 = (A21 - A11) * (B11 + B12)

    subtract(half, A12, A22, temp1);  // A12 - A22
    add(half, B21, B22, temp2);  // B21 + B22
    strassen(half, temp1, temp2, M7, mul_count, add_count);  // P7 = (A12 - A22) * (B21 + B22)

    // Calculate the final result using the values of P1 to P7
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            result[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            result[i][j + half] = M3[i][j] + M5[i][j];
            result[i + half][j] = M2[i][j] + M4[i][j];
            result[i + half][j + half] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

    // Count the number of additions and multiplications
    *add_count += 12 * (half * half);  // Each add and subtract operation on n/2 matrices takes n/2*n/2 additions
    *mul_count += 7;  // We have exactly 7 multiplications (M1 to M7)
}

int main() {
    int n = 4; // Example matrix size (power of 2)
    int A[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int B[4][4] = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };
    int result[4][4];
    int mul_count = 0, add_count = 0;

    strassen(n, A, B, result, &mul_count, &add_count);

    printf("Resultant Matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("Number of multiplications: %d\n", mul_count);
    printf("Number of additions: %d\n", add_count);

    return 0;
}

#include <stdio.h>
#include <math.h>

// Function to evaluate polynomial using brute-force method
int evaluatePolynomialBruteForce(int coeffs[], int degree, int x, int *multiplications) {
    int result = 0;
    *multiplications = 0; // Initialize multiplication counter

    for (int i = 0; i <= degree; i++) {
        int term = coeffs[i];
        for (int j = 0; j < degree - i; j++) { // Multiply x for (degree - i) times
            term *= x;
            (*multiplications)++;
        }
        result += term;
    }

    return result;
}

// Function to evaluate polynomial using Horner's rule
int evaluatePolynomialHorner(int coeffs[], int degree, int x, int *multiplications) {
    int result = coeffs[0];
    *multiplications = 0; // Initialize multiplication counter

    for (int i = 1; i <= degree; i++) {
        result = result * x + coeffs[i];
        (*multiplications)++; // Increment multiplication count
    }

    return result;
}

int main() {
    // Coefficients of the polynomial P(x) = 6x^6 + 5x^5 + 4x^4 - 3x^3 + 2x^2 + 8x - 7
    int coeffs[] = {6, 5, 4, -3, 2, 8, -7};
    int degree = 6; // Degree of the polynomial
    int x = 3;      // Value of x to evaluate the polynomial
    int multiplicationsBruteForce, multiplicationsHorner;

    // Evaluate polynomial using brute-force method
    int resultBruteForce = evaluatePolynomialBruteForce(coeffs, degree, x, &multiplicationsBruteForce);
    printf("Brute-force method: P(%d) = %d\n", x, resultBruteForce);
    printf("Multiplications (Brute-force): %d\n", multiplicationsBruteForce);

    // Evaluate polynomial using Horner's method
    int resultHorner = evaluatePolynomialHorner(coeffs, degree, x, &multiplicationsHorner);
    printf("Horner's method: P(%d) = %d\n", x, resultHorner);
    printf("Multiplications (Horner's): %d\n", multiplicationsHorner);

    return 0;
}

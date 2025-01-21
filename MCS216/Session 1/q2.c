#include <stdio.h>

// Function to evaluate the polynomial using Horner's rule
int evaluatePolynomial(int coeffs[], int degree, int x) {
    int result = coeffs[0]; // Initialize the result to the highest-degree term
    for (int i = 1; i <= degree; i++) {
        result = result * x + coeffs[i]; // Horner's rule: Multiply and add
    }
    return result;
}

int main() {
    // Coefficients of the polynomial in decreasing order of powers
    // P(x) = 6x^6 + 5x^5 + 4x^4 - 3x^3 + 2x^2 + 8x - 7
    int coeffs[] = {6, 5, 4, -3, 2, 8, -7};
    int degree = 6; // Degree of the polynomial
    int x = 3;      // Value of x to evaluate the polynomial

    // Evaluate the polynomial
    int result = evaluatePolynomial(coeffs, degree, x);
    printf("The value of P(%d) is: %d\n", x, result);

    // Number of multiplications and additions
    printf("Number of multiplications: %d\n", degree);
    printf("Number of additions: %d\n", degree);
    printf("Number of iterations: %d\n", degree);

    return 0;
}

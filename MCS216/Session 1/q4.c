#include <stdio.h>

// Function for Left-to-Right Binary Exponentiation
long long int leftToRightBinaryExp(long long int base, long long int exp) {
    long long int result = 1;

    // We need to process the exponent bit by bit from left to right
    // The highest bit is 1 << (sizeof(exp) * 8 - 1), but we'll only check the actual bits of exp
    for (long long int i = exp; i > 0; i >>= 1) {
        result *= result;  // Square the result
        if (i & 1) {  // If the current bit of the exponent is 1
            result *= base; // Multiply by base
        }
    }

    return result;
}

// Function for Right-to-Left Binary Exponentiation
long long int rightToLeftBinaryExp(long long int base, long long int exp) {
    long long int result = 1;

    while (exp > 0) {
        if (exp % 2 == 1) {  // If current bit (least significant bit) is 1
            result *= base;  // Multiply the result by base
        }
        base *= base;  // Square the base for the next bit
        exp /= 2;  // Right shift the exponent (divide by 2)
    }

    return result;
}

int main() {
    long long int base1 = 4, exp1 = 512;
    long long int base2 = 3, exp2 = 31;

    // Problem (i): 4^512
    printf("Left-to-Right Binary Exponentiation for 4^512: %lld\n", leftToRightBinaryExp(base1, exp1));
    printf("Right-to-Left Binary Exponentiation for 4^512: %lld\n", rightToLeftBinaryExp(base1, exp1));

    // Problem (ii): 3^31
    printf("Left-to-Right Binary Exponentiation for 3^31: %lld\n", leftToRightBinaryExp(base2, exp2));
    printf("Right-to-Left Binary Exponentiation for 3^31: %lld\n", rightToLeftBinaryExp(base2, exp2));

    return 0;
}

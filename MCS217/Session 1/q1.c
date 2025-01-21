#include <stdio.h>

int gcd(int a, int b) {
    int modCount = 0, assignCount = 0;

    while (b != 0) {
        modCount++;
        int temp = b;
        b = a % b;
        assignCount++;
        a = temp;
        assignCount++;
    }

    printf("Mod operations: %d\n", modCount);
    printf("Assignment operations: %d\n", assignCount);

    return a;
}

int main() {
    int num1 = 15265, num2 = 15;

    printf("GCD of %d and %d is: %d\n", num1, num2, gcd(num1, num2));

    return 0;
}

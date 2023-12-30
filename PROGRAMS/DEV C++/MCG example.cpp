#include <stdio.h>

int mcg(int seed, int n) {
    int a = 17;  // Multiplier
    int c = 47;   // Increment
    int m = 100; // Modulus

    int result[100];
    int x = seed;

    for (int i = 0; i < n; i++) {
        x = (a * x + c) % m;
        result[i] = x;
    }

    return *result;
}

int main() {
    int seed;
    printf("Enter the seed value: ");
    scanf("%d", &seed);

    int result = mcg(seed, 100);

    printf("MCG sequence:\n");
    for (int i = 0; i < 100; i++) {
        printf("Value %d: %d\n", i, result + i);
    }

    return 0;
}


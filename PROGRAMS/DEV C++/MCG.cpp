#include <stdio.h>
#include <stdbool.h>

bool isMapped[100] = { false }; // To keep track of mapped numbers

void mcg(int seed, int* sequence, int* length) {
    int a = 17;  // Multiplier
    int c = 43;   // Increment
    int m = 100; // Modulus

    int x = seed;
    int count = 0;

    while (!isMapped[x]) {
        sequence[count] = x;
        isMapped[x] = true;
        x = (a * x + c) % m;
        count++;
    }

    *length = count;
}

int main() {
    int seed;
    printf("Enter the seed value: ");
    scanf("%d", &seed);

    int sequence[100];
    int length;

    mcg(seed, sequence, &length);

    printf("Maximal Length Sequence:\n");
    for (int i = 0; i < length; i++) {
        printf("Value %d: %d\n", i, sequence[i]);
    }

    printf("\nNon-interleaving Sequences:\n");
    for (int i = 0; i < 100; i++) {
        if (!isMapped[i]) {
            mcg(i, sequence, &length);
            printf("Seed %d:\n", i);
            for (int j = 0; j < length; j++) {
                printf("Value %d: %d\n", j, sequence[j]);
            }
            printf("\n");
        }
    }

    return 0;
}


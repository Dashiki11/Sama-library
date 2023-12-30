#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void mcg(int seed, int* sequence, int* length);

int main() {
	system("Programs\sequence generator.c");
    int sequence[100];
    int lengths[100];
    bool isMapped[100] = { false };

    for (int i = 0; i < 100; i++) {
        sequence[i] = -1;  // Initialize the sequence array with -1
    }

    printf("Enter the seed value: ");
    int seed;
    scanf("%d", &seed);

    int count = 0;  // Count of mapped sequences

    for (int i = 0; i < 100; i++) {
        if (sequence[i] == -1) {
            mcg(i, sequence, &lengths[i]);

            // Map the sequence to numbers
            for (int j = 0; j < lengths[i]; j++) {
                isMapped[sequence[j]] = true;
            }

            count++;
        }
    }

    printf("Maximal Length Sequence:\n");
    for (int i = 0; i < lengths[seed]; i++) {
        printf("Value %d: %d\n", i, sequence[i]);
    }

    printf("\nNon-interleaving Sequences:\n");
    for (int i = 0; i < 100; i++) {
        if (!isMapped[i]) {
            printf("Seed %d:\n", i);
            for (int j = 0; j < lengths[i]; j++) {
                printf("Value %d: %d\n", j, sequence[j]);
            }
            printf("\n");
        }
    }

    return 0;
}


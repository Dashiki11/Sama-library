#include <stdio.h>

void findSequences(int seed, int modulus, int multiplier, int increment) {
    int sequence[modulus];
    int isVisited[modulus];

    // Initialize arrays
    for (int i = 0; i < modulus; i++) {
        sequence[i] = -1;   // -1 indicates unvisited
        isVisited[i] = 0;   // 0 indicates unvisited
    }

    int x = seed;
    int count = 0;
    int currentSequence = 1;

    // Generate sequences
    while (!isVisited[x]) {
        isVisited[x] = 1;
        sequence[count++] = x;
        x = (multiplier * x + increment) % modulus;

        if (isVisited[x]) {
            // Start a new sequence
            printf("Sequence %d: ", currentSequence);
            for (int i = 0; i < modulus; i++) {
                if (sequence[i] != -1)
                    printf("%d ", sequence[i]);
                else
                    break;
            }
            printf("\n");

            currentSequence++;
            count = 0;
            for (int i = 0; i < modulus; i++) {
                if (isVisited[i] == 0) {
                    x = i;
                    break;
                }
            }
        }
    }

    // Check if there are any remaining numbers for the last sequence
    if (count > 0) {
        printf("Sequence %d: ", currentSequence);
        for (int i = 0; i < count; i++) {
            printf("%d ", sequence[i]);
        }
        printf("\n");
    }
}

int main() {
	int seed;
    printf("Please enter the seed: ");
    scanf("%d", &seed);
    int modulus = 100;
    int multiplier = 17;
    int increment = 43;

    findSequences(seed, modulus, multiplier, increment);

    return 0;
}


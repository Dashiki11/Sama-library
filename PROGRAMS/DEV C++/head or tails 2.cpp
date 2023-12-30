#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    int i;
    double rand_num;

    // Initialize random number generator with current time
    srand(time(NULL));

    // Generate and print 10 random numbers
    for (i = 0; i < 30; i++) {
        rand_num = (double)rand() / RAND_MAX;
        std::cout << rand_num << std::endl;
    }

    return 0;
}


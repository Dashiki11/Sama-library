#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i;
    double random_number;
    char outcome;

    // Use the current time as seed for the random number generator
    srand(time(NULL));

    // Generate and print 10 random numbers
    //for (i = 0; i < 30; i++)
    for (i = 0; i < 10; i++) 
	{
        random_number = (double) rand() / RAND_MAX;
        if(random_number <= 0.5)
        {
        	outcome = 'H';
		}
		else
		{
			outcome = 'T';
		}
        printf("%f\t %c\n", random_number, outcome);
    }

    return 0;
}


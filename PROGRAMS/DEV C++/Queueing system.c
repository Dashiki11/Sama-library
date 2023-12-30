#include <stdio.h>
#include <math.h>


int main() {
	
    float lambda, mu, rho, Q, N, RT, a, b, c;
    printf("Enter service rate (mu): ");
    scanf("%f", &mu);
    printf("Enter the starting point of rho: ");
    scanf("%f", &a);
    printf("Enter the ending point of rho: ");
    scanf("%f", &b);
	printf("Enter the step value of rho: ");
    scanf("%f", &c);
    
    printf("Start value of Rho= %.3f\n", a);
    printf("End value of Rho= %.3f\n", b);
    printf("Step value of Rho= %.3f\n", c);
    printf("Service Rate, Mu= %.3f\n", mu);
    
    printf("Rho\tN\tQ\tRT\n");
        
    for(rho = a; rho <= b; rho = rho + c)
    {
     lambda = rho * mu; // Traffic intensity(utilization factor)
     Q = pow(rho, 2) / (1 - rho); // Average number of customers in queue
     N = rho/(1-rho); //average number of customers in the system
     RT = N/lambda; //response time = 1/(mu - lambda)

    
     printf("%.3f\t%.3f\t%.3f\t%.3f\n", rho, N, Q, RT);
   }

    return 0;
}


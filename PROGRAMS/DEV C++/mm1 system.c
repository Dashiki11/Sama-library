#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRIVAL_EVENT 1
#define DEPARTURE_EVENT 2

// Structure to represent an event
typedef struct {
    double time;
    int type;
} Event;

// Function to generate an exponential random variable
double exponentialRandom(double mean) {
    double u;
    u = rand() / (RAND_MAX + 1.0);
    return -mean * log(1 - u);
}

int main() {
    double lambda, mu; // Arrival rate and service rate
    double simulationDuration;
    double currentTime = 0.0;
    double totalWaitingTime = 0.0;
    int numCustomers = 0;

    // Prompt for input parameters
    printf("Enter arrival rate (lambda): ");
    scanf("%lf", &lambda);
    printf("Enter service rate (mu): ");
    scanf("%lf", &mu);
    printf("Enter simulation duration: ");
    scanf("%lf", &simulationDuration);

    // Initialize the priority queue for events
    Event* eventQueue = (Event*)malloc(sizeof(Event));
    int queueSize = 1;
    int queueCapacity = 1;

    // Generate the first arrival event
    Event arrivalEvent;
    arrivalEvent.time = exponentialRandom(1 / lambda);
    arrivalEvent.type = ARRIVAL_EVENT;
    eventQueue[0] = arrivalEvent;

    // Initialize the departure event as infinity
    Event departureEvent;
    departureEvent.time = INFINITY;
    departureEvent.type = DEPARTURE_EVENT;

    // Main event loop
    while (currentTime < simulationDuration) {
        // Get the next event from the priority queue
        Event currentEvent = eventQueue[0];
        for (int i = 1; i < queueSize; i++) {
            eventQueue[i - 1] = eventQueue[i];
        }
        queueSize--;

        // Update the simulation time
        currentTime = currentEvent.time;

        if (currentEvent.type == ARRIVAL_EVENT) {
            // Process arrival event
            // Generate next arrival event
            Event nextArrival;
            nextArrival.time = currentTime + exponentialRandom(1 / lambda);
            nextArrival.type = ARRIVAL_EVENT;
            // Add next arrival event to the priority queue
            if (queueSize == queueCapacity) {
                queueCapacity *= 2;
                eventQueue = (Event*)realloc(eventQueue, queueCapacity * sizeof(Event));
            }
            eventQueue[queueSize] = nextArrival;
            queueSize++;

            if (departureEvent.time == INFINITY) {
                // Server is idle, generate departure event
                departureEvent.time = currentTime + exponentialRandom(1 / mu);
                departureEvent.type = DEPARTURE_EVENT;
            }
            else {
                // Server is busy, customer goes into the queue
                numCustomers++;
            }
        }
        else if (currentEvent.type == DEPARTURE_EVENT) {
            // Process departure event
            if (numCustomers > 0) {
                // Serve the next customer in the queue
                numCustomers--;
                totalWaitingTime += currentTime;
                departureEvent.time = currentTime + exponentialRandom(1 / mu);
            }
            else {
                // No customer in the queue, server becomes idle
                departureEvent.time = INFINITY;
            }
        }
    }

    // Calculate average waiting time
    double averageWaitingTime = totalWaitingTime / (numCustomers + 1);

    // Output statistics
    printf("Simulation completed.\n");
    printf("Number of customers: %d\n", numCustomers);
    printf("Average waiting time: %.2f\n", averageWaitingTime);

    // Clean up memory
    free(eventQueue);

    return 0;
}


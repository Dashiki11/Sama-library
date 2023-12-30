#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

struct Process {
    int burst_time;
    int arrival_time;
    int priority;
    int waiting_time;
    string process_id;

    Process() : burst_time(0), arrival_time(0), priority(0), waiting_time(0), process_id("") {}
};

vector<Process> readInputFromFile(const string& filename) {
    vector<Process> processes;
    ifstream inputFile("input.txt");

    if (!inputFile) {
        cerr << "Error: Unable to open the input file.\n";
        return processes;
    }

    string line;
    int processCount = 1;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string burst, arrival, priority;
        getline(ss, burst, ':');
        getline(ss, arrival, ':');
        getline(ss, priority, ':');

        Process p;
        p.burst_time = stoi(burst);
        p.arrival_time = stoi(arrival);
        p.priority = stoi(priority);
        p.waiting_time = 0;
        p.process_id = "P" + to_string(processCount++);
        processes.push_back(p);
    }

    inputFile.close();
    return processes;
}

void displayResults(const vector<Process>& processes, const string& method) {
    cout << "Scheduling Method: " << method << endl;
    cout << "Process Waiting Times:" << endl;
    for (const Process& p : processes) {
        cout << p.process_id << ": " << p.waiting_time << " ms" << endl;
    }

    int totalWaitingTime = 0;
    for (const Process& p : processes) {
        totalWaitingTime += p.waiting_time;
    }

    double averageWaitingTime = static_cast<double>(totalWaitingTime) / processes.size();
    cout << "Average Waiting Time: " << fixed << setprecision(1) << averageWaitingTime << " ms" << endl;
}

void firstComeFirstServed(vector<Process>& processes) {
    int currentTime = 0;
    for (Process& p : processes) {
        if (p.arrival_time > currentTime) {
            currentTime = p.arrival_time;
        }
        p.waiting_time = currentTime - p.arrival_time;
        currentTime += p.burst_time;
    }
}

void shortestJobFirstPreemptive(vector<Process>& processes) {
    int n = processes.size();
    vector<int> remainingTime(n);

    for (int i = 0; i < n; ++i) {
        remainingTime[i] = processes[i].burst_time;
    }

    int currentTime = 0, completed = 0;
    while (completed != n) {
        int shortest = INT_MAX, shortestIndex = -1;
        for (int i = 0; i < n; ++i) {
            if (processes[i].arrival_time <= currentTime && remainingTime[i] < shortest && remainingTime[i] > 0) {
                shortest = remainingTime[i];
                shortestIndex = i;
            }
        }

        if (shortestIndex == -1) {
            currentTime++;
            continue;
        }

        remainingTime[shortestIndex]--;

        if (remainingTime[shortestIndex] == 0) {
            completed++;
            int finishTime = currentTime + 1;
            processes[shortestIndex].waiting_time = finishTime - processes[shortestIndex].burst_time - processes[shortestIndex].arrival_time;
        }
        currentTime++;
    }
}

void shortestJobFirstNonPreemptive(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.burst_time < b.burst_time;
    });

    int currentTime = 0;
    for (Process& p : processes) {
        if (p.arrival_time > currentTime) {
            currentTime = p.arrival_time;
        }
        p.waiting_time = currentTime - p.arrival_time;
        currentTime += p.burst_time;
    }
}

void priorityScheduling(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.priority < b.priority;
    });

    int currentTime = 0;
    for (Process& p : processes) {
        if (p.arrival_time > currentTime) {
            currentTime = p.arrival_time;
        }
        p.waiting_time = currentTime - p.arrival_time;
        currentTime += p.burst_time;
    }
}

void prioritySchedulingPreemptive(vector<Process>& processes) {
    int n = processes.size();
    vector<int> remainingTime(n);

    for (int i = 0; i < n; ++i) {
        remainingTime[i] = processes[i].burst_time;
    }

    int currentTime = 0, completed = 0;
    while (completed != n) {
        int highestPriority = INT_MAX, highestPriorityIndex = -1;
        for (int i = 0; i < n; ++i) {
            if (processes[i].arrival_time <= currentTime && processes[i].priority < highestPriority && remainingTime[i] > 0) {
                highestPriority = processes[i].priority;
                highestPriorityIndex = i;
            }
        }

        if (highestPriorityIndex == -1) {
            currentTime++;
            continue;
        }

        remainingTime[highestPriorityIndex]--;

        if (remainingTime[highestPriorityIndex] == 0) {
            completed++;
            int finishTime = currentTime + 1;
            processes[highestPriorityIndex].waiting_time = finishTime - processes[highestPriorityIndex].burst_time - processes[highestPriorityIndex].arrival_time;
        }
        currentTime++;
    }
}

void roundRobinScheduling(vector<Process>& processes, int timeQuantum) {
    int n = processes.size();
    vector<int> remainingTime(n);

    for (int i = 0; i < n; ++i) {
        remainingTime[i] = processes[i].burst_time;
    }

    int currentTime = 0;
    while (true) {
        bool done = true;
        for (int i = 0; i < n; ++i) {
            if (remainingTime[i] > 0) {
                done = false;
                if (remainingTime[i] > timeQuantum) {
                    currentTime += timeQuantum;
                    remainingTime[i] -= timeQuantum;
                } else {
                    currentTime += remainingTime[i];
                    processes[i].waiting_time = currentTime - processes[i].burst_time - processes[i].arrival_time;
                    remainingTime[i] = 0;
                }
            }
        }
        if (done) {
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    string inputFilename = "input.txt"; 
	string outputFilename = "output.txt";
    vector<Process> processes;

    // Parse command-line arguments for input and output filenames
    if (argc < 5) {
        cerr << "Usage: " << argv[0] << " -f input.txt -o output.txt\n";
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        if (string(argv[i]) == "-f" && i + 1 < argc) {
            inputFilename = argv[i + 1];
        } else if (string(argv[i]) == "-o" && i + 1 < argc) {
            outputFilename = argv[i + 1];
        }
    }

    // Read input from the specified file
    processes = readInputFromFile(inputFilename);

    if (processes.empty()) {
        cerr << "No valid input data. Exiting...\n";
        return 1;
    }

    while (true) {
        cout << "CPU Scheduler Simulator" << endl;
        cout << "1) Scheduling Method (None)" << endl;
        cout << "2) Preemptive Mode (Off)" << endl;
        cout << "3) Show Result" << endl;
        cout << "4) End Program" << endl;
        cout << "Option > ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                // Implement scheduling methods selection logic
                // Invoke corresponding scheduling algorithm functions
                
                break;
            }
            case 2: {
                // Implement preemptive mode logic
                break;
            }
            case 3: {
                // Display results to the console
                // Write results to the output file
                displayResults(processes, "Chosen Method");
                ofstream outputFile(outputfilename);
                if (outputFile.is_open()) {
                    outputFile << "Results will go here...\n"; // Write the results to the file
                    outputFile.close();
                } else {
                    cerr << "Error: Unable to open the output file.\n";
                }
                break;
            }
            case 4: {
                // Display all implemented scheduling results on the console
                // Write these results to the output file and terminate the simulator
                // Implement logic to write all scheduling results to the output file
                // Display the results on the console
                break;
            }
            default: {
                cout << "Invalid choice. Please select a valid option.\n";
                break;
            }
        }

        // Add condition to exit the loop and end the program
        // based on the user's choice
    }

    return 0;
}


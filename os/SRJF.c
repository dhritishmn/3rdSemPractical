#include <stdio.h>

struct Process {
    int processID;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

// Function to find the waiting time and turnaround time using SRJF
void calculateTimes(struct Process processes[], int n) {
    int currentTime = 0;
    int remainingTime[n];
    int completedProcesses = 0;

    // Initialize remainingTime array with burst times
    for (int i = 0; i < n; i++) {
        remainingTime[i] = processes[i].burstTime;
    }

    while (completedProcesses < n) {
        int minIndex = -1;
        int minBurst = __INT_MAX__;

        // Find the process with the shortest remaining time
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && remainingTime[i] < minBurst && remainingTime[i] > 0) {
                minIndex = i;
                minBurst = remainingTime[i];
            }
        }

        if (minIndex == -1) {
            currentTime++;
        } else {
            // Update waiting time and turnaround time
            processes[minIndex].waitingTime = currentTime - processes[minIndex].arrivalTime;
            processes[minIndex].turnaroundTime = processes[minIndex].waitingTime + processes[minIndex].burstTime;

            // Reduce remaining time for the chosen process
            remainingTime[minIndex]--;
            currentTime++;

            // Check if the process is completed
            if (remainingTime[minIndex] == 0) {
                completedProcesses++;
            }
        }
    }
}

// Function to display the waiting time and turnaround time
void displayTimes(struct Process processes[], int n) {
    printf("Process\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", processes[i].processID, processes[i].waitingTime, processes[i].turnaroundTime);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].processID = i + 1;
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
    }

    // Calculate waiting time and turnaround time using SRJF
    calculateTimes(processes, n);

    // Display the waiting time and turnaround time
    displayTimes(processes, n);

    return 0;
}

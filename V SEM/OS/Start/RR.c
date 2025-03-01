#include <stdio.h>

void roundRobin(int processes[], int n, int burstTimes[], int quantum) {
    int remainingTimes[n]; // Array to store remaining burst times
    int totalTime = 0;     // Total time to execute all processes
    int i;

    // Initialize remaining burst times
    for (i = 0; i < n; i++) {
        remainingTimes[i] = burstTimes[i];
    }

    printf("\nOrder of process execution:\n");

    while (1) {
        int done = 1; // Flag to check if all processes are done

        for (i = 0; i < n; i++) {
            if (remainingTimes[i] > 0) {
                done = 0; // There is a process still not finished

                if (remainingTimes[i] > quantum) {
                    // Process execution
                    printf("P%d\t", processes[i]);
                    totalTime += quantum;
                    remainingTimes[i] -= quantum;
                } else {
                    // Last execution of the process
                    printf("P%d\t", processes[i]);
                    totalTime += remainingTimes[i];
                    remainingTimes[i] = 0;
                }
            }
        }

        // If all processes are done, exit the loop
        if (done == 1) {
            break;
        }
    }

    // Calculate and display average times
    int waitingTime[n], turnaroundTime[n];
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    for (i = 0; i < n; i++) {
        turnaroundTime[i] = totalTime - burstTimes[i];
        waitingTime[i] = turnaroundTime[i] - burstTimes[i];

        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    printf("\n\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", processes[i], burstTimes[i], waitingTime[i], turnaroundTime[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int burstTimes[n];

    printf("Enter the burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1; // Assign process IDs as 1, 2, 3, ...
        printf("P%d: ", i + 1);
        scanf("%d", &burstTimes[i]);
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    roundRobin(processes, n, burstTimes, quantum);

    return 0;
}

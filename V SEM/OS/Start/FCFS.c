#include <stdio.h>

void calculate_times(int process_ids[], int arrival_times[], int burst_times[], int completion_times[], int turnaround_times[], int waiting_times[], int n) {
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < arrival_times[i]) {
            current_time = arrival_times[i];
        }

        completion_times[i] = current_time + burst_times[i];
        turnaround_times[i] = completion_times[i] - arrival_times[i];
        waiting_times[i] = turnaround_times[i] - burst_times[i];

        current_time = completion_times[i];
    }
}

void print_table(int process_ids[], int arrival_times[], int burst_times[], int completion_times[], int turnaround_times[], int waiting_times[], int n) {
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    printf("----------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               process_ids[i],
               arrival_times[i],
               burst_times[i],
               completion_times[i],
               turnaround_times[i],
               waiting_times[i]);
    }

    printf("----------------------------------------------------------------------\n");
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int process_ids[n], arrival_times[n], burst_times[n], completion_times[n], turnaround_times[n], waiting_times[n];

    for (int i = 0; i < n; i++) {
        process_ids[i] = i + 1;
        printf("Enter arrival time and burst time for process P%d: ", process_ids[i]);
        scanf("%d %d", &arrival_times[i], &burst_times[i]);
    }

    // Sort processes by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrival_times[j] > arrival_times[j + 1]) {
                int temp;

                // Swap process IDs
                temp = process_ids[j];
                process_ids[j] = process_ids[j + 1];
                process_ids[j + 1] = temp;

                // Swap arrival times
                temp = arrival_times[j];
                arrival_times[j] = arrival_times[j + 1];
                arrival_times[j + 1] = temp;

                // Swap burst times
                temp = burst_times[j];
                burst_times[j] = burst_times[j + 1];
                burst_times[j + 1] = temp;
            }
        }
    }

    calculate_times(process_ids, arrival_times, burst_times, completion_times, turnaround_times, waiting_times, n);
    print_table(process_ids, arrival_times, burst_times, completion_times, turnaround_times, waiting_times, n);

    return 0;
}

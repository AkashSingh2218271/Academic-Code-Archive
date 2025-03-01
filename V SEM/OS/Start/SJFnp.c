#include <stdio.h>

void calculate_times(int n, int ids[], int arrival_times[], int burst_times[], int completion_times[], int turnaround_times[], int waiting_times[], int is_completed[]) {
    int current_time = 0, completed = 0;

    while (completed < n) {
        int shortest_job = -1;
        int min_burst_time = 1e9;

        for (int i = 0; i < n; i++) {
            if (!is_completed[i] && arrival_times[i] <= current_time && burst_times[i] < min_burst_time) {
                min_burst_time = burst_times[i];
                shortest_job = i;
            }
        }

        if (shortest_job == -1) {
            current_time++;
            continue;
        }

        current_time += burst_times[shortest_job];
        completion_times[shortest_job] = current_time;
        turnaround_times[shortest_job] = completion_times[shortest_job] - arrival_times[shortest_job];
        waiting_times[shortest_job] = turnaround_times[shortest_job] - burst_times[shortest_job];
        is_completed[shortest_job] = 1;
        completed++;
    }
}

void print_table(int n, int ids[], int arrival_times[], int burst_times[], int completion_times[], int turnaround_times[], int waiting_times[]) {
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    printf("----------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               ids[i],
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

    int ids[n], arrival_times[n], burst_times[n], completion_times[n], turnaround_times[n], waiting_times[n], is_completed[n];

    for (int i = 0; i < n; i++) {
        ids[i] = i + 1;
        is_completed[i] = 0;
        printf("Enter arrival time and burst time for process P%d: ", ids[i]);
        scanf("%d %d", &arrival_times[i], &burst_times[i]);
    }

    calculate_times(n, ids, arrival_times, burst_times, completion_times, turnaround_times, waiting_times, is_completed);
    print_table(n, ids, arrival_times, burst_times, completion_times, turnaround_times, waiting_times);

    return 0;
}

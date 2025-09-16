#include <stdio.h>

int main() {
    int n, i, j;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int arrival_time[n], burst_time[n], temp_burst[n], waiting_time[n], turnaround_time[n];
    int completed[n];
    int current_time = 0, completed_count = 0;

    for (i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        temp_burst[i] = burst_time[i];
        completed[i] = 0; // not completed yet
    }

    while (completed_count < n) {
        int idx = -1;
        int min_burst = 100000;

        for (i = 0; i < n; i++) {
            if (arrival_time[i] <= current_time && completed[i] == 0) {
                if (burst_time[i] < min_burst) {
                    min_burst = burst_time[i];
                    idx = i;
                }
                // if burst times are equal, choose process with earlier arrival time
                else if (burst_time[i] == min_burst) {
                    if (arrival_time[i] < arrival_time[idx]) {
                        idx = i;
                    }
                }
            }
        }
        
        if (idx != -1) {
            waiting_time[idx] = current_time - arrival_time[idx];
            if (waiting_time[idx] < 0) 
                waiting_time[idx] = 0;
            current_time += burst_time[idx];
            turnaround_time[idx] = current_time - arrival_time[idx];
            completed[idx] = 1;
            completed_count++;
        } else {
            current_time++;
        }
    }

    float total_wt = 0, total_tat = 0;

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], temp_burst[i], waiting_time[i],
        turnaround_time[i]);
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
    }

    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
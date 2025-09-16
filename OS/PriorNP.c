#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int arrival[n], burst[n], priority[n];
    int waiting[n], turnaround[n], done[n];
    int current = 0, completed = 0;

    // Input process details
    for (i = 0; i < n; i++) {
        printf("Process %d arrival time: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &burst[i]);
        printf("Process %d priority (lower = higher): ", i + 1);
        scanf("%d", &priority[i]);
        done[i] = 0;
    }

    // Priority scheduling
    while (completed < n) {
        int next = -1;

        for (i = 0; i < n; i++) {
            if (arrival[i] <= current && !done[i]) {
                if (next == -1 || priority[i] < priority[next] || 
                    (priority[i] == priority[next] && arrival[i] < arrival[next])) {
                    next = i;
                }
            }
        }

        if (next != -1) {
            waiting[next] = (current - arrival[next] > 0) ? current - arrival[next] : 0;
            current += burst[next];
            turnaround[next] = current - arrival[next];
            done[next] = 1;
            completed++;
        } else {
            current++; // CPU idle
        }
    }

    // Print results
    float total_wt = 0, total_tat = 0;
    printf("\nP#\tArrival\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", i + 1, arrival[i], burst[i], priority[i],
               waiting[i], turnaround[i]);
        total_wt += waiting[i];
        total_tat += turnaround[i];
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}






































#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int arrival_time[n], burst_time[n], priority[n];
    int waiting_time[n], turnaround_time[n];
    int completed[n];
    int current_time = 0, completed_count = 0;

    // Input process details
    for (i = 0; i < n; i++) {
        printf("Process %d arrival time: ", i + 1);
        scanf("%d", &arrival_time[i]);

        printf("Process %d burst time: ", i + 1);
        scanf("%d", &burst_time[i]);

        printf("Process %d priority (lower value = higher priority): ", i + 1);
        scanf("%d", &priority[i]);

        completed[i] = 0; // not completed
    }

    // Priority Scheduling
    while (completed_count < n) {
        int idx = -1;
        int highest_priority = 1e9;

        // Find next process to execute
        for (i = 0; i < n; i++) {
            if (arrival_time[i] <= current_time && !completed[i]) {
                if (priority[i] < highest_priority) {
                    highest_priority = priority[i];
                    idx = i;
                } else if (priority[i] == highest_priority) {
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
            current_time++; // CPU idle
        }
    }

    // Display results
    float total_wt = 0, total_tat = 0;
    printf("\nP#\tArrival\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", i + 1, arrival_time[i], burst_time[i], priority[i],
               waiting_time[i], turnaround_time[i]);
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}









































#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], wt[n], tat[n], done[n];
    int current = 0, completed = 0;

    for (i = 0; i < n; i++) {
        printf("Arrival and Burst for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        done[i] = 0;
    }

    while (completed < n) {
        int next = -1;
        for (i = 0; i < n; i++)
            if (at[i] <= current && !done[i] && (next == -1 || bt[i] < bt[next] || (bt[i]==bt[next] && at[i]<at[next])))
                next = i;

        if (next != -1) {
            wt[next] = (current - at[next] > 0) ? current - at[next] : 0;
            current += bt[next];
            tat[next] = current - at[next];
            done[next] = 1;
            completed++;
        } else current++;
    }

    float total_wt = 0, total_tat = 0;
    printf("\nP\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAvg WT = %.2f\nAvg TAT = %.2f\n", total_wt/n, total_tat/n);
    return 0;
}










































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
if (waiting_time[idx] < 0) waiting_time[idx] = 0;
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
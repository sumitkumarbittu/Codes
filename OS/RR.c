#include <stdio.h>

int main() {
    int n, i, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int arrival[n], burst[n], priority[n];
    int wt[n], tat[n], rem_bt[n], ct[n], complete[n];

    // Input process details
    for (i = 0; i < n; i++) {
        printf("Process %d arrival time: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &burst[i]);
        printf("Process %d priority (lower = higher): ", i + 1);
        scanf("%d", &priority[i]);
        rem_bt[i] = burst[i];  // initialize remaining burst time
        wt[i] = 0;
        complete[i] = 0;       // 0 = not completed
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    int t = 0, done_count = 0;

    // Round Robin calculation using complete[]
    while (done_count < n) { // loop until all processes complete
        int executed = 0;
        for (i = 0; i < n; i++) {
            if (arrival[i] <= t && complete[i] == 0) {
                executed = 1;
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - burst[i] - arrival[i];
                    rem_bt[i] = 0;
                    complete[i] = 1;  // mark as completed
                    ct[i] = t;        // store completion time
                    done_count++;     // increment count of completed processes
                }
            }
        }
        if (!executed) {
            t++; // increment time if no process was executed (CPU idle)
        }
    }

    // Turnaround time calculation
    for (i = 0; i < n; i++) {
        tat[i] = burst[i] + wt[i];
    }

    // Display results
    int total_wt = 0, total_tat = 0;
    printf("\nP#\tArrival\tBurst\tPriority\tWaiting\tTurnaround\tCompletion\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\t\t%d\n",
               i + 1, arrival[i], burst[i], priority[i], wt[i], tat[i], ct[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time = %.2f\n", (float)total_tat / n);

    return 0;
}

// 5 0 5 1 3 2 8 3 6 4 4 2






































#include <stdio.h>

int main() {
    int n, i, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int arrival[n], burst[n];
    int waiting[n], turnaround[n], rem_bt[n], done[n];
    int current = 0, completed = 0;

    // Input process details
    for (i = 0; i < n; i++) {
        printf("Process %d arrival time: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &burst[i]);
        rem_bt[i] = burst[i]; // initialize remaining burst time
        done[i] = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    // Round Robin scheduling
    while (completed < n) {
        int executed = 0;

        for (i = 0; i < n; i++) {
            if (arrival[i] <= current && rem_bt[i] > 0) {
                executed = 1;
                if (rem_bt[i] > quantum) {
                    current += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    current += rem_bt[i];
                    waiting[i] = current - burst[i] - arrival[i];
                    rem_bt[i] = 0;
                    done[i] = 1;
                    completed++;
                }
            }
        }

        if (!executed)
            current++; // CPU idle
    }

    // Turnaround time calculation
    for (i = 0; i < n; i++) {
        turnaround[i] = burst[i] + waiting[i];
    }

    // Print results
    float total_wt = 0, total_tat = 0;
    printf("\nP#\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, arrival[i], burst[i],
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
    int n, i, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int arrival[n], burst[n], priority[n];
    int wt[n], tat[n], rem_bt[n];

    // Input process details
    for (i = 0; i < n; i++) {
        printf("Process %d arrival time: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &burst[i]);
        printf("Process %d priority (lower = higher): ", i + 1);
        scanf("%d", &priority[i]);
        rem_bt[i] = burst[i]; // initialize remaining burst time
        wt[i] = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    int t = 0, done;
    // Round Robin calculation
    while (1) {
        done = 1;
        for (i = 0; i < n; i++) {
            if (arrival[i] <= t && rem_bt[i] > 0) {
                done = 0;
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - burst[i] - arrival[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done) break;
        t++;
    }

    // Turnaround time calculation
    for (i = 0; i < n; i++) {
        tat[i] = burst[i] + wt[i];
    }

    // Display results
    int total_wt = 0, total_tat = 0;
    printf("\nP#\tArrival\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", i + 1, arrival[i], burst[i], priority[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time = %.2f\n", (float)total_tat / n);

    return 0;
}

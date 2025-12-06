#include <stdio.h>

int main() {
    int n, i, t = 0, done = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], wt[n], tat[n], fin[n];
    float awt = 0, atat = 0;

    for (i = 0; i < n; i++) {
        printf("AT & BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];   // remaining time
        fin[i] = 0;      // not finished yet
    }

    while (done < n) {
        int idx = -1;

        for (i = 0; i < n; i++) {
            if (!fin[i] && at[i] <= t && rt[i] > 0) {
                if (idx == -1 || rt[i] < rt[idx]) {
                    idx = i;
                }
            }
        }

        if (idx == -1) { t++; continue; }

        rt[idx]--; t++;

        if (rt[idx] == 0) {
            fin[idx] = 1; done++;
            tat[idx] = t - at[idx];
            wt[idx]  = tat[idx] - bt[idx];
            awt += wt[idx]; atat += tat[idx];
        }
    }

    printf("\nP\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);

    printf("\nAvg WT = %.2f\nAvg TAT = %.2f\n", awt/n, atat/n);
    return 0;
}

// 5 0 7 2 4 4 1 5 4 6 2



































/*

#include <stdio.h>

int main() {
    int n, i, t = 0, done = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], wt[n], tat[n], fin[n];
    float awt = 0, atat = 0;

    for (i = 0; i < n; i++) {
        printf("AT & BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];   // remaining time
        fin[i] = 0;      // not finished yet
    }

    while (done < n) {
        int idx = -1, min = 1e9;

        for (i = 0; i < n; i++) {
            if (!fin[i] && at[i] <= t && rt[i] < min && rt[i] > 0) {
                min = rt[i];
                idx = i;
            }
        }

        if (idx == -1) { t++; continue; }

        rt[idx]--; t++;

        if (rt[idx] == 0) {
            fin[idx] = 1; done++;
            tat[idx] = t - at[idx];
            wt[idx]  = tat[idx] - bt[idx];
            awt += wt[idx]; atat += tat[idx];
        }
    }

    printf("\nP\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);

    printf("\nAvg WT = %.2f\nAvg TAT = %.2f\n", awt/n, atat/n);
    return 0;
}

*/

























/*

#include <stdio.h>

int main() {
    int n, i, completed = 0, current_time = 0, min_index;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int arrival_time[n], burst_time[n], remaining_time[n], waiting_time[n], turnaround_time[n];
    int is_completed[n];

    for (i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i];
        is_completed[i] = 0;
        waiting_time[i] = 0;
    }

    while (completed != n) {
        min_index = -1;
        int min_remaining = 100000;

        for (i = 0; i < n; i++) {
            if (arrival_time[i] <= current_time && !is_completed[i] && remaining_time[i] < min_remaining && remaining_time[i] > 0) {
                min_remaining = remaining_time[i];
                min_index = i;
            }
        }

        if (min_index == -1) {
            current_time++;
            continue;
        }

        remaining_time[min_index]--;
        current_time++;

        if (remaining_time[min_index] == 0) {
            is_completed[min_index] = 1;
            completed++;

            turnaround_time[min_index] = current_time - arrival_time[min_index];
            waiting_time[min_index] = turnaround_time[min_index] - burst_time[min_index];

            if (waiting_time[min_index] < 0) 
                waiting_time[min_index] = 0;
        }
    }

    float total_wt = 0, total_tat = 0;
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
    }

    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}

*/
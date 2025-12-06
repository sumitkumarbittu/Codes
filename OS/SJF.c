#include <stdio.h>

int main() {
    int n, i, currentTime = 0, finished = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int arrivalTime[n], burstTime[n], completionTime[n];
    int turnaroundTime[n], waitingTime[n], isDone[n];
    float totalTAT = 0, totalWT = 0;

    // Input
    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time & Burst Time for P%d: ", i + 1);
        scanf("%d %d", &arrivalTime[i], &burstTime[i]);
        isDone[i] = 0;  // mark as not finished
    }

    // SJF Scheduling (Non-Preemptive)
    while (finished < n) {
        int shortestJobIndex = -1;

        // Find the shortest job that has already arrived
        for (i = 0; i < n; i++) {
            if (!isDone[i] && arrivalTime[i] <= currentTime) {
                if (shortestJobIndex == -1 || burstTime[i] < burstTime[shortestJobIndex]) {
                    shortestJobIndex = i;
                }
            }
        }

        if (shortestJobIndex == -1) {
            currentTime++;   // CPU idle
        } else {
            currentTime += burstTime[shortestJobIndex]; 
            completionTime[shortestJobIndex] = currentTime;

            turnaroundTime[shortestJobIndex] = completionTime[shortestJobIndex] - arrivalTime[shortestJobIndex];
            waitingTime[shortestJobIndex] = turnaroundTime[shortestJobIndex] - burstTime[shortestJobIndex];

            totalTAT += turnaroundTime[shortestJobIndex];
            totalWT  += waitingTime[shortestJobIndex];

            isDone[shortestJobIndex] = 1;  // mark as completed
            finished++;
        }
    }

    // Output
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, arrivalTime[i], burstTime[i],
               completionTime[i], turnaroundTime[i], waitingTime[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", totalTAT / n);
    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);

    return 0;
}
      
// 5 0 6 2 8 4 7 5 3 7 4



















/*
#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], done[n];
    float avg_tat = 0, avg_wt = 0;

    // Input
    for (i = 0; i < n; i++) {
        printf("AT & BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        done[i] = 0;
    }

    // SJF Scheduling
    while (completed < n) {
        int idx = -1;

        // Find shortest job that has arrived
        for (i = 0; i < n; i++) {
            if (!done[i] && at[i] <= time) {
                if (idx == -1 || bt[i] < bt[idx])
                    idx = i;
            }
        }

        if (idx == -1) {
            time++;   // CPU idle
        } else {
            time += bt[idx];              // run the job
            ct[idx] = time;               // completion time
            tat[idx] = ct[idx] - at[idx]; // turnaround
            wt[idx]  = tat[idx] - bt[idx]; // waiting
            avg_tat += tat[idx];
            avg_wt  += wt[idx];
            done[idx] = 1;
            completed++;
        }
    }

    // Output
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);

    printf("\nAvg TAT = %.2f\nAvg WT = %.2f\n", avg_tat/n, avg_wt/n);
    return 0;
}

*/





















/*
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
*/
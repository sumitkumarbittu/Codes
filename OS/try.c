/*

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    pid = fork(); // create a child process
    if (pid < 0) {
        // fork failed
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0){
        // Child process
        printf("Child process (PID: %d) is running...\n", getpid());
        sleep(2);
        printf("Child process completed.\n");
        exit(0);
    }
    else {
        // Parent process
        printf("Parent process (PID: %d) waiting for child...\n", getpid());
        wait(NULL); // parent waits for child to finish
        printf("Parent process resumes after child has terminated.\n");
    }
    printf("\n");
    return 0;
}

*/







/*

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main() {
    pid_t p = fork();

    if(p < 0)
        printf("Fork1 Failed!");
    else if(p == 0) {
        printf("Child Node!");
        exit(0);
    }
    else {
        sleep(3);
        printf("Zombie Parent Node");
    }

    return 0;
}

*/











#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

//orphan process
//Parent -> Child(orphan)
int main() {
    pid_t p = fork();

    if(p < 0)
        printf("Fork1 Failed!\n");
    else if(p == 0) {
        sleep(3);
        printf("Orphan Child Node!\n");
    } 
    else {
        printf("Parent Node!\n");
    }

    return 0;
}












/*

#include<stdio.h> 
#include<stdbool.h>

//Round Robin
int main() {
    int n;
    printf("Input n : ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n], complete=0, time=0, time_quantum;
    bool done[n];
    float avg_tat=0, avg_wt=0;

    for(int i=0; i<n; i++) {
        printf("Enter at%d, bt%d and p%d",i,i,i);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
        done[i] = false;
    }

    printf("Enter Time Quantum : ");
    scanf("%d", &time_quantum);

    printf("\nP#\tAT\tBT\tCT\tTAT\tWT\n");

    while(complete < n) {
        bool idx = false;

        for(int i=0; i<n; i++) {
            if(!done[i] && at[i] <= time) {
                idx = true;
                if(rt[i] > time_quantum)
                    rt[i] -= time_quantum, time += time_quantum;
                else {
                    time += rt[i];
                    rt[i] = 0;
                    done[i] = true;
                    complete++;
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    avg_tat += tat[i];
                    avg_wt += wt[i];
                    printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
                }
            }
        }

        if(!idx)
            time++;
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("Avg Tat : %.2f, Avg Wt : %.2f", avg_tat, avg_wt);

    return 0;
}

// 5 0 5 1 3 2 8 3 6 4 4 2

*/





/*

#include<stdio.h>
#include<stdbool.h>

//Priority Scheduling Preemptive
int main() {
    int n;
    printf("Input n : ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], rt[n], p[n], tat[n], wt[n], complete=0, time=0;
    bool done[n];
    float avg_tat=0, avg_wt=0;

    for(int i=0; i<n; i++) {
        printf("Enter at%d, bt%d and p%d : ",i,i,i);
        scanf("%d %d %d", &at[i], &bt[i], &p[i]);
        done[i] = false;
        rt[i] = bt[i];
    }

    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    while(complete < n) {
        int idx = -1;

        for(int i=0; i<n; i++)
            if(!done[i] && at[i]<=time && rt[i]>0 && (idx==-1 || p[i] > p[idx] || (p[i] == p[idx] && at[i] < at[idx])))
                idx = i;

        if(idx == -1) {
            time++;
            continue;
        }

        time++, rt[idx]--;

        if(!rt[idx]) {
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            done[idx] = true;
            complete++;
            avg_tat += tat[idx];
            avg_wt += wt[idx];
            printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", idx, at[idx], bt[idx], p[idx], ct[idx], tat[idx], wt[idx]);
        }
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("Avg Tat : %.2f, Avg Wt : %.2f", avg_tat, avg_wt);

    return 0;
}

// 5 0 7 2 2 4 1 4 1 3 5 4 2 6 3 1

*/













/*

#include<stdio.h>
#include<stdbool.h>

//Priority Scheduling Non-Preemptive
int main() {
    int n;
    printf("Input n: ");
    scanf("%d", &n);
    
    int at[n], bt[n], ct[n], p[n], tat[n], wt[n], time=0, complete=0;
    bool done[n];
    float avg_tat=0, avg_wt=0;

    for(int i=0; i<n; i++) {
        printf("Enter at%d, bt%d and p%d : ",i,i,i);
        scanf("%d %d %d", &at[i], &bt[i], &p[i]);
        done[i] = false;
    }

    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    while(complete < n) {
        int idx = -1;
        
        for(int i=0; i<n; i++) {
            if(!done[i] && at[i] <= time && (idx==-1 || p[i] > p[idx] || (p[i] == p[idx] && at[i] < at[idx])))
                idx = i;
        }

        if(idx == -1) 
            time++;
        else {
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            done[idx] = true;
            complete++;
            avg_tat += tat[idx];
            avg_wt += wt[idx];
            printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", idx, at[idx], bt[idx], p[idx], ct[idx], tat[idx], wt[idx]);
        }
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("Avg Tat : %.2f, Avg Wt : %.2f", avg_tat, avg_wt);

    return 0;
}

// 5 0 6 2 2 8 1 4 7 3 5 3 2 7 4 1

*/






/*

#include<stdio.h>
#include<stdbool.h>

//SRTF
int main() {
    int n;
    printf("Input n : ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n], complete=0, time=0;
    bool done[n];
    float avg_tat=0, avg_wt=0;

    for(int i=0; i<n; i++) {
        printf("Enter at%d and bt%d : ",i,i);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
        done[i] = false;
    }

    while(complete < n) {
        int idx = -1;

        for(int i=0; i<n; i++) {
            if(!done[i] && at[i] <= time && rt[i] > 0 && (rt[i] < rt[idx] || idx==-1))
                idx = i;
        }
        
        if(idx == -1) {
            time++; 
            continue;
        }
        
        time++, rt[idx]--;

        if(!rt[idx]) {
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            done[idx] = true;
            complete++;
            avg_tat += tat[idx];
            avg_wt += wt[idx];
        }
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("Avg Tat : %.2f, Avg Wt : %.2f", avg_tat, avg_wt);

    return 0;
}

// 5 0 7 2 4 4 1 5 4 6 2

*/









/*

#include<stdio.h>
#include<stdbool.h>

//SJF
int main() {
    int n;
    printf("Input n: ");
    scanf("%d",&n);

    int at[n], bt[n], ct[n], tat[n], wt[n], complete=0, time=0;
    bool done[n];
    float avg_wt=0, avg_tat=0;

    for(int i=0; i<n; i++) {
        printf("Enter at%d and bt%d : ", i, i);
        scanf("%d %d", &at[i], &bt[i]);
        done[i] = false;
    }

    while(complete < n) {
        int idx = -1;

        for(int i=0; i<n; i++) {
            if(!done[i] && at[i] <= time && (idx==-1 || bt[i] < bt[idx]))
                idx = i;
        }

        if(idx == -1)
            time++;
        else {
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            avg_tat += tat[idx];
            avg_wt += wt[idx];
            done[idx] = true;
            complete++;
        }
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("Avg Tat : %.2f, Avg Wt : %.2f", avg_tat, avg_wt);

    return 0;
}

// 5 0 6 2 8 4 7 5 3 7 4

*/










/*

#include<stdio.h>

// FCFS
int main() {
    int n;
    printf("Input n: ");
    scanf("%d",&n);

    int at[n], bt[n], ct[n], tat[n], wt[n];
    float avg_wt=0, avg_tat=0;

    for(int i=0; i<n; i++) {
        printf("Enter at%d and bt%d : ", i, i);
        scanf("%d %d", &at[i], &bt[i]);
    }

    ct[0] = at[0] + bt[0];
    for(int i=1; i<n; i++) 
        ct[i] = (at[i] > ct[i-1] ? at[i] : ct[i-1] ) + bt[i];

    for(int i=0; i<n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("Avg Tat : %.2f, Avg Wt : %.2f", avg_tat, avg_wt);

    return 0;
}

// 4 0 5 1 3 2 8 3 6

*/
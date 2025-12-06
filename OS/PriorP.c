#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n], rt[n], wt[n], tat[n], done[n];
    int i, t=0, completed=0;
    
    for(i=0;i<n;i++){
        printf("P%d Arrival, Burst, Priority: ", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i]=bt[i]; done[i]=0; wt[i]=0;
    }

    while(completed < n) {
        int idx = -1;
        for(i=0;i<n;i++) {
            if(at[i]<=t && !done[i]) {
                if(idx==-1 || pr[i]<pr[idx] || (pr[i]==pr[idx] && at[i]<at[idx])){
                    idx=i;
                }
            }
        }
        if(idx==-1){ t++; continue; }

        rt[idx]--; t++;
        if(rt[idx]==0){
            done[idx]=1; completed++;
            tat[idx]=t-at[idx];
            wt[idx]=tat[idx]-bt[idx];
        }
    }

    float total_wt=0, total_tat=0;
    printf("\nP#\tAT\tBT\tPR\tWT\tTAT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], pr[i], wt[i], tat[i]);
        total_wt+=wt[i]; total_tat+=tat[i];
    }
    printf("\nAvg WT=%.2f, Avg TAT=%.2f\n", total_wt/n, total_tat/n);
    return 0;
}

// 5 0 7 2 2 4 1 4 1 3 5 4 2 6 3 1
//LRU PR
#include <stdio.h>
#include <stdbool.h>

int main() {
    int f, p;
    printf("Frames & Pages Count: ");
    scanf("%d %d", &f, &p);
    
    int frames[f], time[f];
    for(int i=0; i<f; i++)
        frames[i] = -1, time[i] = 0;
        
    int pages[p];
    for(int i=0; i<p; i++)
        scanf("%d", &pages[i]);
        
    int hit=0, miss=0, counter=0;
    
    for(int i=0; i<p; i++) {
        
        int page = pages[i];
        bool found = false;
        for(int j=0; j<f; j++) 
            if(page == frames[j]) {
                printf("\nHit %d page", pages[i]);
                found = true;
                hit++;
                time[j] = ++counter;
                break;
            }
        
        if(!found) {
            miss++, counter++;
            int index = -1;
            
            for(int j=0; j<f; j++) 
                if(frames[j] == -1) {
                    index = j;
                    break;
                }
                
            if(index == -1) {
                index = 0;
                for(int j=1; j<f; j++)
                    index = time[j] < time[index] ? j : index;
            }
            
            frames[index] = page;
            time[index] = counter;
            
            printf("\nPage %d inserted ->  Frames :",page);
            for(int j=0; j<f; j++)
                printf(" %d",frames[j]);
        }
    }
    
    printf("\nTotal Hits  = %d\n", hit);
    printf("Total Misses = %d\n", miss);
    
    return 0;
}

// 3 7 7 0 1 2 0 3 0
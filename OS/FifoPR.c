//FIFO
#include<stdio.h>
#include<stdbool.h>

int main() {
    int f, p;
    printf("Frames & Pages Count: ");
    scanf("%d %d", &f, &p);
    
    int frames[f];
    for(int i=0; i<f; i++)
        frames[i] = -1;
        
    int pages[p];
    for(int i=0; i<p; i++)
        scanf("%d", &pages[i]);
        
    int hit=0, miss=0, index=0;
    
    for(int i=0; i<p; i++) {
        
        bool found = false;
        for(int j=0; j<f; j++)
            if(pages[i] == frames[j]) {
                printf("Page %d hit\n", pages[i]);
                hit++;
                found = true;
                break;
            }
                
        if(!found) {
            frames[index] = pages[i];
            index = (index+1) % f;
            miss++;
            
            printf("Page %d inserted → Frames: ", pages[i]);
            for (int k = 0; k < f; k++)
                printf("%d ", frames[k]);
            printf("\n");
            
        }
    }
    
    printf("\nTotal Hits  = %d\n", hit);
    printf("Total Misses = %d\n", miss);

    return 0;
}

//3 8 7 0 1 2 0 3 0 4
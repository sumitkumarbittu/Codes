#include <stdio.h>
#include <stdlib.h>

void Mergesort(int a[], int l, int r) {
    if(l<r)
    {
        int m = l + (r-l)/2;
        Mergesort(a, l, m);
        Mergesort(a, m+1, r);
        int n1 = m-l+1;
        int n2 = r-m;
        int *L = (int *)malloc(n1*sizeof(int));
        int *R = (int *)malloc(n1*sizeof(int));
        for(int i=0; i<n1; i++)
        L[i] = a[l+i];
        for(int j=0; j<n2; j++)
        R[j] = a[m+1+j];
        int i=0,j=0,k=l;
        while(i<n1 && j<n2)
        {
            if(L[i] <= R[j])
            a[k] = L[i++];
            else
            a[k] = R[j++];
            k++;
        }
        while(i<n1)
        a[k++] = L[i++];
        while(j<n2)
        a[k++] = a[j++];
        free(L);
        free(R);
    }
}

void quicksort(int a[], int l, int h) {
    if(l<h)
    {
        int p = a[h];
        int i = l-1;
        for(int j=l; j<= h-1; j++)
        {
            if(a[j] <= p)
            {
                i++;
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
            for(int k=0;k<7;k++)
            printf("%d ", a[k]);
            printf("\n");
        }
        printf("\n");
        int t = a[i+1];
        a[i+1] = a[h];
        a[h] = t;
        int pi = i+1;
        quicksort(a,l, pi-1);
        quicksort(a,pi+1, h);
    }
}

/*
        10 30 80 90 40

*/

void insertionsort(int a[], int n) {
    for(int i = 1; i < n; i++)
    {
        int k = a[i];
        int j = i-1;
        while(j>=0 && a[j]>k)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = k;
    }
}

void selectionsort(int a[], int n) {
    for(int i = 0; i < n - 1; i++)
    {
        int s = i;
        for(int j = i+1; j < n; j++)
        {
            if(a[s] > a[j])
            s = j;
        }
        int t = a[s];
        a[s] = a[i];
        a[i] = t;
    }
}

void bubblesort(int a[], int n) {
    for(int i = 0; i < n-1;i++)
    {
        for(int j = 0; j < n-(i+1);j++)
        {
            if(a[j] > a[j+1])
            {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
        printf("\n");
    }
}

int main() {
    int a[] = {55, 3, 5, 4, 66, 0, 10};
    int n = sizeof(a)/sizeof(a[0]);
    //insertionsort(a,n);
    //selectionsort(a,n);
    //bubblesort(a,n);
    quicksort(a,0,n-1);
    printf("Sorted Array : ");
    //for(int i=0;i<n;i++)
    //printf("%d ",a[i]);
    printf("\n");
    return 0;
}

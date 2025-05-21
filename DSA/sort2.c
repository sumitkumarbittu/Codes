#include<stdio.h>

void quickSort(int a[], int l, int h)
{
    if (l < h)
    {
        int p = a[h], i = l - 1, j, t;
        for (j = l; j < h; j++) {
            if (a[j] < p) {
                t = a[++i];
                a[i] = a[j];
                a[j] = t;
            }
        }
        t = a[++i];
        a[i] = a[h];
        a[h] = t;
        quickSort(a, l, i - 1);
        quickSort(a, i + 1, h);
    }
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        int i = l, j = m + 1, k = 0, t[r - l + 1];
        while (i <= m && j <= r)
        t[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
        while (i <= m) t[k++] = a[i++];
        while (j <= r) t[k++] = a[j++];
        for (i = l, k = 0; i <= r; i++, k++)
        a[i] = t[k];
    }
}

int main()
{
    int c;
    while(1)
    {
        printf("Choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1 :
                int a[20],n;
                printf("No of Elements : ");
                scanf("%d",&n);
                printf("Elements : "            );
                for(int k=0;k<n;k++)
                scanf("%d",&a[k]);
                quickSort(a, 0, n - 1);
                printf("Sorted aay: ");
                for (int i = 0; i < n; i++)
                printf("%d ", a[i]);
                printf("\n");
                break;
    
            default:
                printf("Thank You!\n");
                break;
        }
    }
    return 0;
}
#include <stdio.h>

int binarysearch(int a[], int l, int r, int t) {
    while(l<=r) {
        int m = l + (r-l)/2;
        if(a[m] == t)
        return m;
        if(a[m] < t)
        l = m+1;
        if(a[m] > t)
        r = m-1;
    }
    return -1;
}

int main() {
    int a[] = {1,3,0,5,9,6};
    int n = sizeof(a)/sizeof(a[0]);
    int x = binarysearch(a, 0, n-1, 8);
    printf("%d\n", x);
    return 0;
}

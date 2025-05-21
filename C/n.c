#include <stdio.h>

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int sum = 0;
    for (int i = -n; i <= n; i++) {
        printf("%d", i);
        sum += i;

        
    }

    printf("\nSum of the sequence: %d\n", sum);

    return 0;
}

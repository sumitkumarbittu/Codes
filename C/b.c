#include<stdio.h>

int main() {
    int i,n,sum;

    printf("enter the number");
    scanf("%d",&n);


    if(i==0)
        sum=1;
    else if(i%2==0)
        sum=sum+i, printf("%d\n",sum);
    else
        sum=sum+(i*-1), printf("%d\n",sum);
    
    printf("sum of the series:- %d",sum);
    return 0;
}
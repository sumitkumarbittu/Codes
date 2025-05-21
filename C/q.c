#include <stdio.h>
#include<math.h>
int armstrong(int);
int main()
{
    int n;
    printf("Input Number : ");
    scanf("%d",&n);
    armstrong(n);
    if (armstrong(n)==n)
    {
        printf("%d is armstrong.\n",n);
    }
    else
    {
        printf("%d is not an Armstong.\n", n);
    }
    return 0;
}
int armstrong(int n)
{
    int a,b,arm=0;
    while (n!=0)
    {
        b=n%10;
        a=pow(b,3);
	arm+=a;
	n=n/10;
    }
	
        return arm;
}
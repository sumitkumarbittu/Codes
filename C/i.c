#include <stdio.h>
int main()
{
	int I,sum=0,n,j;
	printf("Input Value for n : ");
	scanf("%d",&n);
	for (I=0;I<n;I++)
	{
		j=I*I*(I+1);
		sum+=j;
		printf("%d\n",j);
	}
	printf("Sum : %d",sum);
	return 0;
}
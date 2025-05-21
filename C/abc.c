#include <stdio.h>
int main()
{
//Factors of any Number
	int n,i;
	printf("Input a number to print its Factors : ");
	scanf("%d",&n);
	i=2;
	printf("1\n");
	while(n>1)
	{
		if(n%i==0)
		{
			printf("%d\n",i);
			n=n/i;
		}
		else
		{
			i++;
		}
	}	
	return 0;
}




#
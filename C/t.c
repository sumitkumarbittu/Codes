#include<stdio.h>
void pat(int n);
int main()
{
	int n;
	printf("enter the no.");
	scanf("%d",&n);
	pat(n);
	return 0;
}


void pat(int n)
{
	int i,j,k,l=0,a=0;
	for(i=1;i<=n;i++)
	{
		a=l;
		a+=i;
		for(j=n;j>i;j--)
		{
			printf(" ");
		}
		for(k=1;k<=i;k++)	
		{
			printf("%d",a);
			a--;
			l++;
		}
		printf("\n");
	}
}
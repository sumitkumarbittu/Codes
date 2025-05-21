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
	int i,j,k=0,l;
	for(i=1;i<=n;i++)
	{
			for(l=n-1;l>0;l--)
			{
				printf(" ");
			}
			for(j=1;j<=i;j++)
				{				
					
					
				}
		printf("\n");
	}
}
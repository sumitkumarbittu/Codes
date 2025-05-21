#include<stdio.h>
int main()
{
	int a=1,n=4;
	for(int i=0;i<n;i++)
	{
		
		for(int k=n-1;k>i;k--)
		{
			printf(" ");
		}
		for(int j=0;j<=i;j++)
		{
			printf("%d ",a);
			a++;
		}
		printf("\n");
	}
}


























/*
#include<stdio.h>
int main()
{
	int n;
	printf("Input no of term to print : ");
	scanf("%d",&n);
	int x=n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=x;j++)
		{
			printf("*");
		}
		x--;
		printf("\n");
	}
	
}
*/

/*
#include<stdio.h>
int main()
{
	int a,b=9,c=99,d=0,n;
	printf("Input no of term to print : ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		a=i%2;
		if(a!=0)
		{
			d+=b;
			printf("%d\n",b);
			b--;
		}
		else
		{
			d+=c;
			printf("%d\n",c);
			c-=10;
		}
	}
	printf("Sum : %d",d);
}
*/

/*
#include <stdio.h>

int main() 
{
    int A[20],B[20],R[40], n, m;
    printf("Enter the number of elements in array A: ");
    scanf("%d", &n);
    printf("Enter elements of array A: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("Enter the number of elements in array B: ");
    scanf("%d", &m);
    printf("Enter elements of array B: ");
    for (int i = 0; i < m; i++) 
    {
        scanf("%d", &B[i]);
    }
    for (int i = 0; i < n; i++)
    {
        R[i] = A[i];
    }
    for (int i = 0; i < m; i++) 
    {
        R[n + i] = B[i];
    }
    for (int i = 0; i < n+m-1; i++) 
    {     
        for (int j = 0; j < n+m-i-1; j++)
        { 
            if (R[j] > R[j+1])
            {
                // Swap array[j] and array[j+1]
                int temp=0;
		temp = R[j];
                R[j] = R[j+1];
                R[j+1] = temp;
            }
        }
    }
    printf("Merged array is: ");
    for (int i = 0; i < n + m; i++) 
    {
        printf("%d ", R[i]);
    }
    return 0;
}
*/
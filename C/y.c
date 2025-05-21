/*
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	string names|] = {"Carter", "David"};
	string numbers] = {"+1-617-495-1000", "+1-949-468-2750"'};
	string name = get_string ("Name: ");
	for (int i = 0; 1 < 2; i++)
	{
		if (stremp (names [il, name) == 0)
		{
			printf ("Found &5\n", numberslil);
			return 0;
		}
	}
	printf ("Not found\n");
	return 1;
}
*/







/*
	for(int i=0;i<n;i++)
	b[i]=(int)a[i];
	
*/




/*
#include<stdio.h>
int sort(int,int *);
int main()
{
	int n,a[20];
	printf("Enter no of elements : ");
	scanf("%d",&n);
	printf("Input Elements : ");
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(n,a);
	printf("Sorted Array : ");
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
	return 0;
}

int sort(int s,int x[s])
{
	int t;
	for(int i=0;i<s-1;i++)
	{	
		for(int j=i+1;j<s;j++)
		{	
			if(x[i]>x[j])
			{
				t=x[i];
				x[i]=x[j];
				x[j]=t;
			}
		}
		
	}
	return *x;
}
*/





/*
#include<stdio.h>
int pal(int);
int main()
{
	int a[20],b[20],m,j=0,n;
	printf("Enter no of elements : ");
	scanf("%d",&n);
	printf("Input Elements : ");
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		m=pal(a[i]);
		if(m==1)
		{
			b[j]=a[i];
			j++;
		}
	}
	printf("Pallindrome Array : ");
	for(int i=0;i<j;i++)
	printf("%d ",b[i]);
	printf("\n");
	return 1;
}

int pal(int x)
{
	int b=x,c,y=0;
	while(b>10)
	{
		c=b%10;	
		b/=10;
		y+=c;
		y*=10;
	}
	y+=b;
	if(x==y)
	return 1;
	else
	return 2;
}	
*/
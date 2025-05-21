/*
#include<stdio.h>
#include<string.h>

typedef struct
{
	string name;
	string number;
}
person;

int main()
{
	person people[2];
	people[0].name = "Bittu";
	People[0].number = "+91 9939598571";

	people[1].name = "Sumit";
	people[1].number "+91 9546803861";

	if()



}
*/



/*
#include<stdio.h>
int ss(int,int *);
int main()
{
	int a[20],n;
	printf("Enter no of elements : ");
	scanf("%d",&n);
	printf("Input Elements : ");
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	ss(n,a);
	printf("Sorted Array : ");
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
	return 0;
}

int ss(int n,int x[])
{
	int t;
	for(int i=0;i<n-1;i++)
	{	
		t=x[i];
		for(int j=i+1;j<n;j++)
		{	
		if(x[j]<t)
		t=x[j];
		}
		x[i]=t;
	}
	return *x;
}
*/






























int get_int(char x[])
{
	int a;
	printf("%s",x);
	scanf("%d",&a);
	return a;
}
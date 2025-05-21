#include <stdio.h>
int sum(int x, int y)
{
	int s;
	s=x+y;
	return s;

}






int main()
{
	int a,b,s;
	printf("Enter values for a and B: "); 
	scanf("%d %d",&a,&b); 
	s=sum(a,b);
	printf("Sum of %d and %d is %d\n",a,b,s);
}
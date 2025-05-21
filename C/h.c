#include <stdio.h>
int main()
{
	int I,n,a,b,c,sum=0,m,j;
	printf("Input any 6 digit no. ");
	scanf("%d",&n);
	m=n;
	while(m>0)
	{
	a=m%10;
	m=m/10;
	b=m%10;
	m=m/10;
	c=10*a+b;
	c=c*j;
	for (I=1;I<3;I++)
	{j=j*10;}
	sum=sum+c;
	}
	printf("%d\n",sum);
	return 0;
}
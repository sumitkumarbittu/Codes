#include<stdio.h>
void rev(void);
int main()
{
	rev();	
}

void ad(void)
{
	int n;
	printf("Input : ");
	scanf("%d ",&n);
	
	printf("%d ",result);
}













/*
#include<stdio.h>
#include<math.h>
int fact(int n);
int main()
{
	int x=0,y,z=0,N=6;
	for(int i=1;i<=N;i++)
	{
		x+=fact(i)/i;
		printf("%d ",x);
	}
	
}
*/
/*
#include<stdio.h>
#include<math.h>
int fact(int n);
int main()
{
	int x=2,N=5;
	float z,y=0;
	for(int i=1;i<=N;i++)
	{
		if(i%2!=0)
		y+= (float)((pow(x,i)/fact(i)));
		else
		y-= (float)((pow(x,i)/fact(i)));
	}
	printf("%f\n",y);
}
*/





int fact(int n)
{
	int a=1,b=1,c=n;
	for(int i=1;i<n;i++)
	{
		
		b=c;
		a*=b;
		c--;
	}
	return a;

}

/*
#include <stdio.h>
int fac(int);
int main()
{
    int n,z=1,g=1,j=2,v=1;
    float w=0,y,e,f,u;
    int p=3,q=1;
    printf("Input : ");
    scanf("%d",&n);
    
    while(z<=n)
    {
    e=fac(p);
    f=fac(q);
    u=g*e;
    y=u/f;
	printf("%d*%d!/%d! = %d*%.0f/%.0f",g,p,q,g,e,f);
    if(v%2==0)
    {g++;}
    else
    {
        g+=j;
        j++;
    }
    v++;    
    if(z==1)
    {}
    else if(z%4==0||z%4==1)
    {y=(-1)*y;}
    else
    {}
    w+=y;
	printf("    : %f\n",y);
    z++;
    p+=2;
    q++;
    }
    printf("Sum : %.2f\n",w);
return 0;
}
*/














/*
int fac(int i)
{
    int a=1,b=1;
    while(b<=i)
    {
        a*=b;
        b++;
    }
    return a;
}
*/
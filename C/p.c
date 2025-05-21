#include <stdio.h>
int fac(int i);
int main()
{
	int n,z=1;
	float w,y,e,f,g,h,u,v;
	int p=1,q=2,r=2,s=3,k=4,l=2,m=3;
	printf("Input : ");
	scanf("%d",&n);
	
	while(z<=n)
	{
		e=fac(p);
		f=fac(q);
		g=fac(r);
		h=fac(s);
		u=e*f;
		v=g+h;
		y=u/v;
		if(z%2==0)
		{y=(-1)*y;}
		else
		{}
		w+=y;
		z++;
		p=p+k;
		k--;
		q=q*2;
		r=r+l;
		l++;
		s=s+m;
		m++;
	} 
	printf("%.2f",w);
	return 0;		
}




int fac(int i)
{
	int a=1,b=1;
	while(b<=i)
	{
		a=a*b;
		b++;
	}
	return a;
}
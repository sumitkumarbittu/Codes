/*
#include<stdio.h>
int main()
{
	int n=5;
	for(int i=0;i<n;i++)
	{
		int b=1;
		for(int j=n;j>1;j--)
		printf("%d",b);
		printf("\n");
	}
	return 0;
}
*/





























/*
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int fibonacciSum(int n) {
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += fibonacci(i);
    }
    return sum;
}

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    int result = fibonacciSum(n);

    printf("Sum of the Fibonacci series up to %d terms is: %d\n", n, result);

    return 0;
}
*/
























/*
#include<stdio.h>
int main()
{}



int fib(int n)
{
	int a=0,b=1;
	if(n==0)
	return 0;
	else
	


}
*/

















/*
#include<stdio.h>
int sort(int,int *);
int main()
{
	int a[10],n;
	printf("Input Limit : ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(n,a);
	printf("%d ",a[4]);
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
int a(int,int);
int main()
{
	int x,y,a;
	printf("Input X and Y : ");
	scanf("%d %d",&x,&y);
	a=a(x,y);
	printf("%d",a);
}


int a(int x,int y) 
{
	if(y==0)
	return 1;
	else
	return x*a(x,y-1);
}
*/















/*
#include<stdio.h>
int sod(int);
int main()
{
	int n=54321;
	printf("%d\n",sod(n));

}

int sod(int n)
{
	int b=0,c;
	if(n==0)
	return 0;
	else
	{
		b+=n%10;
		return b+sod(n/10);
	}

}
*/


















/*
#include<stdio.h>
#include<math.h>
int p(int x,int n)
{
    if(n==0)
    return 1;
    else if(n%2==1)
    return p(x,n-1);
    else
    return pow(x,n)+p(x,n-1);
}



int main()
{
    int x,n;
    printf("Input x & n : ");
    scanf("%d %d",&x,&n);
    printf("%d\n",p(x,n));
    return 0;
}
*/


























#include<stdio.h>
int sort(int,int *);
int main()
{
	int a[]={86,18,11,16,99,23},b[3]={21,45,9};
	int sa=sizeof(a)/sizeof(a[0]);
	int sb=sizeof(b)/sizeof(b[0]);
	sort(sb,b);
	for(int k=0;k<sb;k++)
	printf("%d ",b[k]);

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
























/*
	
#include<stdio.h>
int po(int y);
int main()
{
	printf("x^y : %d\n",po(5));
	


}

int po(int y) 
{
	int x=2,z;
	if(y>0)
	{
		y--;
		return x*po(y);
	}
	return 1;
}
*/






















/*
#include<stdio.h>
#include<math.h>
int a=0,i=0;
int p(int n)
{
    int x=2;
    if(2*i==n)
    return a;
    if(i==0)
    i+=2;
    if(i%2==0)
    {
        int b;
        b=pow(x,i);
        a+=b;
        printf("%d",a);
        i+=2;
        return a+p(n-1);
    }
}



int main()
{
    int c;
    printf("Input : ");
    scanf("%d",&c);
    c*=2;
    printf("%d\n",p(8));
    return 0;
}
*/
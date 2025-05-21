/*
#include<stdio.h>
#include<string.h>
int get_int(char x[]);

int main()
{
	char a[20];
	int vowel=0,consonant=0;
	int m = get_int("Input Size of First Array : ");
	for (int i=0;i<m;i++)
	scanf("%c",&a[i]);
	for (int i=0;i<m;i++)
	{
		if (a[i]=='a')
		{
			a[i]='$';
			vowel++;
		}
		else
		{
			a[i]='#';
			consonant++;
		}
	}
	printf("Vowel : %d \nConsonant : %d\n",vowel,consonant);
	printf("Modified Array : \n");
	for (int i=0;i<m;i++)
	printf("%c ",a[i]);
	printf("\n");
}
*/

/*
#include<stdio.h>
#include<string.h>
int get_int(char x[]);

int main()
{
	int a[20],x[20];
	int m = get_int("Input Size of First Array : ");
	for (int i=0;i<m;i++)
	scanf("%d",&a[i]);
	for (int i=0;i<m;i++)
	{	
		int s=0;
		for (int j=0;j<m;j++)
		{
			if (a[i]==a[j])
			{
				for (int k=0;k<m-j;k++)
				a[j]=a[j+1];
				s++;
				printf("%d : %d\n",a[i],s);
				m--;
			}
		}
	}
}
*/

/*
#include<stdio.h>
#include<string.h>
int get_int(char x[]);

int main()
{
	int a[20];
	int m = get_int("Input Size of First Array : ");
	for (int i=0;i<m;i++)
	scanf("%d",&a[i]);
	printf("Reverse of the Array : \n");
	for (int i=m-1,j=0;i>-1,j<m;i--,j++)
	{
		b[j]=a[i];
		printf("%d ",b[j]);
	}
	printf("\n");
}
*/

/*
#include<stdio.h>
#include<string.h>
int get_int(char x[]);

int main()
{
	int a[20];
	int m = get_int("Input Size of First Array : ");
	for (int i=0;i<m;i++)
	scanf("%d",&a[i]);
	int q = get_int("Enter Position to add Element : ");
	int r = get_int("Enter Element for position q : ");
	for (int i=m;i>q;i--)
	a[i+1]=a[i];
	a[q-1]=r;
	printf("Modified Array : \n");
	for (int i=0;i<m+1;i++)
	printf("%d ",a[i]);
	printf("\n");
}
*/


/*
#include<stdio.h>
#include<string.h>
int get_int(char x[]);

int main()
{
	int a[20],b[20],c[40];
	int m = get_int("Input Size of First Array : ");
	for (int i=0;i<m;i++)
	scanf("%d",&a[i]);
	int n = get_int("Input Size of Second Array : ");
	for (int i=0;i<n;i++)
	scanf("%d",&b[i]);
	for (int i=0;i<m;i++)
	c[i]=a[i];
	int y = m+n;
	for (int p=m,j=0;p<y,j<n;p++,j++)
	c[p]=a[j];
	int z = get_int("Enter Element to Print from array C : ");
	printf("Element %d of array C is %d",z,c[z-1]);
}
*/

/*
#include<stdio.h>
#include<string.h>
int get_int(char x[]);
void prime(int n, int i);
int main()
{
	int n = get_int("Input a Number : ");
	prime(n,2);
	printf("%d is ")
}

void prime(int n, int i)
{
	
	if(n==1)
	printf("non Prime.\n");
	if(i>=n/2)
	return;
	if(n%i!=0)
	prime(n,i+1);
	else
	printf("Prime.\n");
}

*/








/*
#include<stdio.h>
void fac(int n, int);
int main()
{
	int n;
	printf("Enter a Number : ");
	scanf("%d",&n);
	fac(n,1);
	printf("%d\n",n);
	return 0;
}

void fac(int n, int i)
{
	if(i>n/2)
	return;
	if(n%i==0)
	printf("%d ",i);
	fac(n,i+1);
}
*/






/*
#include <stdio.h>
void findFactorsRecursive(int num, int i);
int main() 
{
    int number;
    printf("Enter a positive integer: ");
    scanf("%d", &number);
    if (number < 1) 
    {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    printf("Factors of %d are: ", number);
    findFactorsRecursive(number, 1);

    return 0;
}

void findFactorsRecursive(int num, int i) 
{
    if (i > num) 
    {
        return;
    }
    if (num % i == 0) {
        printf("%d ", i);
    }
    findFactorsRecursive(num, i + 1);
}
*/



/*
#include <stdio.h>

int main() 
{
    int number;
    printf("Enter a positive integer: ");
    scanf("%d", &number);
    if (number < 1) 
    {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    findFactors(number);
    return 0;
}


void findFactors(int num) 
{
    printf("Factors of %d are: ", num);
    for (int i = 1; i <= num; ++i) {
        if (num % i == 0)
            printf("%d ", i);
    }
    printf("\n");
}
*/













/*
#include<stdio.h>
int fact(int);
int main()
{
	int n,res;
	printf("Input a Number : ");
	scanf("%d",&n);
	res = fact(n);
	printf("%d\n",res);
	return 0;
}

int fact(int n)
{
	if(n==0)
	return 1;
	else
	return (n*fact(n-1));
}
*/






int get_int(char x[])
{
	int a;
	printf("%s",x);
	scanf("%d",&a);
	return a;
}
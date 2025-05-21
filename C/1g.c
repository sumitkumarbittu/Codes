/*
#include<stdio.h>
int main()
{
	char a[50];				//Strlen
	int j=0;
	printf("Input a String : ");
	fgets(a,sizeof(a),stdin);
	while(a[j]!='\0' && a[j]!='\n')
	j++;
	printf("Length : %d\n",j+1);
	return 0;
}
*/

/*
#include<stdio.h>
#include<math.h>
void scr(int,int*,int*,double*);
int main()
{
	int n,s,c;			//pointer ^2 ^3 ^1/2
	double r;
	printf("Enter a Number : ");
	scanf("%d",&n);
	scr(n,&s,&c,&r);
	printf("%d %d %f\n",s,c,r);
	return 0;
}

void scr(int n,int *s,int *c,double *r)
{
	*s=pow(n,2);
	*c=pow(n,3);
	*r=sqrt(n);
}
*/

/*
#include<stdio.h>
int count(int);
int main()
{
	int n,a;				//return count
	printf("Input a No. ");
	scanf("%d",&n);
	printf("%d",count(n));
	return 0;
}

int count(int n)
{
	int c=0;
	while(n!=0)
	{
		c++;
		n/=10;
	}
	return c;
}
*/

/*
#include<stdio.h>
int main()
{
	char a[100];				//upper to lower
	int j=0;
	printf("Input a String : ");
	fgets(a,sizeof(a),stdin);
	while(a[j]!='\0' && a[j]!='\n')
	{
		if(a[j]>=65 && a[j]<=90)
		a[j]+=32;
		j++;
	}
	printf("%s",a);
	return 0;
}
*/

/*
#include<stdio.h>
int main()
{
	char a[100];				//palindrome sr
	int j=0,k=0;
	printf("Input a String : ");
	fgets(a,sizeof(a),stdin);
	while(a[k]!='\0' && a[k]!='\n')
	k++;
	k--;
	while(a[j]!='\0' && a[j]!='\n')
	{
		if(a[j]==a[k])
		{
			j++;
			k--;
		}
		else
		{
			printf("Non Palindrome\n");
			return 1;
		}
	}
	printf("Palindrome\n");
	return 0;
}
*/

/*
#include<stdio.h>
int main()
{
	int a[5][5],r,c,l=0,u=0;		//upper lower 2d 
	printf("Enter no of rows and columns : ");
	scanf("%d %d",&r,&c);
	for(int j=0;j<r;j++)
	{	
		for(int k=0;k<c;k++)
		scanf("%d",&a[j][k]);
	}
	for(int j=0;j<r;j++)
	{	
		for(int k=0;k<c;k++)
		{
			if(k<=j)
			l+=a[j][k];
			if(j<=k)
			u+=a[j][k];
		}
	}
	printf("%d %d",l,u);
	return 0;
}
*/

/*
#include<stdio.h>
int main()
{
	int a[5][5],r,c;					//2d scan print
	printf("Enter no of rows and columns : ");
	scanf("%d %d",&r,&c);
	for(int j=0;j<r;j++)
	{	
		for(int k=0;k<c;k++)
		scanf("%d",&a[j][k]);
	}
	for(int j=0;j<r;j++)
	{	
		for(int k=0;k<c;k++)
		printf("%d",a[j][k]);
	}
	return 0;
}
*/

/*
#include<stdio.h>
int main()
{
	int a[5][5],r,c,s,l;					//2d small large
	printf("Enter no of rows and columns : ");
	scanf("%d %d",&r,&c);
	for(int j=0;j<r;j++)
	{	
		for(int k=0;k<c;k++)
		scanf("%d",&a[j][k]);
	}
	s=l=a[0][0];
	for(int j=0;j<r;j++)
	{	
		for(int k=0;k<c;k++)
		{
			if(l<a[j][k])
			l=a[j][k];
			if(s>a[j][k])
			s=a[j][k];
		}
	}
	printf("%d %d",s,l);
	return 0;
}
*/

/*
#include<stdio.h>
int main()
{
	int a[5][5],r,c,o[25],e[25];				//2d odd even print
	printf("Enter no of rows and columns : ");
	scanf("%d %d",&r,&c);
	for(int j=0;j<r;j++)
	{	
		for(int k=0;k<c;k++)
		scanf("%d",&a[j][k]);
	}
	int m=0,n=0;
	for(int j=0;j<r;j++)
	{	
		for(int k=0;k<c;k++)
		{
			if(a[j][k]%2==0)
			{
				e[m]=a[j][k];
				m++;
			}
			else
			{
				o[n]=a[j][k];
				n++;
			}
		}
	}
	printf("Even : ");
	for(int p=0;p<m;p++)
	printf("%d ",e[p]);
	printf("\nOdd : ");
	for(int p=0;p<n;p++)
	printf("%d ",o[p]);
	printf("\n");
	return 0;
}
*/

/*
#include<stdio.h>
int main()
{
	int a[5][5],r,c,s[25],m[12],z;		//2d occurrence
	int p=0,q=0,w=0,f=0;
	printf("Enter no of rows and columns : ");
	scanf("%d %d",&r,&c);
	for(int j=0;j<r;j++)
	{	
		for(int k=0;k<c;k++)
		scanf("%d",&a[j][k]);
	}
	for(int j=0;j<r;j++)
	{	
		for(int k=0;k<c;k++)
		{
			z=0;
			for(int x=0;x<r;x++)
			{	
				for(int y=0;y<c;y++)
				{
					if(j!=x || k!=y)
					{
						if(a[j][k]==a[x][y])
						z++;
					}
				}
			}
			if(z==0)
			{
				for(int u=0;u<p;u++)
				{
					if(a[j][k]==s[u])
					w++;
				}
				if(w==0)
				{
					s[p]=a[j][k];
					p++;
				}
				w=0;
			}
			else
			{
				for(int u=0;u<q;u++)
				{
					if(a[j][k]==m[u])
					f++;
				}
				if(f==0)
				{
					m[q]=a[j][k];
					q++;
				}
				f=0;
			}
		}
	}
	printf("Single : ");
	for(int d=0;d<p;d++)
	printf("%d ",s[d]);
	printf("\nMulti : ");
	for(int e=0;e<q;e++)
	printf("%d ",m[e]);
	printf("\n");
	return 0;
}
*/

/*
void smo(int r,int c,int a[r][c],int *s[25],int *m[12])
{
	z=0;
	
}
*/

/*
#include<stdio.h>
int main()
{
	int a[5][5],r,c;				//2d 
	printf("Enter no of rows and columns : ");
	scanf("%d %d",&r,&c);
	for(int j=0;j<r;j++)
	{	
		for(int k=0;k<c;k++)
		scanf("%d",&a[j][k]);
	}
	for(int j=0;j<r;j++)
	{	
		for(int k=0;k<c;k++)
		{
			


		}
	}
}
*/

/*
for(int j=0;j<a;j++)
{
	if(str1[j]=='#')
	{
		printf("Anagram\n");
		return 0;
	}
}
*/

/*
#include<stdio.h>
#include<string.h>
int main()
{
	char str1[20],str2[20];				//Anagram
	printf("Input String 1 : ");
	fgets(str1,sizeof(str1),stdin);
	printf("Input String 2 : ");
	fgets(str2,sizeof(str2),stdin);
	int a=strlen(str1);
	int b=strlen(str2);
	if (a!=b)
	{
		printf("Not Anagram\n");
		return 1;
	}
	else
	{
		for(int j=0;j<a;j++)
		{	
			for(int k=0;k<b;k++)
			{
				if(str1[j]==str2[k])
				str1[j]=str2[k]='#';
			}
		}
		for(int j=0;j<a;j++)
		{
			if(str1[j]!='#')
			{
				printf("Not Anagram\n");
				return 2;
			}
		}
		printf("Anagram");
	}
	return 0;
}
*/

/*
#include<stdio.h>
int main()
{
	char a[50];				//spaces to words
	int j=0,b;
	printf("Input a String : ");
	fgets(a,sizeof(a),stdin);
	b=strlen(a);
	while(a[j]!='\0')
	{
		if(a[j]==32)
		{
			a[j]=10;
		}
		j++;
	}
	printf("%s",a);
	return 0;
}
*/

/*
#include<stdio.h>
int main()
{
	char a[50],b[50];				//only alphabets
	int j=0,k=0;
	printf("Input a String : ");
	fgets(a,sizeof(a),stdin);
	while(a[j]!='\0')
	{
		if(a[j]>=65 && a[j]<=90 || a[j]>=97 && a[j]<=122)
		{
			b[k]=a[j];
			k++;
		}
		j++;
	}
	printf("%s\n",b);
	return 0;
}
*/

/*
#include<stdio.h>
int main()
{
	char a[50],b[50];				//Space deletion
	int j=0,k=0;
	printf("Input a String : ");
	fgets(a,sizeof(a),stdin);
	while(a[j]!='\0')
	{	
		if(a[j]!=32)
		{
			b[k]=a[j];
			k++;
		}
		j++;
	}
	printf("%s",b);
	return 0;
}
*/

/*
#include<stdio.h>
int main()
{
	int a,*p;					//pointer address print
	printf("Input a no. ");
	scanf("%d",&a);
	p=&a;
	printf("%p",p);
	return 0;
}
*/

/*
#include<stdio.h>		
int main()
{
	int *a;						//size of pointers
	short int *b;
	long int *c;
	char *d;
	float *e;
	double *f;
	printf("int : %zu\n",sizeof(*a));
	printf("Short int : %zu\n",sizeof(*b));
	printf("Long int : %zu\n",sizeof(*c));
	printf("char : %zu\n",sizeof(*d));
	printf("float : %zu\n",sizeof(*e));
	printf("double : %zu\n",sizeof(*f));
	return 0;
}
*/

/*
#include <stdio.h>
int main() {
    printf("Size of integer pointer: %zu bytes\n", sizeof(int*));
    printf("Size of short integer pointer: %zu bytes\n", sizeof(short int*));
    printf("Size of long integer pointer: %zu bytes\n", sizeof(long int*));
    printf("Size of character pointer: %zu bytes\n", sizeof(char*));
    printf("Size of float pointer: %zu bytes\n", sizeof(float*));
    printf("Size of double pointer: %zu bytes\n", sizeof(double*));

    return 0;
}
*/

/*
#include<stdio.h>
int main()
{
	int *a,*b,*c,d,e,f;					//swap using pointer
	a=&d,b=&e,c=&f;
	printf("Input two no. ");
	scanf("%d %d",a,b);
	*c = *a;
	*a = *b;
	*b = *c;
	printf("%d %d\n",*a,*b);
	return 0;
}
*/

/*
#include<stdio.h>
int main()
{
	int *a,*b,d,e;						//greater using pointer
	a=&d,b=&e;
	printf("Input two no. ");
	scanf("%d %d",a,b);
	if(*a>*b)
	printf("%d\n",*a);
	else
	printf("%d\n",*b);
	return 0;
}
*/

/*
#include<stdio.h>
int main()
{
	int a[10],*b,*p,*q,*z,n;				//array access using pointer
	z=&n;
	b=a;
	printf("Input no of elements : ");
	scanf("%d",z);
	for(int j=0;j<n;j++,b++)
	scanf("%d",b);
	p=a;
	q=&a[n-1];
	printf("First : %d\nSecond : %d\nSecond-First : %d\n",*p,*q,*q-*p);
}
*/

/*
#include<stdio.h>
void swap(int *x,int *y);
int main()
{
	int *a,*b,c,d;						//swap pass using pointer
	a=&c,b=&d;
	printf("Input two no. ");
	scanf("%d %d",a,b);
	swap(a,b);
	printf("%d %d\n",*a,*b);
}

void swap(int *x,int *y)
{
	int *j,k;
	j=&k;
	*j=*x;
	*x=*y;
	*y=*j;
}
*/

/*
#include<stdio.h>
int main()
{
	int a[10],*p,n,*z,*b;					//array print using pointer
	z=&n;
	printf("Input no of elements : ");
	scanf("%d",z);
	b=a;
	for(int j=0;j<n;j++,b++)
	scanf("%d",b);
	p=a;
	for(int j=0;j<n;j++,p++)
	printf("%d ",*p);
}
*/

/*
#include<stdio.h>
int main()
{
	int a[10],*p,n,*z,*b;					//print array reverse using pointer
	z=&n;
	printf("Input no of elements : ");
	scanf("%d",z);
	b=a;
	for(int j=0;j<n;j++,b++)
	scanf("%d",b);
	p=&a[n-1];
	for(int j=0;j<n;j++,p--)
	printf("%d ",*p);
}
*/

/*
#include<stdio.h>
int main()
{
	int a[10],*p,n,*z,*b,*q;				//increment decrement using pointer
	z=&n;
	printf("Input no of elements : ");
	scanf("%d",z);
	b=a;
	for(int j=0;j<n;j++,b++)
	scanf("%d",b);
	p=a;
	for(int j=0;j<n;j++,p++)
	{
		if(j%2==0)
		(*p) -= 10;
		else
		(*p)++;
	}
	q=a;
	for(int j=0;j<n;j++,q++)
	printf("%d ",*q);
}
*/

/*
#include<stdio.h>
int main()
{
	int a[10],*p,n,*z,*b,*q,*r,*s,t;			//reverse of array using pointer
	z=&n,s=&t;
	printf("Input no of elements : ");
	scanf("%d",z);
	b=a;
	for(int j=0;j<n;j++,b++)
	scanf("%d",b);
	p=a;
	q=&a[n-1];
	for(int j=0;j<n/2;j++,p++,q--)
	{
		*s=*p;
		*p=*q;
		*q=*s;
	}
	r=a;
	for(int j=0;j<n;j++,r++)
	printf("%d ",*r);
}
*/

/*
#include<stdio.h>
void sort2d(int r, int c, int a[][5]);
int main()
{
	int a[5][5],r,c;					//2d sorting
	printf("Enter no of rows and columns : ");
	scanf("%d %d",&r,&c);
	for(int j=0;j<r;j++)
	{	
		for(int k=0;k<c;k++)
		scanf("%d",&a[j][k]);
	}
	sort2d(r,c,a);
	for(int j=0;j<r;j++)
	{	
		for(int k=0;k<c;k++)
		printf("%d ",a[j][k]);
		printf("\n");
	}
}

void sort2d(int r, int c, int a[][5])
{
	int t;
	for(int j=0;j<r;j++)
	{	
		for(int k=0;k<c;k++)
		{
			for(int x=0;x<r;x++)
			{	
				for(int y=0;y<c;y++)
				{
					if(a[j][k]<a[x][y])
					{
						t=a[j][k];
						a[j][k]=a[x][y];
						a[x][y]=t;
					}
				}
			}
		}
	}
}
*/

/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;						
	char *p;
	printf("Input size of string : ");
	scanf("%d",&n);
	while(getchar() != '\n');
	p=(char *)malloc(n*sizeof(char));
	if(p==NULL)
	{
		printf("Memory Allocation failed!");
		return 1;
	}
	printf("Input a string : ");
	fgets(p,n*sizeof(char),stdin);
	printf("%s",p);
	free(p);
}
*/

/*
#include<stdio.h>

typedef struct student
{
	char *college;
	int roll;
	int marks;
	struct student *student;
}student;

int main()
{
	student bittu;
	bittu.college = "GEU\n";
	bittu.roll = 51;
	bittu.marks = 86;
	printf("%s",bittu.college);
	printf("%d\n",bittu.roll);
	printf("%d\n",bittu.marks);
}
*/

/*
#include<stdio.h>
int main()
{
	char a[50];				//Strlen using for
	int j=0;
	printf("Input a String : ");
	fgets(a,sizeof(a),stdin);
	for(j=0;a[j]!='\0';j++)
	{}
	printf("%d",j-1);
}
*/

/*
#include<stdio.h>
void sm(int *a,int *z, int *k);
int main()
{
	int a[20],n,k[2];				//error
	printf("Input Limit : ");
	scanf("%d",&n);
	for(int j=0;j<n;j++)
	scanf("%d",a+j);
	sm(a,n);
	printf("S: %d\nM: %d\n",k[0],k[1]);
}

void sm(int *a,int n, int *k)
{
	for(int j=0;j<n;j++)
	{if(*(a+j)>9)
	k[0]+=(*(a+j));
	else
	k[1]+=(*(a+j));}
}
*/

/*
#include<stdio.h>
int main()
{
	int a[5] = {5,1,15,20,25};			//3 2 15
	int i,j,m;
	i=++a[1]; 
	j=a[1]++;
	m=a[i++];
	printf("%d %d %d",i,j,m);
	return 0;
}
*/

/*
#include<stdio.h>
#include<string.h>
int main()
{ 
	struct box					//TRIANGLETRIANGLE
	{
		char shape[10];
	}box1,box2;
	strcpy(box1.shape,"TRIANGLE");
	printf("%s",box1.shape);
	box2=box1;
	strcpy(box2.shape,"SQUARE");
	printf("%s",box1.shape);
	return 0;
}
*/


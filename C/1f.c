/*
#include<stdio.h>
int p(int,int);
int main()				//x^y
{
	int x,y,z;
	printf("Input x and y : ");
	scanf("%d %d",&x,&y);
	z=p(x,y);
	printf("%d^%d = %d\n",x,y,z);
	return 0;
}

int p(int x,int y)
{
	if(y==1)
	return x;
	else
	return x*p(x,y-1);
}
*/


/*
#include<stdio.h>
#include<stdlib.h>
int main()					//memory allocation string print
{
	char r[20],s[20];
	printf("Enter String 1 and 2 : ");
	r = (char *)malloc(100*sizeof(char));
	s = (char *)malloc(100*sizeof(char));
	if(r==NULL)
	{
		printf("Memory Allocation Failed!\n");
		return 1;
	}
	if(s==NULL)
	{
		printf("Memory Allocation Failed!\n");
		free(r);
		return 2;
	}
	fgets(r,20*sizeof(char),stdin);
	fgets(s,20*sizeof(char),stdin);
	scanf("%s",s);
	printf("%s\n%s\n",r,s);
	free(r);
	free(s);
	return 0;
}
*/

/*
#include<stdio.h>
int fact(int);
int main()					//combination formula
{
	int n,r,o;
	printf("Input n and r : ");
	scanf("%d %d",&n,&r);
	o=fact(n)/(fact(n-r)*fact(r));
	printf("%d",o);
	return 0;
}




int fact(int n)
{
	if(n==1)
	return 1;
	else
	return n*fact(n-1);
}
*/


/*
#include<stdio.h>
int main()					//string print
{
	char r[20],s[20];
	printf("Enter String : ");
	fgets(r,20*sizeof(char),stdin);
	fgets(s,20*sizeof(char),stdin);
	printf("%s%s",r,s);
	return 0;
}

*/

/*
#include<stdio.h>
#include<string.h>
int main()					//palindrome
{
	char r[20];
	int j,i=0,c=0,z;	
	printf("Enter String : ");
	fgets(r,sizeof(r),stdin);
	j=strlen(r);
	while(i<=j-2)
	{
		printf("%c %c\n",r[i],r[j-i-2]);
		if(r[i]!=r[j-i-2])
		{
			c=1;
			break;
		}
		i++;
	}
	if(c==0)
	printf("Palindrome");
	else
	printf("Not a Palindrome");
	return 0;
}
*/

/*
#include<stdio.h>
#include<string.h>
int main()					//uppercase to lowercase
{
	char r[20];
	int j,i=0;
	printf("Enter String : ");
	fgets(r,sizeof(r),stdin);
	j=strlen(r);
	while(i<=j-2)
	{
		if(r[i]>64 && r[i]<91)
		r[i]+=32;
		i++;
	}
	printf("%s",r);
	return 0;
}
*/


/*
#include<stdio.h>
#include<math.h>
int* scr(int);
int main()					//square,cube,root return
{
	int n;
	printf("Enter a number : ");
	scanf("%d",&n);
	int *b=scr(n);
	for(int i=0;i<3;i++)
	printf("%d\n",b[i]);
	return 0;
}

int* scr(int n)
{
	int a[3];
	a[0]=n*n;
	a[1]=n*n*n;
	a[2]=sqrt(n);
	int *b=&a[0];
	return b;
}
*/


/*
#include<stdio.h>
int nod(int);
int main()					//no of digits return
{
	int n;
	printf("Enter a number : ");
	scanf("%d",&n);
	int d=nod(n);
	printf("%d\n",d);
	return 0;
}

int nod(int n)
{
	int c=0;
	while(n>0)
	{
		c++;
		n/=10;
	}
	return c;
}
*/


/*
#include<stdio.h>
int main()				//239 extract
{
	int r,s,j,c=0;
	printf("Enter two no. ");
	scanf("%d %d",&r,&s);
	for(int i=r;i<=s;i++)
	{
		j=i%10;
		if(j==2||j==3||j==9)
		c++;
	}
	printf("%d\n",c);
	return 0;
}
*/

/*
#include<stdio.h>
#include<string.h>
int main()							//Single and Multi occurs
{
	char r[20];
	int j,c,d,e=0,f=0;
	printf("Enter String : ");
	fgets(r,sizeof(r),stdin);
	j=strlen(r);
	for(int i=0;i<j-1;i++)
	{	
		d=0;
	if(r[i]=='$')
	{continue;}
	else
	{	
		for(int k=i+1;k<j;k++)
		{	
			if(r[k]=='$')
			{continue;}
			else
			{
				if(r[i]==r[k])
				{
					r[k]='$';
					d++;
				}
			}
		}
		if(d>0)
		f++;
		else
		e++;
		r[i]='$';				
	}
	}
	printf("Single : %d \nMulti : %d\n",e,f);
	return 0;
}
*/

/*
#include<stdio.h>

typedef struct
{
	int roll;
	char name[20];
	int maths;
	int physics;
	int chemistry;
}student;

int main()							//datatype and max marks details
{
	student a[10];
	int n,b,c[10],r=0,d;
	printf("Enter no of Students : ");
	scanf("%d",&n);
	for(int j=0;j<n;j++)
	{
		printf("Enter Roll no. : ");
		scanf("%d",&a[j].roll);
		getchar();
		printf("Enter Name : ");
		fgets(a[j].name,20,stdin);
		printf("Enter Marks in Maths, Physics and Chemistry: ");
		scanf("%d %d %d",&a[j].maths,&a[j].physics,&a[j].chemistry);
	}
	for(int j=0;j<n;j++)
	c[j]=a[j].maths+a[j].physics+a[j].chemistry;
	for(int j=1;j<n;j++)
	{
		if(c[j]>c[d])
		d=j;
	}
	printf("Maximum Marks Details :\nRoll No :  %d\nName : %sMarks in Maths : %d\nMarks in Physics : %d\nMarks in Chemistry : %d\n",a[d].roll,a[d].name,a[d].maths,a[d].physics,a[d].chemistry);
	return 0;
}
*/

/*
#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])				//String in File and Reverse of string
{
	char ch,b[20],t;
	char *filename = argv[1];
	FILE *f = fopen(filename,"wb");
	printf("Enter a string : ");
	while((ch = getchar()) != '\n')
	fputc(ch , f);
	fclose(f);
	FILE *z = fopen(filename,"rb");
	fread(b , 1 , 16 , f);
	int l=strlen(b);
	for(int i=0,j=l-1;i<j;i++,j--)
	{
		t=b[i];
		b[i]=b[j];
		b[j]=t;
	}
	printf("Output : %s\n",b);
	fclose(f);
	return 0;
}
*/

/*
#include<stdio.h>
int main(int argc,char *argv[])					//read int from file a and write sum of digits to file b
{
	int a[10],n, sum =0,b;
	char *filename1 = argv[1];
	char *filename2 = argv[2];
	FILE *f = fopen(filename1 , "rb");
	FILE *g = fopen(filename2 , "wb");
	printf("Enter no of Intergers : ");
	scanf("%d",&n);
	fread(a, sizeof(int), n, f);
	for(int j=0;j<n;j++)
	{
		while(a[j]>0)
		{
			b=a[j]%10;
			a[j]/=10;
			sum+=b;
		}
		a[j]=sum;
		sum=0;
	}
	for(int j=0;j<n;j++)
	printf("%d\n",a[j]);
	fwrite(a, sizeof(int), n, g);
	fclose(f);
	fclose(g);
	return 0;
}
*/

/*
#include<stdio.h>
int main()							//1-9 print pattern
{
	int c=1,n;
	printf("Enter no of rows : ");
	scanf("%d",&n);
	for(int j=0;j<n;j++)
	{	
		for(int k=0;k<=j;k++)
		{
			if(c==10)
			c=1;
			printf("%d ",c);
			c++;	
		}
		printf("\n");
	}
	
	return 0;
}
*/

/*
#include<stdio.h>
int main()							//reverse of array		
{
	int a[5]={1,2,3,4,5},b[5];
	for(int j=0,k=4;j<5;j++,k--)
	b[j]=a[k];
	for(int j=0;j<5;j++)
	printf("%d ",b[j]);
	return 0;
}
*/

/*
#include<stdio.h>
int main(int argc,char *argv[])					//read int from file a and write sum of digits to file b
{
	int a[10],n, sum =0,b;
	char *filename1 = argv[1];
	FILE *f = fopen(filename1 , "w");
	printf("Enter no of Intergers : ");
	scanf("%d",&n);
	for(int j=0;j<n;j++)
	{
	printf("Enter any Integer : ");
	scanf("%d",&a[j]);
	}
	fwrite(a, sizeof(int), n, f);
	fclose(f);
	return 0;
}
*/

/*
#include<stdio.h>
int sort(int,int *);
int main()									
{
	int a[10],j,n,r,s,t,b;
	printf("Enter no of Elements : ");
	scanf("%d",&n);
	for(j=0;j<n;j++)
	scanf("%d",&a[j]);
	sort(n,a);
	if(a[0]*a[1]>a[j-3]*a[j-2])
	{printf("%d %d %d\n",a[0],a[1],a[j-1]);
	r=a[0];
	s=a[1];
	t=a[j-1];
	}
	else
	{printf("%d %d %d\n",a[j-3],a[j-2],a[j-1]);
	r=a[j-3];
	s=a[j-2];
	t=a[j-1];
	}
	b=r*s*t;
	printf("FInal: %d",b);
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
int main()
{
	int a=0,b,num=5678976;
	while (num!=0)
	{
		a++;
		b=num%10; 
		num/=10;
	}
	printf("%d",a);
}
*/

/*
#include<stdio.h>
int sm(int a[5][5],int r,int c);
int main()
{
	int a[5][5],r,c;
	printf("Input no of Rows and Columns : ");
	scanf("%d %d",&r,&c);
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		scanf("%d",&a[i][j]);
	}
	printf("%d",sm(a,r,c));
	return 0;
}

int sm(int a[5][5],int r,int c)
{
	int sum=0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(a[i][j]>9)
			sum+=a[i][j];
		}
	}
	return sum;
}
*/

/*
#include<stdlib.h>
#include<stdio.h>
int main()
{
	int j;
	for(j=0;j<5;j++)
	printf("%d\n",j);
	for(j=0;j<5;j++)
	printf("%d\n",j);
	return 0;
}
*/

/*
#include <stdio.h>

int large(int*);
int small(int*);

int main() {
    int arr[ROWS][COLS];
    int i, j;
    printf("Enter elements of the 2D array (%d x %d):\n", ROWS, COLS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int largest = large(arr);
    int smallest = small(arr);
    printf("Largest : %d\nSmallest : %d\n",largest,smallest);
    return 0A
}

int large(int arr[][]) 
{
    int i, j;
    int largest = arr[0][0];

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (arr[i][j] > largest) {
                largest = arr[i][j];
            }
        }
    }

    return largest;
}

int small(int arr[][]) {
    int i, j;
    int smallest = arr[0][0];

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (arr[i][j] < smallest) {
                smallest = arr[i][j];
            }
        }
    }

    return smallest;
}


*/


/*
#include <stdio.h>
#include <string.h>
int main()
{
	char a[20],j=0;
	printf("Enter a String : ");
	fgets(a,sizeof(a),stdin);
	int l=strlen(a);
	while(j<l-1)
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
#include <stdio.h>
#include <string.h>
int main()
{
	char a[20],j=0,k=0,h;
	printf("Enter a String : ");
	fgets(a,sizeof(a),stdin);
	while(a[j]!='\0' && a[j]!='\n')
	j++,k++;
	int l=strlen(a);
	for(h=0;a[h]!='\0'&&a[h]!='\n';h++)
	{}
	printf("%d %d %d",k,l,h);
	return 0;
}
*/

/*
#include<stdio.h>
int main()
{
	int a[5][5],b[5][5],r,c,s=0;
	printf("Enter no of Rows and Colms : ");
	scanf("%d %d",&r,&c);
	for(int j=0;j<r;j++)
	{
		for(int k=0;k<c;k++)
		scanf("%d",&a[j][k]);
	}
	int m=a[0][0];
	for(int j=0;j<r;j++)
	{
		for(int k=0;k<c;k++)
		{
			
				
		}
	}
	for(int j=0;j<r;j++)
	{
		for(int k=0;k<c;k++)
		{		
			printf("%d",b[j][k]);	
		}
	}
	return 0;
}
*/


#include<stdio.h>
int main()
{
	



}


void 2dsort()
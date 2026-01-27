/*
#include <stdio.h>
#include <string.h>

int main()
{
							// WAP to delete n characters in the string from a particular position.
	char s[]={"Jai Shree Ram"};
	puts(s);

	int p=5,n=6;
	
	int l=strlen(s);

	printf("%d\n",l);
	p--;

	for(int i=0;i<n;i++)
	{
		for(int j=p;j<l;j++)
		s[j]=s[j+1];
		puts(s);
	}

	printf("\n");
	puts(s);

	return 0;
}
	
*/



/*
#include <stdio.h>
#include <stdlib.h>

int rev(int n);

int main()					//reverse the array elements from particular index to the last using dynamic memory allocation
{
	int p=3,s=10;
	p--;
	
	int *a = malloc(s*sizeof(int));

	for(int i=0;i<s;i++)
	scanf("%d",&a[i]);


	for(int i=p;i<s;i++)
	a[i]=rev(a[i]);

	for(int i=0;i<s;i++)
	printf("%d\n",a[i]);

	free(a);

	return 0;
}




int rev(int n)
{
	int b,s=0;
	while(n!=0)
	{
		b=n%10;
		n/=10;
		s*=10;
		s+=b;
	}
	return s;
}
*/



/*
#include <stdio.h>
#include <string.h>

struct car				//structure named "Car" to store details like car ID, model, and rental rate per day
{
	int id,rd;
	char m[20];
};


int main()
{
	struct car a;
	int d,rt;

	printf("Enter Car ID : ");
	scanf("%d",&a.id);

	getchar();

	printf("Enter Car Model : ");
	fgets(a.m,20,stdin);

	printf("Enter Car Rental Per Day : ");
	scanf("%d",&a.rd);

	printf("Enter no of days for Car rental : ");
	scanf("%d",&d);

	rt=a.rd*d;

	printf("Car ID is %d\n",a.id);
	printf("Car Model is %s",a.m);
	printf("Enter Car Rental for %d days is %d\n",d,rt);

	return 0;
}
*/




/*
#include <stdio.h>

typedef struct Student				//structure to specify data on students Roll number, Name, Department, Course, Year of joining
{
	int roll,yj;
	char N[20],D[10],C[10]; 

}student;

void yoj(student a[20],int s,int y);
void data(student a[20],int s,int r);

int main()
{
	student a[20];
	int s,y,r,n;

	printf("Enter total no of student : ");
	scanf("%d",&s);

	for(int i=0;i<s;i++)
	{
		printf("Enter Roll No of Student %d : ",i+1);
		scanf("%d",&a[i].roll);

		getchar();

		printf("Enter Name of Student %d : ",i+1);		
		fgets(a[i].N,20,stdin);

		printf("Enter Department of Student %d : ",i+1);		
		fgets(a[i].D,10,stdin);

		printf("Enter Course of Student %d : ",i+1);		
		fgets(a[i].C,10,stdin);

		printf("Enter Year of Joining of Student %d : ",i+1);
		scanf("%d",&a[i].yj);
	}

	printf("Input 1 for Year of Joining and 2 for details of a Certain Roll No : ");
	scanf("%d",&n);
	
	switch(n)
	{
		case 1 :
		printf("Enter Joining Year to Find Students : ");
		scanf("%d",&y);

		yoj(a,s,y);
		break;

		case 2 : 
		printf("Enter Roll no to Find Student : ");
		scanf("%d",&r);

		data(a,s,r);
		break;

		default : 
		printf("Invalid Choice!\n");

	}
	return 0;

}

void yoj(student a[20],int s,int y)					//function to print names of all students who joined in a particular year.
{
	for(int i=0;i<s;i++)
	{
		if(y==a[i].yj)
		printf("%s",a[i].N);
	}
}

void data(student a[20],int s,int r)					//function to print the data of a student whose roll number is given
{
	for(int i=0;i<s;i++)
	{
		if(r==a[i].roll)
		{
			printf("%d\n",a[i].roll);
			printf("%s",a[i].N);
			printf("%s",a[i].D);
			printf("%s",a[i].C);
			printf("%d\n",a[i].yj);
			break;
		}
	}
}
*/













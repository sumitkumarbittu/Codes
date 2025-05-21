/*
Why HexaDecimal?
Because one character takes four bits and memory allocation 
says we can only store in multiple of eight so use of two 
characters is because eight bits i.e, two character of four 
bits each.
*/











#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	char name[50];
	char subject[50];
	int marks;
} student;

student get_child(char b[]);
int main()
{
	student moniter[10];
	for(int i=0;i<2;i++)
		moniter[i] = get_child("Enter a Student : ");
	for(int i=0;i<2;i++)
		printf("%s\n%s\n%d\n",moniter[i].name,moniter[i].subject,moniter[i].marks);
}

student get_child(char b[])
{
	student a;
	printf("%s",b);
	printf("\nEnter a Name : ");
	scanf("%s", a.name);
	printf("Enter a Subject : ");
	scanf("%s", a.subject);
	printf("Enter Marks : ");
	scanf("%d",&a.marks);
	return a; 
}



Hot sex naked stepmom Bittu favourite









/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	char name[50];
	char subject[50];
	int marks;
} student;

student get_child(char b[]);
int main()
{
	student moniter = get_child("Enter a Student : ");
	printf("%s\n%s\n%d\n",moniter.name,moniter.subject,moniter.marks);
}

student get_child(char b[])
{
	student a;
	printf("%s",b);
	printf("\nEnter a Name : ");
	scanf("%s", a.name);
	printf("Enter a Subject : ");
	scanf("%s", a.subject);
	printf("Enter Marks : ");
	scanf("%d",&a.marks);
	return a; 
}
*/
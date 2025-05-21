#include<stdio.h>
#include<string.h>

int get_int(void);
int get_string(void);

int main(void)
{
	int x = get_int();
	string y = get_string();
	printf("Age : %d \n Name : %s",x,y);
}



int get_int(void)
{
	int age;
	printf("What is your age?\n");
	scanf("%d",&age);
	return age;
}

int get_string(void)
{
	char n;
	printf("What is your name?\n");
	scanf("%s",&n);
}




















/*

#include <stdio.h>
int main()
{
	int n,i=0;
	printf("No of paracetamol Used this Month : ");
	scanf("%d",&n);
	while(i<=n)
	{
		printf("%d Liver is not safe, go to the doctor\n",i);
		i++;
	}
	
	return 0;
}

*/








/*

#include<stdio.h>
char get_string(char s[]);
int main()
{
	char *a = get_string("Enter a Word : ");
	printf("%s",a);

}

char get_string(char s[])
{
	char y[50];
	printf("%s",s);
	scanf("%s",&y);
	printf("%s",y);
	return *y;
}

*/


/*
#include<stdio.h>
int swap(int *);
int main()
{
	int a[] = {2,3};
	printf("a : %d , b : %d\n",a[0],a[1]);
	swap(a);
	printf("a : %d , b : %d\n",a[0],a[1]);

}

int swap(int *a)
{
	int c;
	c=a[1];
	a[1]=a[0];
	a[0]=c;
	return *a;
}
*/






/*

#include<stdio.h>
#include<stdint.h>

typedef uint8_t INT;

int main(int argc, char *argv[])
{
	char *filename = argv[1];
	int i=5; 
	INT a[i];
	
	FILE *f = fopen(filename,"rb");
	
	fread(a, 1, i, f);

	for(int j=0;j<i;j++)
	printf("%d\n",a[j]);

	fclose(f);
}

*/

/*

#include<stdio.h>

int main(int argc, char *argv[])
{
	char *filename = argv[1];
	int i=50; 
	char *a;
	a[i] = '\0';
	
	FILE *f = fopen(filename,"rb");
	
	fread(a, 1, i, f);

	printf("%s\n",a);

	fclose(f);
}

*/
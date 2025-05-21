#include<stdio.h>
#include<string.h>
int get_int(char x[]);
int sort1(int a[10],int n);
int main()
{
	int a[10];
	int n = get_int("Enter Size of Array : ");
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort1(a[n],n);
	for(int i=0;i<n;i++)
	printf("%d",a[i]);
	return 0;
}

int sort1(int a[n],int n)
{
	int x=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i+1;j++)
		{
			if (a[i]>a[i+1])
			{
				x=a[i];
				a[i]=a[i+1];
				a[i+1]=x;
			}
		}
}
















/*
#include <stdio.h>
int main()
{
	int n,a;
	printf("Input : ");
	scanf("%d",&n);
	for (int i=0;i<=n;i++)
	{
	a=(2*i)+1;
	printf("%d",a);
	}
	return 0;
}


#include <stdio.h>
void insertionSort(int arr[], int n);

int main() 
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void insertionSort(int arr[], int n) 
{
    int i, key, j;
    for (i = 1; i < n; i++) 
	{
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) 
	{
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
	}
}
*/

/*
#include<stdio.h>
#include<string.h>

typedef struct
{
	char *name;
	char *number;
	char *nature;
}
Person;

int main()
{
	Person People[3];
	
	People[0].name = "Sumit";
	People[0].number = "+91 99395 98571";
	People[0].nature = "Angry";

	People[1].name = "Bittu";
	People[1].number = "+91 99395 98571";
	People[1].nature = "Cute";

	People[2].name = "Bit";
	People[2].number = "+91 99395 98571";
	People[2].nature = "Hardworking";

	char *search;
	printf("Name : ");
	scanf("%s",search);
	printf("%s",search);
	for (int i=0;i<2;i++)
	{
		if(strcmp(People[i].name,search))
		{
			printf("Found\nName  %s\nNumber  %s\nNature  %s\n",People[i].name,People[i].number,People[i].nature);
			return 0;
		}
	}
	printf("Not Found");
	return 1;
}
*/







/*
#include<stdio.h>
int main()
{
	char *a = "Apple";
	printf("%s\n",a);
}
*/

/*
#include<stdio.h>
#include<string.h>
int main()
{
	char  *a[] = {"apple","ball"};
	printf("%s\n",a[0]);

}
*/

/*
#include <stdio.h>
#include <string.h>
char get_string(char x[]);
int main()
{
	char m[] = get_string("1st Input : ");
	char n[] = get_string("2nd Input : ");
	printf("%s\n%s\n",m,n);
	return 0;
}



char get_string(char x[])
{
	char *a = x;
	printf("%s",x);
	scanf("%s",&a[]);
	return a;
}
*/

/*
#include <stdio.h>
int get_int(char x[]);
#include <string.h>
int main()
{
	int m = get_int("1st Input : ");
	int n = get_int("2nd Input : ");
	printf("Sum is %d",m+n);
	return 0;
}
int get_int(char x[])
{
	int a;
	printf("%s",x);
	scanf("%d",&a);
	return a;
}
*/

/*
int main(int argc ,char *argv[])
{
	for (int i = 0; i < argc; i++)
	{
	printf("argv[%i] is %s\n", i, argv[i]);
	}
}
{
	char *h[] = {"Apple","Ball","Cat","Dog"};
	int n;
	printf("Input : ");
	scanf("%d",&n);
	printf("%s\n",h[n]);
}
{
int length;
do
{
	printf("Length : ");
	scanf("%d",&length);
}
while (length < 1);
int twice[length];
for (int i = 0; i < length; i++)
{
	if(i==0)
	twice[i] = 2;
	else
	twice[i] = 2 * twice[i-1];
	printf("%i\n", twice[i]);
}
}

{
	char n[] = "Emma";
	int length = strlen(n);
	for (int i = 0; i< length ; i++)
	{
		printf("%c ", n[i]);
	}
	printf("\n");
	return 0;
}

{
	char n[] = {'A','p','p','l','e'};
	char x[] = "Ball";
	
	for(int i=0;i<6;i++)
	printf("%s\n",x);
	return 0;
}

{
	int hours[] = {7, 9, 8, 7, 8};
	for (int i=0;i<5;i++)
	printf("%d\n", hours[i]);

}
{	
	string b = a("What's ur name?\n");
	printf("%s",a);
	return 0;
}
void a(string)
{
	char n;
	printf()
	scanf("%s",&n);
}
*/


int get_int(char x[])
{
	int a;
	printf("%s",x);
	scanf("%d",&a);
	return a;
}
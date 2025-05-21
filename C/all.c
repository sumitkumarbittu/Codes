



#include <stdio.h>
int main()
{
	int a=5;
	switch(a)
	{
		case 0:
		printf("0");
		case 3:
		printf("3");
		case 5:
		printf("5");
		default:
		printf("RABBIT");
	}
	
}



#include <stdio.h>

int main() {
    int day;
    printf("Enter a number for a day of the week (1-7): ");
    scanf("%d", &day);

    switch (day) 
{
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Invalid day number.\n");
            break;
}
    return 0;
}



#include <stdio.h>
int main()
{
	int n,i=1,sum=0;
	printf("Input a no. ");
	scanf("%d",&n);
	
	do
		{
			sum=sum+i;
			i++;
		}
	while(i<=n);
	{
		printf("%d",sum);
	}
	return 0;
}
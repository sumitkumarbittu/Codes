#include<stdio.h>
#include<math.h>
int main()
{
	int I,n;
	float rt;
    printf("enter the numberr");
    scanf("%f",&n);
   rt=sqrt(n);
	I=n/rt;
        if(n/(I*I)==1)
        {
            printf("the number is perfect sq number ");
            
        }
        else
        {
            printf("the number is not perfect sq number ");


        }
        

    
    return 0;
}

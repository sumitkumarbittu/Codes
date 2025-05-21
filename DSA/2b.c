/*

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()				// LEET #2000
{
//    char word[]="rzwuktxcjfpamlonbgyieqdvhs",ch='s';
    char word[]="abcd",ch='z'; 
    int z=1,k=0,l=0;
    char y;
    
    while(word[l] != '\0')
    {
        if(z!=0)
        {
            if(word[l] == ch)
            k++,z=0;
            else
            k++;
        }
        l++;
    }

    if(l<k)
    k=0;

    printf("%d %d\n",l,k);

    for(int i=0,j=k-1;i<k/2;i++,j--)
    {
        y=word[i];
        word[i]=word[j];
        word[j]=y;
    }

    printf("%s",word);


}

*/






/*

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()				// LEET #2000
{
//    char word[]="rzwuktxcjfpamlonbgyieqdvhs",ch='s';    
//    char word[]="abcd",ch='z';    

    int z=1,k=0,l=0;
    char y;
    
    while(word[l] != '\0')
    {
        if(z!=0)
        {
            if(word[l] == ch)
            k++,z=0;
            else
            k++;
        }
        l++;
    }

    if(z!=0)
    k++;

    if(l<=k)
    k=0;

    printf("%d %d ",k,l);

    for(int i=0,j=k-1;i<k/2;i++,j--)
    {
        y=word[i];
        word[i]=word[j];
        word[j]=y;
    }

    printf("%s",word);

}

*/








/*

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()				// LEET #2000   >>
{
//    char word[]="rzwuktxcjfpamlonbgyieqdvhs",ch='s';    
    char word[]="abcd",ch='z'; 

    int z=1,k=0,l=0;
    char y;
    
    while(word[l] != '\0')
    {
        if(z!=0)
        {
            if(word[l] == ch)
            k++,z=0;
            else
            k++;
        }
        l++;
    }

    if(z!=0)
    k++;

    if(l<k)
    k=0;

    printf("%d %d ",k,l);

    for(int i=0,j=k-1;i<k/2;i++,j--)
    {
        y=word[i];
        word[i]=word[j];
        word[j]=y;
    }

    printf("%s",word);


}

*/












/*

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


double minimumAverage(int* nums, int numsSize);


int main()				// LEET #3194   
{
//	int nums[]={7,8,3,4,15,13,4,1},n=8;
	int nums[]={1,9,8,3,10,5},n=6;

	double x=minimumAverage(nums,n);

	printf("%f\n",x);
}





double minimumAverage(int* nums, int numsSize) {
    int x=0,y,m,n,z;
    double a[50];
    double avg;



while(numsSize>0)
{
	for(int i=0;i<numsSize;i++)
    	printf("%d ",nums[i]);
	printf("\n");


    m=nums[0],n=nums[0];
    for(int i=0;i<numsSize;i++)
    {
        if(m<nums[i])
        m=nums[i],y=i;
        if(n>nums[i])
        n=nums[i],z=i;
    }
	printf("m : %d  n : %d\n",m,n);

    	avg=(m+n)/2.0;
	a[x++]=avg;

	printf("%f\n",avg);
	
    for(int i=y;i<numsSize-1;i++)
    nums[i]=nums[i+1];
    numsSize--;
    for(int i=z;i<numsSize-1;i++)
    nums[i]=nums[i+1];
    numsSize--;
}

    avg=a[0];
    for(int i=0;i<x;i++)
    {
        if(avg>a[i])
        avg=a[i];
    }
    return avg;
    
}

*/







/*

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


double minimumAverage(int* nums, int numsSize);


int main()				// LEET #3194   *giving error
{
//	int nums[]={7,8,3,4,15,13,4,1},n=8;
//	int nums[]={1,9,8,3,10,5},n=6;
	int nums[]={1,2,3,7,8,9},n=6;

	double x=minimumAverage(nums,n);

	printf("%f\n",x);
}







double minimumAverage(int* nums, int numsSize) {
    int x=0,y,m,n,z;
    double a[50];
    double avg;

while(numsSize>0)
{
    m=nums[0],n=nums[0];
    for(int i=0;i<numsSize;i++)
    {
        if(m<nums[i])
        m=nums[i],y=i;
        if(n>nums[i])
        n=nums[i],z=i;
    }
    a[x++]=(m+n)/2.0;
    for(int i=y;i<numsSize-1;i++)
    nums[i]=nums[i+1];
    numsSize--;
    for(int i=z;i<numsSize-1;i++)
    nums[i]=nums[i+1];
    numsSize--;
}

    avg=a[0];
    for(int i=0;i<x;i++)
    {
        if(avg>a[i])
        avg=a[i];
    }
    return avg;

}

*/






/*

#include<stdio.h>
#include<stdbool.h>

bool lemonadeChange(int* bills, int billsSize) {
    int x=0,y=0,z;
    for(int i=0;i<billsSize;i++)
    {
        if(bills[i]==5)
        x++;
        else if(bills[i]==10)
        {
            y++;
            if(x>0)
            x--;
            else
            return false;
        }
        else if(bills[i]==20)
        {
            z=15;
            if(y>0)
            y--,z=5;
            if(x>2 && z==15)
            {
                x-=3,z=0;
                continue;
            }
            if(x>0 && z==5)
            x--,z=0;
            else
            return false;
        }
    }
    return true;
}


int main()
{
	int a[]={5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5},n=20;

	bool x = lemonadeChange(int *a, int n);
	
	printbool(x);
	printf("%d\n",x);
}

*/





/*

int minIncrementForUnique(int* nums, int numsSize) {
    int a[50],l=0;
    for(int i=0;i<numsSize-1;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i]==nums[j])
            {
                for(int k=0;k<numsSize && k;k++)

            }
        }
    }
}


*/




/*


#include<stdio.h>

								//LEET #945

int minIncrementForUnique(int* nums, int numsSize) {
    int l=0,x=0;
    for(int i=0;i<numsSize-1;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            while(x==0){
            if(nums[i]==nums[j])
            {
                nums[j]++,l++,x=0;
                for(int k=0;k<numsSize && k!=j;k++)
                {
                    if(nums[j]==nums[k])
                    {
                        x++;
                        break;
                    }
                }

            }
          }
        }
    }
    return l;
}

int main()
{
	int a[]={1,2,2},n=3;

	int x = minIncrementForUnique(a,n);

	printf("%d",x);


}


*/





























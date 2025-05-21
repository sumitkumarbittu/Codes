#include<stdio.h>
#include<stdlib.h>

#define MAX 5

void cenqueue(int *a, int *f, int *r)
{
	if((*r+1)%MAX == MAX-1)
	printf("Queue is Full!\n");
	else if(*f == -1)
	{
		*f = *r = 0;
		printf("Enqueue : ");
		scanf("%d",&a[*f]);
	}
	else
	{
		printf("Enqueue : ");
		scanf("%d",&a[++(*r)]);
	}

}

void cdequeue(int *a, int *f, int *r)
{	
	if(*f == -1)
	printf("Queue is Empty!\n");
	else if( (*f+1)%MAX == (*r+1)%MAX )
	*f = *r = -1;
	else
	(*f)++;
}

void display(int *a, int f, int r)
{
	if(f == -1)
	printf("Queue is Empty!\n");
	else if( (r+1)%MAX == (f+1)%MAX )
	printf("Elements : %d\n",a[f]);
	else
	{
		f = (f+1)%MAX;
		r = (r+1)%MAX;
		printf("Elements : ");
		for(int i=f ; i<=r ; i++)
		{
			printf("%d ",a[i]);
			if(i == MAX-1)
			i = -1;
		}
		printf("\n");
	}
}


int main()
{
    int a[MAX], f = -1, r = -1, c;
    while(1)
    {
        printf("Choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1 :
                cenqueue(a,&f,&r);
                break;

            case 2 :
                cdequeue(a,&f,&r);
                break;
                
            case 3 :
                display(a,f,r);
                break;

            default :
                exit(0);

        }
    }
    return 0;
}
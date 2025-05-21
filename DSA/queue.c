#include<stdio.h>
#include<stdlib.h>

#define MAX 10

void enqueue(int *a, int *f,int *r)
{
    if(*r == MAX-1)
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

void dequeue(int *a, int *f,int *r)
{
    if(*f == -1)
    printf("List is Empty!\n");
    else if(*f == *r)
    *f = *r = -1;
    else
    (*f)++;
}

void display(int *a, int f,int r)
{
    if(f == -1)
    printf("List is Empty!\n");
    else if(f == r)
    printf("Elements : %d\n",a[f]);
    else
    {
        printf("Elements : ");
        for(int i=f ; i<=r ; i++)
        printf("%d ",a[i]);
        printf("\n");
    }
}

int main()
{
    int a[MAX], f=-1, r= -1, c;
    while(1)
    {
        printf("Choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1 :
                enqueue(a,&f,&r);
                break;

            case 2 :
                dequeue(a,&f,&r);
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
#include<stdio.h>
#include<stdlib.h>

#define MAX 10

void push(int *a,int *top)
{
    if(*top == MAX-1)
    printf("Stack is Full!\n");
    else if(*top == -1)
    {
        *top =  0;
        printf("Value : ");
        scanf("%d", &a[*top]);
    }
    else
    {
        printf("Value : ");
        scanf("%d",&a[++*top]);
    }
}

void pop(int *a,int *top)
{
    if(*top == -1)
    printf("Stack is Empty!\n");
    else
    (*top)--;
}

void display(int *a,int top)
{
    if(top == -1)
    printf("Stack is Empty!\n");
    else
    {
        printf("Elements : ");
        for(int i = 0 ; i <= top ; i++)
        printf("%d ",a[i]);
        printf("\n");
    }
}

int main()
{
    int top = -1, a[MAX];
    int c;
    while(1)
    {
        printf("Choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1 : 
                push(a,&top);
                break;

            case 2 : 
                pop(a,&top);
                break;

            case 3 : 
                display(a,top);
                break;

            default : 
                exit(0);
        }
    }

}





void push2(int *a,int *f,int *r)
{
    if(*r==MAX-1)
    printf("Stack is Full!\n");
    else if(*f==-1)
    {
        *f=*r=0;
        printf("Value : ");
        scanf("%d",&a[*r]);
    }
    else
    {
        printf("Value : ");
        scanf("%d",&a[++*r]);
    }
}

void pop2(int *a,int *f,int *r)
{
    if(*f==-1)
    {
        printf("Stack is Empty!\n");
    }
    else if(*f==*r)
    {
        printf("poped : %d\n",a[*r]);
        *f=*r=-1;
    }
    else
    {
        printf("poped : %d\n",a[(*r)--]);
    }
}

void display2(int *a,int f,int r)
{
    if(f==-1)
    printf("Stack is Empty!\n");
    else
    {
        printf("Elements : ");
        for(int i=f;i<=r;i++)
        printf("%d ",a[i]);
        printf("\n");
    }
}

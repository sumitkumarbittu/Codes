#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int d;
    struct stack *n;
};

struct stack* insertatbegin(struct stack *top)
{
    struct stack *new = (struct stack*)malloc(sizeof(struct stack));
    if(new == NULL)
    printf("Memory not allocated!\n");
    else
    {
        printf("Value (Insertion at begin): ");
        scanf("%d",&(new->d));
        new->n = top;
        top = new;
    }
    return top;
}

void display(struct stack *top)
{
    if(top == NULL)
    printf("List is Empty!\n");
    else if(top->n != NULL)
    printf("%d\n",top->d);
    else
    {
        struct stack *p = top, *q = top;
        while(q != NULL)
        {
            q = q->n;
            l++;
        }
        while(l>0)
        {
            p = top;
            while(p != q)
            p = p->n
            printf("%d ",p->d);
        }
    }
}

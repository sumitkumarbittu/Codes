#include<stdio.h>
#include<stdlib.h>

struct stackll
{
     
};

struct stack* insertatbegin(struct stack *head)
{
    struct stack *new = (struct stack*)malloc(sizeof(struct stack));
    if(new == NULL)
    printf("Memory not allocated!\n");
    else
    {
        printf("Value (Insertion at begin): ");
        scanf("%d",&(new->d));
        new->n = head;
        head = new;
    }
    return head;
}

void display(struct stack *head)
{
    if(head == NULL)
    printf("List is Empty!\n");
    else
    {
        struct stack *p = head;
        printf("Elements : ");
        while(p != NULL)
        {
            printf("%d ",p->d);
            p = p->n;
        }
        printf("\n");
    }
}


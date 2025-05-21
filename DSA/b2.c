

















/*

//2
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

struct snode
{
    int d;
    char name[MAX];
    struct snode *n;
};

struct snode* insertatend(struct snode *head)
{
    struct snode *new = (struct snode*)malloc(sizeof(struct snode));
    if(new == NULL)
    printf("Memory not allocated!\n");
    else if(head == NULL)
    {
        head = new;
        printf("Roll no (Insertion at End): ");
        scanf("%d",&(new->d));
        getchar();

        printf("Name (Insertion at End): ");
        fgets(new->name, sizeof(new->name), stdin);
        new->n = NULL;
    }
    else
    {
        struct snode *p = head;
        printf("Value (Insertion at End): ");
        scanf("%d",&(new->d));
        getchar();
        fgets(new->name, sizeof(new->name), stdin);
        new->n = NULL;
        while(p->n != NULL)
        p = p->n;
        p->n = new;
    }
    return head;
}

void display(struct snode *head)
{
    if(head == NULL)
    printf("List is Empty!\n");
    else
    {
        struct snode *p = head;
        printf("Elements : \n");
        while(p != NULL)
        {
            printf("%d   %s",p->d,p->name);
            p = p->n;
        }
    }
}

struct snode* deleteduplicate(struct snode *head)
{
    if(head == NULL || head->n == NULL)
    printf("Less than 2 Nodes!\n");
    else
    {
        struct snode *p = head, *q = NULL, *t =NULL;
        while(p != NULL)
        {
            q = p;
            while(q->n != NULL) 
            {
                if(strcmp(p->name, q->n->name) == 0)
                {
                    t = q->n;
                    q->n = q->n->n;
                    free(t);
                }
                else
                q=q->n;
            }
            p  = p->n;
        }
    }
    return head;
}

int main()
{
    struct snode *head = NULL;
    int c;
    do
    {
        printf("Choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1 :
                head = insertatend(head);
                break;

            case 2 :
                display(head);
                break;

            case 3 : 
                head = deleteduplicate(head);
                break;

            default :
                printf("THANK YOU!\n");
                exit(0);
        };
    }while(1);

    return 0;    
}

*/










/*

//1
#include<stdio.h>
#include<stdlib.h>

struct snode
{
    int d;
    struct snode *n;
};

struct snode* insertatend(struct snode *head)
{
    struct snode *new = (struct snode*)malloc(sizeof(struct snode));
    if(new == NULL)
    printf("Memory not allocated!\n");
    else if(head == NULL)
    {
        head = new;
        printf("Value (Insertion at End): ");
        scanf("%d",&(new->d));
        new->n = NULL;
    }
    else
    {
        struct snode *p = head;
        printf("Value (Insertion at End): ");
        scanf("%d",&(new->d));
        new->n = NULL;
        while(p->n != NULL)
        p = p->n;
        p->n = new;
    }
    return head;
}

void display(struct snode *head)
{
    if(head == NULL)
    printf("List is Empty!\n");
    else
    {
        struct snode *p = head;
        printf("Elements : ");
        while(p != NULL)
        {
            printf("%d ",p->d);
            p = p->n;
        }
        printf("\n");
    }
}

struct snode* reverse(struct snode *head) 
{
    struct snode *p = head, *q = NULL, *s = NULL;
    while (p != NULL)
    {
        s = p->n;
        p->n = q;
        q = p;
        p = s;
    }
    return q;
}


int main()
{
    struct snode *head = NULL;
    int c;
    do
    {
        printf("Choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1 :
                head = insertatend(head);
                break;

            case 2 :
                display(head);
                break;

            case 3 : 
                head = reverse(head);
                break;
               
            default :
                printf("THANK YOU!\n");
                exit(0);
        };
    }while(1);

    return 0;    
}

*/
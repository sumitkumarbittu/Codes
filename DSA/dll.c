#include<stdio.h>
#include<stdlib.h>

struct dnode
{
    struct dnode *f;
    int d;
    struct dnode *r;
};

struct dnode* insertatbegin(struct dnode *head)
{
    struct dnode *new = (struct dnode*)malloc(sizeof(struct dnode));
    if(new == NULL)
    printf("Memory not allocated!\n");
    else
    {
        new->f = NULL;
        printf("Begin Value : ");
        scanf("%d",&(new->d));
        if(head != NULL)
        head->f = new;
        new->r = head;
        head = new;
    }
    return head;
}

struct dnode* insertatend(struct dnode *head)
{
    printf("Function not Defined!\n");
    return head;
}

void display(struct dnode *head)
{
    if(head == NULL)
    printf("List is Empty!\n");
    else
    {
        struct dnode *p = head;
        printf("Elements : ");
        while(p != NULL)
        {
            printf("%d ",p->d);
            p = p->r;
        }
        printf("\n");
    }
}

struct dnode* deleteatbegin(struct dnode *head)
{
    printf("Function not Defined!\n");
    return head;
}

struct dnode* deleteatend(struct dnode *head)
{
    if(head == NULL)
    printf("List is Empty!\n");
    else if(head->r==NULL)
    {
        struct dnode *p = head;
        head = NULL;
        free(p);
    }
    else
    {
        struct dnode *p = head, *q = NULL;
        while(p->r->r != NULL)
        p = p->r;
        q = p->r;
        free(q);
        p->r = NULL;
    }
    return head;
}

struct dnode* insertatposition(struct dnode *head)
{
    struct dnode *new = (struct dnode *)malloc(sizeof(struct dnode));
    if(new == NULL)
    printf("Memory not Allocated!\n");
    else
    {
        int pos,i=1;
        printf("Enter Position : ");
        scanf("%d",&pos);
        if(pos == 1)
        {
            printf("Enter value (at position) : ");
            scanf("%d",&(new->d));
            new->f = NULL;
            new->r = head;
            head = new;
            return head;
        }
        
        struct dnode *p = head;
        while(p != NULL && i < pos-1)
        {
            p = p->r;
            i++;
        }

        if(p == NULL)
        printf("Invalid Position!\n");
        else
        {
            printf("Enter value (at position) : ");
            scanf("%d",&(new->d));
            if(p->r != NULL)
            p->r->f = new;
            new->r = p->r;
            new->f = p;
            p->r = new;
        }
    }
    return head;
}

struct dnode* deleteatposition(struct dnode *head)
{
    if(head == NULL)
    printf("List is Empty!\n");
    else
    {
        int pos,i=1;
        printf("Enter Position : ");
        scanf("%d",&pos);
        if(pos ==  1)
        {
            struct dnode *q = head;
            head = head->r;
            if(head != NULL)
            head->f = NULL;
            free(q);
            return head;
        }

        struct dnode *p = head;
        while(p != NULL && i < pos-1)
        {
            p = p->r;
            i++;
            printf("%d\n",i);
        }        

        if(p == NULL || p->r == NULL)
        printf("Invalid Position!\n");
        else
        {
            struct dnode *q = p->r;
            p->r = q->r;
            if(q->r != NULL)
            q->r->f = p;
            free(q);
        }
    }
    return head;
}

struct dnode* insertatsecond(struct dnode *head)
{
    struct dnode *new = (struct dnode*)malloc(sizeof(struct dnode));
    if(new==NULL)
    printf("Memory not allocated!\n");
    else if(head == NULL)
    {
        new->r = NULL;
        printf("Value (insertion at second) : ");
        scanf("%d",&new->d);
        new->f = head;
        head = new;
    }
    else
    {
        new->f = head;
        printf("Value (insertion at second) : ");
        scanf("%d",&new->d);
        new->r = head->r;
        if(head->r != NULL)
        head->r->f = new;
        head->r = new;
    }
    return head;
}

struct dnode* deleteatsecond(struct dnode *head)
{
    if(head == NULL || head->r == NULL)
    printf("Less than 2 Nodes!\n");
    else
    {
        printf("Value (deletion at second) : %d\n",head->r->d);
        head->r = head->r->r;
        head->r->f = head;
    }
    return head;
}

struct dnode* deleteAlternateNode(struct dnode* head) {
    if (head == NULL)
    return head;

    struct dnode* p = head;
    int c = 0;

    while (p != NULL) 
    {
        if (c % 2 != 0) 
        {
            if (p->f != NULL)
            p->f->r = p->r;

            if (p->r != NULL) 
            p->r->f = p->f;

            struct dnode* temp = p;
            p = p->r;
            free(temp);
        } 
        else
        p = p->r;
        c++;
    }
    return head;
}

int main()
{
    struct dnode *head = NULL;
    int c;
    do
    {
        printf("Choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1 : 
                head = insertatbegin(head);
                break;

            case 2 : 
                head = insertatend(head);
                break;

            case 3 : 
                display(head);
                break;

            case 5 : 
                head = deleteatend(head);
                break;

            case 6 : 
                head = insertatsecond(head);
                break;

            case 7 : 
                head = deleteatsecond(head);
                break;

            case 8 : 
                head = insertatposition(head);
                break;

            case 9 :
                head = deleteatposition(head);
                break;

            case 10 : 
                head = deleteAlternateNode(head);
                break;

            case 15 :
                head = insertatbegin(head);
                head = insertatbegin(head);
                head = insertatbegin(head);
                head = insertatbegin(head);
                head = insertatbegin(head);
                head = insertatbegin(head);
                head = insertatbegin(head);
                head = insertatbegin(head);
                display(head);
                break;

            default :
                printf("THANK YOU!\n");
                exit(0);

        }

    }while (1);

}

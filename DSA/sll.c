#include<stdio.h>
#include<stdlib.h>

struct snode
{
    int d;
    struct snode *n;
};

struct snode* insertatbegin(struct snode *head)
{
    struct snode *new = (struct snode*)malloc(sizeof(struct snode));
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

struct snode* insertmiddle2(struct snode *head)
{
    int c = 0;
    struct snode *p = head;
    while(p->n != NULL)
    {
        p = p->n;
        c++;
    }
    p = head;
    struct snode *new = (struct snode*)malloc(sizeof(struct snode));
    if(new == NULL)
    printf("Memory not allocated!\n");
    else
    {
        printf("Value (Insertion at Middle): ");
        scanf("%d",&(new->d));
    
        for(int i=0;i<c/2;i++)
        {
            
        }
    }
    return head;
}

struct snode* insertatposition(struct snode *head)
{
    struct snode *new = (struct snode *)malloc(sizeof(struct snode));
    if(new == NULL)
    printf("Memory not Allocated!\n");
    else
    {
        int pos,i=1;
        printf("Enter Position : ");
        scanf("%d",&pos);
        if(pos==1)
        {
            printf("Enter value (at position) : ");
            scanf("%d",&(new->d));
            new->n = head;
            head = new;
            return head;
        }

        struct snode *p = head;
        while(p != NULL && i < pos-1)
        {
            p = p->n;
            i++;
        }

        if(p == NULL)
        printf("Invalid Position!\n");
        else
        {
            printf("Enter value (at position) : ");
            scanf("%d",&(new->d));
            new->n = p->n;
            p->n = new;
        }
    }
    return head;
}

struct snode* deleteatpostion(struct snode *head)
{
    if(head == NULL)
    printf("List is Empty!\n");
    else
    {
        int pos,i=1;
        printf("Enter Position : ");
        scanf("%d",&pos);
        if(pos == 1)
        {
            struct snode *q = NULL;
            q = head;
            head = head->n;
            free(q);
            return head;
        }

        struct snode *p = head, *q = NULL;
        while(p != NULL && i < pos-1)
        {
            p = p->n;
            i++;
        }

        if(p == NULL)
        printf("Invalid Position!\n");
        else
        {
            q = p->n;
            p->n = p->n->n;
            free(q);
        }
    }
    return head;
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
                if(p->d == q->n->d)
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

struct snode* concatenate(struct snode *P,struct snode *Q)
{
    struct snode *z = P;
    while(z->n != NULL)
    z = z->n;
    z->n = Q;
    return P;
}

void concatenatetwo()
{
    struct snode *P = NULL;
    struct snode *Q = NULL;
    P = insertatbegin(P);   P = insertatbegin(P);   P = insertatbegin(P);
    P = insertatend(P);     P = insertatend(P);     P = insertatend(P);
    Q = insertatbegin(Q);   Q = insertatbegin(Q);   Q = insertatbegin(Q);
    Q = insertatend(Q);     Q = insertatend(Q);     Q = insertatend(Q);
    printf("P : \n");       display(P);
    printf("Q : \n");       display(Q);
    P = concatenate(P,Q);
    printf("P : \n");       display(P);
    printf("Q : \n");       display(Q);
}

struct snode* sorttwoll(struct snode  *p,struct snode *q)
{
    if(p == NULL)
    return q;
    else if(q == NULL)
    return p;
    else
    {
        struct snode *s, *t;
        if(p->d < q->d)
        {
            s = p;
            p = p->n;
        }
        else
        {
            s = q;
            q = q->n;
        }
        t = s;
        while(q != NULL &&  p != NULL)
        {
            if(p->d <= q->d)
            {
                t->n = p;
                p = p->n;
            }
            else
            {
                t->n = q;
                q = q->n;
            }
            t = t->n;
        }
        if(p != NULL)
        t->n = p;
        else
        t->n = q;
        return s;
    }
}

void sorttwo()
{
    struct snode *P = NULL;
    struct snode *Q = NULL;
    //P = insertatbegin(P);   P = insertatbegin(P);   P = insertatbegin(P);
    P = insertatend(P);     P = insertatend(P);     P = insertatend(P);
    //Q = insertatbegin(Q);   Q = insertatbegin(Q);   Q = insertatbegin(Q);
    Q = insertatend(Q);     Q = insertatend(Q);     Q = insertatend(Q);
    printf("P : \n");       display(P);
    printf("Q : \n");       display(Q);
    P = sorttwoll(P,Q);
    printf("P : \n");       display(P);
    printf("Q : \n");       display(Q);
}

struct snode* minmaxswap(struct snode *head)
{
    if(head == NULL || head->n == NULL)
    printf("Less than 2 nodes!\n");
    else
    {
        //int min = head->d, max = head->d;
        struct snode *m = head, *n = head, *p = head;
        struct snode *q = NULL, *r = NULL, *s = NULL, *t;
        while(p != NULL)
        {
            if(p->d > n->d)
            {
                n = p;
                r = s;
            }
            if(p->d < m->d)
            {
                m = p;
                q = s;
            }
            s = p;
            p = p->n;
        }
        if(m != n)
        {
            if(q != NULL)
            q->n = n;
            else
            head = n;

            if(r != NULL)
            r->n = m;
            else
            head = m;

            t = m->n;
            m->n = n->n;
            n->n = t;
        }
    }
    return head;
}

struct snode* deleteatalternate(struct snode *head)
{
    if(head == NULL)
    printf("List is Empty!\n");
    else
    {
        int c=0;
        struct snode *p = head;
        printf("Deletion at Alternate : ");
        while(p->n != NULL)
        {
            if(c%2==0)
            {
                printf("%d ",p->n->d);
                p->n = p->n->n;
            }
            else
            p = p->n;
            c++;
        }
    }
    return head;
}

struct snode* rotate(struct snode *head)
{
    if(head == NULL || head->n == NULL)
    printf("Less than 2 nodes!\n");
    else
    {
        int c;
        printf("Input no of ele to rotate : ");
        scanf("%d",&c);
        struct snode *p, *q;
        for(int i=0;i<c;i++)
        {
            p = head;
            while(p->n->n != NULL)
            p = p->n;
            q = p->n;
            p->n = NULL;
            q->n = head;
            head = q;
        }
    }
    return head;
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

struct snode* deleteNthFromEnd(struct snode* head) 
{
    struct snode *p = head, *q = head;

    int n;
    printf("Node to Delete from n : ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        if (p == NULL) 
        {
            printf("Less than %d nodes!\n", n);
            return head;
        }
        p = p->n;
    }

    if (p == NULL) 
    {
        struct snode* temp = head;
        head = head->n;
        free(temp);
        return head;
    }

    while (p->n != NULL)
    {
        p = p->n;
        q = q->n;
    }

    struct snode* temp = q->n;
    q->n = temp->n;
    free(temp);
    return head;
}

void printReverse(struct snode* head) 
{
    if (head == NULL) {
        return;
    }
    printReverse(head->n);
    printf("%d ", head->d);
}

struct snode* secondmin(struct snode *head)
{
    if(head == NULL)
    printf("List is Empty!\n");
    else if(head->n == NULL)
    {
        struct snode *t = head;
        head = NULL;
        free(t);
    }
    else
    {
        struct snode *p = head, *q = head, *t = NULL;
        while(p->n != NULL)
        {
            if(p->d )
        }


        free(t);
    }

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
                head = insertatbegin(head);
                break;

            case 2 :
                head = insertatend(head);
                break;

            case 3 :
                display(head);
                break;

            case 4 : 
                concatenatetwo();
                break;

            case 5 : 
                head = deleteatalternate(head);
                break;

            case 6 : 
                head = rotate(head);
                break;

            case 7 : 
                head = reverse(head);
                break;

            case 8 : 
                head = deleteduplicate(head);
                break;

            case 9 :
                head = insertatposition(head);
                break;

            case 10 : 
                head = deleteatpostion(head);
                break;

            case 11 : 
                head = deleteNthFromEnd(head);
                break;

            case 12 : 
                printf("Elements : ");
                printReverse(head);
                printf("\n");
                break;

            case 13 : 
                sorttwo();
                break;

            case 14 :
                head = minmaxswap(head);
                break;

            case 15 :
                head = insertatend(head);
                head = insertatend(head);
                head = insertatend(head);
                head = insertatend(head);
                head = insertatend(head);
                head = insertatend(head);
                head = insertatend(head);
                head = insertatend(head);
                display(head);
                break;

            default :
                printf("THANK YOU!\n");
                exit(0);
        };
    }while(1);

    return 0;    
}




















struct snode* reverse2(struct snode *head)
{
    if(head == NULL || head->n == NULL)
    printf("Less than 2 nodes!\n");
    else
    {
        struct snode *p = head , *q = NULL, *r = NULL, *s = NULL , *t = NULL;
        while(p!=q)
        {
            r=p;
            p=p->n;
            s=p;
            if(s->n == NULL || s->n->n == NULL)
            break;
            while(s->n->n != q)
            s=s->n;
            q=s;
            s=s->n;
            q->n=r;
            r->n=s->n;
            s->n=p;
            if(r == head)
            head = s;
        }
    }
    return head;
}

struct snode* reverse3(struct snode *head)
{
    struct snode *p = head , *q = NULL, *r = NULL, *s = NULL ;// *t = head;

    //while(t->n != NULL)
    //t=t->n;
    while(p!=q)
    {
        r=p;
        p=p->n;
        s=p;
        if(s->n == NULL || s->n->n == NULL)
        break;
        while(s->n->n != q)
        s=s->n;
        q=s;
        s=s->n;
        q->n=r;
        r->n=s->n;
        s->n=p;
        if(r == head)
        head = s;
    }
    return head;
}

struct snode* reverse4(struct snode *head) {
    struct snode *p = head, *q = NULL, *r = NULL, *s = NULL; 

    // If the list is empty or has only one node, no need to swap
    if (head == NULL || head->n == NULL) {
        return head;
    }

    while (p->n != NULL) {
        p = p->n;
    }
    q = p; // q now points to the last node
    p = head; // Reset p back to head

    // Swap p and last, q and q-last, and so on
    while (p != q && p->n != q) {
        // Save the n node after `p`
        s = p->n;

        // Swap the data of `p` (current node) and `q` (last node)
        int temp = p->d;
        p->d = q->d;
        q->d = temp;

        // Move `p` one step forward (toward the middle)
        p = s;

        // Find the node just before `q` (the q-to-last node)
        r = head;
        while (r->n != q) {
            r = r->n;
        }

        // Move `q` one step backward (toward the middle)
        q = r;
    }

    return head;
}

struct snode* rotate2(struct snode *head)
{
    if(head == NULL || head->n == NULL)
    printf("Less than 2 nodes!\n");
    else
    {
        int c;
        printf("Input no of ele to rotate : ");
        scanf("%d",&c);
        struct snode *p=head;
        for(int i=0;i<c;i++)
        {
            while(p->n!=NULL)
            p=p->n;
            p->n=head;
            head = head->n;
            p->n->n=NULL;
        }
    }
    return head;
}

struct snode* sorttwoll2(struct snode  *p,struct snode *q)
{
    if(p == NULL)
    return q;
    else if(q != NULL)
    {
        struct snode *s, *r;
        while(q != NULL)
        {
            s = q;
            q = q->n;
            s->n = NULL;
            r = p;
            while(r != NULL && r->d >= s->d)
            r = r->n;
            s->n = r->n;
            r->n = s;
        }
    }
    return p;
}

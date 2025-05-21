#include<stdio.h>
#include<stdlib.h>

struct cnode
{
    int d;
    struct cnode *n;
};

 
struct cnode* insertatbegin(struct cnode *head)
{
    struct cnode *new = (struct cnode*)malloc(sizeof(struct cnode));
    if(new == NULL)
    printf("Memory Not Allocated!\n");
    else if(head == NULL)
    {
        printf("Enter Value(insertion at begin) : ");
        scanf("%d",&new->d);
        head = new;
        new->n = head;
    }
    else
    {
        struct cnode *p = head;
        while(p->n != head)
        p=p->n;
        printf("Enter Value(insertion at begin) : ");
        scanf("%d",&(new->d));
        new->n = head;
        head = new;
        p->n = head;
    }
    return head;
}

struct cnode* insertatend(struct cnode *head)
{
	struct cnode *new = (struct cnode *)malloc(sizeof(struct cnode));
	if(new == NULL)
	printf("Memory not allocated!\n");
	else if(head == NULL)
	{
        	printf("Enter Value(insertion at end) : ");
        	scanf("%d",&new->d);
        	head = new;
        	new->n = head;
	}
	else
	{
		struct cnode *p = head;
		while(p->n != head)
		p = p->n;
		printf("Enter Value(insertion at end) : ");
        	scanf("%d",&new->d);
		new->n = head;
		p->n = new;
	}
	return head;
}

void display(struct cnode *head)
{
	if(head == NULL)
	printf("List is Empty!\n");
	else
	{
		struct cnode *p = head;
		printf("Elements : ");
		while(p->n != head)
		{
			printf("%d ",p->d);
			p = p->n;
		}
		printf("%d\n",p->d);
	}
}

struct cnode* deleteatbegin(struct cnode *head)
{
	if(head == NULL)
	printf("List is Empty!\n");
	else if(head->n == head)
	{
		struct cnode *t = head;
		head = NULL;
		free(t);
	}
	else
	{
		struct cnode *p = head, *t = head;
		while(p->n != head)
		p = p->n;
		head = head->n;
		p->n = head;
		free(t);
	}
	return head;
}

struct cnode* deleteatend(struct cnode *head)
{
	if(head == NULL)
	printf("List is Empty!\n");
	else if(head->n == head)
	{
		struct cnode *t = head;
		head = NULL;
		free(t);
	}
	else
	{
		struct cnode *p = head , *t;
		while(p->n->n != head)
		p = p->n;
		t = p->n;
		p->n = head;
		free(t);
	}
	return head;
}

struct cnode* deleteduplicate(struct cnode *head)
{
    if(head == NULL || head->n == head)
    printf("Less than 2 nodes!\n");
    else if(head->n->n == head)
    {
        if(head->d == head->n->d)
        {
            struct cnode *t = head->n;
            head->n = head;
            free(t);
        }
        return head;
    }
    else
    {
        struct cnode *p = head, *q = NULL, *t = NULL ;
        while(p->n->n != head)
        {
            q = p;
            while(q->n != head)
            {
                if(p->d == q->n->d)
                {
                    t = q->n;
                    q->n = q->n->n;
                    free(t);
                }
                else
                q = q->n;
            }
            p = p->n;
        }
    }
    return head;
}

struct cnode* reverse(struct cnode *head)
{               //	1 2 3 4 5 6			6 5 4 3 2 1
                //	2 3 4 5 6 1			5 4 3 2 1 6
	if(head == NULL || head->n == head)
	printf("Less than 2 nodes!\n");
	else
	{
		int c=1;
		struct cnode *r = head;
		while(r->n != head)
		r = r->n,c++;
		struct cnode *p = head, *q = r, *s = NULL; 
		while(c>0)
		{
			s = p->n;
			p->n = q;
			q = p;
			p = s;
			c--;
		}
		head = q;
	}
	return head;
}

struct cnode* rotate(struct cnode *head)
{
	if(head == NULL || head->n == head)
	printf("Less than 2 nodes!\n");
	else
	{
		int k;
		printf("No. of Elements to rotate : ");
		scanf("%d",&k);
		struct cnode *p, *q;
        for(int i=0;i<k;i++)
        {
            p = head;
            while(p->n->n != head)
            p = p->n;
            q = p->n;
            q->n = head;
            head = q;
            p->n = head;
        }
	}
	return head;
}

struct cnode* insertatposition(struct cnode *head)
{
    struct cnode *new = (struct cnode*)malloc(sizeof(struct cnode));
    if(new == NULL)
    printf("Memory Not Allocated!\n");
    else
    {
        int c=1,k;
        printf("Enter Position to insert : ");
        scanf("%d",&k);
        if(k == 1)
        {
            printf("Value to insert at %d position : ",k);
            scanf("%d",&(new->d));
            if(head == NULL)
            {
                head = new;
                head->n = head;
            }
            else
            {
                struct cnode *p = head;
                while(p->n != head)
                p = p->n;
                new->n = head;
                head = new;
                p->n = head;
            }
        }
        else if(k == 2 && head != NULL)
        {
            printf("Value to insert at %d position : ",k);
            scanf("%d",&(new->d));
            new->n = head->n;
            head->n = new;
        }
        else
        {
            struct cnode *p = head;
            while( (p != NULL || p != head) && c<k-1)
            {
                p = p->n;
                c++;
            }
            if(p == head)
            printf("Invalid Position!\n");
            else
            {
                printf("Value to insert at %d position : ",k);
                scanf("%d",&(new->d));
                new->n = p->n;
                p->n = new;
            }
        }
    }
    return head;
}

struct cnode* insertatposition3(struct cnode *head)
{
    int c=0,k;
    printf("Enter Position to insert : ");
    scanf("%d",&k);
    struct cnode *p = head;
    while( (p != NULL || p->n != head) && c<k)
    {
        p = p->n;
        c++;
    }
    if(p->n != head)
    printf("Invalid Position!\n");
    else
    {
        struct cnode *new = (struct cnode*)malloc(sizeof(struct cnode));
        if(new == NULL)
        printf("Memory Not Allocated!\n");
        else
        {
            struct cnode *q;
            q = p->n;
            printf("Value (Insertion at Pos %d) : ",k);
            scanf("%d",&new->d);
            p->n = new;
            new->n = q;
        }
    }
    return head;
}

int main()
{
    struct cnode *head = NULL;
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
                head = deleteatbegin(head);
                break;

            case 5 : 
                head = deleteatend(head);
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

            case 15 :
                head = insertatend(head);   head = insertatend(head);
                head = insertatend(head);   head = insertatend(head);
                head = insertatend(head);   head = insertatend(head);
                break;

            default : 
                printf("THANK YOU!\n");
                exit(0);

        }

    }while(1);

    return 0;
}



























struct cnode* deleteduplicate2(struct cnode *head)
{
    if(head == NULL || head->n == head)
    printf("Less than 2 nodes!\n");
    else
    {
        struct cnode *p = head, *q = NULL, *t = NULL ;
        do
        {
            q = p;
            while(q->n != head)
            {
                if(p->d == q->n->d)
                {
                    t = q->n;
                    q->n = q->n->n;
                    free(t);
                }
                else
                q = q->n;
            }
            p = p->n;
        }while(p != head);
    }
    return head;
}

struct cnode* insertatend2(struct cnode *head)
{
    struct cnode *new = (struct cnode*)malloc(sizeof(struct cnode));
    if (new == NULL) {
        printf("Memory Not Allocated!\n");
        return head;
    }
    printf("Enter Value (insertion at end): ");
    scanf("%d", &(new->d));
    if (head == NULL)
    {
        head = new;
        new->n = head;
    }
    else
    {
        struct cnode *p = head;
        while (p->n != head)
        p = p->n;
        p->n = new;
        new->n = head;
    }
    return head;
}

struct cnode* insertatposition2(struct cnode *head) {
    struct cnode *new = (struct cnode*)malloc(sizeof(struct cnode));
    if (new == NULL)
    {
        printf("Memory Not Allocated!\n");
        return head;
    }

    int p;
    printf("Enter position to insert : ");
    scanf("%d",&p);

    printf("Enter Value (insertion at p %d): ", p);
    scanf("%d", &(new->d));

    if (head == NULL)
    {
        if (p == 0)
        {
            head = new;
            new->n = head;
        }
        else
        printf("Position out of bounds!\n");
        return head;
    }

    if (p == 0)
    {
        struct cnode *p = head;
        while (p->n != head)
        p = p->n;
        new->n = head;
        head = new;
        p->n = head; 
        return head;
    }
    struct cnode *c = head;
    int i = 0;

    while (i < p - 1 && c->n != head)
    {
        c = c->n;
        i++;
    }

    if (i == p - 1)
    {
        new->n = c->n;
        c->n = new;
    }
    else
    {
        printf("Position out of bounds!\n");
        free(new);
    }

    return head;
}

struct cnode* insertafternode2(struct cnode *head, int target) {
    if (head == NULL)
    {
        printf("The list is empty!\n");
        return NULL;
    }
    struct cnode *c = head;
    do
    {
        if (c->d == target)
        {
            struct cnode *new = (struct cnode*)malloc(sizeof(struct cnode));
            if (new == NULL) 
            {
                printf("Memory Not Allocated!\n");
                return head;
            }
            printf("Enter Value (insertion after %d): ", target);
            scanf("%d", &(new->d));
            
            new->n = c->n;
            c->n = new;
            return head;
        }
        c = c->n;
    } while (c != head);

    printf("Node with value %d not found!\n", target);
    return head;
}

struct cnode* deletefrombeginning2(struct cnode *head)
{
    if (head == NULL)
    {
        printf("The list is empty! Nothing to delete.\n");
        return NULL;
    }

    struct cnode *toDelete = head;
    if (head->n == head)
    {
        free(toDelete);
        return NULL;
    }
    struct cnode *last = head;
    while (last->n != head)
    last = last->n;
    head = head->n;
    last->n = head;
    free(toDelete);

    return head;
}

struct cnode* deletefromend2(struct cnode *head)
{
    if (head == NULL)
    {
        printf("The list is empty! Nothing to delete.\n");
        return NULL;
    }
    struct cnode *toDelete = head;
    if (head->n == head)
    {
        free(toDelete);
        return NULL;
    }
    struct cnode *current = head;
    while (current->n->n != head)
    current = current->n;
    toDelete = current->n;
    current->n = head;
    free(toDelete);
    return head;
}

struct cnode* deletefromposition2(struct cnode *head)
{
    if (head == NULL)
    {
        printf("The list is empty! Nothing to delete.\n");
        return NULL;
    }

    int position;
    printf("Enter position to insert : ");
    scanf("%d",&position);

    if (position == 0)
    {
        struct cnode *toDelete = head;
        if (head->n == head)
        {
            free(toDelete);
            return NULL;
        }
        struct cnode *last = head;
        while (last->n != head)
        last = last->n;
        head = head->n;
        last->n = head;
        free(toDelete);
        return head;
    }
    struct cnode *current = head;
    int i = 0;

    while (i < position - 1 && current->n != head)
    {
        current = current->n;
        i++;
    }

    if (i == position - 1 && current->n != head)
    {
        struct cnode *toDelete = current->n;
        current->n = toDelete->n;
        free(toDelete);
    }
    else
    printf("Position out of bounds!\n");

    return head;
}

struct cnode* deletebefore2(struct cnode *head, int target)
{
    if (head == NULL)
    {
        printf("The list is empty! Nothing to delete.\n");
        return NULL;
    }

    struct cnode *current = head;
    struct cnode *prev = NULL;
    do {
        if (current->d == target)
        {
            if (prev == NULL)
            {
                printf("There is no node before the head!\n");
                return head;
            }
            struct cnode *toDelete = prev;

            if (toDelete == head)
            {
                struct cnode *last = head;
                while (last->n != head) {
                    last = last->n;
                }
                head = head->n;
                last->n = head;
            }
            else
            {
                prev = head;
                while (prev->n != toDelete)
                prev = prev->n;
                prev->n = toDelete->n;
            }

            free(toDelete);
            return head;
        }
        prev = current;
        current = current->n;
    } while (current != head);

    printf("Node with value %d not found!\n", target);
    return head;
}

void traverse2(struct cnode *head)
{
    if (head == NULL)
    {
        printf("The list is empty!\n");
        return;
    }

    struct cnode *current = head;
    do
    {
        printf("%d ", current->d);
        current = current->n;
    } while (current != head);

    printf("\n");
}

void display2(struct cnode *head)
{
    if(head == NULL)
    printf("List is Empty!\n");
    else
    {
        struct cnode *p = head;
       printf("Elements : ");
       while(p->n != head)
        {
            printf("%d ",p->d);
            p = p->n;
        }
        printf("%d\n",p->d);
    }
}

struct cnode* rotate2(struct cnode *head)
{
    if(head == NULL || head->n == head)
    printf("Less than 2 nodes!\n");
    else
    {
        struct cnode *p = head;
        while(p->n != head)
        p = p->n;
    }
    return head;
}

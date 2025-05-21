#include<stdio.h>
#include<stdlib.h>

struct cdnode
{
    struct cdnode *p;
    int d;
    struct cdnode *n;
};

struct cdnode* insertatbegin(struct cdnode *head) {
    struct cdnode *new = (struct cdnode*)malloc(sizeof(struct cdnode));
    if (new == NULL) {
        printf("Memory Not Allocated!\n");
        return head;
    }

    printf("Enter Value (insertion at begin): ");
    scanf("%d", &(new->d));

    if (head == NULL) {
        head = new;
        new->n = head;
        new->p = head;
    } else {
        struct cdnode *last = head->p;
        new->n = head;
        new->p = last;
        head->p = new;
        last->n = new;
        head = new;
    }
    return head;
}

struct cdnode* insertatend(struct cdnode *head) {
    struct cdnode *new = (struct cdnode*)malloc(sizeof(struct cdnode));
    if (new == NULL) {
        printf("Memory Not Allocated!\n");
        return head;
    }

    printf("Enter Value (insertion at end): ");
    scanf("%d", &(new->d));

    if (head == NULL) {
        head = new;
        new->n = head;
        new->p = head;
    } else {
        struct cdnode *last = head->p;
        new->n = head;
        new->p = last;
        last->n = new;
        head->p = new;
    }
    return head;
}

struct cdnode* insertatposition(struct cdnode *head) {
    struct cdnode *new = (struct cdnode*)malloc(sizeof(struct cdnode));
    if (new == NULL) {
        printf("Memory Not Allocated!\n");
        return head;
    }

    int p;
    printf("Enter position to insert: ");
    scanf("%d", &p);

    printf("Enter Value (insertion at p %d): ", p);
    scanf("%d", &(new->d));

    if (head == NULL) {
        if (p == 0) {
            head = new;
            new->n = head;
            new->p = head;
        } else {
            printf("Position out of bounds!\n");
        }
        return head;
    }

    if (p == 0) {
        return insertatbegin(head);
    }

    struct cdnode *current = head;
    int i = 0;

    while (i < p - 1 && current->n != head) {
        current = current->n;
        i++;
    }

    if (i == p - 1) {
        new->n = current->n;
        new->p = current;
        current->n->p = new;
        current->n = new;
    } else {
        printf("Position out of bounds!\n");
        free(new);
    }

    return head;
}

struct cdnode* insertafternode(struct cdnode *head) {
    if (head == NULL) {
        printf("The list is empty!\n");
        return NULL;
    }
    int target;
    printf("Target : ");
    scanf("%d",&target);

    struct cdnode *current = head;
    do {
        if (current->d == target) {
            struct cdnode *new = (struct cdnode*)malloc(sizeof(struct cdnode));
            if (new == NULL) {
                printf("Memory Not Allocated!\n");
                return head;
            }

            printf("Enter Value (insertion after %d): ", target);
            scanf("%d", &(new->d));

            new->n = current->n;
            new->p = current;
            current->n->p = new;
            current->n = new;
            return head;
        }
        current = current->n;
    } while (current != head);

    printf("Node with value %d not found!\n", target);
    return head;
}

struct cdnode* deletefrombeginning(struct cdnode *head) {
    if (head == NULL) {
        printf("The list is empty! Nothing to delete.\n");
        return NULL;
    }

    struct cdnode *toDelete = head;
    if (head->n == head) {
        free(toDelete);
        return NULL;
    }

    struct cdnode *last = head->p;
    head = head->n;
    last->n = head;
    head->p = last;
    free(toDelete);

    return head;
}

struct cdnode* deletefromend(struct cdnode *head) {
    if (head == NULL) {
        printf("The list is empty! Nothing to delete.\n");
        return NULL;
    }

    if (head->n == head) {
        free(head);
        return NULL;
    }

    struct cdnode *last = head->p;
    last->p->n = head;
    head->p = last->p;
    free(last);

    return head;
}

struct cdnode* deletefromposition(struct cdnode *head) {
    if (head == NULL) {
        printf("The list is empty! Nothing to delete.\n");
        return NULL;
    }

    int position;
    printf("Enter position to delete: ");
    scanf("%d", &position);

    if (position == 0) {
        return deletefrombeginning(head);
    }

    struct cdnode *current = head;
    int i = 0;

    while (i < position - 1 && current->n != head) {
        current = current->n;
        i++;
    }

    if (i == position - 1 && current->n != head) {
        struct cdnode *toDelete = current->n;
        current->n = toDelete->n;
        toDelete->n->p = current;
        free(toDelete);
    } else {
        printf("Position out of bounds!\n");
    }

    return head;
}

struct cdnode* deletebefore(struct cdnode *head) {
    if (head == NULL) {
        printf("The list is empty! Nothing to delete.\n");
        return NULL;
    }
    int target;
    printf("Target : ");
    scanf("%d",&target);

    struct cdnode *current = head;
    struct cdnode *prev = NULL;
    do {
        if (current->d == target) {
            if (prev == NULL) {
                printf("There is no node before the head!\n");
                return head;
            }

            struct cdnode *toDelete = prev;
            if (toDelete == head) {
                struct cdnode *last = head->p;
                head = head->n;
                last->n = head;
                head->p = last;
            } else {
                prev = head;
                while (prev->n != toDelete) {
                    prev = prev->n;
                }
                prev->n = toDelete->n;
                toDelete->n->p = prev;
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

void traverse(struct cdnode *head) {
    if (head == NULL) {
        printf("The list is empty!\n");
    } else {
        struct cdnode *current = head;
        do {
            printf("%d ", current->d);
            current = current->n;
        } while (current != head);
        printf("\n");
    }
}

void display(struct cdnode *head) {
    if (head == NULL) {
        printf("List is Empty!\n");
    } else {
        struct cdnode *p = head;
        printf("Elements: ");
        do {
            printf("%d ", p->d);
            p = p->n;
        } while (p != head);
        printf("\n");
    }
}

int main()
{
    struct cdnode *head = NULL;
    int c;
    while(1)
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
                head = insertatposition(head);
                break;

            case 5 : 
                head = insertafternode(head);
                break;

            case 6 : 
                head = deletefrombeginning(head);
                break;

            case 7 : 
                head = deletefromend(head);
                break;

            case 8 : 
                head = deletefromposition(head);
                break;

            case 9 : 
                head = deletebefore(head);
                break;

            case 10 : 
                traverse(head);
                break;

            default : 
                exit(0);
        }
    }
    return 0;
}

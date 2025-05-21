#include<stdio.h>
#include<stdlib.h>

struct bst
{
    struct bst *l;
    int d;
    struct bst *r;
};

struct bst* insert(struct bst *root, int v)
{
    if(root == NULL)
    {
        struct bst *new = (struct bst*)malloc(sizeof(struct bst));
        if(new == NULL)
        {
            printf("Memory not Allocated!\n");
            return root;
        }
        new->l = NULL;
        new->d = v;
        new->r = NULL;
        return new;
    }
    if(v < root->d)
    root->l = insert(root->l,v);
    else if(v > root->d)
    root->r = insert(root->r,v);
    else
    printf("Duplicate Value!\n");
    return root;
}

struct bst* delete(struct bst *root, int v)
{
    if(root == NULL)
    printf("Value Not Found!\n");
    else if(v < root->d)
    root->l = delete(root->l,v);
    else if(v > root->d)
    root->r = delete(root->r,v);
    else
    {
        if(root->l == NULL && root->r == NULL)
        {
            free(root);             //leaf node
            return NULL;
        }
        else if(root->l == NULL)
        {
            struct bst *t = root->r;
            free(root);             //one node right
            return t;
        }
        else if(root->r == NULL)
        {
            struct bst *t = root->l;
            free(root);             //one node left
            return t;
        }
        else
        {
            struct bst *t = root->r;
            while(t->l != NULL)        //two node
            t = t->l;
            root->d = t->d;
            root->r = delete(root->r, t->d);
        }
    }
    return root;
}

void inorder(struct bst *root)
{
    if(root == NULL)
    return;
    else
    {
        inorder(root->l);
        printf("%d ",root->d);
        inorder(root->r);
    }
}

void preorder(struct bst *root)
{
    if(root == NULL)
    return;
    else
    {
        printf("%d ",root->d);
        preorder(root->l);
        preorder(root->r);
    }
}

void postorder(struct bst *root)
{
    if(root == NULL)
    return;
    else
    {
        postorder(root->l);
        postorder(root->r);
        printf("%d ",root->d);
    }
}

int count0child(struct bst *root, int c)
{
    if(root == NULL)
    return c;
    if(root->l == NULL && root->r == NULL)
    c++;
    c = count0child(root->l,c);
    return count0child(root->r,c);
}

int count1child(struct bst *root, int c)
{
    if(root == NULL)
    return c;
    if(root->l == NULL && root->r != NULL)
    c++;
    if(root->l != NULL && root->r == NULL)
    c++;
    c = count1child(root->l,c);
    return count1child(root->r,c);
}

int count2child(struct bst *root, int c)
{
    if(root == NULL)
    return c;
    if(root->l != NULL && root->r != NULL)
    c++;
    c = count2child(root->l,c);
    return count2child(root->r,c);
}

int countnodes(struct bst *root, int c)
{
    if(root == NULL)
    return c;
    if(root->l == NULL && root->r == NULL)
    c++;
    if(root->l == NULL && root->r != NULL)
    c++;
    if(root->l != NULL && root->r == NULL)
    c++;
    if(root->l != NULL && root->r != NULL)
    c++;
    c = countnodes(root->l,c);
    return countnodes(root->r,c);
}

int min(struct bst *root)
{
    while(root && root->l != NULL)
    root = root->l;
    return root->d;
}

int max(struct bst *root)
{
    while(root && root->r != NULL)
    root = root->r;
    return root->d;
}

int height(struct bst *root)
{
    if(root == NULL)
    return -1;
    int left = height(root->l);
    int right = height(root->r);
    return (left > right ? left : right)+1;
}

int main()
{
    struct bst *root = NULL;
    int c,v;
    while(1)
    {
        printf("Choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1 :
                printf("Enter value : ");
                scanf("%d",&v);
                root = insert(root,v);
                break;

            case 2 :
                printf("Enter value : ");
                scanf("%d",&v);
                root = delete(root,v);
                break;

            case 3 :
                printf("Inorder : ");
                inorder(root);
                printf("\n");
                break;

            case 4 :
                printf("Preorder : ");
                preorder(root);
                printf("\n");
                break;

            case 5 :
                printf("Postorder : ");
                postorder(root);
                printf("\n");
                break;

            case 6 :
                printf("Count Leaf : %d\n",count0child(root,0));
                break;

            case 7 :
                printf("Count 1 child : %d\n",count1child(root,0));
                break;

            case 8 :
                printf("Count 2 child : %d\n",count2child(root,0));
                break;

            case 9 :
                printf("Count Nodes : %d\n",countnodes(root,0));
                break;

            case 10 :
                printf("Min : %d\n",min(root));
                break;

            case 11 :
                printf("Max : %d\n",max(root));
                break;

            case 12 :
                printf("Height : %d\n",height(root));
                break;

            default :
                printf("THANK YOU!\n");
                exit(0);
        }
    }
    return 0;
}

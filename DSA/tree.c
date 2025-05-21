#include<stdio.h>
#include<stdlib.h>

int** edge(int **t, int x,int y)
{

    return t;
}

void printtree(int **t, int n)
{
    int *s,l;
    for(int i=0;i<n;i++)
    {
        s = t[i];
        
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int **t = (int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
    {
        t[i] = (int *)malloc(10*sizeof(int));
        t[i][0] = -1;
    }
    int x,y;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d %d",&x,&y);
        t = edge(t,x,y);
    }
    printtree(t,n);
}





























/*

#include <stdio.h>
#include <stdlib.h>

// Function to add an edge from u to v
void addEdge(int** tree, int u, int v) {
    int* currentList = tree[u];
    int size = 0;

    // Find the current size of the adjacency list for node u
    while (currentList[size] != -1) {
        size++;
    }

    // Allocate more space if needed
    if (size % 10 == 0) {
        tree[u] = (int*)realloc(tree[u], (size + 11) * sizeof(int));
    }

    // Add the new edge and mark the end of the list with -1
    tree[u][size] = v;
    tree[u][size + 1] = -1;
}

// Function to print the adjacency list
void printTree(int** tree, int n) {
    for (int i = 0; i < n; i++) {
        int* currentList = tree[i];
        int j = 0;
        while (currentList[j] != -1) {
            printf("%d ", currentList[j]);
            j++;
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // This is our adjacency list
    int** tree = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        tree[i] = (int*)malloc(10 * sizeof(int));
        tree[i][0] = -1; // Initialize the list to be empty
    }

    int u, v;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &u, &v);
        addEdge(tree, u, v);
    }

    printTree(tree, n);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(tree[i]);
    }
    free(tree);

    return 0;
}

*/
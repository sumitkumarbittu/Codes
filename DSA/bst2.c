#include<stdio.h>
#include<stdlib.h>

// Define the binary search tree structure
struct bst {
    struct bst *l; // Left child
    int d;         // Data
    struct bst *r; // Right child
};

// Function to insert a value into the BST
struct bst* insert(struct bst *root) {
    int v;
    printf("Enter value to insert: ");
    scanf("%d", &v);

    // Create a new node
    struct bst *newNode = (struct bst*)malloc(sizeof(struct bst));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return root;
    }
    newNode->d = v;
    newNode->l = NULL;
    newNode->r = NULL;

    // Insert the new node into the correct position
    if (root == NULL) {
        return newNode; // New node becomes the root
    }
    if (v < root->d) {
        root->l = insert(root->l); // Recur to the left subtree
    } else {
        root->r = insert(root->r); // Recur to the right subtree
    }
    return root;
}

// Function for in-order traversal
void inorder(struct bst *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->l); // Traverse left subtree
    printf("%d ", root->d); // Print current node
    inorder(root->r); // Traverse right subtree
}

int main() {
    struct bst *root = NULL;
    int choice;

    while (1) {
        printf("\n1. Insert\n2. In-order Traversal\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = insert(root);
                break;
            case 2:
                printf("In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("THANK YOU!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

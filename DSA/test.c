#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    new_node->data = new_data;

    new_node->next = *head_ref;

    *head_ref = new_node;
}

void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

struct Node* reverse(struct Node *head);

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 40);
    insertAtBeginning(&head, 50);

    printf("Linked list: ");
    displayList(head);
    
    head = reverse(head);
    
    printf("Linked list: ");
    displayList(head);

    return 0;
}





struct Node* reverse(struct Node *head)
{
  struct Node *p = head ,*q = NULL,*r,*s;
  while(p!=q)
  {
    r=p;
    p=p->next;
    while(s->next!=q)
    s=s->next;
    q=s;
    s=s->next;
    s->next=p;
    q->next=r;
  }
  
  return head;
}


/*
#include<stdio.h>

typedef struct dnode {
    int d;
    struct dnode *r;  // Pointer to the next node
    struct dnode *l;  // Pointer to the previous node
} dnode;

void display(dnode *head) {
    if (head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    dnode *current = head;  // Use a separate pointer for traversal

    while (current != NULL) {
        printf("%d ", current->d);
        current = current->r;  // Move to the next node
    }

    printf("\n");  // Print newline at the end of the list
}


int main() {
    // Example setup of nodes (manual creation for illustration)
    dnode node1 = {10, NULL, NULL};
    dnode node2 = {20, NULL, &node1};
    dnode node3 = {30, NULL, &node2};
    node1.r = &node2;
    node2.r = &node3;

    dnode *head = &node1;

    // Display the list
    display(head);

    return 0;
}
*/
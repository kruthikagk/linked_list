#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

int main() {
    struct node *newnode = NULL, *head = NULL, *temp = NULL;
    int n;

    printf("Enter the number of nodes you want to insert: ");
    scanf("%d", &n);

    // Create the first node
    head = (struct node*)malloc(sizeof(struct node));
    printf("Enter data for node 1: ");
    scanf("%d", &head->data);
    head->link = NULL;
    temp = head;

    // Create remaining nodes
    for (int i = 1; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->link = NULL;
        temp->link = newnode;
        temp = newnode;
    }

    // Insertion at beginning
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert at beginning: ");
    scanf("%d", &newnode->data);
    newnode->link = head;
    head = newnode;

    // Insertion at end
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert at end: ");
    scanf("%d", &nn->data);
    nn->link = NULL;

    temp = head;
    while (temp->link != NULL)
        temp = temp->link;
    temp->link = nn;

    // Insertion at a given position
    int p, count = 1;
    printf("Enter the position you want to insert: ");
    scanf("%d", &p);

    temp = head;
    while (temp != NULL && count < p - 1) {
        temp = temp->link;
        count++;
    }

    if (temp == NULL)
        printf("Invalid position!\n");
    else {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter new node data: ");
        scanf("%d", &newnode->data);
        newnode->link = temp->link;
        temp->link = newnode;
    }

    // Delete at beginning
    if (head != NULL) {
        temp = head;
        head = head->link;
        free(temp);
    }

    // Delete at end
    temp = head;
    if (head != NULL) {
        if (head->link == NULL) {
            free(head);
            head = NULL;
        } else {
            while (temp->link->link != NULL)
                temp = temp->link;
            free(temp->link);
            temp->link = NULL;
        }
    }

    // Delete at given position
    struct node *prev;
    int g;
    printf("Enter the position of the node you want to delete: ");
    scanf("%d", &g);

    if (head == NULL)
        printf("List is empty!\n");
    else if (g == 1) {
        temp = head;
        head = head->link;
        free(temp);
    } else {
        temp = head;
        count = 1;
        while (temp != NULL && count < g) {
            prev = temp;
            temp = temp->link;
            count++;
        }
        if (temp == NULL)
            printf("Invalid position!\n");
        else {
            prev->link = temp->link;
            free(temp);
        }
    }

    // Displaying the linked list
    printf("\nFinal Linked List:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");

    return 0;
}

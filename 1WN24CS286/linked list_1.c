#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Insert at beginning */
void insert_begin() {
    struct node *newnode;
    int item;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &item);

    newnode->data = item;
    newnode->next = head;
    head = newnode;
}

/* Insert at end */
void insert_end() {
    struct node *newnode, *temp;
    int item;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &item);

    newnode->data = item;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

/* Insert at any position */
void insert_position() {
    struct node *newnode, *temp;
    int item, pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        insert_begin();
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &item);
    newnode->data = item;

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

/* Display list */
void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Any Position\n");
        printf("3. Insert at End\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_begin(); break;
            case 2: insert_position(); break;
            case 3: insert_end(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Insert at end (to build list) */
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

/* Delete first element */
void delete_first() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    temp = head;
    head = head->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

/* Delete last element */
void delete_last() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (head->next == NULL) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

/* Delete specified element */
void delete_element() {
    struct node *temp, *prev;
    int key;

    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    printf("Enter element to delete: ");
    scanf("%d", &key);

    temp = head;
    prev = NULL;

    if (temp->data == key) {
        head = temp->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }

    prev->next = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

/* Display list */
void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("Linked list is empty.\n");
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
        printf("1. Insert (to build list)\n");
        printf("2. Delete First Element\n");
        printf("3. Delete Specified Element\n");
        printf("4. Delete Last Element\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_end(); break;
            case 2: delete_first(); break;
            case 3: delete_element(); break;
            case 4: delete_last(); break;
            case 5: display(); break;
            case 6: return 0;
            default: printf("Invalid choice\n");
        }
    }
}

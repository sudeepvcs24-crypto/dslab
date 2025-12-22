#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

/* Insert at end (used to create lists) */
void insert_end(struct node **head) {
    struct node *newnode, *temp;
    int item;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &item);

    newnode->data = item;
    newnode->next = NULL;

    if (*head == NULL) {
        *head = newnode;
        return;
    }

    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

/* Display list */
void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* Sort linked list (Bubble sort method) */
void sort_list(struct node *head) {
    struct node *i, *j;
    int temp;

    if (head == NULL)
        return;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted successfully.\n");
}

/* Reverse linked list */
void reverse_list(struct node **head) {
    struct node *prev = NULL, *curr = *head, *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
    printf("List reversed successfully.\n");
}

/* Concatenate two lists */
void concatenate() {
    struct node *temp;

    if (head1 == NULL) {
        head1 = head2;
        return;
    }

    temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    printf("Lists concatenated successfully.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate List1 and List2\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_end(&head1); break;
            case 2: insert_end(&head2); break;
            case 3: display(head1); break;
            case 4: display(head2); break;
            case 5: sort_list(head1); break;
            case 6: reverse_list(&head1); break;
            case 7: concatenate(); break;
            case 8: return 0;
            default: printf("Invalid choice\n");
        }
    }
}

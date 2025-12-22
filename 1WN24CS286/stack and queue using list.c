#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;          // for Stack
struct node *front = NULL, *rear = NULL;   // for Queue

/* ---------------- STACK OPERATIONS ---------------- */

/* Push operation */
void push() {
    struct node *newnode;
    int item;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter element to push: ");
    scanf("%d", &item);

    newnode->data = item;
    newnode->next = top;
    top = newnode;

    printf("Element pushed successfully.\n");
}

/* Pop operation */
void pop() {
    struct node *temp;

    if (top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }

    temp = top;
    top = top->next;
    printf("Popped element: %d\n", temp->data);
    free(temp);
}

/* Display stack */
void display_stack() {
    struct node *temp = top;

    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

/* ---------------- QUEUE OPERATIONS ---------------- */

/* Enqueue operation */
void enqueue() {
    struct node *newnode;
    int item;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter element to enqueue: ");
    scanf("%d", &item);

    newnode->data = item;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Element enqueued successfully.\n");
}

/* Dequeue operation */
void dequeue() {
    struct node *temp;

    if (front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    temp = front;
    front = front->next;
    printf("Dequeued element: %d\n", temp->data);
    free(temp);

    if (front == NULL)
        rear = NULL;
}

/* Display queue */
void display_queue() {
    struct node *temp = front;

    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* ---------------- MAIN MENU ---------------- */

int main() {
    int choice;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display_stack(); break;
            case 4: enqueue(); break;
            case 5: dequeue(); break;
            case 6: display_queue(); break;
            case 7: return 0;
            default: printf("Invalid choice\n");
        }
    }
}

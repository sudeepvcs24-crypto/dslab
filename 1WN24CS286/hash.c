#include <stdio.h>
#define MAX 100

int ht[MAX];
int m;

/* Initialize hash table */
void init() {
    for (int i = 0; i < m; i++)
        ht[i] = -1;
}

/* Insert key using linear probing */
void insert(int key) {
    int index = key % m;
    int start = index;

    while (ht[index] != -1) {
        index = (index + 1) % m;

        if (index == start) {
            printf("Hash table is full. Cannot insert %d\n", key);
            return;
        }
    }

    ht[index] = key;
    printf("Key %d inserted at address %d\n", key, index);
}

/* Display hash table */
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++) {
        if (ht[i] == -1)
            printf("%d : EMPTY\n", i);
        else
            printf("%d : %d\n", i, ht[i]);
    }
}

int main() {
    int n, key;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    init();

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter 4-digit key: ");
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}

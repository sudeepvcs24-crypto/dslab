#include <stdio.h>

int n;
int adj[10][10];
int visited[10];

void dfs(int v) {
    int i;
    visited[v] = 1;

    for (i = 1; i <= n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (i = 1; i <= n; i++)
        visited[i] = 0;

    /* Start DFS from vertex 1 */
    dfs(1);

    /* Check if all vertices are visited */
    for (i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            printf("Graph is NOT connected.\n");
            return 0;
        }
    }

    printf("Graph is CONNECTED.\n");
    return 0;
}

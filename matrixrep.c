#include <stdio.h>

#define MAX 10

void createGraph(int adj[MAX][MAX], int n) {
    int i, j;
    int edges, src, dest;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize matrix with 0
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (src dest):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d%d", &src, &dest);
        adj[src][dest] = 1;  // directed edge
        adj[dest][src] = 1;  // comment this for directed graph
    }
}

void displayGraph(int adj[MAX][MAX], int n) {
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adj[MAX][MAX];
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    createGraph(adj, n);
    displayGraph(adj, n);

    return 0;
}

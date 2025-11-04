#include <stdio.h>

int adj[10][10];     // Adjacency matrix
int visited[10];     // Visited array

void dfs(int v, int n) {
    int i;
    visited[v] = 1;          // Mark current vertex as visited
    printf("%d ", v);        // Process (print) the vertex

    for (i = 0; i < n; i++) {
        // If there's an edge from v to i and i is not visited
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(i, n);       // Recur for next vertex
        }
    }
}

int main() {
    int n, e, i, v1, v2, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize adjacency matrix
    for (i = 0; i < e; i++) {
        printf("Enter edge (v1 v2): ");
        scanf("%d %d", &v1, &v2);
        adj[v1][v2] = adj[v2][v1] = 1;  // Undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    dfs(start, n);

    return 0;
}

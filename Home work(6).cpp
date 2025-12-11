#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];   // adjacency matrix
int visited[MAX];
int n; // number of nodes

void dfs(int node) {
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int edges, u, v;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    // Read edges
    printf("Enter each edge (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;   // undirected graph
    }

    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int component = 1;

    printf("\nConnected Components (Clusters):\n");

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("Cluster %d: ", component);
            dfs(i);
            printf("\n");
            component++;
        }
    }

    return 0;
}


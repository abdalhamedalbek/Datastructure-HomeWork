#include <stdio.h>

int graph[6][6] = {
 {0,1,0,0,0,0},
 {1,0,1,0,0,0},
 {0,1,0,0,0,0},
 {0,0,0,0,1,0},
 {0,0,0,1,0,0},
 {0,0,0,0,0,0}
};

int visited[6];

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for(int i=0;i<6;i++)
        if(graph[v][i] && !visited[i])
            dfs(i);
}

int main() {
    for(int i=0;i<6;i++) {
        if(!visited[i]) {
            printf("Cluster: ");
            dfs(i);
            printf("\n");
        }
    }
}

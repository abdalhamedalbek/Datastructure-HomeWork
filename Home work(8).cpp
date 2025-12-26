void dfs(int g[10][10], int v, int visited[]){
    visited[v]=1;
    printf("%d ", v);

    for(int i=0;i<10;i++)
        if(g[v][i] && !visited[i])
            dfs(g,i,visited);
}


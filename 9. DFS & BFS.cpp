void dfs(int v){
    visited[v]=1;
    for(int i=0;i<n;i++)
        if(graph[v][i] && !visited[i])
            dfs(i);
}
void bfs(int start){
    int q[50], f=0, r=0;
    q[r++] = start;
    visited[start]=1;

    while(f<r){
        int v = q[f++];
        for(int i=0;i<n;i++){
            if(graph[v][i] && !visited[i]){
                visited[i]=1;
                q[r++] = i;
            }
        }
    }
}


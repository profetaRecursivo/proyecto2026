int c = 0;
void dfs(int u, int p){
    tin[u] = ++c;
    low[u] = tin[u];
    for(int v:g[u]){
        if(v == p)continue;
        if(tin[v]==0){//no visitado
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u]){
                puentes.push_back({u, v});
            }
        }else
            low[u] = min(low[u], tin[v]);
        
    }
}
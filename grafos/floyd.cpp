vector<vector<int>> floyd(vector<vector<pii>>& grafo, int n){
    vector<vector<int>> dis(n+1, vi(n+1, INF));
    for(int i = 1;i<=n; i++){
        dis[i][i] = 0;
    }
    fore(u, 1, n+1){
        for(auto [v, w]:grafo[u]){
            dis[u][v] = min(dis[u][v], w);
            dis[v][u] = min(dis[v][u], w);
        }
    }
    fore(k, 1, n+1){
        fore(u, 1, n+1){
            fore(v, 1, n+1){
                dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
            }
        }
    }
    return dis;
}  

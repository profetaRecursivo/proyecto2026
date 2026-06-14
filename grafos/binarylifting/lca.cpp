auto lca = [&](int u, int v){
        if(dist[u] < dist[v])swap(u, v);
        if(dist[u] > dist[v]){
            int diff = dist[u] - dist[v];
            for(int i = 0; i<LOG; i++){
                if(diff>>i&1){
                    u = bl[u][i];
                }
            }
        }
        if(u == v){
            return u;
        }
        for(int i = LOG-1; i>=0; i--){
            if(bl[u][i] != bl[v][i]){
                u = bl[u][i], v = bl[v][i];
            }
        }
        return bl[u][0];
    };

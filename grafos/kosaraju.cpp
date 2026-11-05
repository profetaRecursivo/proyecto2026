struct Kosaraju {
    int n, scc_count;
    vector<vector<int>> adj, adj_rev;
    vector<int> comp;
    vector<bool> vis;
    vector<int> order;
    Kosaraju(int n, const vector<vector<int>>& adj) : n(n), adj(adj) {
        adj_rev.resize(n);
        for (int u = 0; u < n; u++) {
            for (int v : adj[u]) {
                adj_rev[v].push_back(u);
            }
        }
        vis.assign(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs1(i);
        }
        vis.assign(n, false);
        comp.assign(n, -1);
        scc_count = 0;
        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            if (!vis[u]) {
                dfs2(u, scc_count);
                scc_count++;
            }
        }
    }

    void dfs1(int u) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) dfs1(v);
        }
        order.push_back(u);
    }

    void dfs2(int u, int c) {
        vis[u] = true;
        comp[u] = c;
        for (int v : adj_rev[u]) {
            if (!vis[v]) dfs2(v, c);
        }
    }
};